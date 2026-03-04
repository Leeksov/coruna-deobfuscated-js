let r = {};
"use strict";
const {
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
} = globalThis["vKTo89"]["OLdwIx"]("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0");
const T = globalThis["vKTo89"]["OLdwIx"]("6b57ca3347345883898400ea4318af3b9aa1dc5c");
const K = globalThis["vKTo89"]["OLdwIx"]("1ff010bb3e857e2b0383f1d9a1cf9f54e321fbb0");
async function q(t, e) {
  const n = 0;
  const r = 1;
  const i = 2;
  const s = 3;
  const o = t => {};
  let l = 0x29874;
  if (navigator.constructor.setAme === "Navigator") {
    o("");
    l = e
  }
  const c = "00";
  const h = "01";
  const u = "02";
  const a = "03";
  const f = "04";
  const w = "05";
  const p = "06";
  const m = "07";
  const y = "08";
  const b = "09";
  const A = "0a";
  const U = "0b";
  const g = "0c";
  const d = "0d";
  const B = "0e";
  const x = "0f";
  const v = "10";
  const C = "11";
  const P = "12";
  const F = "13";
  const N = "14";
  const k = "15";
  const I = "16";
  const _ = "17";
  const W = "18";
  const j = "19";
  const R = "1a";
  const D = "1b";
  const E = "1c";
  const H = "1d";
  const L = "1e";
  const M = "1f";
  const O = "20";
  const V = "21";
  const J = "22";
  const G = "23";
  const $ = "24";
  const z = "25";
  const Q = "26";
  const X = "27";
  const Y = "28";
  const Z = "29";
  const tt = {};
  tt[c] = 0xb0;
  tt[h] = 88;
  tt[u] = 96;
  tt[a] = 8;
  tt[f] = 16;
  tt[w] = 16;
  tt[p] = 24;
  tt[m] = 16;
  tt[y] = 24;
  tt[b] = 16;
  tt[A] = 16;
  tt[U] = 16;
  tt[g] = 0x148;
  tt[d] = 0x1d8;
  tt[B] = 0x200;
  tt[x] = 0x208;
  tt[v] = 0x298;
  tt[C] = 8;
  tt[P] = 0;
  tt[F] = 4;
  tt[N] = 12;
  tt[k] = 16;
  tt[I] = 20;
  tt[_] = 3;
  tt[W] = 32;
  tt[j] = 48;
  tt[R] = 16;
  tt[D] = 44;
  tt[E] = 48;
  tt[H] = 56;
  tt[L] = 32;
  tt[M] = 64;
  tt[O] = 0x70;
  tt[V] = 8;
  tt[J] = 24;
  tt[G] = 0x300;
  tt[$] = 0x90;
  tt[z] = 96;
  tt[Q] = 32;
  tt[X] = 0xcc08;
  tt[Y] = 0xcc10;
  tt[Z] = true;

  function et() {
    if (l >= 0x29810) {
      tt[h] = 96;
      tt[u] = 0x68;
      tt[X] = 0x12e98;
      tt[Y] = 0x12ea0
    }
    if (l >= 0x29874) {
      tt[X] = 0x13298;
      tt[Y] = 0x132a0
    }
    if (l >= 0x298d8) {
      tt[X] = 0x132c0;
      tt[Y] = 0x132c8
    }
  }

  function nt(t) {
    return "0x" + t.toString(16)
  }

  function rt(t) {
    return BigInt(t)
  }
  const it = BigInt(549755813887);
  const st = 0x7f;
  const ot = BigInt(39);

  function lt(t) {
    return t & rt(it)
  }
  const ct = async () => {
    const t = new ut;
    const e = true;
    const n = false;
    const s = true;
    const l = 2;
    const h = 2;
    const m = {
      Xr: () => {},
      ts: []
    };

    function y(t, e, n = null) {
      U[t / 4] = e;
      U[t / 4 + 1] = n !== null ? n : e / b
    }
    const b = 4294967296;
    let A = new ArrayBuffer(16);
    let U = new Uint32Array(A);
    let g = new Float64Array(A);
    let d = new BigUint64Array(A);
    let B = 0;

    function x(t, e = null) {
      y(B, t, e);
      return g[B / 8]
    }
    m.es = x;

    function v(t) {
      g[B / 8] = t;
      return U[B / 4] + b * U[B / 4 + 1]
    }

    function T(t) {
      g[B / 8] = t;
      return d[B / 8]
    }

    function C(t = 0x2710) {
      let e = [];
      for (let n = 0; n < t; ++n) e.push(new Uint8Array(0x2710))
    }

    function P() {
      for (let t = 0; t < 8; t++) new ArrayBuffer(0x1000000)
    }
    async function F(t) {
      try {
        if (window.testRunner) await print(testRunner.describe(t))
      } catch (t) {}
    }
    async function N(t, e) {
      let n = new ArrayBuffer(e);
      let r = new Uint32Array(n);
      for (let n = 0; n < e; n += 4) r[n / 4] = m.ns(t + n);
      await dumphex(n)
    }

    function k(t) {
      let e = new ArrayBuffer(t.length);
      let n = new Uint8Array(e);
      for (let e = 0, r = t.length; e < r; e++) n[e] = t.charCodeAt(e);
      return e
    }
    async function I(t) {
      return new Promise(((e, n) => setTimeout(e, t)))
    }

    function S(t) {
      let e = new Uint32Array(t);
      let n = m.rs(m.ss(e) + 16);
      m.ts.push(e);
      return [e, n]
    }

    function _(t) {
      let e = new Uint8Array(t);
      let n = m.rs(m.ss(e) + 16);
      m.ts.push(e);
      return [e, n]
    }
    const W = 0x1000000;
    const j = 0x20000;
    const R = 4294967296;
    const D = R - 1;
    let E = new Float64Array(1);
    let H = new Uint32Array(E.buffer);

    function L(t) {
      E[0] = t;
      return H[1] * R + H[0]
    }
    let M = new Uint32Array(2);
    let O = new Float64Array(M.buffer);
    let V = new Uint32Array(2);
    let J = new BigUint64Array(V.buffer);
    let G = new Float64Array(V.buffer);

    function K(t) {
      M[1] = t / R;
      M[0] = t & D;
      return O[0]
    }
    pm = {
      init: function() {
        o("");
        pm.tmput32 = new Uint32Array(2);
        pm.tmpFl = new Float64Array(pm.tmput32.buffer);
        pm.fc = {
          os: 1,
          ls: 2
        };
        pm.fa = [1.1, pm.fc];
        let t = [1.1, 1.1];
        t.cs = 1.1;
        let e = [1.1, 2.2];
        e.cs = 1.1;

        function n() {}
        let r = Reflect.construct(Object, [], n);
        let i = Reflect.construct(Object, [], n);
        r.p1 = t;
        r.p2 = t;
        i.p1 = 0x1337;
        i.p2 = 0x1337;
        delete i.p2;
        delete i.p1;
        i.p1 = 0x1337;
        i.p2 = 0x1337;
        let s = {
          guard_p1: 1,
          p1: [1.1, 2.2]
        };
        let l = new Uint32Array(2);
        let c = new Float64Array(l.buffer);
        let h = function(t, n) {
          if (n) return;
          let o = r;
          if (t) {
            o = i;
            (0)[0]
          }
          let h = 0;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          "hs" in o;
          let u = o.p1;
          if (t) u = e;
          c[0] = u[1];
          l[0] = l[0] + 16;
          u[1] = c[0];
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--;
          while (h < 1) {
            s.guard_p1 = 1;
            h++
          }
          h--
        };
        for (let t = 0; t < W; t++) {
          if (t > j) {
            h(false, true);
            continue
          }
          h(t % 2 && t < 0x100, t > 0x1000);
          if (t == j) delete r.p2
        }
        for (let t = 0; t < 0x100000; t++) new Array(13.37, 13.37, 13.37, 13.37);
        delete r.p1;
        r.p1 = pm.fa;
        r.p2 = 1;
        h(false, false)
      },
      us: function(t) {
        pm.tmput32[0] = t[0];
        pm.tmput32[1] = t[1] - 0x20000;
        return pm.tmpFl[0]
      },
      fs: function(t) {
        pm.fc.os = t
      },
      ws: function() {
        pm.gRWArray1 = [{}, {}, {}];
        let t = {
          p1: 1,
          p2: 1,
          length: 16
        };
        Array.prototype.fill.call(t, 1.1);
        let e = new Float64Array(8);
        let n = new Uint32Array(e.buffer);
        var i = [];
        for (let t = 0; t < 16; t++) i[t] = {};
        pm.ref = i[7];
        pm.ref2 = i[8];
        var s = pm.us([0x31337, 0x1001706]);
        pm.far = [0x31337, 0x31337];
        pm.tmpOptArr = [];
        for (let t = 0; t < 0x100; t++) pm.tmpOptArr[t] = {
          a1: 3.14,
          a2: 1.1
        };
        let o = {
          b1: pm.ref2
        };
        o[0] = 1.1;
        o[1] = 1.1;
        o[2] = 1.1;
        o[3] = 1.1;
        o[4] = 1.1;
        for (let t = 0x100; t < 0x200; t++) pm.tmpOptArr[t] = {
          a1: 3.14,
          a2: 1.1
        };
        let l = pm.tmpOptArr[0x100];
        l[0] = 1.1;
        l[1] = 1.1;
        l[2] = 1.1;
        l[3] = 1.1;
        l[4] = 1.1;
        let c = pm.tmpOptArr[0xff];
        c[0] = 1.1;
        c[1] = 1.1;
        c[2] = 1.1;
        c[3] = 1.1;
        c[4] = 1.1;
        pm.gRWArray1[0] = t;
        pm.gRWArray1[2] = t;
        pm.fc.os = s;
        pm.fc.ls = o;

        function h(t, n) {
          let r = pm.gRWArray1[0];
          e[0] = r[2];
          e[1] = r[4];
          e[2] = r[5];
          e[3] = r[0];
          e[4] = r[1];
          r = pm.gRWArray1[2];
          r[t] = n
        }
        for (let t = 0; t < 0x100000; t++) h(1, 1.1);
        m.ps = function(n) {
          o.b1 = n;
          pm.gRWArray1[2] = t;
          h(1, 1.1);
          return L(e[0])
        };
        let u = new Array(1.1, 1.1, 1.1, 1.1);
        u[0] = 1.1;
        let a = [u, t];

        function f() {
          let t = a[0];
          let n = a[1];
          t[2] = 3.3;
          n[0] = e[0];
          useless[1] = 3.3;
          e[0] = t[0];
          n[0] = e[1];
          return e[0]
        }
        for (let t = 0; t < 0x100000; t++) {
          useless = new Array(1, 2, 3);
          f(t + 3.3);
          f(t + .1)
        }

        function w() {
          let t = a[0];
          let n = a[1];
          t[2] = 3.3;
          n[0] = e[0];
          useless[1] = 3.3;
          t[0] = e[2];
          n[0] = e[1]
        }
        for (let t = 0; t < 0x100000; t++) {
          useless = new Array(1, 2, 3);
          w(t + 3.3, 13.37);
          w(t + 3.3, 13.37)
        }
        pm.gRWArray1[0] = pm.fa[1];
        pm.fa[1] = null;
        h(1, 3.14);
        pm.far[0] = n[6];
        pm.far[1] = 0x1001706;
        var p = pm.us(pm.far);
        pm.fs(p);
        pm.far[1] = 0x1001700;
        var y = pm.us(pm.far);
        pm.ref2Address = m.ps(pm.ref2);
        var b = m.ps(o);
        var A = m.ps(l);
        var U = m.ps(c);
        var g = A - b;
        var d = U - b;
        if (pm.ref2Address == 0x7ff8000000000000 || g != 32 && d != 32) {
          pm.fs(y);
          pm.gRWArray1[0] = t;
          h(1, 3.14);
          throw r
        }
        if (d == 32) {
          l = c;
          c = null
        }
        let B = m.ps(u);
        h(1, 1.1);
        let x = e[4];
        pm.fc.ls = o;
        pm.gRWArray1[2] = pm.gRWArray1[0];
        h(5, K(B + 8));
        pm.gRWArray1[2] = t;
        for (let t = 0; t < 0x800000; t++) {
          f(t + 13.37);
          w(13.38, 13.38)
        }

        function v(t) {
          a[1] = l;
          e[0] = K(t);
          e[1] = x;
          return L(f())
        }

        function T(t, n) {
          a[1] = l;
          e[0] = K(t);
          e[1] = x;
          e[2] = K(n);
          w()
        }

        function C(t, n) {
          a[1] = l;
          e[0] = K(t);
          e[1] = x;
          e[2] = n;
          w()
        }
        m.ys = v;
        m.bs = T;
        m.As = C;
        let P = {};
        P[0] = .1;
        objectForCellAddr = m.ps(P);
        pm.far[0] = v(objectForCellAddr - 4) / R;
        pm.far[1] = 0x1001706;
        pm.fs(pm.us(pm.far))
      },
      Us: function() {
        o("");
        let t = new Array(0x1000).fill(13.37);

        function e() {
          return t.length
        }
        pm.testobj = {
          a: 1
        };
        pm.testobjAddr = m.ps(pm.testobj) + 16;
        m.ps = function(t) {
          pm.testobj.a = t;
          return m.ys(pm.testobjAddr)
        };
        m.ss = t => m.ps(t);
        for (let t = 0; t < 0x100000; t++) e(t + .1);
        for (let n = 0; n < 0x100000; n++) {
          m.ps(t);
          e(n + .1)
        }
        for (let n = 0; n < 0x100000; n++) {
          m.ss(t);
          e(n + .1)
        }
        const n = m.ps(t);
        const r = m.ys(n + 8);
        m.ns = function(t) {
          m.bs(n + 8, t + 8);
          let i = e();
          m.bs(n + 8, r);
          return i >>> 0
        };
        m.rs = function(t) {
          return m.ns(t) + (m.ns(t + 4) & 0x7f) * 4294967296
        };
        m.gs = function(t) {
          return m.ns(t) + (m.ns(t + 4) & 0x7fff) * 4294967296
        };
        m.ds = function(t) {
          let e = m.ns(t);
          let n = m.ns(t + 4);
          return [e, n]
        };
        m.Bs = function(t, e) {
          m.As(t, e)
        };
        m.xs = function(t, e) {
          m.bs(t, e)
        };
        m.vs = function(t, e, n) {
          U[0] = e;
          U[1] = n;
          m.Bs(t, g[0])
        };
        m.Ts = function(t) {
          let e = m.ds(t);
          U[0] = e[0];
          U[1] = e[1];
          return g[0]
        }
      },
      test: function() {
        o("");
        let [t, e] = S(16);
        t[0] = 0x1337;
        t[1] = 0x4141;
        let n = m.ds(e);
        if (n[0] !== 0x1337 || n[1] !== 0x4141) throw new Error("");
        o("");
        m.xs(e, 0xdead);
        if (t[0] !== 0xdead) throw new Error("");
        o("")
      },
      Xr: function() {
        o("");
        for (let t = 0; t < pm.tmpOptArr.length; t++) pm.tmpOptArr[t] = null;
        pm.tmpOptArr = null;
        m.vs(pm.ref2Address + 24, m.rs(m.ps(pm.ref) + 24));
        pm.gRWArray1[0] = null;
        pm.gRWArray1[2] = null;
        pm.ref2 = null
      }
    };
    async function $() {
      o("");

      function e(t) {
        if (typeof t == "bigint") {
          J[0] = t;
          t = V[0] + (V[1] & 0x7f) * 4294967296
        }
        let e = m.ns(t);
        let n = m.ns(t + 4);
        V[0] = e;
        V[1] = n;
        return J[0]
      }

      function n(t, e) {
        if (typeof t == "bigint") {
          J[0] = t;
          t = V[0] + (V[1] & 0x7f) * 4294967296
        }
        m.Bs(t, e)
      }

      function r(t) {
        pm.testobj.a = t;
        return e(pm.testobjAddr)
      }
      pm.init();
      pm.ws();
      pm.Us();
      pm.test();
      const i = t => {
        const n = r(t);
        o("");
        const i = e(n + rt(tt[w]));
        o("");
        const s = i + rt(tt[c]);
        const l = e(s);
        return [i, s, l]
      };
      const s = r(t.addrOfArray);
      const [l, h, a] = i(t.rwPrimCsmInstanceA);
      const [f, p, y] = i(t.rwPrimCsmInstanceB);
      o("");
      o("");
      o("");
      n(f + rt(tt[u]), -0);
      n(l + rt(tt[u]), -0);
      n(h, t.converter.wn(p));
      pm.Xr();
      t.rwPrimA = f;
      t.rwPrimB = y;
      t.rwPrimC = l;
      t.rwPrimD = a;
      t.addrOfPtr = s
    }
    async function q() {
      const e = t;
      self.postMessage({
        type: i
      });
      self.setTimeout((() => {
        const t = e.addrOfJS(e.rwPrimCsmInstanceA);
        o("");
        const n = e.readU64(t + rt(tt[w]));
        o("");
        const r = e.readU64(n + rt(tt[a]));
        o("");
        const i = e.readU64(t + rt(tt[p]));
        o("");
        const s = e.readU64(n + rt(tt[f]));
        o("");
        const l = e.readU64(r + rt(tt[Q]));
        o("");
        const h = e.readU64(r + rt(tt[X]));
        o("");
        const m = e.readU64(h + rt(tt[Y]));
        o("");
        const y = e.readU64(h + rt(tt[X]));
        o("");
        const b = e.readU64(h + rt(tt[Q]));
        o("");
        const A = t => {
          const e = readBigPtr(inst_jsptr + rt(tt[w]));
          const n = e + rt(tt[c]);
          const r = readBigPtr(n);
          return [e, n, r]
        };
        const U = () => {
          for (let t = -0x1800n; t > -0x3000n; t -= 0x8n) {
            const n = b - t;
            if (e.readU64(n) == 0xfffe000000055432n && e.readU64(n + 0x8n * 2n) == 0xfffe000000055432n && e.readU64(n + 0x8n * 3n) == 0xfffe0000000ff432n && e.readU64(n + 0x8n * 5n) == 0xfffe0000000ff432n) {
              o("");
              const t = e.readU64(n + 0x8n * 1n);
              const r = e.readU64(t + 0x8n);
              o("");
              const i = e.readU64(n + 0x8n * 4n);
              const s = e.readU64(i + 0x8n);
              o("");
              o("");
              o("");
              o("");
              const l = e.readU64(r);
              o("");
              const h = e.readU64(l + rt(tt[w]));
              o("");
              const a = h + rt(tt[c]);
              o("");
              const f = e.readU64(r + 0x8n);
              o("");
              const p = e.readU64(f + rt(tt[w]));
              o("");
              const m = p + rt(tt[c]);
              o("");
              e.writeU64(p + rt(tt[u]), 0x8000000000000000n);
              e.writeU64(h + rt(tt[u]), 0x8000000000000000n);
              e.writeU64(a, m);
              e.writeU64(s + 0x0n, p);
              e.writeU64(s + 0x8n, m);
              e.writeU64(s + 0x10n, h);
              e.writeU64(s + 0x18n, a);
              e.writeU64(s + 0x20n, t);
              e.writeU64(s + 0x28n, 0x0n);
              return
            }
          }
          self.setTimeout(U, 10)
        };
        self.setTimeout(U, 0)
      }), 0x78)
    }
    o("");
    try {
      await $();
      await q()
    } catch (t) {
      if (t === r) self.postMessage({
        type: r
      });
      else throw t
    }
  };
  const ht = async t => {
    o("");
    const e = JSON.parse("[0.0, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10]");
    const c = new ut;
    const h = c.addrOfArray;
    e[0] = c.converter.wn(0xdeadn);
    e[1] = -0;
    h[0] = c.rwPrimCsmInstanceA;
    h[1] = c.rwPrimCsmInstanceB;
    const u = () => {
      const n = [0x55432, h, 0x55432, 0xff432, e, 0xff432];
      const r = (t, ...e) => {
        try {
          r(t + 1, ...n, ...e)
        } catch (t) {}
      };
      r(0, n);
      if (e[5] !== 6.6) {
        o("");
        try {
          o("");
          c.rwPrimA = c.converter.Cs(e[0]);
          c.rwPrimB = c.converter.Cs(e[1]);
          c.rwPrimC = c.converter.Cs(e[2]);
          c.rwPrimD = c.converter.Cs(e[3]);
          c.addrOfPtr = c.converter.Cs(e[4]);
          T.engine.memory = c;
          t()
        } catch (t) {
          o(t)
        }
      } else window.setTimeout(u, 0)
    };
    const a = () => {
      const t = q.toString();
      const e = "(" + (t.toString()) + ")()";
      const c = URL.createObjectURL(new Blob([e], {
        type: "text/javascript"
      }));
      const h = new Worker(c);
      URL.revokeObjectURL(c);
      o("");
      h.onerror = t => {
        o("")
      };
      h.onmessage = t => {
        if (t.data.type === n);
        else if (t.data.type === r) {
          o("");
          h.terminate();
          a()
        } else if (t.data.type === i) {
          o("");
          window.setTimeout(u, 0)
        }
      };
      h.postMessage({
        type: s,
        dn: l
      })
    };
    a()
  };
  class ut {
    ne(t) {
      return K.K(this.addrOfJS(t))
    }
    lr(t, e = 0x100) {
      const n = K.O(t.yt());
      return this.readString(n, e)
    }
    re(t) {
      const e = this.readU32Raw(K.O(t));
      const n = this.readU32Raw(K.O(t + 4));
      return new K.Ptr64(e, n)
    }
    le(t) {
      return this.readU32Raw(K.O(t.yt()))
    }
    hr(t) {
      return this.readPair(t.yt())
    }
    Dr(t, e) {
      const n = K.O(t);
      const r = e.Nt();
      this.writeU64(n, r)
    }
    br(t, e = false) {
      const n = this.readU32Raw(K.O(t));
      let r = this.readU32Raw(K.O(t + 4));
      if (e === true || tt[Z]) r &= st;
      return K.T(n, r)
    }
    ee(t) {
      return this.readPair(t).yt()
    }
    tr(t, e = 0x300) {
      for (let t = 0; t < e; t += 8) o("")
    }
    Yr(t, e) {
      this.writeU64(K.O(t), K.O(e))
    }
    Ar(t) {
      if (t instanceof ArrayBuffer) t = new Uint8Array(t);
      const e = this.addrOfJS(t);
      return K.K(lt(this.readU64(e + rt(tt[m]))))
    }
    Pr(t, ...e) {
      const n = new Array(e.length + 10);
      for (let t = 0; t < e.length; t++) n[t] = this.readPair(e[t].Sr);
      try {
        for (let t = 0; t < e.length; t++) this.writePtr(e[t].Sr, e[t].Zt);
        t()
      } finally {
        for (let t = 0; t < e.length; t++) this.writePtr(e[t].Sr, n[t])
      }
    }
    constructor() {
      const t = new Uint8Array([0, 97, 0x73, 0x6d, 1, 0, 0, 0, 1, 9, 2, 96, 0, 1, 0x7e, 96, 1, 0x7e, 0, 3, 3, 2, 0, 1, 4, 4, 1, 0x6f, 0, 1, 5, 3, 1, 0, 1, 6, 82, 8, 0x7b, 1, 0xfd, 12, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 11, 0x7e, 1, 66, 0xcd, 0xd7, 0xb6, 0xde, 0xda, 0xf9, 0xea, 0xe6, 0xab, 0x7f, 11, 0x7b, 1, 0xfd, 12, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 11, 0x6f, 1, 0xd0, 0x6f, 11, 0x6f, 1, 0xd0, 0x6f, 11, 0x6f, 1, 0xd0, 0x6f, 11, 0x6f, 1, 0xd0, 0x6f, 11, 0x6f, 1, 0xd0, 0x6f, 11, 7, 29, 4, 4, 0x65, 0x64, 0x66, 0x79, 3, 1, 6, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 2, 0, 3, 98, 0x74, 0x6c, 0, 0, 3, 97, 0x6c, 0x74, 0, 1, 10, 13, 2, 4, 0, 35, 1, 11, 6, 0, 32, 0, 36, 1, 11]);
      const e = t => t.exports["btl"]();
      const n = (t, e) => {
        t.exports["alt"](e)
      };
      this.ta = [];
      const r = new WebAssembly.scanSegmentPairdule(t, {});
      this.rwPrimCsmInstanceA = new WebAssembly.Instance(r, {});
      this.rwPrimCsmInstanceA[0] = 3;
      this.callA = e.bind(null, this.rwPrimCsmInstanceA);
      this.setA = n.bind(null, this.rwPrimCsmInstanceA);
      this.rwPrimCsmInstanceB = new WebAssembly.Instance(r, {});
      this.rwPrimCsmInstanceB[0] = 3;
      this.callB = e.bind(null, this.rwPrimCsmInstanceB);
      this.setB = n.bind(null, this.rwPrimCsmInstanceB);
      this.addrOfArray = [{}, 1, 8];
      this.addrOfArray["q23"] = 90;
      this.tempBuf = new ArrayBuffer(16);
      this.u32View = new Uint32Array(this.tempBuf);
      this.u64View = new BigUint64Array(this.tempBuf);
      this.ca = new ArrayBuffer(32);
      this.fa = new DataView(this.ca);
      this.converter = new ft;
      const i = 0n;
      for (let t = 0; t < 1; t++) {
        this.callA();
        this.callB();
        this.setA(i);
        this.setB(i)
      }
      this.Ps = 1;
      this.Fs = 2;
      this.Ns = 4;
      this.ks = 8;
      this.Is = new at(this)
    }
    Ss() {
      return this.Is
    }
    ua(t, e, n, r, i) {
      this.rwPrimA = this.converter.Bn(t);
      this.rwPrimB = this.converter.Bn(e);
      this.rwPrimC = this.converter.Bn(n);
      this.rwPrimD = this.converter.Bn(r);
      this.addrOfPtr = this.converter.Bn(i);
      o("");
      o("");
      o("");
      o("");
      o("")
    }
    Xr() {}
    Si(t) {
      this.setA(t)
    }
    da(t) {
      this.Si(t);
      return this.callB()
    }
    Ua(t, e) {
      this.Si(t);
      return this.setB(e)
    }
    Ci(t) {
      this.u64View[0] = this.da(t);
      return this.u64View[0]
    }
    Ba(t) {
      if (!(t instanceof Function)) throw new Error("");
      const e = this.addrOfJS(t);
      const n = this.readU64(e + BigInt(tt[y]));
      return n
    }
    sr(t, e) {
      if (typeof t === "bigint") {
        const n = this.readU64(t);
        this.u64View[0] = n;
        this.u32View[0] = e;
        const r = this.u64View[0];
        this.Ua(t, r)
      } else return this.writeU32(K.O(t), e)
    }
    Ta(t) {
      const e = new Uint8Array(new ArrayBuffer(t.length + 1));
      for (let n = 0; n < t.length; n++) e[n] = t.charCodeAt(n);
      return [e, this.ma(e)]
    }
    pa(t) {
      const e = new Uint8Array(new ArrayBuffer(Number(t)));
      const n = this.ma(e);
      this.ta.push(e);
      return n
    }
    ka(t) {
      const e = new Uint8Array(new ArrayBuffer(Number(t)));
      const n = this.ma(e);
      this.ta.push(e);
      return [e, n]
    }
    ma(t) {
      if (t instanceof ArrayBuffer) t = new Uint8Array(t);
      const e = this.addrOfJS(t);
      return lt(this.readU64(e + 0x10n))
    }
    Sa(t, e) {
      this.fa.setBigUint64(0, this.readU64(t), true);
      this.fa.setUint8(0, e, true);
      this.writeU64(t, this.fa.getBigUint64(0, true))
    }
    dr(t, e = 0x300) {
      let n = t;
      if (typeof t === "number") n = K.O(t);
      let r = "";
      for (let t = 0; t < e; t++) {
        const e = this.readByte(n + BigInt(t));
        if (e === 0) break;
        r += String.fromCharCode(e)
      }
      return r
    }
    wr(t) {
      return this.readU32Raw(t) & 0xff
    }
    rr(t) {
      if (typeof t === "bigint") {
        this.u64View[0] = this.da(t);
        return this.u32View[0]
      } else return this.readU32Raw(K.O(t))
    }
    zi(t, e) {
      return this.Ua(t, e)
    }
    tA(t) {
      this.addrOfArray[0] = t;
      const e = this.readU64(this.addrOfPtr + 0x8n);
      const n = this.readU64(e);
      this.addrOfArray[0] = null;
      return n
    }
    _s(t) {
      if (!(t instanceof Uint32Array) && !(t instanceof BigUint64Array) && !(t instanceof Uint8Array) && !(t instanceof Uint16Array)) throw new Error("jsobj must be a BigUint64Array, or a Uint[8,16,32]Array");
      const e = this.addrOfJS(t);
      return S(this.readU64(e + rt(globalThis["vKTo89"]["OLdwIx"]("6b57ca3347345883898400ea4318af3b9aa1dc5c").engine.config["uPSG1h"])))
    }
  }
  class at {
    constructor(t) {
      this.Ws = t
    }
    js(t) {
      for (const [e, n] of t)
        for (let [t, r, i] of n) {
          if (i === undefined || i === null) i = 0x0n;
          i = rt(i);
          if (t != 8) i = Number(i.toString());
          switch (t) {
            case 1:
              this.Ws.Sa(rt(e) + rt(r), i);
              break;
            case 2:
              this.Ws.Rs(rt(e) + rt(r), i);
              break;
            case 4:
              this.Ws.writeU32(rt(e) + rt(r), i);
              break;
            case 8:
              this.Ws.writeU64(rt(e) + rt(r), i);
              break;
            default:
              throw new Error("unreachable")
          }
        }
    }
  }
  class ft {
    constructor() {
      this.rn = new ArrayBuffer(16);
      this.en = new DataView(this.rn)
    }
    un(t) {
      this.en.setInt16(0, t, true);
      return this.en.getInt16(0, true)
    }
    on(t) {
      this.en.setUint16(0, t, true);
      return this.en.getUint16(0, true)
    }
    sn(t) {
      if (typeof t === "bigint") this.en.setBigUint64(0, t, true);
      else this.en.setUint32(0, t, true);
      return this.en.getUint32(0, true)
    }
    hn(t, e) {
      this.en.setFloat64(0, t, true);
      this.en.setUint32(0, e, true);
      return this.en.getFloat64(0, true)
    }
    cn(t, e) {
      this.en.setFloat64(0, t, true);
      this.en.setUint32(4, e, true);
      return this.en.getFloat64(0, true)
    }
    fn(t) {
      for (let e = 0; e < 8 / 2; e++) {
        let n = t.charCodeAt(e);
        if (Number.isNaN(n)) throw new Error("");
        this.en.setUint16(e * 2, n, true)
      }
      return this.en.getBigUint64(0, true)
    }
    an(t) {
      this.en.setFloat32(0, t, true);
      return this.en.getUint32(0, true)
    }
    wn(t) {
      this.en.setBigUint64(0, t, true);
      return this.en.getFloat64(0, true)
    }
    Cs(t) {
      this.en.setFloat64(0, t, true);
      return this.en.getBigUint64(0, true)
    }
    gn(t, e) {
      this.en.setBigUint64(0, t, true);
      this.en.setUint8(0, Number(e));
      return this.en.getBigUint64(0, true)
    }
    ln(t, e) {
      this.en.setBigUint64(0, t, true);
      this.en.setUint32(0, Number(e), true);
      return this.en.getBigUint64(0, true)
    }
    bn(t, e) {
      this.en.setUint32(0, t, true);
      this.en.setUint8(0, Number(e));
      return this.en.getUint32(0, true)
    }
    Un(t, e) {
      this.en.setUint32(0, t, true);
      this.en.setUint32(0, Number(e), true);
      return this.en.getUint32(0, true)
    }
    Bn(t) {
      this.en.setUint32(0, Number(t >>> 0), true);
      this.en.setUint32(4, Number(t / 4294967296), true);
      return this.en.getBigUint64(0, true)
    }
    mn(t, e) {
      this.en.setBigUint64(0, t, true);
      this.en.setUint32(0, Number(e), true);
      return this.en.getBigUint64(0, true)
    }
    In(t) {
      this.en.setBigUint64(0, t, true);
      return this.en.getBigUint64(0, true)
    }
  }
  if (navigator.constructor.setAme === "Navigator") {
    et();
    ht(t)
  } else {
    o("");
    self.onmessage = t => {
      o("");
      if (t.data.type === s) {
        o("");
        l = t.data.dn;
        et();
        ct()
      }
    }
  }
}
async function X() {
  await new Promise((t => {
    try {
      q(t, T.engine.dn)
    } catch (t) {
      T.engine.memory = undefined
    }
  }));
  return T.engine.memory
}
r.kr = X;
return r;
