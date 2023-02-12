#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
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

template <class T>
struct SegmentTree {
  using F = function<T(T, T)>;
  using E = function<T()>;
  using P = function<bool(T)>;
  int n, size;
  vector<T> d;
  F f;
  E e;
  SegmentTree(int n, F f, E e):
    n(n), size(ceil_pow2(n)), d(size * 2, e()), f(f), e(e) { }
  void set(int i, T x) {
    for (d[i += size] = x;i > 1;) {
      i >>= 1;
      d[i] = f(d[i * 2], d[i * 2 + 1]);
    }
  }
  T query(int l, int r) {
    T sml = e(), smr = e();
    for (l += size, r += size;l < r;l >>= 1, r >>= 1) {
      if (l & 1) sml = f(sml, d[l++]);
      if (r & 1) smr = f(d[--r], smr);
    }
    return f(sml, smr);
  }
  int max_right(int l, P p) {
    assert(0 <= l && l <= n);
    if (l == n) return n;
    l += size;
    T sm = e();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!p(f(sm, d[l]))) {
        while (l < size) {
          if (p(f(sm, d[l *= 2])))
            sm = f(sm, d[l++]);
        }
        return l - size;
      }
      sm = f(sm, d[l++]);
    } while ((l & -l) != l);
    return n;
  }
  int min_left(int r, P p) {
    assert(0 <= r && r <= n);
    if (r == 0) return 0;
    r += size;
    T sm = e();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!p(f(d[r], sm))) {
        while (r < size) {
          r = r * 2 + 1;
          if (p(f(d[r], sm)))
            sm = f(d[r--], sm);
        }
        return r + 1 - size;
      }
      sm = f(d[r], sm);
    } while ((r & -r) != r);
    return 0;
  }
};

int main() {
  IOS;

  int N, Q;
  cin >> N;
  VVI G(N);
  REP(i, 0, N - 1) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  cin >> Q;
  VI A(Q), B(Q);
  REP(i, 0, Q) cin >> A[i] >> B[i], A[i]--, B[i]--;

  // euler tour  
  VI P, D, L(N);
  function<void(int, int, int)> dfs = [&](int u, int p, int d) {
    L[u] = P.size();
    P.push_back(u);
    D.push_back(d);
    for (auto v : G[u]) {
      if (v == p) continue;
      dfs(v, u, d + 1);
      P.push_back(u);
      D.push_back(d);
    }
  };
  dfs(0, -1, 0);

  SegmentTree<int> seg(N * 2, [](int a, int b) { return min(a, b); }, [&]() { return N; });
  REP(i, 0, N * 2) seg.set(i, D[i]);

  REP(i, 0, Q) {
    int l = L[A[i]], r = L[B[i]];
    if (l > r) swap(l, r);
    int lca = seg.query(l, r + 1);
    cout << D[l] + D[r] - lca * 2 + 1 << endl;
  }

  return 0;
}