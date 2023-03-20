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
    push(p);
    d[p] = x;
    REP(i, 1, h + 1) build(p >> i);
  }

  S get(int p) {
    assert(0 <= p && p < n);
    p += size;
    push(p);
    return d[p];
  }

  void set(int l, int r, F f) {
    assert(0 <= l && l <= r && r <= n);
    if (l == r) return;

    l += size, r += size;
    push(l), push(r - 1);

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
    push(l), push(r - 1);

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
  void push(int p) {
    REPR(i, h, 1) {
      int k = p >> i;
      apply(2 * k, lz[k]);
      apply(2 * k + 1, lz[k]);
      lz[k] = id();
    }
  }
};

int main() {
  IOS;

  int N, M; cin >> N >> M;
  VI T(M), L(M), R(M);
  REP(i, 0, M) cin >> T[i] >> L[i] >> R[i], L[i]--;

  LST<int, int> lst(N,
    [](int l, int r) { return max(l, r); },
    []() { return 0; },
    [](int l, int r) { return max(l, r); },
    [](int l, int r) { return max(l, r); },
    []() { return 0; });
  REP(i, 0, M) lst.set(L[i], R[i], T[i]);

  LL res = 0;
  REP(i, 0, N) res += lst.get(i);
  cout << res << endl;

  return 0;
}