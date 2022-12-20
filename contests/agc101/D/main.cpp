// https://betrue12.hateblo.jp/entry/2018/08/26/122740
// https://maspypy.com/atcoder-median-of-medians%EF%BC%88abc-107d
// https://www.creativ.xyz/arc101-d-916/
// https://drken1215.hatenablog.com/entry/2018/09/08/011500

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 61)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

template <class T> struct BinaryIndexTree {
  int _n;
  vector<T> data;

public:
  BinaryIndexTree(int n) : _n(n), data(n, 0) {}
  void add(int p, T x) {
    for (; p < _n; p += p & -p)
      data[p] += x;
  }
  T sum(int r) {
    T s = 0;
    for (; r > 0; r -= r & -r)
      s += data[r];
    return s;
  }
};

int main() {
  LL N;
  cin >> N;
  VI A(N);
  REP(i, 0, N) cin >> A[i];

  LL M = N * (N + 1) / 4;

  auto check = [&](int x) -> bool {
    VLL B(N + 1);
    REP(i, 0, N) B[i + 1] += B[i] + (A[i] <= x ? 1 : -1);
    REP(i, 0, N + 1) B[i] += N + 1;

    LL k = 0;

    BinaryIndexTree<LL> bit((N + 1) * 2 + 2);
    bit.add(B[0], 1);
    REP(i, 1, N + 1) {
      LL b = B[i];
      k += bit.sum(b - 1);
      bit.add(b, 1);
    }

    return k > M;
  };

  int lo = 0, hi = 1000000000, mid;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (!check(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << hi << endl;

  return 0;
}