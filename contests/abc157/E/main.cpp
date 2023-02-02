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
  SegmentTree(int n): n(n), size(ceil_pow2(n)), d(size * 2) { }
  void set(int i, T x) {
    for (d[i += size] = x;i > 1;i >>= 1)
      d[i >> 1] = d[i] | d[i ^ 1];
  }
  T query(int l, int r) {
    T res = 0;
    for (l += size, r += size;l < r;l >>= 1, r >>= 1) {
      if (l & 1) res |= d[l++];
      if (r & 1) res |= d[--r];
    }
    return res;
  }
};

int main() {
  IOS;

  int N, Q;
  string S;
  cin >> N >> S >> Q;

  SegmentTree<int> seg(N);
  REP(i, 0, N) seg.set(i, 1 << (S[i] - 'a'));

  int T;
  REP(k, 0, Q) {
    cin >> T;
    if (T == 1) {
      int i;
      char c;
      cin >> i >> c;
      seg.set(i - 1, 1 << (c - 'a'));
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << __builtin_popcount(seg.query(l - 1, r)) << endl;
    }
  }

  return 0;
}