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
template <typename T> T mul(T a, T b) { return 1ULL * a * b % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

template <class T = int>
struct BinaryIndexTree {
  int n;
  vector<T> data;
public:
  BinaryIndexTree(int n): n(n), data(n, 0) {}
  void set(int i, T x) {
    for (; i < n; i += i & -i)
      data[i] += x;
  }
  T query(T r) {
    T s = 0;
    for (; r > 0; r -= r & -r)
      s += data[r];
    return s;
  }
  int lower_bound(T x) {
    T s = 0;
    int p = 0;
    for (int i = log2(n); i >= 0; i--) {
      int b = 1 << i;
      if (p + b < n && s + data[p + b] < x) {
        s += data[p += b];
      }
    }
    return p + 1;
  }
};

int main() {
  IOS;

  int N; cin >> N;
  VLL A(N); REP(i, 0, N) cin >> A[i];

  BinaryIndexTree<LL> bit(N + 1);
  VLL R(N);
  REP(i, 0, N) {
    bit.set(A[i] + 1, 1);
    R[A[i]] = A[i] - bit.query(A[i]);
  }

  LL S = accumulate(all(R), 0LL);
  for (auto a : A) {
    cout << S << endl;
    S += N - 1 - a - a;
  };

  return 0;
}