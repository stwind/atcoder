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
    for (d[i += size] = x;i > 1;i >>= 1)
      d[i >> 1] = f(d[i], d[i ^ 1]);
  }
  T query(int l, int r) {
    T res = e();
    for (l += size, r += size;l < r;l >>= 1, r >>= 1) {
      if (l & 1) res = f(res, d[l++]);
      if (r & 1) res = f(res, d[--r]);
    }
    return res;
  }
};

template <typename T>
vector<T> coord_compress(vector<T>& X) {
  vector<T> vals = X;
  sort(all(vals));

  vals.erase(unique(all(vals)), vals.end());

  int n = X.size();
  VI I(n);
  REP(i, 0, n)
    I[i] = lower_bound(all(vals), X[i]) - vals.begin();

  return I;
}

int main() {
  IOS;

  int L, Q;
  cin >> L >> Q;
  VI C(Q), X(Q);
  REP(i, 0, Q) cin >> C[i] >> X[i];

  VI I = coord_compress(X);
  int n = I.size() + 1;

  auto f0 = [](int a, int b) { return min(a, b); };
  auto e0 = []() { return numeric_limits<int>::max(); };
  SegmentTree<int> smin(n + 1, f0, e0);
  smin.set(0, 0);
  smin.set(n, L);
  auto f1 = [](int a, int b) { return max(a, b); };
  auto e1 = []() { return numeric_limits<int>::min(); };
  SegmentTree<int> smax(n + 1, f1, e1);
  smax.set(0, 0);
  smax.set(n, L);

  REP(i, 0, Q) {
    if (C[i] == 1) {
      smin.set(I[i] + 1, X[i]);
      smax.set(I[i] + 1, X[i]);
    }
    if (C[i] == 2) {
      int a = smin.query(I[i] + 1, n + 1);
      int b = smax.query(0, I[i] + 2);
      cout << a - b << endl;
    }
  }

  return 0;
}