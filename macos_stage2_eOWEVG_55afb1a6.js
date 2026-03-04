let r = {};
const K = globalResolve("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0"),
  T = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c"),
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
r.Mh = function() {
  T.engine.memory, T.engine.En;
  const t = new ta;
  return T.engine.On = t, T.engine.Wn = new ct, T.engine.Nn = t.Nn, T.engine.Vh = new lt, T.engine.$h = new ht, new aa(t)
};
class aa {
  constructor(t) {
    this.fh = t, this.Cc = true, this.ib = this.fh.ib, this.ob = this.fh.ob, this.lb = this.fh.lb, this.tb = this.fh.tb
  }
  sc(t, a) {
    return K.Ptr64.ot(this.fh.sc(t.Nt(), a.Nt()))
  }
  oe(t, a) {
    return K.Ptr64.ot(this.fh.oe(t.Nt(), a.Nt()))
  }
  cc(t, a) {
    return K.Ptr64.ot(this.fh.cc(t.Nt(), a.Nt()))
  }
  ac(t, a) {
    return K.Ptr64.ot(this.fh.ac(t.Nt(), a.Nt()))
  }
  Ic(t, a, s) {
    return K.Ptr64.ot(this.fh.Nn.call({
      _h: t.Nt(),
      xh: a.Nt(),
      x1: s.Nt(),
      x2: j(0),
      wh: j(0),
      zh: j(0)
    }))
  }
}
class ta {
  constructor() {
    const t = T.engine.En,
      a = T.engine.memory;
    this.En = {
      ec: t.nl.ec
    }, this.Fh = {
      Hh: null
    }, this.Bh = a.pa(32), this.Eh = a.pa(48), this.Nn = new ha, this.Ph = new sa;
    {
      const a = t.nl.oc;
      let s = 0x10n,
        i = [(0xaa0003f1), (0xaa0803f0), (0xd503211f), 0x1400000c, (0xaa0003f1), (0xaa0803f0), (0xdac10a11), 0x14000008, (0xaa0003f1), (0xaa0803f0), (0xd503215f), 0x14000004, (0xaa0003f1), (0xaa0803f0), (0xdac10e11), (0xaa1103e0), (0xd65f03c0)],
        c = null;
      const h = s => t.rl.Kl(a, i, s);
      for (;;) {
        if (c = h(c), null === c) return null;
        if (c !== this.En.ec) break;
        c += j(0x4n * i.length)
      }
      if (null === c) return null;
      this.ib = m.ot(c), this.ob = m.ot(c + 1n * s), this.lb = m.ot(c + 2n * s), this.tb = m.ot(c + 3n * s)
    }
  }
  Sh(t, a, s) {
    T.engine.En, T.engine.memory;
    return null === this.Fh.Hh && (this.Fh.Hh = this.Ph.call({
      _h: this.En.ec
    })), this.Nn.call({
      _h: this.Fh.Hh,
      xh: a,
      x1: s & j(0xffffffffffff),
      x2: 1n,
      wh: s >> 48n & 0xFFFFn,
      zh: j(t)
    })
  }
  sc(t, a) {
    return this.Sh(0, t, a)
  }
  oe(t, a) {
    return this.Sh(1, t, a)
  }
  ac(t, a) {
    return this.Sh(2, t, a)
  }
  cc(t, a) {
    return this.Sh(3, t, a)
  }
  Yh(t) {
    return this.Sh(1, this.ob.Dt().Nt() + 0x8n, t)
  }
}
class ha {
  constructor() {
    const t = T.engine.En,
      a = T.engine.memory;
    this.En = {
      za: t.nl.za
    }, this.Fh = {
      kh: null
    }, this.Bh = a.pa(32), this.Eh = a.pa(48), this.Wh = new ia, this.Ph = new sa
  }
  call(t) {
    T.engine.En;
    const a = T.engine.memory;
    if (0 === t.xh || 0x0n === t.xh) throw new Error("");
    null === this.Fh.kh && (this.Fh.kh = this.Ph.call({
      _h: this.En.za
    }));
    const s = [[this.Bh, [[0, this.Eh], [8, 1], [12, 1]]], [this.Eh, [[0, 0], [8, t.x2], [16, t.wh], [24, t.zh], [32, t.xh], [40, 1]]]];
    for (const [t, i] of s)
      for (let [s, c] of i) null == c && (c = 0x0n), a.writeU64(j(t) + j(s), j(c));
    return this.Wh.call({
      _h: this.Fh.kh,
      xh: this.Bh,
      x1: t._h,
      x2: t.x1
    })
  }
}
class ia {
  constructor() {
    const t = T.engine.En,
      a = T.engine.memory;
    this.En = {
      Zl: t.nl.Zl,
      ql: t.nl.ql,
      Yl: t.nl.Yl,
      Wl: t.nl.Wl,
      $l: t.nl.$l,
      Ql: t.nl.Ql,
      Ka: t.nl.Ka
    }, this.Uh = a.pa(80), this.jh = a.pa(80), this.qh = a.pa(80), this.Rh = a.pa(0x300), this.Dh = a.pa(80), this.Jh = new ca
  }
  call(t) {
    T.engine.En;
    const a = T.engine.memory,
      s = [[this.qh, [[32, this.En.ql], [8, this.Dh], [48, this.Rh]]], [this.Dh, [[16, j(7444609979)]]], [this.Rh, [[64, 0], [24, 0], [0x78, 0], [0x128, 0], [0x130, 0], [0x138, 0], [0x158, 0], [0x178, this.En.Ql], [0x88, 0], [0x180, t.x1], [0x188, this.Uh], [0x190, j(0x1ccccccc)]]], [this.Uh, [[16, t._h], [8, t.xh], [48, t.x2]]]];
    for (const [t, i] of s)
      for (let [s, c] of i) null == c && (c = 0x0n), a.writeU64(j(t) + j(s), j(c));
    const i = a.readU64(this.En.Yl),
      c = a.readU64(this.En.Wl);
    try {
      a.writeU64(this.En.Yl, this.En.$l), a.writeU64(this.En.Wl, this.En.Zl), this.Jh.call(this.En.Ka, this.qh)
    } finally {
      a.writeU64(this.En.Yl, i), a.writeU64(this.En.Wl, c)
    }
    return a.readU64(this.Dh + 0x10n)
  }
}
class sa {
  constructor() {
    const t = T.engine.En,
      a = T.engine.memory;
    this.En = {
      nc: t.nl.nc,
      Ya: t.nl.Ya,
      Za: t.nl.Za,
      qa: t.nl.qa
    }, this.Zh = null, this.Fb = a.pa(32), this.Ub = new at
  }
  call(t) {
    T.engine.En;
    const a = T.engine.memory;
    null === this.Zh && (this.Zh = this.Ub.call({
      id: this.En.nc,
      jb: this.En.Ya
    }));
    const s = a.readU64(this.En.Za);
    try {
      a.writeU64(this.En.Za, t._h), this.Ub.call({
        id: this.Zh,
        jb: this.En.qa,
        Eb: this.Fb + 0x10n,
        qb: this.Fb
      })
    } finally {
      a.writeU64(this.En.Za, s)
    }
    return a.readU64(this.Fb)
  }
}
class at {
  constructor() {
    const t = T.engine.En;
    T.engine.memory;
    this.En = {
      rc: t.nl.rc,
      Qa: t.nl.Qa
    }, this.$b = new it
  }
  call(t) {
    T.engine.En;
    const a = T.engine.memory,
      s = a.readU64(this.En.Qa);
    try {
      return a.writeU64(this.En.Qa, t.jb), this.$b.call({
        _h: this.En.rc,
        xh: t.id,
        x2: t.Eb,
        wh: t.qb
      })
    } finally {
      a.writeU64(this.En.Qa, s)
    }
  }
}
class st {
  constructor() {
    const t = T.engine.En;
    T.engine.memory;
    this.Fh = {
      mc: t.nl.mc
    }, this.Wh = new ia
  }
  call(t) {
    return this.Wh.call({
      _h: this.Fh.mc,
      xh: t.size,
      x1: 0x0n,
      x2: 0x0n
    })
  }
}
class it {
  constructor() {
    const t = T.engine.En,
      a = T.engine.memory;
    this.En = {
      Zl: t.nl.Zl,
      ql: t.nl.ql,
      Yl: t.nl.Yl,
      Wl: t.nl.Wl,
      $l: t.nl.$l,
      tc: t.nl.tc,
      Ka: t.nl.Ka
    }, this.qh = a.pa(80), this.Rh = a.pa(0x220), this.Dh = a.pa(80), this.Yb = null, this.tf = a.pa(80), this.af = new st, this.Jh = new ca
  }
  call(t) {
    const a = T.engine.memory;
    this.Yb = this.af.call({
      size: 0x120n
    });
    const s = [[this.qh, [[32, this.En.$l], [8, this.Rh], [48, 0]]], [this.Rh, [[64, 0], [24, 0], [0x78, 0], [0x128, 0], [0x130, 0], [0x138, 0], [0x158, 0], [0x178, this.En.tc], [0x88, 0], [0x180, this.Yb], [0x188, t.x2], [0x190, t.wh]]], [this.Yb, [[0, t.xh], [8, this.tf]]], [this.tf, [[0, this.Dh], [16, this.En.ql]]], [this.Dh, [[16, 0x0bbb9999n]]]];
    for (const [t, i] of s)
      for (let [s, c] of i) null == c && (c = 0x0n), a.writeU64(j(t) + j(s), j(c));
    const i = a.readU64(this.En.Yl),
      c = a.readU64(this.En.Wl);
    try {
      a.writeU64(this.En.Yl, t._h), a.writeU64(this.En.Wl, this.En.Zl), this.Jh.call(this.En.Ka, this.qh)
    } finally {
      a.writeU64(this.En.Yl, i), a.writeU64(this.En.Wl, c)
    }
    return a.readU64(this.Dh + 0x10n)
  }
}
class ca {
  constructor() {
    const t = T.engine.memory,
      a = new Intl.Segmenter("en", {
        nu: "sentence"
      }),
      s = [];
    for (let t = 0; t < 0x12c; t++) s.push("a");
    const i = s.loadImagesin(" ");
    a.segment(i);
    this.Nh = a, this.Qh = a.segment(i), this.Jb = t.pa(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.IMuONj)
  }
  call(t, a) {
    const s = T.engine.memory,
      i = this.Qh[Symbol.iterator](),
      c = (() => {
        const t = s.addrOfJS(i);
        return s.readU64(t + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.poHcKr))
      })(),
      h = c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.MqzmhP),
      l = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.ezbcB7)),
      n = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.YNPpX2)),
      r = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.pWvdyQ)),
      e = s.readU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KdIBeK)),
      o = s.readU64(l + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.sS3pIv)),
      b = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.HI0NlH));
    {
      const t = s.readU32Raw(o + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.tCLyui)),
        a = s.readU32Raw(o + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.Le3A61)),
        i = 2 * (globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KcwpPX + s.readU32Raw(o + j(a))),
        b = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.LjzPLJ + i * t;
      if (b % 4 != 0) throw new Error("");
      const [f, _] = s.ka(i);
      for (let t = 0; t < b; t += 4) s.writeU32(_ + j(t), s.readU32Raw(o + j(t)));
      const u = 2,
        d = 4;
      s.writeU32(_ + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.PpDlB4), d | u);
      for (let i = 0; i < t; i++) {
        const t = _ + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.NkCst2 + a * i);
        s.writeU32(t, 2);
        for (let i = 0; i < a; i++) s.Sa(t + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.XuxRwq + i), 0)
      }
      const [x, p] = s.ka(0xc0);
      s.writeU32(_ + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.JROzse), 48);
      {
        const t = r + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.mpZaG6);
        for (let a = 0; a < 0x80; a++) s.writeU32(t + j(4 * a), 0xa0)
      }
      s.writeU64(l + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.sS3pIv), _), s.writeU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.HI0NlH), p), s.writeU32(n + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.BYDV96), (0xffffffff)), s.writeU32(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.bGq8I5), 0xa0);
      for (let t = 0; t < globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.IMuONj; t += 4) s.writeU32(this.Jb + j(t), s.readU32Raw(e) + t)
    }
    s.writeU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KdIBeK), this.Jb);
    try {
      s.writeU64(this.Jb + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.okYhnZ), t), s.writeU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.wshMzH), a), i.next().value
    } finally {
      s.writeU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KdIBeK), e), s.writeU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.HI0NlH), b)
    }
  }
}
class ct {
  constructor() {
    const t = T.engine.En,
      a = T.engine.memory,
      s = T.engine.On,
      i = new Uint8Array([0, 97, 0x73, 0x6d, 1, 0, 0, 0, 1, 52, 3, 96, 8, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 1, 0x7e, 96, 16, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 1, 0x7e, 96, 16, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0x7f, 0, 3, 5, 4, 0, 1, 1, 2, 4, 4, 1, 0x70, 0, 2, 5, 4, 1, 1, 1, 1, 7, 17, 4, 1, 0x74, 1, 0, 1, 0x6d, 2, 0, 1, 0x6f, 0, 0, 1, 0x66, 0, 3, 9, 7, 1, 0, 65, 0, 11, 1, 0, 10, 0xc2, 1, 4, 4, 0, 66, 0, 11, 88, 0, 32, 1, 0xad, 66, 32, 0x86, 32, 0, 0xad, 0x84, 32, 3, 0xad, 66, 32, 0x86, 32, 2, 0xad, 0x84, 32, 5, 0xad, 66, 32, 0x86, 32, 4, 0xad, 0x84, 32, 7, 0xad, 66, 32, 0x86, 32, 6, 0xad, 0x84, 32, 9, 0xad, 66, 32, 0x86, 32, 8, 0xad, 0x84, 32, 11, 0xad, 66, 32, 0x86, 32, 10, 0xad, 0x84, 32, 13, 0xad, 66, 32, 0x86, 32, 12, 0xad, 0x84, 32, 15, 0xad, 66, 32, 0x86, 32, 14, 0xad, 0x84, 65, 0, 17, 0, 0, 15, 11, 37, 0, 32, 0, 32, 1, 32, 2, 32, 3, 32, 4, 32, 5, 32, 6, 32, 7, 32, 8, 32, 9, 32, 10, 32, 11, 32, 12, 32, 13, 32, 14, 32, 15, 16, 1, 15, 11, 60, 1, 1, 0x7e, 32, 0, 32, 1, 32, 2, 32, 3, 32, 4, 32, 5, 32, 6, 32, 7, 32, 8, 32, 9, 32, 10, 32, 11, 32, 12, 32, 13, 32, 14, 32, 15, 16, 2, 33, 16, 65, 0, 32, 16, 0xa7, 54, 2, 0, 65, 4, 32, 16, 66, 32, 0x88, 0xa7, 54, 2, 0, 15, 11]),
      c = new WebAssembly.scanSegmentPairdule(i, {}),
      h = new WebAssembly.Instance(c, {});
    this.sf = h.exports.f, this.if = h.exports.o, this.cf = new Uint32Array(h.exports.m.buffer), this.hf = a.addrOfJS(this.if), this.En = {
      uc: t.nl.uc
    }, this.Fh = {
      lf: s.sc(this.En.uc, 0x0n)
    }, this.nf = new BigUint64Array(8), this.rf = new Int32Array(this.nf.buffer), this.ef = new DataView(this.nf.buffer)
  }
  call(t, a) {
    T.engine.En;
    const s = T.engine.memory,
      i = (T.engine.On, T.engine.Nn);
    if (!(a.length <= 8)) throw new Error("WasmJitCageCallPrimitive only supports 8 register args, got " + (a.length));
    for (const t in a) this.nf[t] = j(a[t]);
    const c = s.readU64(this.hf + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.bvVGhS)),
      h = s.readU64(c),
      l = j(0x24ad);
    i.call({
      _h: this.Fh.lf,
      xh: S(h),
      x1: l
    });
    const n = i.call({
      _h: this.Fh.lf,
      xh: S(t),
      x1: l
    });
    try {
      return s.writeU64(c, n), this.sf(...this.rf), this.rf[0] = this.cf[0], this.rf[1] = this.cf[1], this.nf[0]
    } finally {
      s.writeU64(c, h)
    }
  }
}
class ht {
  constructor() {
    const t = T.engine.En,
      a = T.engine.On;
    this.Fh = {
      bf: a.sc(t.nl.xc, 0x0n)
    }
  }
  ff(t) {
    return T.engine.Nn.call({
      _h: this.Fh.bf,
      xh: j(t)
    })
  }
}
class lt {
  constructor() {
    const t = T.engine.En,
      a = T.engine.On;
    this.Fh = {
      _f: a.sc(t.nl.bc, 0x0n),
      uf: a.sc(t.nl.yc, 0x0n),
      df: a.sc(t.nl.hc, 0x0n),
      xf: a.sc(t.nl.wc, 0x0n)
    }
  }
  pf(t) {
    return T.engine.Nn.call({
      _h: this.Fh._f,
      xh: j(t)
    })
  }
  gf(t) {
    return T.engine.Nn.call({
      _h: this.Fh.uf,
      xh: t
    })
  }
  Tf(t, a, s) {
    return T.engine.Nn.call({
      _h: this.Fh.xf,
      xh: t,
      x1: a,
      x2: s
    })
  }
  wf(t, a, s) {
    return T.engine.Nn.call({
      _h: this.Fh.df,
      xh: t,
      x1: a,
      x2: s
    })
  }
}
return r;
