let r = {};
globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0");
const T = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c"),
  {
    N: x,
    tn: W,
    nn: F,
    Ptr64: m,
    U: j,
    An: S,
    vn: O,
    T: l,
    v: o,
    I: u,
    B: s,
    K: R,
    O: L
  } = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0");
class DyldSharedCache {
  constructor(r, n) {
    this.vmSlide = r, this.images = n, this.rl = new or, this.nl = new er
  }
  tl(...r) {
    for (const n of r)
      for (const r of this.images)
        if (-1 !== r.path.indexOf(n)) return null === r.ol && (r.ol = rr.el(r.ll)), r.ol;
    throw new Error("")
  }
  static il(r) {
    const n = T.engine.memory,
      t = rr.il(r),
      o = (() => {
        const r = t.sl("__TEXT");
        if (null === r) throw new Error("");
        return {
          Qs: t.al - r.cl,
          fl: t.al - r._l
        }
      })(),
      e = n.readU32Raw(o.fl + 0x1c0n),
      l = n.readU32Raw(o.fl + 0x1c4n),
      i = [],
      s = o.fl + j(e);
    for (let r = 0; r < l; r++) {
      const e = S(n.readU64(s + j(32 * r))) + o.vmSlide,
        l = n.readU32Raw(s + j(32 * r) + 0x18n),
        a = n.readString(o.fl + j(l), 0x400);
      i.push({
        path: a,
        ll: e,
        ol: t.al === e ? t : null
      })
    }
    return new nt(o.vmSlide, i)
  }
}
r.ul = async function() {
  const r = T.engine.memory,
    n = new Intl.DateTimeFormat,
    t = r.addrOfJS(n),
    o = r.readU64(t + 0x18n),
    e = S(r.readU64(o)),
    l = S(r.readU64(e)),
    i = nt.il(l);
  T.engine.En = i
};
class rr {
  static il(r) {
    const n = T.engine.memory;
    let t = r - r % 0x1000n;
    for (;
      (0xfeedfacf) !== n.readU32Raw(t);) t -= 0x1000n;
    return rr.el(t)
  }
  static el(r) {
    const n = T.engine.memory,
      t = n.readU32Raw(r + j(16)),
      o = [];
    let e = null,
      l = null,
      i = 32;
    for (let s = 0; s < t; s += 1) {
      const t = n.readU32Raw(r + j(i)),
        s = n.readU32Raw(r + j(i) + j(4));
      switch (t) {
        case 25: {
          const t = Object.create({
            Re: n.readString(r + j(i) + j(8), 16),
            cl: n.readU64(r + j(i) + j(24)),
            ml: n.readU64(r + j(i) + j(32)),
            _l: n.readU64(r + j(i) + j(40)),
            dl: n.readU64(r + j(i) + j(48)),
            hl: n.readU32Raw(r + j(i) + j(56)),
            wl: n.readU32Raw(r + j(i) + j(60)),
            flags: n.readU32Raw(r + j(i) + j(68)),
            bl: undefined,
            yl: (() => {
              const t = n.readU32Raw(r + j(i) + j(64)),
                o = new Array(t).fill(null);
              for (const t in o) o[t] = {
                name: n.readString(r + j(80 * t) + j(i + 72), 16),
                cl: n.readU64(r + j(80 * t) + j(i + 72) + 0x20n),
                ml: n.readU64(r + j(80 * t) + j(i + 72) + 0x28n),
                _l: n.readU64(r + j(80 * t) + j(i + 72) + 0x30n),
                bl: undefined
              };
              return o
            })(),
            xl(r) {
              for (const n of this.yl)
                if (n.setAme === r) return n;
              return null
            }
          });
          if ("__TEXT" === t.segName) {
            if (null !== l) throw new Error("");
            l = r - t.cl
          }
          o.push(t);
          break
        }
        case (0x80000022):
        case (0x80000033):
          if (null !== e) throw new Error("");
          e = {
            _e: n.readU32Raw(r + j(i) + j((0x80000022) === t ? 40 : 8)),
            size: n.readU32Raw(r + j(i) + j((0x80000022) === t ? 44 : 12))
          }
      }
      i += s
    }
    const s = {},
      a = [];
    if (null === l) throw new Error("");
    for (const r of o) {
      r.bl = r.cl + l;
      for (const n of r.yl) n.bl = r.cl + l;
      r.segName.length > 0 ? s[r.segName] = r : a.push(r)
    }
    return new rr(r, s, a, e)
  }
  constructor(r, n, t, o) {
    const e = T.engine.memory;
    this.al = r, this.Al = n, this.Sl = t, this.Cl = (() => {
      if (null === o) return null;
      const r = n.__LINKEDIT;
      if (undefined === r) return null;
      const t = r.bl + j(o._e) - r._l,
        l = new Uint32Array(o.size + 3 >> 2);
      for (let r = 0; r < l.length; r++) l[r] = e.readU32Raw(t + j(4 * r));
      return new nr(l.buffer)
    })()
  }
  sl(r) {
    const n = this.Al[r];
    return undefined !== n ? n : null
  }
  kl(r) {
    if (null !== this.Cl) {
      const n = this.Cl.config(r);
      return null !== n ? this.al + j(n) : null
    }
    throw new Error("")
  }
}
class nr {
  config(r) {
    const n = new tr(this.Tl);
    let t = "",
      o = false;
    for (; !o;) {
      o = true;
      const e = n.El();
      if (0 !== e && r === t) {
        const r = n.El();
        if (8 !== r && 16 !== r) {
          return n.El()
        }
      }
      n.pl(e);
      const l = n.gl();
      for (let e = 0; e < l; e += 1) {
        const e = n.Il(0, 0x1024),
          l = n.El();
        if (e.length > 0 && r.startsWith(t + e)) {
          t += e, n.fe(l), o = false;
          break
        }
      }
    }
    return null
  }
  constructor(r) {
    this.Tl = r
  }
}
class tr {
  constructor(r) {
    this.Fl = new Uint8Array(r), this.en = new DataView(r), this.Pl = 0
  }
  pl(r) {
    this.Pl += r
  }
  fe(r) {
    this.Pl = r
  }
  gl() {
    const r = this.Fl[this.Pl];
    return this.Pl += 1, r
  }
  Il(r, n = 0x100) {
    let t = "";
    for (let o = 0; o < n; o++) {
      const n = this.gl();
      if (n === r) return t;
      t += String.fromCharCode(n)
    }
    throw new Error("")
  }
  El() {
    let r = 0,
      n = 0;
    for (let t = 0; t < 0x80; t += 1) {
      const t = this.gl();
      if (r += (0x7f & t) << n, n += 7, 0 == (0x80 & t)) return r
    }
    throw new Error("")
  }
}
class or {
  constructor() {}
  Ul(r) {
    const n = T.engine.memory,
      t = r.vl.kl(r.Dl);
    if (null !== t)
      for (const o of ["__AUTH", "__AUTH_CONST", "__DATA", "__DATA_DIRTY"]) {
        const e = r.Ll.sl(o);
        if (null !== e)
          for (let r = 0x0n; r < e.ml; r += 0x8n) {
            const o = n.readU64(e.bl + r);
            if (S(o) === t) return o
          }
      }
    return null
  }
  Bl(r) {
    const n = T.engine.memory,
      t = r.ol.sl("__TEXT");
    if (null === t) return null;
    const o = r.Ol;
    for (const e of ["__AUTH", "__AUTH_CONST", "__DATA", "__DATA_DIRTY"]) {
      const l = r.ol.sl(e);
      if (null !== l)
        for (let r = 0x0n; r < l.ml; r += 0x8n) {
          const e = n.readU64(l.bl + r),
            i = S(e);
          if (t.bl <= i && i <= t.bl + t.ml && this.Nl(i, o)) return e
        }
    }
    return null
  }
  Kl(r, n, t = null) {
    T.engine.memory;
    const o = r.sl("__TEXT");
    if (null === o) return null;
    const e = o.bl;
    let l = null !== t ? t - o.bl : 0x0n;
    for (; l < o.ml;) {
      const r = e + l;
      if (this.Nl(r, n, false)) return r;
      l += 0x4n
    }
    return null
  }
  zl(r, n = 64) {
    const t = T.engine.memory,
      o = r,
      e = [];
    let l = 0x0n;
    for (; l < j(n);) {
      const r = o + l,
        n = t.readU32Raw(r);
      if (0x14000000n === (0xfc000000n & j(n)) || 0x94000000n === (0xfc000000n & j(n))) {
        const t = 4 * this.Hl(n);
        e.push(r + j(t))
      }
      l += 0x4n
    }
    return e
  }
  Rl(r, n, t = 64) {
    T.engine.memory;
    const o = r;
    let e = 0x0n;
    for (; e < j(t);) {
      const r = o + e;
      if (this.Nl(r, n, false)) return r;
      e += 0x4n
    }
    return null
  }
  Hl(r) {
    return r << 6 >> 6
  }
  Nl(r, n, t = true) {
    const o = T.engine.memory;
    let e = 0;
    const l = [];
    for (const r of n) 0x90000000n === (0x9f000000n & j(r)) ? (l.push(0x9f00001fn), e += 1) : e > 0 && 0xf9400000n === (0xffc00000n & j(r)) ? l.push(0xffc003ffn) : 0x14000000n === (0xfc000000n & j(r)) || 0x94000000n === (0xfc000000n & j(r)) ? l.push(0xfc000000n) : l.push(0xffffffffn);
    l.length !== n.length && W();
    let i = r;
    for (const r in n) {
      const e = o.readU32Raw(i);
      if ((j(n[r]) & j(l[r])) != (j(e) & j(l[r]))) returnfalse;
      if (true === t && 0x14000000n === (0xfc000000n & j(e))) {
        const r = 4 * this.Hl(e);
        i += j(r)
      } else i += 0x4n
    }
    returntrue
  }
  Ml(r, n = 0x300, t = null) {
    const o = T.engine.memory,
      e = [],
      l = new Array(32).fill(null);
    let i = false;
    for (let s = 0; s < n; s += 4) {
      const n = r + j(s),
        a = j(o.readU32Raw(n));
      if (null !== t && a === t) {
        i = true;
        break
      }
      if (0xd65f0fffn === a || 0xd65f03c0n === a) {
        i = true;
        break
      }
      if (0x90000000n === (0x9f000000n & a)) {
        const r = a << 8n >> 13n,
          t = a >> 29n & 3n,
          o = 0x1fn & a,
          e = BigInt.asIntN(32, (r << 2n | t) << 12n);
        l[o] = n - n % 0x1000n + e
      } else if (0xf9400000n === (0xffc00000n & a)) {
        const r = a >> 5n & 0x1fn,
          n = a >> 10n & 0xfffn,
          t = l[r];
        null !== t && (e.push(t + 0x8n * n), l[r] = null)
      }
    }
    if (!i) throw new Error("");
    return e
  }
  Jl(r, n, t) {
    T.engine.En;
    const o = T.engine.memory,
      e = n.sl("__DATA_CONST");
    if (null === e) throw new Error("");
    let l = r;
    const i = o.readU32Raw(r);
    if (0x14000000n !== (0xfc000000n & j(i))) returnfalse;
    const s = 4 * this.Hl(i);
    l += j(s);
    try {
      const r = this.Ml(l, 0x300, 0xd4200020n);
      if (2 != r.length) returnfalse;
      const n = r[0];
      if (!(e.bl < n && n < e.bl + e.ml)) returnfalse;
      const i = o.readU64(n);
      return o.readString(i, t.length + 48) === t
    } catch (r) {
      returnfalse
    }
  }
  Gl(r, n, t) {
    const o = T.engine.En,
      e = T.engine.memory,
      l = o.tl(r),
      i = o.tl(n),
      s = i.sl("__TEXT");
    for (const r of ["__AUTH_CONST", "__DATA_CONST", "__AUTH"]) {
      const n = l.sl(r);
      if (null !== n)
        for (let r = 0x0n; r < n.ml; r += 0x8n) {
          const o = e.readU64(n.bl + r),
            l = S(o);
          if (s.bl <= l && l <= s.bl + s.ml && l % 0x4n === 0x0n && this.Jl(l, i, t)) return o
        }
    }
    throw new Error("")
  }
}
class er {
  constructor() {
    return this.jl = er.Xl(), this.Vl = {}, new Proxy(this, {
      get: (r, n) => (n in this.Vl || (this.Vl[n] = this.jl[n]()), this.Vl[n])
    })
  }
  static Xl() {
    return {
      Zl() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Ul({
          Dl: "_xmlSAX2GetPublicId",
          vl: r.tl("libxml2.2.dylib"),
          Ll: r.tl("libxml2.2.dylib")
        })
      },
      ql() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Bl({
          Dl: "enet_allocate_packet_payload_default",
          Ol: [(0xd503237f), (0xa9be4ff4), (0xa9017bfd), (0x910043fd), (0xaa0003f3), (0xb00f1048), (0xf9416d08), (0xaa0103e0), (0xd63f091f), (0xaa0003f4), (0xb5000080), (0xb00f1048), (0xf9417508), (0xd63f091f), (0xf9000a74), (0xa9417bfd), (0xa8c24ff4), (0xd65f0fff)],
          ol: r.tl("/System/Library/PrivateFrameworks/RESync.framework/RESync", "/System/Library/PrivateFrameworks/RESync.framework/Versions/A/RESync")
        })
      },
      Yl() {
        const r = T.engine.En,
          n = (T.engine.memory, r.rl.Ml(S(r.nl.ql), 0x230));
        if (2 !== n.length) throw new Error("");
        return n[0]
      },
      Wl() {
        const r = T.engine.En,
          n = (T.engine.memory, r.rl.Ml(S(r.nl.ql), 0x230));
        if (2 !== n.length) throw new Error("");
        return n[1]
      },
      $l() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Bl({
          Dl: "_HTTPConnectionFinalize",
          Ol: [(0xd503237f), (0xa9be4ff4), (0xa9017bfd), (0x910043fd), (0xaa0003f3), (0xf9402008), (0xb4000088), (0xf9401661), (0xaa1303e0), (0xd63f091f)],
          ol: r.tl("/System/Library/PrivateFrameworks/CoreUtils.framework/CoreUtils")
        })
      },
      Ql() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Bl({
          Dl: "_autohinter_iterator_begin",
          Ol: [(0xb40000c2), (0xf9400843), (0xb4000083), (0xf9400440), (0xf9401842), (0xd61f087f), (0xd65f03c0)],
          ol: r.tl("/System/Library/Frameworks/CoreGraphics.framework/CoreGraphics")
        })
      },
      Ka() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Bl({
          Dl: "_autohinter_iterator_end",
          Ol: [(0xb40000c1), (0xf9401022), (0xb4000082), (0xf9400420), (0xf9401821), (0xd61f085f), (0xd65f03c0)],
          ol: r.tl("/System/Library/Frameworks/CoreGraphics.framework/CoreGraphics")
        })
      },
      za() {
        const r = T.engine.En;
        T.engine.memory;
        return r.tl("libxml2.2.dylib").kl("_xmlHashScanFull")
      },
      Xa() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Kl(r.tl("/System/Library/Frameworks/CloudKit.framework/CloudKit"), [(0xd503237f), (0xa9bc5ff8), (0xa90157f6), (0xa9024ff4), (0xa9037bfd), (0x9100c3fd), (0xaa0303f3), (0xaa0203f4), (0xaa0003f5), 0x52800217, 0x52800200, 0x529de6e1, 0x72ad3dc1, (0x950881fa), (0xaa0003f6), (0xaa1503e0), (0xaa1603e2), (0x9408e512), (0xf9000297), (0xb02578b0), (0xf945fe10), (0xdac123f0), (0xf9000270), (0xaa1603e0), (0xa9437bfd), (0xa9424ff4), (0xa94157f6), (0xa8c45ff8), (0xd65f0fff)])
      },
      Za() {
        const r = T.engine.En,
          n = (T.engine.memory, r.nl.Xa),
          t = r.rl.Ml(S(n), 0x74);
        if (1 !== t.length) throw new Error("");
        return t[0]
      },
      qa() {
        const r = T.engine.En,
          n = T.engine.memory,
          t = r.tl("/usr/lib/libobjc.A.dylib"),
          o = r.tl("/System/Library/Frameworks/CloudKit.framework/CloudKit"),
          e = t.sl("__OBJC_RO");
        if (null === e) throw new Error("");
        const l = o.sl("__DATA_CONST");
        if (null === l) throw new Error("");
        const i = "cksqlcs_blobBindingValue:destructor:error:",
          s = l.bl + l.ml;
        for (let r = l.bl; r < s; r += 0x8n) {
          const t = n.readU64(r);
          if (t >= e.bl && t < e.bl + e.ml && n.readString(t, i.length) === i) return t
        }
        throw new Error("")
      },
      Ya() {
        const r = T.engine.En,
          n = T.engine.memory,
          t = r.tl("/usr/lib/libobjc.A.dylib"),
          o = r.tl("/System/Library/Frameworks/CloudKit.framework/CloudKit"),
          e = t.sl("__OBJC_RO");
        if (null === e) throw new Error("");
        const l = o.sl("__DATA_CONST");
        if (null === l) throw new Error("");
        const i = "UUID",
          s = l.bl + l.ml;
        for (let r = l.bl; r < s; r += 0x8n) {
          const t = n.readU64(r);
          if (t >= e.bl && t < e.bl + e.ml && n.readString(t, i.length + 48) === i) return t
        }
        throw new Error("")
      },
      Qa() {
        const r = T.engine.En,
          n = T.engine.memory,
          t = r.tl("/usr/lib/libobjc.A.dylib"),
          o = r.tl("/System/Library/PrivateFrameworks/UIKitCore.framework/UIKitCore"),
          e = t.sl("__OBJC_RO");
        if (null === e) throw new Error("");
        const l = o.sl("__DATA_CONST");
        if (null === l) throw new Error("");
        const i = "secondAttribute",
          s = l.bl + l.ml;
        for (let r = l.bl; r < s; r += 0x8n) {
          const t = n.readU64(r);
          if (t >= e.bl && t < e.bl + e.ml && n.readString(t, i.length + 48) === i) return r
        }
        throw new Error("")
      },
      rc() {
        T.engine.En, T.engine.memory;
        return T.engine.En.rl.Gl("/System/Library/PrivateFrameworks/UIKitCore.framework/UIKitCore", "/System/Library/PrivateFrameworks/UIKitCore.framework/UIKitCore", "secondAttribute")
      },
      nc() {
        const r = T.engine.En,
          n = (T.engine.memory, r.tl("/System/Library/Frameworks/Foundation.framework/Foundation").kl("_OBJC_CLASS_$_NSUUID"));
        if (null === n) throw new Error("");
        return n
      },
      tc() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Bl({
          Dl: "_EdgeInfoCFArrayReleaseCallBack",
          Ol: [(0xd503237f), (0xa9be4ff4), (0xa9017bfd), (0x910043fd), (0xaa0103f3), (0xaa0003f4), (0xf9400429), (0xf9400928), (0xb4000088), (0xf9400120), (0xf9400261), (0xd63f091f), (0xaa1403e0), (0xaa1303e1), (0xa9417bfd), (0xa8c24ff4), (0xd50323ff), (0xca1e07d0), (0xb6f00050), (0xd4388e20), 0x14055908],
          ol: r.tl("/System/Library/Frameworks/CoreMedia.framework/CoreMedia")
        })
      },
      oc() {
        const r = T.engine.En,
          n = T.engine.memory,
          [t, o] = (() => {
            const t = r.tl("libdyld.dylib").sl("__DATA_DIRTY");
            if (null === t) return null;
            const o = t.xl("__dyld4");
            if (null === o) return null;
            const e = n.readU64(o.bl + 8n),
              l = n.readU64(S(e)),
              i = n.readU64(S(l));
            return [e, rr.il(S(i))]
          })();
        if (null === o) throw new Error("");
        return o
      },
      ec() {
        const r = T.engine.En,
          n = (T.engine.memory, r.nl.oc),
          t = (() => {
            const t = [null],
              o = [(0xd503237f), (0xa9bf7bfd), (0x910003fd), (0xf9400009), (0xb6f80189), (0xd370c128), (0xd360bd23), (0xd371c924), (0xaa0203e0), (0xaa0803e2), (0xa8c17bfd), (0xd50323ff), (0xca1e07d0), (0xb6f00050), (0xd4388e20)];
            let e;
            for (e = [(0xaa0003f1), (0xaa0803f0), (0xd503211f), 0x1400000c, (0xaa0003f1), (0xaa0803f0), (0xdac10a11), 0x14000008, (0xaa0003f1), (0xaa0803f0), (0xd503215f), 0x14000004, (0xaa0003f1), (0xaa0803f0), (0xdac10e11), (0xaa1103e0), (0xd65f03c0)]; t.length > 0;) {
              const l = r.rl.Kl(n, o, t.pop());
              if (null === l) continue;
              t.push(l + 0x4n);
              const i = r.rl.zl(l, 4 * o.length + 12);
              for (const r in i)
                if (2 !== i.length) continue;
              if (null !== r.rl.Rl(i[0], e, 0x100)) return l
            }
            return null
          })();
        if (null === t) throw new Error("");
        const {
          lc: o,
          ic: e
        } = (() => {
          let o, e;
          e = 0x10n, o = [(0xaa0003f1), (0xaa0803f0), (0xd503211f), 0x1400000c, (0xaa0003f1), (0xaa0803f0), (0xdac10a11), 0x14000008, (0xaa0003f1), (0xaa0803f0), (0xd503215f), 0x14000004, (0xaa0003f1), (0xaa0803f0), (0xdac10e11), (0xaa1103e0), (0xd65f03c0)];
          let l = null;
          for (;;) {
            if (i = l, l = r.rl.Kl(n, o, i), null === l) return null;
            if (l !== t) break;
            l += j(0x4n * o.length)
          }
          var i;
          if (null === l) return null;
          return {
            lc: l - 0x40n,
            ic: {
              sc: l,
              ac: l + 1n * e,
              oe: l + 2n * e,
              cc: l + 3n * e
            }
          }
        })();
        if (null === o) throw new Error("");
        if (null === e.sc) throw new Error("");
        if (null === e.ac) throw new Error("");
        if (null === e.oe) throw new Error("");
        if (null === e.cc) throw new Error("");
        return o
      },
      fc() {
        const r = T.engine.En;
        T.engine.memory;
        return r.rl.Bl({
          Dl: "_dlfcn_globallookup",
          Ol: [(0xd503237f), (0xa9be4ff4), (0xa9017bfd), (0x910043fd), (0xaa0003f3), (0xd2800000), 0x52800021, (0x940ba8a8), (0xb4000100), (0xaa0003f4), (0xaa1303e1), (0x944354d1), (0xaa0003f3), (0xaa1403e0), (0x940ba899), (0xaa1303e0), (0xa9417bfd), (0xa8c24ff4), (0xd65f0fff)],
          ol: r.tl("/System/Library/PrivateFrameworks/ActionKit.framework/ActionKit")
        })
      },
      _c() {
        const r = T.engine.En.tl("/System/Library/Frameworks/JavaScriptCore.framework/JavaScriptCore");
        if (null === r) throw new Error("");
        return r
      },
      uc: () => T.engine.En.nl._c.kl("_jitCagePtr"),
      mc() {
        const r = T.engine.memory,
          n = T.engine.En.tl("/usr/lib/libxml2.2.dylib").kl("_xmlMalloc");
        return r.readU64(n)
      },
      dc: () => T.engine.En.nl._c.kl("__ZN3JSC10LinkBuffer8linkCodeERNS_14MacroAssemblerENS_20JITCompilationEffortE"),
      hc: () => T.engine.En.tl("/usr/lib/system/libsystem_platform.dylib").kl("__platform_memset"),
      wc: () => T.engine.En.tl("/usr/lib/system/libsystem_platform.dylib").kl("__platform_memmove"),
      bc: () => T.engine.En.tl("/usr/lib/system/libsystem_malloc.dylib").kl("_malloc"),
      yc: () => T.engine.En.tl("/usr/lib/system/libsystem_malloc.dylib").kl("_free"),
      xc: () => T.engine.En.nl._c.kl("__ZN3WTF10fastMallocEm")
    }
  }
}
return r;
