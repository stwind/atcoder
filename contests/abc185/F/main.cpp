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
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

template <class T>
struct BinaryIndexTree {
  int _n;
  vector<T> data;

public:
  BinaryIndexTree(int n): _n(n), data(n, 0) {}
  void update(int p, T x) {
    for (; p < _n; p += p & -p)
      data[p] ^= x;
  }
  T query(int r) {
    T s = 0;
    for (; r > 0; r -= r & -r)
      s ^= data[r];
    return s;
  }
};

int main() {
  IOS;

  int N, Q;
  cin >> N >> Q;
  VI A(N);
  REP(i, 0, N) cin >> A[i];
  VI T(Q), X(Q), Y(Q);
  REP(i, 0, Q) cin >> T[i] >> X[i] >> Y[i];

  BinaryIndexTree<int> bit(N + 1);
  REP(i, 0, N) bit.update(i + 1, A[i]);

  REP(i, 0, Q) {
    if (T[i] == 1) {
      bit.update(X[i], Y[i]);
    }
    else {
      cout << (bit.query(Y[i]) ^ bit.query(X[i] - 1)) << endl;
    }
  }

  return 0;
}