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
  int n, size;
  vector<T> d;
  SegmentTree(int n): n(n), size(ceil_pow2(n)), d(size * 2, -1) { }
  void set(int i, T x) {
    for (d[i += size] = x;i > 1;i >>= 1)
      d[i >> 1] = max(d[i], d[i ^ 1]);
  }
  T query(int l, int r) {
    T res = 0LL;
    for (l += size, r += size;l < r;l >>= 1, r >>= 1) {
      if (l & 1) chmax(res, d[l++]);
      if (r & 1) chmax(res, d[--r]);
    }
    return res;
  }
  int max_right(int l, T x) {
    assert(0 <= l && l <= n);
    if (l == n) return n;
    l += size;
    T sm = -1;
    do {
      while (l % 2 == 0) l >>= 1;
      if (!(max(sm, d[l]) < x)) {
        while (l < size) {
          if (max(sm, d[l *= 2]) < x) chmax(sm, d[l++]);
        }
        return l - size;
      }
      chmax(sm, d[l++]);
    } while ((l & -l) != l);
    return n;
  }
};

int main() {
  IOS;

  int N, Q;
  cin >> N >> Q;
  VLL A(N);
  REP(i, 0, N) cin >> A[i];

  SegmentTree<LL> seg(N);
  REP(i, 0, N) seg.set(i, A[i]);

  while (Q--) {
    LL t, x, y; cin >> t >> x >> y;
    if (t == 1) seg.set(x - 1, y);
    if (t == 2) cout << seg.query(x - 1, y) << endl;
    if (t == 3) cout << seg.max_right(x - 1, y) + 1 << endl;
  }

  return 0;
}