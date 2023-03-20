#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return ((a) * (b)) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int ceil_pow2(int x) {
  x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return ++x;
};

template <class S, class F>
struct LST {
  using Op = function<S(S, S)>;
  using E = function<S()>;
  using Mapping = function<S(F, S)>;
  using Comp = function<F(F, F)>;
  using Id = function<F()>;

  int n, size, h;
  vector<S> d;
  vector<F> lz;
  Op op;
  E e;
  Mapping mapping;
  Comp comp;
  Id id;

  explicit LST(
    int n, Op op, E e, Mapping mapping, Comp comp, Id id):
    n(n), size(ceil_pow2(n)), h(log2(size)),
    d(size * 2, e()), lz(size, id()),
    op(op), e(e), mapping(mapping), comp(comp), id(id) {}

  void set(int p, S x) {
    assert(0 <= p && p < n);
    p += size;
    REPR(i, h, 1) push(p >> i);
    d[p] = x;
    REP(i, 1, h + 1) build(p >> i);
  }

  void set(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size, r += size;
    REPR(i, h, 1) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    for (int ll = l, rr = r;ll < rr;ll >>= 1, rr >>= 1) {
      if (ll & 1) apply(ll++, f);
      if (rr & 1) apply(--rr, f);
    }

    REP(i, 1, h + 1) {
      if (((l >> i) << i) != l) build(l >> i);
      if (((r >> i) << i) != r) build((r - 1) >> i);
    }
  }

  S prod(int l, int r) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return e();

    l += size, r += size;
    REPR(i, h, 1) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    S sml = e(), smr = e();
    for (;l < r;l >>= 1, r >>= 1) {
      if (l & 1) sml = op(sml, d[l++]);
      if (r & 1) smr = op(d[--r], smr);
    }

    return op(sml, smr);
  }

private:
  void build(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
  void apply(int k, F f) {
    d[k] = mapping(f, d[k]);
    if (k < size) lz[k] = comp(f, lz[k]);
  }
  void push(int k) {
    apply(2 * k, lz[k]);
    apply(2 * k + 1, lz[k]);
    lz[k] = id();
  }
};

struct S {
  LL zero, one, inv;
};

using F = bool;

int main() {
  IOS;

  int N, Q; cin >> N >> Q;
  VI A(N);
  REP(i, 0, N) cin >> A[i];
  VI T(Q), L(Q), R(Q);
  REP(i, 0, Q) cin >> T[i] >> L[i] >> R[i], L[i]--;

  LST<S, F> lst(N,
    [](S l, S r) { return S{ l.zero + r.zero, l.one + r.one, l.inv + r.inv + l.one * r.zero }; },
    []() { return S{ 0, 0, 0 }; },
    [](F l, S r) { return l ? S{ r.one, r.zero, r.one* r.zero - r.inv } : r; },
    [](F l, F r) { return (l && !r) || (!l && r); },
    []() { return false; });
  REP(i, 0, N) lst.set(i, A[i] ? S{ 0, 1, 0 } : S{ 1, 0, 0 });

  REP(i, 0, Q) {
    if (T[i] == 1)
      lst.set(L[i], R[i], true);
    else
      cout << lst.prod(L[i], R[i]).inv << endl;
  }

  return 0;
}