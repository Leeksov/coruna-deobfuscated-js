let r = {};
const K = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  {
    N: x
  } = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  T = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c"),
  {
    engine: M
  } = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c"),
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
          case "__TEXT":
            n.fileOff.Et() ? o = false : l = t.sub(n.fileOff), i = t.sub(n.vmAddr);
            break;
          case "__LINKEDIT":
            u = n.vmAddr.add(i).sub(n.fileOff);
            break;
          case "__AUTH_CONST":
            if (r) {
              const t = n.sections.__auth_got;
              undefined !== t && (d = t.vmAddr.add(i))
            }
        }
        break
      }
      case (0x80000022):
        h = true, c = e.readU32(s.H(40)), a = e.readU32(s.H(44));
        break;
      case (0x80000033):
        h = true, c = e.readU32(s.H(8)), a = e.readU32(s.H(12))
    }
    s = s.H(f)
  }
  let b = i;
  if (r && !o && !m) {
    const r = e.readU32(t.H(4));
    if (w && 0x100000c === r && g >= 0xb0000) {
      if (null === d) throw new Error("");
      let t = e.readPtr(d).Dt();
      if (t.Et()) throw new Error("");
      for (t = t.Bt(t.it % 0x1000);
        (0xfeedfacf) !== e.readU32(t);) t = t.Bt(0x1000);
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
    const r = this.ao("_" + (t));
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
        i += (0x7f & r[n]) << o, o += 7
      } while (0x80 & r[n++]);
      if (e === t && 0 !== i) {
        n++;
        let t = 0;
        o = 0;
        do {
          t += (0x7f & r[n]) << o, o += 7
        } while (0x80 & r[n++]);
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
          h += (0x7f & r[n]) << o, o += 7
        } while (0x80 & r[n++]);
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
    const r = this.uo.ao("_" + (t));
    return r ? this.uo.parsedHeader.rwPrimAseData.H(r) : new K.Ptr64(0, 0)
  }
  wo(t) {
    const r = this.uo.ao("_" + (t));
    if (!r) throw new Error("");
    return r ? this.uo.parsedHeader.rwPrimAseData.H(r) : new K.Ptr64(0, 0)
  }
  mo(t) {
    return 0 !== this.uo.ao("_" + (t))
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
    const r = this.uo.ao("_" + (t));
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
    return 0 !== this.uo.ao("_" + (t))
  }
  wo(t) {
    const r = this.uo.ao("_" + (t));
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
    const r = this.getSegmentOrThrow("__TEXT");
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
    return "dyld_v1  arm64e" === this.magic()
  }
  Ko() {
    return this.cacheSlide
  }
  jo() {
    const t = [];
    if (!this.magic().startsWith("dyld")) throw new Error("");
    let r = T.engine.memory.readU32Raw(this.cacheHeader + 24),
      e = T.engine.memory.readU32Raw(this.cacheHeader + 28);
    if (0 === r && 0 === e && (this.Xo = true, r = T.engine.memory.readU32Raw(this.cacheHeader + 0x1c0), e = T.engine.memory.readU32Raw(this.cacheHeader + 0x1c4), 0 === r && 0 === e)) throw new Error("");
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
return r;
