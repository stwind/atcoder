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
      d[i >> 1] = min(d[i], d[i ^ 1]);
  }
  T query(int l, int r) {
    T res = numeric_limits<T>::max();
    for (l += size, r += size;l < r;l >>= 1, r >>= 1) {
      if (l & 1) chmin(res, d[l++]);
      if (r & 1) chmin(res, d[--r]);
    }
    return res;
  }
  int max_right(int l, T x) {
    assert(0 <= l && l <= n);
    if (l == n) return n;
    l += size;
    T sm = numeric_limits<T>::max();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!(min(sm, d[l]) >= x)) {
        while (l < size) {
          if (min(sm, d[l *= 2]) >= x) chmin(sm, d[l++]);
        }
        return l - size;
      }
      chmin(sm, d[l++]);
    } while ((l & -l) != l);
    return n;
  }
  int min_left(int r, T x) {
    assert(0 <= r && r <= n);
    if (r == 0) return 0;
    r += size;
    T sm = numeric_limits<T>::max();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!(min(sm, d[r]) >= x)) {
        while (r < size) {
          r = r * 2 + 1;
          if (min(sm, d[r]) >= x) chmin(sm, d[r--]);
        }
        return r + 1 - size;
      }
      chmin(sm, d[r]);
    } while ((r & -r) != r);
    return 0;
  }
};

int main() {
  IOS;

  int N;
  cin >> N;
  VI A(N);
  REP(i, 0, N) cin >> A[i];

  SegmentTree<LL> seg(N);
  REP(i, 0, N) seg.set(i, A[i]);

  LL res = 0;
  REP(i, 0, N) {
    LL l = seg.min_left(i, A[i]) - 1;
    LL r = seg.max_right(i, A[i]);
    res += A[i] * (i - l) * (r - i);
  }
  cout << res << endl;

  // VLL L(N);
  // stack<int> sl;
  // sl.push(-1);
  // REP(i, 0, N) {
  //   while (sl.top() >= 0 && A[sl.top()] >= A[i]) {
  //     int idx = sl.top();
  //     sl.pop();
  //     L[idx] = sl.top();
  //   }
  //   sl.push(i);
  // }
  // while (sl.top() >= 0) {
  //   int idx = sl.top();
  //   sl.pop();
  //   L[idx] = sl.top();
  // }

  // VLL R(N);
  // stack<int> sr;
  // sr.push(N);
  // REPR(i, N - 1, 0) {
  //   while (sr.top() < N && A[sr.top()] >= A[i]) {
  //     int idx = sr.top();
  //     sr.pop();
  //     R[idx] = sr.top();
  //   }
  //   sr.push(i);
  // }
  // while (sr.top() < N) {
  //   int idx = sr.top();
  //   sr.pop();
  //   R[idx] = sr.top();
  // }
  // LL res = 0;
  // for (LL i = 0;i < N;i++)
  //   res += (i - L[i]) * (R[i] - i) * A[i];
  // cout << res << endl;

  return 0;
}