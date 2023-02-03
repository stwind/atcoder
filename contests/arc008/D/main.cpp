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
};

template <typename T>
VI coord_compress(vector<T>& X) {
  vector<T> vals = X;
  sort(all(vals));

  vals.erase(unique(all(vals)), vals.end());

  int n = X.size();
  VI I(n);
  REP(i, 0, n)
    I[i] = lower_bound(all(vals), X[i]) - vals.begin();

  return I;
}

struct Box {
  double a, b;
};

int main() {
  IOS;

  LL N, M;
  cin >> N >> M;
  VLL P(M);
  vector<double> A(M), B(M);
  REP(i, 0, M)
    cin >> P[i] >> A[i] >> B[i];

  VI I = coord_compress(P);

  auto f = [](Box s, Box t) { return Box{ s.a * t.a, t.a * s.b + t.b }; };
  auto e = []() { return Box{ 1, 0 }; };
  SegmentTree<Box> seg(M, f, e);

  double mn = 1, mx = 1;
  REP(i, 0, M) {
    seg.set(I[i], Box{ A[i],B[i] });
    Box c = seg.d[1];
    double v = c.a + c.b;
    chmin(mn, v);
    chmax(mx, v);
  }
  cout << fixed << setprecision(8) << mn << endl << mx << endl;

  return 0;
}