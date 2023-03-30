#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
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

int fac(int n) {
  int res = 1;
  REPR(i, n, 1) res *= i;
  return res;
};

int main() {
  IOS;

  int N; cin >> N;
  vector<double> X(N), Y(N);
  REP(i, 0, N) cin >> X[i] >> Y[i];

  VI I(N); REP(i, 0, N) I[i] = i;

  double tot = 0;
  do {
    REP(i, 1, N) tot += hypot(X[I[i]] - X[I[i - 1]], Y[I[i]] - Y[I[i - 1]]);
  } while (next_permutation(all(I)));
  cout << fixed << setprecision(8) << tot / fac(N) << endl;

  return 0;
}