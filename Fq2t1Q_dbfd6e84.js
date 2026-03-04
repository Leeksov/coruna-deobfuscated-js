let r = {};
const K = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  {
    N: x,
    Ptr64: m,
    v: o
  } = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  T = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c");
class E {
  constructor(t) {
    this.gi = t, this.yr = {
      a: false
    }, this.Ur = 0, this.nr = false
  }
  tr(t, i, n = 0) {
    let r = "";
    for (let s = 0; s < i; s += 8) {
      const i = this.readU32Raw(t + s + n),
        a = this.readU32Raw(t + s + n + 4);
      r += (x(t + s)) + "(" + (x(s)) + "): " + (e = i, o = a, "0x" + (o.toString(16)) + "00000000" + (e.toString(16)).slice(-8)) + "\n"
    }
    var e, o
  }
  ir(t, i, n) {
    for (let r = 0; r < n; r += 4) this.writeU32(t + r, i)
  }
  er(t, i, n) {
    if (n % 4 != 0) throw new Error("");
    this.nr = true;
    for (let r = 0; r < n; r += 4) this.writeU32(t.H(r).W(), this.readU32Raw(i.H(r).W()));
    this.nr = false
  }
  le(t) {
    this.nr = true;
    const i = this.readU32Raw(t.W());
    return this.nr = false, i
  }
  hr(t) {
    this.nr = true;
    const i = this.readU32Raw(t.W()),
      n = this.readU32Raw(t.H(4).W());
    return this.nr = false, new m(i, n)
  }
  ar(t) {
    this.nr = true;
    const i = this.readU32Raw(t.W()),
      n = this.readU32Raw(t.H(4).W());
    return this.nr = false, K.T(i, n)
  }
  cr(t) {
    const i = t.it % 4;
    t = t.Bt(i), this.nr = true;
    const n = this.readU32Raw(t.W()) >> 8 * i & 0xff;
    return this.nr = false, n
  }
  lr(t, i = 0x100) {
    let n = "";
    for (; n.length < i;) {
      const i = this.cr(t.H(n.length));
      if (0 === i) break;
      n += String.fromCharCode(i)
    }
    return n
  }
  ur(t, i) {
    let n = "";
    for (; n.length < i;) {
      const i = this.cr(t.H(n.length));
      n += String.fromCharCode(i)
    }
    return n
  }
  rr(t) {
    return -1
  }
  Dr(t, i) {}
  jr(t, i, n) {
    this.writeU32(t, i), this.writeU32(t + 4, n)
  }
  Yr(t, i) {}
  sr(t, i) {}
  wr(t) {
    const i = t % 4;
    let n;
    return n = true === this.nr ? K.q(t, -i) : t - i, this.readU32Raw(n) >> 8 * i & 0xff
  }
  ee(t) {
    const i = this.readU32Raw(t),
      n = this.readU32Raw(t + 4);
    if (n > o) throw new Error("");
    return K.T(i, n)
  }
  br(t, i = false) {
    const n = this.readU32Raw(t);
    let r = this.readU32Raw(t + 4);
    return (true === i || globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.iiExAt) && (r &= o), K.T(n, r)
  }
  re(t) {
    const i = this.readU32Raw(t),
      n = this.readU32Raw(t + 4);
    return new m(i, n)
  }
  dr(t, i = 0x100) {
    let n = 0x7fffffff;
    "number" == typeof i && (n = i);
    let r = "";
    for (; r.length < n;) {
      const i = this.readByte(t + r.length);
      if (0 === i) break;
      r += String.fromCharCode(i)
    }
    return r
  }
  gr(t, i) {
    let n = "";
    for (; n.length < i;) {
      const i = this.readByte(t + n.length);
      n += String.fromCharCode(i)
    }
    return n
  }
  ne(t) {
    this.yr.a = t;
    const i = this.readAddrVal(this.Ur);
    return this.yr.a = null, i
  }
  Xr() {}
  mr(t) {
    const i = new DataView(new ArrayBuffer(t.length + 1));
    K.D(i);
    for (let n = 0; n < t.length; n++) i.setUint8(n, t.charCodeAt(n));
    return this.getBackingAddr(i)
  }
  Tr(t, i = false) {
    const n = new ArrayBuffer(t),
      r = new Uint8Array(n);
    K.D(n);
    const e = this.addrOfObj(r),
      o = this.readPtrStripped(e + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.hXqDfP);
    if (true === i) {
      const t = this.addrOfObj(n),
        i = this.readPtrStripped(t + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.QvkVI6);
      let r = this.readU32Raw(i + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.fieNdh);
      r += 32, this.writeU32(i + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.fieNdh, r)
    }
    return o
  }
  Ar(t, i = false) {
    t instanceof ArrayBuffer && (t = new Int8Array(t));
    const n = this.addrOfObj(t);
    return this.readPtrStripped(n + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.hXqDfP, i)
  }
  Pr(t, ...i) {
    const n = new Array(i.length + 10);
    for (let t = 0; t < i.length; t++) n[t] = this.readPair(i[t].Sr);
    try {
      for (let t = 0; t < i.length; t++) this.writePtr(i[t].Sr, i[t].Zt);
      t()
    } finally {
      for (let t = 0; t < i.length; t++) this.writePtr(i[t].Sr, n[t])
    }
  }
}
class k extends E {
  constructor(t, i) {
    super(t), this.di = i, this.Ur = K.K(this.di.addrOfJS(this.yr)) + globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.Dyzpbm
  }
  Bi(t) {
    returntrue === this.nr ? K.X(t) : K.O(t)
  }
  rr(t) {
    return this.di.readU32Raw(this.Bi(t))
  }
  sr(t, i) {
    this.di.writeU32(this.Bi(t), i)
  }
  Yr(t, i) {
    this.di.writeU32(this.Bi(t), i >>> 0), this.di.writeU32(this.Bi(t) + BigInt(4), i / 4294967296 >>> 0)
  }
  Dr(t, i) {
    this.di.writeU32(this.Bi(t), i.it), this.di.writeU32(this.Bi(t) + BigInt(4), i.et)
  }
  jr(t, i, n) {
    this.di.writeU32(this.Bi(t), i), this.di.writeU32(this.Bi(t) + BigInt(4), n)
  }
}
class F {
  constructor() {
    this.rn = new ArrayBuffer(16), this.en = new DataView(this.rn)
  }
  un(t) {
    return this.en.setInt16(0, t, true), this.en.getInt16(0, true)
  }
  on(t) {
    return this.en.setUint16(0, t, true), this.en.getUint16(0, true)
  }
  sn(t) {
    return this.en.setUint32(0, t, true), this.en.getUint32(0, true)
  }
  hn(t, i) {
    return this.en.setFloat64(0, t, true), this.en.setUint32(0, i, true), this.en.getFloat64(0, true)
  }
  cn(t, i) {
    return this.en.setFloat64(0, t, true), this.en.setUint32(4, i, true), this.en.getFloat64(0, true)
  }
  fn(t) {
    for (let i = 0; i < 4; i++) {
      const n = t.charCodeAt(i);
      if (Number.isNaN(n)) throw new Error("");
      this.en.setUint16(2 * i, n, true)
    }
    return this.en.getBigUint64(0, true)
  }
  an(t) {
    return this.en.setFloat32(0, t, true), this.en.getUint32(0, true)
  }
  wn(t) {
    return this.en.setBigUint64(0, t, true), this.en.getFloat64(0, true)
  }
  gn(t, i) {
    return this.en.setBigUint64(0, t, true), this.en.setUint8(0, Number(i)), this.en.getBigUint64(0, true)
  }
  ln(t, i) {
    return this.en.setBigUint64(0, t, true), this.en.setUint32(0, Number(i), true), this.en.getBigUint64(0, true)
  }
  bn(t, i) {
    return this.en.setUint32(0, t, true), this.en.setUint8(0, Number(i)), this.en.getUint32(0, true)
  }
  Un(t, i) {
    return this.en.setUint32(0, t, true), this.en.setUint32(0, Number(i), true), this.en.getUint32(0, true)
  }
  mn(t, i) {
    return this.en.setBigUint64(0, t, true), this.en.setUint32(0, Number(i), true), this.en.getBigUint64(0, true)
  }
  Ii(t) {
    return this.en.setBigInt64(0, t, true), this.en.getBigUint64(0, true)
  }
}
class z {
  constructor(t, i, n, r, e, o, s, a) {
    this._i = t, this.mi = i, this.yi = n, this.Ui = r, this.Ei = e, this.ki = o, this.vi = s, this.Fi = a, this.converter = new F
  }
  Si(t) {
    this.Ui.rwPrimAseVal = Number(t >> BigInt(32)), this.mi.rwPrimAseVal = Number(t - BigInt(28) & BigInt("0xFFFFFFFF"))
  }
  Ai(t) {
    this.converter.en.setUint32(0, Number(t), true), this.ki.rwPrimAseVal = this.converter.en.getUint32(0, true)
  }
  Ti() {
    return this.converter.en.setUint32(0, this.ki.rwPrimAseVal, true), this.converter.en.getUint32(0, true)
  }
  sr(t, i) {
    this.Si(t), this.Ai(i)
  }
  zi(t, i) {
    this.Si(t), this.Ai(i & BigInt("0xFFFFFFFF")), this.Si(t + BigInt(4)), this.Ai(i >> BigInt(32))
  }
  dr(t, i = 0x300) {
    let n = "";
    for (let r = 0; r < i; r++) {
      const i = this.readByte(t + BigInt(r));
      if (0 === i) break;
      n += String.fromCharCode(i)
    }
    return n
  }
  rr(t) {
    return this.Si(t), this.Ti()
  }
  pi(t) {
    return 0xffff & this.readU32Raw(t)
  }
  wr(t) {
    return 0xff & this.readU32Raw(t)
  }
  Ci(t) {
    const i = this.readU32Raw(t),
      n = this.readU32Raw(t + BigInt(4));
    return BigInt(n) << BigInt(32) | BigInt(i)
  }
  tA(t) {
    this.Fi[0] = t;
    const i = this.readU64(this.vi + BigInt(8)),
      n = this.readU64(i);
    return this.Fi[0] = null, n
  }
}
return r.kr = async function(t) {
  const i = BigInt("0x7FFFFFFFFF");

  function n(t) {
    return t & i
  }
  try {
    const i = await async function() {
      const i = {
          xi: null,
          Pi: null
        },
        r = new OfflineAudioContext(2, 0xac44, 0xac44),
        e = r.decodeAudioData.bind(r),
        o = [];
      r.decodeAudioData = async t => {
        const i = await e(t);
        return o.push(i), null
      };
      const s = 0x1b58;

      function a() {
        let t = 0;
        for (let i = 0; i < s; i++) try {
          new Intl.NumberFormat("dowocjfjq[", {})
        } catch (i) {
          t += 1
        }
        if (t !== s) throw new Error("")
      }

      function c() {
        for (let t = 0; t < 0xf0; t++) new ArrayBuffer(0x400000)
      }
      async function h(t, i) {
        const n = T(v, new C),
          e = x(new ArrayBuffer(0x4000), 0xb40, 0x11c0),
          o = [],
          h = [],
          l = [];
        for (let n = 0; n < s; n++) t[i + n] = new Intl.NumberFormat("en-US", {}), o[n] = [new Intl.NumberFormat("en-US", {}), new Intl.NumberFormat("en-US", {}), new Intl.NumberFormat("en-US", {})], h.push([new Intl.NumberFormat("en-US", {}), new Intl.NumberFormat("en-US", {})]);
        h.length = 0, c(), a();
        for (let n = 0; n < s; n++) t[i + n].format(1), t[i + n].format(2), t[i + n].format(3);
        o.length = 0, c(), a();
        for (let t = 0; t < 20; t++) {
          await r.decodeAudioData(e), await r.decodeAudioData(e);
          try {
            await r.decodeAudioData(n)
          } catch (t) {}
        }
        for (let n = i; n < t.length; n++) {
          const i = t[n];
          if (null === i) continue;
          const r = i.format(1.02);
          if (4 !== r.length) {
            for (let t = 0; t < r.length; t++);
            let n = BigInt(r.charCodeAt(19));
            return n = n << BigInt(16) | BigInt(r.charCodeAt(18)), n = n << BigInt(16) | BigInt(r.charCodeAt(17)), n -= BigInt(0x138), {
              Mi: [...t, ...o, ...h, ...l],
              Oi: i,
              Wi: n
            }
          }
        }
        throw new Error("")
      }
      const l = 0xc010,
        f = 1,
        w = 2,
        u = 3,
        g = 5,
        d = 6,
        B = 10,
        b = 0x57907536,
        I = BigInt(0x388),
        _ = BigInt(0x3c8),
        m = BigInt(8),
        y = BigInt(12),
        U = BigInt(10),
        E = BigInt(24),
        v = new ArrayBuffer(0x4000),
        N = new F;
      class S {
        Di(t) {
          if (t !== this.tempBuf.length) throw new Error("")
        }
        $i(t) {
          if (0 === t.length) return 0;
          if (this.Hi + t.length >= this.tempBuf.length && (this.Di(this.Hi + t.length + 1), this.Hi + t.length >= this.tempBuf.length)) throw new Error("");
          return this.tempBuf.set(t, this.Hi), this.Hi += t.length, t.length
        }
        ji(t) {
          if (this.Hi < 0) throw new Error("");
          if (this.Hi > this.tempBuf.length) throw new Error("");
          this.Hi = t
        }
        Ki() {
          this.Hi = 0
        }
        Ji() {
          return this.tempBuf.length
        }
        Li() {
          return this.Hi
        }
        Ri() {
          return this.tempBuf.subarray()
        }
        constructor(t) {
          this.tempBuf = new Uint8Array(t), this.Hi = 0, this.Xi = new ArrayBuffer(32), this.qi = new Uint8Array(this.Xi), this.Gi = new DataView(this.Xi)
        }
        Qi(t) {
          this.Gi.setUint32(0, t, false), this.$i(this.qi.subarray(0, 4))
        }
        Yi(t) {
          this.Gi.setUint16(0, t, false), this.$i(this.qi.subarray(0, 2))
        }
        Zi(t, i) {
          const n = new Uint8Array(i);
          n.fill(t), this.$i(n)
        }
        se(t) {
          this.$i(new Uint8Array([t]))
        }
        he(t) {
          let i = 0;
          for (; i < t.length;) {
            const n = t.charCodeAt(i);
            if (0 != (0xff00 & n)) throw new Error("");
            this.se(n), i++
          }
        }
        fe(t) {
          this.ji(t)
        }
        we() {
          this.Ki()
        }
        ge() {
          return this.Ji()
        }
        de() {
          return this.Li()
        }
        Be() {
          return this.Ri()
        }
      }
      class A {
        be(t) {}
        Ie(t) {}
      }

      function T(t, i) {
        const n = new S(t),
          r = [{
            tag: f,
            _e: undefined,
            me: undefined
          }, {
            tag: u,
            _e: undefined,
            me: undefined
          }, {
            tag: g,
            _e: undefined,
            me: undefined
          }, {
            tag: d,
            _e: undefined,
            me: undefined
          }, {
            tag: B,
            _e: undefined,
            me: undefined
          }],
          e = 16 + 12 * r.length;
        n.fe(e);
        for (const t of r) {
          const r = n.de();
          switch (t._e = r, t.tag) {
            case f: {
              const t = {
                ye: 0,
                Ue: 0,
                Ee: b,
                ke: 0,
                ve: 0,
                Fe: 0,
                Ne: 0
              };
              n.Yi(t.ye), n.Yi(t.Ue), n.Qi(t.Ee), n.Qi(t.ke), n.Qi(t.ve), n.Qi(t.Fe), n.Qi(t.Ne);
              break
            }
            case u:
              n.Yi(0), n.Zi("\0", 16), n.Zi("\0", 40), n.Qi(0), n.Qi(0), n.Qi(0), n.Qi(0);
              break;
            case g:
              n.Qi(0);
              break;
            case d:
              i.be(n);
              break;
            case B:
              i.Ie(n)
          }
          t.me = n.de() - r
        }
        const o = n.de();
        n.fe(0), n.Qi(o), n.Qi(b), n.Qi(r.length), n.Qi(0);
        for (const t of r) n.Qi(t.tag), n.Qi(t._e), n.Qi(t.me);
        return n.Be().buffer.slice(0, o)
      }
      class p extends A {
        constructor(t, i) {
          super(), this.Se = t, this.Ae = i
        }
        be(t) {
          const i = [],
            n = 0x3228;
          if (this.Se < BigInt(4294967296)) throw new Error("");
          let r = Number((this.Se >> BigInt(32)).toString());
          N.on(r) % 2 == 0 && (r += 1);
          let e = N.un(-0x3400);
          e -= 16 * r;
          let o = N.un(24 * r + 72);
          if (N.on(o) % 16 != 0) throw new Error("");
          o += 16, e += o;
          const s = Math.floor(e / 16),
            a = N.un(8 * s);
          let c = this.Se - BigInt(a.toString());
          c -= BigInt(N.on(8 * r).toString());
          const h = (t, i) => t <= i ? t : i,
            f = (t, i) => Number(BigInt.asUintN(t, i).toString()),
            w = h(BigInt((0xffffffff)), c);
          i.push({
            Te: 0,
            ze: f(32, w),
            pe: l
          }), c -= w;
          let u = r;
          for (; u > 0;)
            if (u -= 1, c !== BigInt(0)) {
              const t = h(BigInt((0xffffffff)), c);
              i.push({
                Te: 1,
                ze: f(32, t),
                pe: l
              }), c -= t
            } else i.push({
              Te: 1,
              ze: 0,
              pe: l
            });
          i.push({
            Te: N.on(s),
            ze: 0,
            pe: l
          }), i.push({
            Te: 1,
            ze: 0,
            pe: l
          }), i.push({
            Te: 12,
            ze: 0,
            pe: l
          });
          let g = 0;
          for (const t of i) g += N.un(t.Te);
          let d = 0;
          if (g < 0) d += -1 * g, d += 0x321;
          else {
            if (d > 0x321) throw new Error("");
            d += 0x321 - d
          }
          if (i.push({
              Te: d,
              ze: 0,
              pe: l
            }), 24 * i.length > n) throw new Error("");
          for (; 24 * i.length !== n;) i.push({
            Te: 0,
            ze: 0,
            pe: l
          });
          t.Qi(i.length);
          for (const n of i) t.Qi(n.Te), t.Qi(0), t.Qi(0), t.Qi(n.ze), t.Qi(0), t.Yi(n.pe), t.Qi(0)
        }
        Ie(t) {
          t.Qi(this.Ae[1]), t.Qi(this.Ae[0])
        }
      }
      class C extends A {
        constructor() {
          super()
        }
        be(t) {
          const i = [];
          let n = -0x1200;
          n += 0x780, n = Math.floor(n / 16), i.push({
            Te: 0,
            ze: 0,
            pe: l
          }), i.push({
            Te: 0,
            ze: 0,
            pe: l
          }), i.push({
            Te: N.on(n),
            ze: 0,
            pe: l
          }), i.push({
            Te: 1,
            ze: (0xffffffff),
            pe: 0
          });
          const r = Math.floor(-0x68);
          i.push({
            Te: N.on(r),
            ze: 0xf333,
            pe: 0
          }), i.push({
            Te: 2,
            ze: 0xf333,
            pe: 0
          }), i.push({
            Te: 2,
            ze: 0xf333,
            pe: 0
          });
          let e = 0;
          for (const t of i) e += N.un(t.Te);
          const o = Math.floor(0x11c);
          let s = 0;
          if (e < 0) s += -1 * e, s += o;
          else {
            if (s > o) throw new Error("");
            s += o - s
          }
          for (i.push({
              Te: s,
              ze: 0,
              pe: 0
            }); 24 * i.length != 0xd8;) i.push({
            Te: 0,
            ze: 0,
            pe: 0
          });
          t.Qi(i.length);
          for (const n of i) t.Qi(n.Te), t.Qi(0), t.Qi(0), t.Qi(n.ze), t.Qi(0), t.Yi(n.pe), t.Qi(0)
        }
        Ie(t) {
          t.Qi(0x342), t.Qi(0x342), t.Qi(0xf333), t.Qi(0xf444)
        }
      }

      function x(t, i, n) {
        const r = new S(t);
        if (i % 24 != 0) throw new Error("");
        if (n % 16 != 0) throw new Error("");
        const e = i / 24,
          o = n / 16;
        if (e >= o) throw new Error("");
        if (o >= 0x7fff) throw new Error("");
        const s = [];
        for (let t = 0; t < e - 1; t++) s.push({
          Te: 1
        });
        s.push({
          Te: o - e
        });
        for (const t of s) t.ze = 0, t.Ce = 1, t.pe = l;
        s[0].ze = 19;
        const a = [{
            tag: f,
            _e: undefined,
            me: undefined
          }, {
            tag: w,
            _e: undefined,
            me: undefined
          }, {
            tag: u,
            _e: undefined,
            me: undefined
          }, {
            tag: g,
            _e: undefined,
            me: undefined
          }, {
            tag: d,
            _e: undefined,
            me: undefined
          }, {
            tag: B,
            _e: undefined,
            me: undefined
          }],
          c = 16 + 12 * a.length;
        r.fe(c);
        for (const t of a) {
          const i = r.de();
          switch (t._e = i, t.tag) {
            case f: {
              const t = {
                ye: 0,
                Ue: 0,
                Ee: b,
                ke: 0,
                ve: 0,
                Fe: 0,
                Ne: 0
              };
              r.Yi(t.ye), r.Yi(t.Ue), r.Qi(t.Ee), r.Qi(t.ke), r.Qi(t.ve), r.Qi(t.Fe), r.Qi(t.Ne);
              break
            }
            case w: {
              const t = [["HeaderSeed", "0"], ["EncryptedBlocks", "0"], ["HeaderKey", "0 0 0 0"], ["CPUType", "0"]];
              r.Qi(t.length);
              for (const [i, n] of t) r.se(0), r.Qi(i.length), r.Qi(n.length), r.he(i), r.he(n);
              break
            }
            case u:
              r.Yi(0), r.Zi("\0", 16), r.Zi("\0", 40), r.Qi(19), r.Qi(0), r.Qi(0), r.Qi(0);
              break;
            case g:
              r.Qi(0);
              break;
            case d: {
              const t = -1;
              r.Qi(s.length);
              for (const i of s) r.Qi(i.Te), r.Qi(t), r.Qi(t), r.Qi(i.ze), r.Qi(i.Ce), r.Yi(i.pe), r.Qi(0);
              break
            }
            case B: {
              r.Qi(19);
              const t = r.de() + 4;
              r.Qi(t), r.Zi("\0", 19);
              let i = r.de() + 8;
              for (let t = 0; t < o; t++) r.Qi(0), r.Qi(i), i += 8;
              break
            }
          }
          t.me = r.de() - i
        }
        const h = r.de();
        r.fe(0), r.Qi(h), r.Qi(b), r.Qi(a.length), r.Qi(0);
        for (const t of a) r.Qi(t.tag), r.Qi(t._e), r.Qi(t.me);
        return r.Be().buffer.slice(0, h)
      }
      return await async function() {
        const e = [];
        let s = 0,
          a = 0,
          c = null;
        for (a = 0; a < 12; a++) try {
          c = await h(e, s);
          break
        } catch (t) {
          s = e.length
        }
        if (null === c) throw new Error("");
        const l = await async function(e) {
          const o = new ArrayBuffer(0x4000),
            s = new ArrayBuffer(0x4000),
            a = x(o, 0xb40, 0x2400);
          class c {
            async init() {
              const t = e.Wi + I,
                i = t + m,
                o = t + E,
                c = e.Wi + _,
                h = async (t, i) => {
                  {
                    const n = T(s, new p(t, [i, 0]));
                    let o = 0;
                    const c = e.Oi.format(1 / 0);
                    do {
                      if (o += 1, o > 20) throw Error(0);
                      for (let t = 0; t < 12; t++) await r.decodeAudioData(a);
                      try {
                        await r.decodeAudioData(n)
                      } catch (t) {}
                    } while (c === e.Oi.format(1 / 0))
                  }
                };
              await h(i, 0x302), await h(o, Number(c & BigInt("0xFFFFFFFF"))), await h(o + BigInt(4), Number(c >> BigInt(32)));
              {
                const t = e.Oi.format(1 / 0),
                  i = (E - U) / BigInt(2);
                let n = BigInt(0);
                for (let r = 3; r >= 0; r--) n = n << BigInt(16) | BigInt(t.charCodeAt(Number(i) + r))
              }
              await h(i, 0x408);
              const l = e.Oi.format(1 / 0);
              this.xe = n(this.Pe(l, 0))
            }
            constructor() {
              this.Me = false, this.Oe = null, this.We = null, this.De = null, this.xe = null, this.Ve = new Uint16Array(new ArrayBuffer(32)), this.$e = new DataView(this.Ve.buffer)
            }
            tr(t = 0x300) {
              for (let i = 0; i < Math.min(t, Number(this.We)); i += 8);
            }
            He(t, i) {
              if (i = BigInt(i), null === this.Oe) throw new Error("");
              if (null === this.We) throw new Error("");
              if (null === this.De) throw new Error("");
              const n = t + i;
              if (n < this.Oe) throw new Error("");
              if (n >= this.Oe + this.We) throw new Error("")
            }
            je() {
              this.De = e.Oi.format(NaN)
            }
            rr(t) {
              if ((t = Number(t)) % 2 != 0) throw new Error("");
              this.He(this.Oe, t), t /= 2;
              for (let i = 0; i < 2; i++) {
                const n = this.De.charCodeAt(t + i);
                if (Number.isNaN(n)) throw new Error("");
                this.Ve[i] = n
              }
              return this.$e.getUint32(0, true)
            }
            dr(t = 0, i = 0x3e8) {
              t = Number(t), this.He(this.Oe, t);
              let n = "",
                r = 0,
                e = t % 2 != 0;
              for (;;) {
                const o = this.De.charCodeAt(Math.floor((t + r) / 2)),
                  s = 0xff & o,
                  a = o >>> 8;
                if (false === e) {
                  if (0 === s) break;
                  if (n += String.fromCharCode(s), r += 1, r >= i) break
                }
                if (e = false, 0 === a) break;
                if (n += String.fromCharCode(a), r += 1, r >= i) break
              }
              return n
            }
            Ci(t) {
              if ((t = Number(t)) % 2 != 0) throw new Error("");
              this.He(this.Oe, t), t /= 2;
              for (let i = 0; i < 4; i++) {
                const n = this.De.charCodeAt(t + i);
                if (Number.isNaN(n)) throw new Error("");
                this.Ve[i] = n
              }
              return this.$e.getBigUint64(0, true)
            }
            Pe(t, i) {
              if ((i = Number(i)) % 2 != 0) throw new Error("");
              i /= 2;
              for (let n = 0; n < 4; n++) {
                const r = t.charCodeAt(i + n);
                if (Number.isNaN(r)) throw new Error("");
                this.Ve[n] = r
              }
              return this.$e.getBigUint64(0, true)
            }
            async Ke(t, i = null) {
              const n = e.Wi + _,
                o = n + m,
                c = n + y,
                h = n + E;
              let l = 0,
                f = null,
                w = null,
                u = null;
              if (false === this.Me || null !== i) {
                let t = 0x200;
                if (null !== i && (t = Number(i)), BigInt(t) !== this.We) {
                  this.We = BigInt(t);
                  const i = t > 0x200;
                  let n = 8 | t << 5;
                  true === i && (n = 0xe008), u = T(s, new p(o, [n, 0])), l = 0, f = e.Oi.format(1 / 0);
                  do {
                    if (l += 1, l > 20) throw Error(0);
                    for (let t = 0; t < 12; t++) await r.decodeAudioData(a);
                    try {
                      await r.decodeAudioData(u)
                    } catch (t) {}
                  } while (f === e.Oi.format(1 / 0));
                  if (w = this.Pe(e.Oi.format(1 / 0), Number(m)), w !== BigInt(n)) throw new Error("");
                  if (true === i) {
                    u = T(s, new p(c, [t, 0])), l = 0, f = e.Oi.format(1 / 0);
                    do {
                      if (l += 1, l > 20) throw Error(0);
                      for (let t = 0; t < 12; t++) await r.decodeAudioData(a);
                      try {
                        await r.decodeAudioData(u)
                      } catch (t) {}
                    } while (f === e.Oi.format(1 / 0));
                    if (w = this.Pe(e.Oi.format(1 / 0), Number(y)), w !== BigInt(t)) throw new Error("")
                  }
                }
              }
              u = T(s, new p(h, [Number(t & BigInt("0xFFFFFFFF")), 0])), l = 0, f = e.Oi.format(1 / 0);
              do {
                if (l += 1, l > 40) throw Error(0);
                for (let t = 0; t < 12; t++) await r.decodeAudioData(a);
                try {
                  await r.decodeAudioData(u)
                } catch (t) {}
              } while (f === e.Oi.format(1 / 0));
              u = T(s, new p(h + BigInt(4), [Number(t >> BigInt(32)), 0])), l = 0, f = e.Oi.format(1 / 0);
              do {
                if (l += 1, l > 40) throw Error(0);
                for (let t = 0; t < 12; t++) await r.decodeAudioData(a);
                try {
                  await r.decodeAudioData(u)
                } catch (t) {}
              } while (f === e.Oi.format(1 / 0));
              if (w = this.Pe(e.Oi.format(1 / 0), Number(E)), w !== t) throw new Error("");
              this.Oe = t, this.De = e.Oi.format(NaN), this.Me = true
            }
          }
          const h = new c;
          await h.init();
          const l = h.xe;
          await h.Ke(l), n(h.readU64(0));
          const f = n(h.readU64(0));
          let w = f - f % BigInt(0xa0000);
          const u = BigInt(0xa0000);
          await h.Ke(w, u);
          let g = null;
          for (; null === g;) {
            for (let t = BigInt(0); t < u; t += BigInt(0x1000))(0xfeedfacf) === h.readU32Raw(t) && (g = w + t);
            null === g && (w -= u, await h.Ke(w))
          }
          const d = 4,
            B = 40,
            b = 8,
            v = 24,
            F = 32;
          await h.Ke(g, BigInt(0x4000));
          let N = null,
            S = null;
          const A = h.readU32Raw(16);
          (() => {
            let t = F;
            for (let i = 0; i < A; i++) {
              const i = h.readU32Raw(t),
                n = h.readU32Raw(t + d);
              if (25 === i && "__TEXT" === h.readString(t + b)) {
                const i = h.readU64(t + v),
                  n = h.readU64(t + B);
                return N = g - i, void(S = g - n)
              }
              t += n
            }
            throw new Error("")
          })(), await h.Ke(S, BigInt(0x1000));
          const C = h.readU32Raw(0x1c0),
            P = h.readU32Raw(0x1c4),
            M = S + BigInt(C);
          await h.Ke(M, BigInt(32 * P));
          const O = [];
          let W = 0xfffffff,
            D = 0;
          for (let t = 0; t < P; t++) {
            const i = 32 * t,
              n = h.readU32Raw(i + 24);
            W = Math.min(n, W), D = Math.max(n, D), O.push({
              Je: h.readU64(i) + N,
              Le: n
            })
          }
          await h.Ke(S + BigInt(W), BigInt(D - W) + BigInt(0x12c));
          const V = (() => {
              for (const {
                  Je: t,
                  Le: i
                }
                of O)
                if ("/usr/lib/system/libsystem_pthread.dylib" === h.readString(i - W)) return t;
              throw new Error("")
            })(),
            $ = async t => {
              let i = false,
                n = null,
                r = null,
                e = null,
                o = null;
              const s = {};
              let a = null;
              await h.Ke(t, BigInt(0x1000));
              const c = h.readU32Raw(16);
              let l = F;
              for (let e = 0; e < c; e++) {
                const e = h.readU32Raw(l),
                  c = h.readU32Raw(l + d);
                switch (e) {
                  case 25: {
                    const i = {
                      Re: h.readString(l + b, 16),
                      Xe: h.readU64(l + v),
                      qe: null,
                      Ge: h.readU64(l + B)
                    };
                    switch (i.segName) {
                      case "__TEXT":
                        o = t - i.vmAddr;
                        break;
                      case "__LINKEDIT":
                        a = i.vmAddr + o - i.fileOff
                    }
                    if (undefined !== s[i.segName]) throw new Error("");
                    s[i.segName] = i;
                    break
                  }
                  case (0x80000022):
                    i = true, n = h.readU32Raw(l + 40), r = h.readU32Raw(l + 44);
                    break;
                  case (0x80000033):
                    i = true, n = h.readU32Raw(l + 8), r = h.readU32Raw(l + 12)
                }
                l += c
              }
              for (const t of Object.keys(s)) {
                const i = s[t];
                i.qe = i.vmAddr + o
              }
              if (false === i) throw new Error("");
              e = a + BigInt(n);
              const f = new ArrayBuffer(r);
              await h.Ke(e, r);
              const w = new Uint32Array(f);
              for (let t = 0; t < w.length; t++) w[t] = h.readU32Raw(4 * t);
              const u = new Uint8Array(f),
                g = t => {
                  const i = u;
                  let n = "",
                    r = 0,
                    e = false;
                  for (; !e;) {
                    e = true;
                    let o = 0,
                      s = 0;
                    do {
                      o += (0x7f & i[r]) << s, s += 7
                    } while (0x80 & i[r++]);
                    if (n === t && 0 !== o) {
                      r++;
                      let t = 0;
                      s = 0;
                      do {
                        t += (0x7f & i[r]) << s, s += 7
                      } while (0x80 & i[r++]);
                      return t
                    }
                    r += o;
                    const a = i[r++];
                    for (let o = 0; o < a; o++) {
                      let o = "";
                      for (; 0 !== i[r];) o += String.fromCharCode(i[r++]);
                      r++;
                      let a = 0;
                      s = 0;
                      do {
                        a += (0x7f & i[r]) << s, s += 7
                      } while (0x80 & i[r++]);
                      if (o.length && n + o === t.substr(0, n.length + o.length)) {
                        n += o, r = a, e = false;
                        break
                      }
                    }
                  }
                  return null
                },
                I = i => {
                  const n = g("_" + (i));
                  if (null === n) throw new Error("");
                  return t + BigInt(n)
                };
              return {
                Qe: g,
                Ye: I
              }
            }, H = (await $(V)).Ye("pthread_main_thread_np"), j = BigInt(64);
          await h.Ke(H, j);
          const K = new Uint32Array(Number(j) / 4);
          for (let t = 0; t < K.length; t += 1) K[t] = h.readU32Raw(4 * t);
          let J = null,
            L = null;
          for (const t in K) {
            const i = K[t];
            if (-0x70000000 == ((0x9f000000) & i)) {
              const t = (0xffffe0 & i) >> 5 << 14 | (0x60000000 & i) >> 29 << 12;
              J = H - H % BigInt(0x1000) + BigInt(t)
            } else if (-0x6c00000 == ((0xffc00000) & i)) {
              L = J + BigInt(8 * (i >> 10 & 0xfff));
              break
            }
          }
          if (null === L) throw new Error("");
          await h.Ke(L, BigInt(0x100));
          const R = h.readU64(0),
            X = BigInt(0xb0),
            q = BigInt(0xb8),
            G = BigInt(16),
            Q = [];
          let Y = R;
          do {
            await h.Ke(Y);
            const t = h.readU64(X);
            t - h.readU64(q) >= BigInt(0xa000) && Q.push({
              Ze: Y,
              io: t
            }), Y = h.readU64(G)
          } while (Y !== BigInt(0));
          const Z = async t => {
            const i = [0x55432, 0x66533, t, 0x22334, 0x99234];
            let n = null;
            const r = (t, ...e) => {
              try {
                r(t + 1, ...i, ...e)
              } catch (t) {
                h.je();
                for (let t = 0; t < 0x1000; t += 8)
                  if (h.readU64(t) === BigInt("0xfffe000000055432") && h.readU64(t + 8) === BigInt("0xfffe000000066533") && h.readU64(t + 24) === BigInt("0xfffe000000022334") && h.readU64(t + 32) === BigInt("0xfffe000000099234")) return void(n = h.readU64(t + 16))
              }
            };
            for (const t in Q) {
              const e = Q[t].io - BigInt(0x4000);
              if (await h.Ke(e, BigInt(0x1000)), r(0, ...i), null !== n) break
            }
            if (null === n) throw new Error("");
            return n
          }, tt = new Array(0xc8);
          tt.fill(null);
          const it = await Z(tt);
          await h.Ke(it, BigInt(96));
          const nt = h.readU64(8);
          await h.Ke(nt), tt.fill(0x7b);
          const rt = async (t, i) => {
            const n = Number((i >> BigInt(32)).toString()),
              e = Number((i & BigInt((0xffffffff))).toString()),
              o = T(s, new p(t, [e, 0]));
            for (let t = 0; t < 12; t++) r.decodeAudioData(a);
            try {
              await r.decodeAudioData(o)
            } catch (t) {}
            const c = T(s, new p(t + BigInt(4), [n, 0]));
            for (let t = 0; t < 12; t++) r.decodeAudioData(a);
            try {
              await r.decodeAudioData(c)
            } catch (t) {}
          }, et = [document.createElementNS("http://www.w3.org/2000/svg", "feConvolveMatrix"), document.createElementNS("http://www.w3.org/2000/svg", "feConvolveMatrix"), document.createElementNS("http://www.w3.org/2000/svg", "feConvolveMatrix")], ot = et[0].orderX, st = et[1].orderX, at = et[2].orderX, ct = JSON.parse("[1.1, []]");
          tt[0] = ot, tt[1] = st, tt[2] = at, tt[3] = ct, tt[4] = 0xdead22, await h.Ke(nt);
          const ht = h.readU64(0),
            lt = h.readU64(8),
            ft = h.readU64(16),
            wt = h.readU64(24),
            ut = {
              no: [],
              ro: [],
              eo: []
            };
          await h.Ke(lt);
          const gt = h.readU64(24);
          await h.Ke(gt), ut.ro.push([BigInt(40), h.readU64(40)]), ut.ro.push([BigInt(48), h.readU64(48)]);
          do {
            await rt(gt + BigInt(16), BigInt(0)), await rt(gt + BigInt(24), BigInt(0)), h.je()
          } while (h.readU64(16) !== BigInt(0) || h.readU64(24) !== BigInt(0));
          await h.Ke(ht);
          const dt = h.readU64(24);
          await h.Ke(dt), ut.no.push([BigInt(40), h.readU64(40)]), ut.no.push([BigInt(48), h.readU64(48)]);
          do {
            await rt(dt + BigInt(16), BigInt(0)), await rt(dt + BigInt(24), BigInt(0)), h.je()
          } while (h.readU64(16) !== BigInt(0) || h.readU64(24) !== BigInt(0));
          await h.Ke(ft);
          const Bt = h.readU64(24);
          await h.Ke(Bt), ut.eo.push([BigInt(40), h.readU64(40)]), ut.eo.push([BigInt(48), h.readU64(48)]);
          do {
            await rt(Bt + BigInt(16), BigInt(0)), await rt(Bt + BigInt(24), BigInt(0)), h.je()
          } while (h.readU64(16) !== BigInt(0) || h.readU64(24) !== BigInt(0));
          await h.Ke(dt);
          do {
            await rt(dt + BigInt(32), Bt + BigInt(32) - BigInt(28)), h.je()
          } while (h.readU64(32) !== Bt + BigInt(32) - BigInt(28));
          await h.Ke(gt);
          do {
            await rt(gt + BigInt(32), Bt + BigInt(32) - BigInt(28) + BigInt(4)), h.je()
          } while (h.readU64(32) !== Bt + BigInt(32) - BigInt(28) + BigInt(4));
          const bt = new z(dt, ot, gt, st, Bt, at, wt, ct);
          for (const t of [[gt, ut.ro], [dt, ut.no], [Bt, ut.eo]]) {
            const i = t[0],
              n = t[1];
            for (const t of n) {
              const n = t[0],
                r = t[1];
              bt.writeU64(i + BigInt(n), r)
            }
          }
          for (const t in et) {
            const i = et[t],
              r = bt.addrOfJS(i),
              e = n(bt.readU64(r + BigInt(24))),
              o = bt.readU32Raw(e + BigInt(24));
            bt.writeU32(e + BigInt(24), o + 0x4000)
          }
          const It = [ot, st, at];
          for (const t in It) {
            const i = It[t],
              r = bt.addrOfJS(i),
              e = n(bt.readU64(r + BigInt(24))),
              o = bt.readU32Raw(e + BigInt(8));
            bt.writeU32(e + BigInt(8), o + 0x4000)
          }
          return i.xi = S, i.Pi = N, new k(t, bt)
        }(c);
        for (const t of e) {
          if (null === t) continue;
          const i = l.addrOfObj(t);
          l.writeU32(i + 24, 0), l.writeU32(i + 28, 0), l.writeU32(i + 32, 0), l.writeU32(i + 36, 0)
        }
        for (const t in o) {
          const i = o[t],
            n = l.addrOfObj(i),
            r = l.readPtrStripped(n + 24),
            e = l.readU32Raw(r + 0);
          l.writeU32(r + 0, e + 0x4000)
        }
        return o.length = 0, e.length = 0, l
      }()
    }();
    T.engine.memory = i
  } catch (t) {
    throw T.engine.memory = undefined, t
  }
}, r;
