#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x;  i >= y; i--)
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
      data[p] += x;
  }

  T query(int r) {
    T s = 0;
    for (; r > 0; r -= r & -r)
      s += data[r];
    return s;
  }
};

template <typename T>
vector<T> compress(vector<T>& X) {
  vector<T> vals = X;
  sort(all(vals));

  vals.erase(unique(all(vals)), vals.end());

  int n = X.size();
  VI I(n);
  REP(i, 0, n) I[i] = lower_bound(all(vals), X[i]) - vals.begin();

  return I;
}

int main() {
  IOS;

  int N;
  cin >> N;
  VI A(N), B(N);
  REP(i, 0, N) cin >> A[i];
  REP(i, 0, N) cin >> B[i];

  VI AX = compress(A), BX = compress(B);

  VI I(N);
  REP(i, 0, N) I[i] = i;
  sort(all(I), [&](int a, int b) { return A[a] == A[b] ? B[a] > B[b] : A[a] < A[b]; });

  LL res = 0;
  BinaryIndexTree<int> bit(N + 1);

  int la, lb, cnt = 0;
  REP(i, 0, N) {
    int b = N - BX[I[i]];
    bit.update(b, 1);
    res += bit.query(b);
    if (la == AX[I[i]] && lb == b) {
      cnt++;
      res += cnt;
    }
    else {
      la = AX[I[i]];
      lb = b;
      cnt = 0;
    }
  }

  cout << res << endl;

  return 0;
}