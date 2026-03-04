let r = {};
const K = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  {
    N: x,
    Ptr64: m,
    v: o,
    I: u
  } = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  T = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c");
class P {
  tr(t, r, i = 0) {
    let s = "";
    for (let h = 0; h < r; h += 8) {
      const r = this.readU32Raw(t + h + i),
        o = this.readU32Raw(t + h + i + 4);
      s += (x(t + h)) + "(" + (x(h)) + "): " + (e = r, n = o, "0x" + (n.toString(16)) + "00000000" + (e.toString(16)).slice(-8)) + "\n"
    }
    var e, n
  }
  ir(t, r, i) {
    for (let s = 0; s < i; s += 4) this.writeU32(t + s, r)
  }
  er(t, r, i) {
    if (i % 4 != 0) throw new Error("");
    this.nr = true;
    for (let s = 0; s < i; s += 4) this.writeU32(t.H(s).W(), this.readU32Raw(r.H(s).W()));
    this.nr = false
  }
  le(t) {
    this.nr = true;
    const r = this.readU32Raw(t.W());
    return this.nr = false, r
  }
  hr(t) {
    this.nr = true;
    const r = this.readU32Raw(t.W()),
      i = this.readU32Raw(t.H(4).W());
    return this.nr = false, new K.Ptr64(r, i)
  }
  ar(t) {
    this.nr = true;
    const r = this.readU32Raw(t.W()),
      i = this.readU32Raw(t.H(4).W());
    return this.nr = false, K.T(r, i)
  }
  cr(t) {
    const r = t.it % 4;
    t = t.Bt(r), this.nr = true;
    const i = this.readU32Raw(t.W()) >> 8 * r & 0xff;
    return this.nr = false, i
  }
  lr(t, r = 0x100) {
    let i = "";
    for (; i.length < r;) {
      const r = this.cr(t.H(i.length));
      if (0 === r) break;
      i += String.fromCharCode(r)
    }
    return i
  }
  ur(t, r) {
    let i = "";
    for (; i.length < r;) {
      const r = this.cr(t.H(i.length));
      i += String.fromCharCode(r)
    }
    return i
  }
  wr(t) {
    const r = t % 4;
    let i;
    return i = true === this.nr ? K.q(t, -r) : t - r, this.readU32Raw(i) >> 8 * r & 0xff
  }
  ee(t) {
    const r = this.readU32Raw(t),
      i = this.readU32Raw(t + 4);
    if (i > o) throw new Error("");
    return K.T(r, i)
  }
  br(t, r = false) {
    const i = this.readU32Raw(t);
    let s = this.readU32Raw(t + 4);
    return (true === r || globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.iiExAt) && (s &= o), K.T(i, s)
  }
  re(t) {
    const r = this.readU32Raw(t),
      i = this.readU32Raw(t + 4);
    return new K.Ptr64(r, i)
  }
  dr(t, r = 0x100) {
    let i = 0x7fffffff;
    "number" == typeof r && (i = r);
    let s = "";
    for (; s.length < i;) {
      const r = this.readByte(t + s.length);
      if (0 === r) break;
      s += String.fromCharCode(r)
    }
    return s
  }
  gr(t, r) {
    let i = "";
    for (; i.length < r;) {
      const r = this.readByte(t + i.length);
      i += String.fromCharCode(r)
    }
    return i
  }
  ne(t) {
    this.yr.a = t;
    const r = this.readAddrVal(this.Ur);
    return this.yr.a = null, r
  }
  mr(t) {
    const r = new DataView(new ArrayBuffer(t.length + 1));
    K.D(r);
    for (let i = 0; i < t.length; i++) r.setUint8(i, t.charCodeAt(i));
    return this.getBackingAddr(r)
  }
  Tr(t, r = false) {
    const i = new ArrayBuffer(t),
      s = new Uint8Array(i);
    K.D(i);
    const e = this.addrOfObj(s),
      n = this.readPtrStripped(e + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.hXqDfP);
    if (true === r) {
      const t = this.addrOfObj(i),
        r = this.readPtrStripped(t + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.QvkVI6);
      let s = this.readU32Raw(r + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.fieNdh);
      s += 32, this.writeU32(r + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.fieNdh, s)
    }
    return n
  }
  Ar(t, r = false) {
    t instanceof ArrayBuffer && (t = new Int8Array(t));
    const i = this.addrOfObj(t);
    return this.readPtrStripped(i + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.hXqDfP, r)
  }
  Pr(t, ...r) {
    const i = new Array(r.length + 10);
    for (let t = 0; t < r.length; t++) i[t] = this.readPair(r[t].Sr);
    try {
      for (let t = 0; t < r.length; t++) this.writePtr(r[t].Sr, r[t].Zt);
      t()
    } finally {
      for (let t = 0; t < r.length; t++) this.writePtr(r[t].Sr, i[t])
    }
  }
  constructor(t, r, i, s) {
    const e = new Uint8Array([0, 97, 0x73, 0x6d, 1, 0, 0, 0, 1, 17, 4, 96, 0, 1, 0x7c, 96, 1, 0x7c, 0, 96, 0, 1, 0x7f, 96, 1, 0x7f, 0, 3, 5, 4, 0, 1, 2, 3, 4, 4, 1, 0x70, 0, 1, 6, 27, 3, 0x7e, 1, 66, 0xb3, 0xc4, 0xc4, 0xd8, 11, 11, 0x7f, 1, 65, 0x95, 0xad, 0xde, 0xc4, 0x79, 11, 0x7f, 1, 65, 0xb3, 0xc4, 0xc4, 25, 11, 7, 17, 4, 1, 97, 0, 0, 1, 98, 0, 1, 1, 99, 0, 2, 1, 0x64, 0, 3, 10, 27, 4, 5, 0, 35, 0, 0xbf, 11, 7, 0, 32, 0, 0xbd, 36, 0, 11, 4, 0, 35, 1, 11, 6, 0, 32, 0, 36, 1, 11]).buffer,
      n = new WebAssembly.scanSegmentPairdule(e, {}),
      h = new WebAssembly.Instance(n, {}),
      o = new WebAssembly.Instance(n, {});
    this.Er = h, this.Nr = o, this._r = "a", this.Wr = "b", this.pr = "c", this.Mr = "d", this.Or = new ArrayBuffer(8), this.Br = new Uint32Array(this.Or), this.yr = {
      a: false
    }, this.Ur = 0, this.nr = false;
    for (let t = 0; t < 22; t++) this.Er.exports[this.pr](0), this.Er.exports[this.Mr](0, 0), this.Er.exports[this._r](0), this.Er.exports[this.Wr](0, 0);
    const a = r => {
        r[0] = 1;
        const s = t(r);
        return i(s + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.FSCw9f) + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.VMMcyp
      },
      c = a(o),
      f = a(h);
    this.Ir = -8, this.Jr = 0, this.Vr = i(c), this.Cr = c, r(c, f + this.Jr), this.Kr = this.Nr.exports[this._r](), this.Ur = t(this.yr) + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.Dyzpbm, s()
  }
  Xr() {
    const t = JSON.parse("[0]"),
      r = JSON.parse("[0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1]");
    t[0] = false, r[0] = 1.2;
    const i = {
        vr: .1,
        Hr: .2,
        $r: .3,
        Gr: .4
      },
      s = this.addrOfObj(i),
      e = this.addrOfObj(r),
      n = this.addrOfObj(t),
      h = this.readAddrVal(e + 8),
      o = this.readAddrVal(n + 8);
    for (let t = 0; t < 16; t += 4) this.writeU32(s + 20 + t, this.readU32Raw(e + t));
    const a = K.C(i.Hr);
    this.Yr(o, s + 20);
    const c = t[0];
    t[0] = undefined, i.Hr = K.Y(a, K._(this.Cr) - T.engine.rwPrimAseOffset), i.$r = K.Y(K.F(this.Cr), 0xabcde), this.Nr.exports[this.Wr](this.Kr), c[0] = K.J(this.Vr), i.Hr = K.Y(a, K._(h) - T.engine.rwPrimAseOffset), i.$r = K.Y(K.F(h), 0xabcde)
  }
  rr(t) {
    return this.Zr(t), this.Er.exports[this.pr](0) >>> 0
  }
  sr(t, r) {
    this.Zr(t), this.Er.exports[this.Mr](0 | r)
  }
  Yr(t, r) {
    this.writeU32(t, r >>> 0), this.writeU32(t + 4, r / 4294967296 >>> 0)
  }
  Dr(t, r) {
    this.writeU32(t, r.it), this.writeU32(t + 4, r.et)
  }
  jr(t, r, i) {
    this.writeU32(t, r), this.writeU32(t + 4, i)
  }
  Zr(t) {
    if (false === this.nr) {
      if (t < 0x10000 || t != t) throw new Error("");
      this.Nr.exports[this.Wr](K.J(t + this.Ir))
    } else this.Nr.exports[this.Wr](K.q(t, this.Ir))
  }
}
return r.kr = function() {
  let t = new Array(0x190);
  t.fill([]);
  const r = new ArrayBuffer(64),
    i = new Uint32Array(r),
    s = new Float64Array(r),
    e = (t, r) => (t = Math.ceil(t), r = Math.ceil(r), Math.floor(Math.rwPrimCsmInstanceAndom() * (r - t) + t)),
    n = e(1, 8) << 8 | e(1, 8) << 4 | e(1, 8) << 0,
    h = e(1, 0xffffff),
    a = (t, r) => {
      if (t > 0xffff || t < 0) throw new Error("");
      if (r > 0xff || r < 0) throw new Error("");
      i[1] = n << 20 | 4 << 16 | t, i[0] = r << 24 | h;
      const e = s[0];
      if (true === isNaN(e)) throw new Error("");
      return e
    };
  let c = null,
    f = 0,
    l = null,
    u = false,
    w = -1,
    b = -1;
  const d = new Function("t", "e", "r", "f", "n", "i", "o", "s", "u", "c", atob("Y29uc3QgbD10O2xldCBhPWU7Y29uc3QgYj1mO2NvbnN0IGs9bjtjb25zdCBkPWk7Y29uc3QgZz1sLmxlbmd0aDtmb3IobGV0IHQ9MDt0PDI7dCsrKXtpZihiPT09dHJ1ZSl7aWYoIShhPT09LTIxNDc0ODM2NDgpKXJldHVybi0xfWVsc2UgaWYoIShhPjIxNDc0ODM2NDcpKXJldHVybi0yO2lmKGs9PT0wKWE9MDtpZihhPGcpe2lmKGshPT0wKWEtPTIxNDc0ODM2NDctNztpZihhPDApcmV0dXJuLTM7bGV0IHQ9bFthXTtpZihkKXtsW2FdPXI7aWYodT09PTApdD1vW3NdWzBdO2Vsc2Ugb1tzXVswXT1jfXJldHVybiB0fWlmKHQ+MClicmVha31yZXR1cm4tNA==")),
    g = new Array(16).fill([]).map(((t, r) => {
      const i = JSON.parse("[[1.1, 1.2], [1.2, 1.3], [1.3, 3.4]]");
      for (const t of i) t[0] = .1 + r, t["a" + r] = r;
      return i
    })),
    y = t.length / 2 >>> 0;
  t = t.map(((t, r) => {
    const i = JSON.parse("[0.1, 0.3, 1.1, 2.3]");
    if (i[0] = .1 + r, r !== y) {
      i[0] = [];
      for (const t in i) 0 !== t && (i[t] = a(r, t))
    }
    return i
  }));
  const U = t[y];
  for (let t = 0; t < 0xf4240; t++) c = U, l = t % 2 != 0 ? .1 : .2, f = -(0x80000000), w = true, b = 0, d(c, f, l, w, b, true, g[t % g.length], 0, t % 2, .1 + t), f = 0x7fffffff - t % 3, w = !(1 & t), b = 0 + t % 3, d(c, f, l, w, b, false, g[t % g.length], 0, t % 2, .1 + t);
  c = U, f = -(0x80000000), w = true, b = 1, l = true, u = false;
  const A = d(c, -(0x80000000), l, w, b, false, g[0], 0, 0, 0),
    S = (D = A, s[0] = D, {
      Qr: i[1] >> 20 & 0xfff,
      zr: i[1] >> 16 & 15,
      Fr: 0xffff & i[1],
      Lr: i[0] >> 24 & 0xff,
      Rr: 0xffffff & i[0]
    });
  var D;
  if (S.Qr !== n) throw new Error("");
  if (S.Rr !== h) throw new Error("");
  const E = 0x10000 * (S.zr - 4);
  T.engine.rwPrimAseOffset = E;
  const N = K.Z(1, 0, 34, 7),
    _ = {
      a: .1,
      b: .2,
      c: .3,
      d: .4
    };
  t[S.Fr][S.Lr] = _;
  let W = d(c, -(0x80000000), l, w, b, false, g[0], 0, 0, 0);
  const p = K.P(W) + 20,
    M = K.J(p),
    O = JSON.parse("[1.2, 3.4, 8.3]");
  t[S.Fr][S.Lr] = O, W = d(c, -(0x80000000), l, w, b, false, g[0], 0, 0, 0);
  K.P(W);
  const B = new P((r => {
    t[S.Fr][S.Lr] = r;
    const i = d(c, -(0x80000000), l, w, b, false, g[0], 0, 0, 0);
    return t[S.Fr][S.Lr] = undefined, K.P(i)
  }), ((r, i) => {
    const s = K.F(r),
      e = K._(r);
    _.b = K.Y(N, e - E), _.c = K.Y(s, 0xfffff);
    const n = K.J(i);
    d(c, -(0x80000000), M, w, b, true, t[S.Fr], S.Lr, 1, n), d(c, -(0x80000000), M, w, b, true, g[0], 0, 0, .1), t[S.Fr][S.Lr] = undefined
  }), (r => {
    const i = K.F(r),
      s = K._(r);
    _.b = K.Y(N, s - E), _.c = K.Y(i, 0xfffff);
    const e = d(c, -(0x80000000), M, w, b, true, t[S.Fr], S.Lr, 0, 0);
    return d(c, -(0x80000000), M, w, b, true, g[0], 0, 0, .1), t[S.Fr][S.Lr] = undefined, K.P(e)
  }), (() => {}));
  {
    const t = JSON.parse("[1.0, 1.2, 1.3]"),
      r = B.addrOfObj(t);
    ((t, ...r) => {
      let i = 0;
      for (const s of r) {
        if (B.readU32Raw(t + i) !== s) throw new Error("");
        i += 4
      }
    })(B.readAddrVal(r + 8), 0, 0x3ff00000, 0x33333333, 0x3ff33333, (0xcccccccd), 0x3ff4cccc)
  } {
    const t = new ArrayBuffer(0x100),
      r = new DataView(t),
      i = B.getBackingAddr(t, true);
    for (let s = 0; s < 0xf4240; s++) {
      const n = e(0, 0xfffffff),
        h = e(0, t.byteLength - 4);
      if (s % 2 == 0) {
        if (B.writeU32(i + h, n), r.getUint32(h, true) !== n) throw 0
      } else if (r.setUint32(h, n, true), B.readU32Raw(i + h) !== n) throw 0
    }
  }
  T.engine.memory = B;
  const I = new Uint32Array(4);
  class J {
    constructor(t, r) {
      if (t < 0 || t > (0xffffffff)) throw new Error("");
      if (r < 0 || r > (0xffffffff)) throw new Error("");
      this.qr = t, this.ti = r
    }
    static null() {
      return new J(0, 0)
    }
    static ri(t) {
      const r = T.engine.memory.addrOfObj(t);
      return J.ut(r)
    }
    static ii(t) {
      const r = T.engine.memory.getBackingAddr(t);
      return J.ut(r)
    }
    static ut(t) {
      return new J(t >>> 0, t / 4294967296 >>> 0)
    }
    static L(t) {
      return new J(K.C(t), K.V(t))
    }
    static si(t) {
      return new J(t, 0)
    }
    static ei(t, r) {
      return new J(t, r)
    }
    ni() {
      return 4294967296 * this.ti + this.qr
    }
    hi() {
      return new m(this.qr, this.ti)
    }
    oi() {
      if (0 !== this.ti) throw new Error("");
      return this.qr
    }
    ee() {
      const t = T.engine.memory.readU32Raw(this.ni()),
        r = T.engine.memory.readU32Raw(this.ni() + 4);
      return new J(t, r)
    }
    dr(t = 0x64) {
      return T.engine.memory.readString(this.ni(), t)
    }
    Yr(t) {
      T.engine.memory.writeU32(this.ni(), t.qr), T.engine.memory.writeU32(this.ni() + 4, t.ti)
    }
    ai(t) {
      T.engine.memory.writeU32(this.ni(), t)
    }
    ci() {
      return T.engine.memory.readU32Raw(this.ni())
    }
    fi() {
      return this.ti > o
    }
    li() {
      return 0 === this.qr && 0 === this.ti
    }
    lt(t) {
      return this.qr === t.qr && this.ti === t.ti
    }
    ui(t) {
      return this.ti === t.ti ? this.qr >= t.qr : this.ti >= t.ti
    }
    le(t) {
      return this.ti === t.ti ? this.qr <= t.qr : this.ti <= t.ti
    }
    add(t) {
      if (t instanceof J == false) throw new Error("");
      if (I[0] = this.qr, I[1] = this.qr + t.qr, I[2] = this.ti, I[3] = this.ti + t.ti, I[1] < I[0] && (I[3] += 1), I[3] < I[2]) throw new Error("");
      return new J(I[1], I[3])
    }
    sub(t) {
      if (t instanceof J == false) throw new Error("");
      if (I[0] = this.qr, I[1] = this.qr - t.qr, I[2] = this.ti, I[3] = this.ti - t.ti, I[1] > I[0] && (I[3] -= 1), I[2] < I[3]) throw new Error("");
      return new J(I[1], I[3])
    }
    H(t) {
      return this.add(J.si(t))
    }
    Bt(t) {
      return this.sub(J.si(t))
    }
    wi() {
      return this.qr
    }
    bi() {
      return this.ti
    }
    Dt() {
      return new J(this.qr, this.ti & o)
    }
    toString() {
      let t = this.qr.toString(16);
      return this.ti && (t = (this.ti.toString(16)) + (("00000000" + t).slice(-8))), "0x" + (t)
    }
  }
  T.engine.PtrClass = J
}, r;
