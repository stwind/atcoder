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
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main() {
  IOS;

  int N;cin >> N;
  VI T(N), X(N), A(N);
  REP(i, 0, N) cin >> T[i] >> X[i] >> A[i];

  map<PII, int> TX;
  REP(i, 0, N) TX[{X[i], T[i]}] = A[i];

  int mt = *max_element(all(T));
  VVLL dp(5, VLL(mt + 1));

  LL res = 0;
  REP(t, 1, mt + 1) REP(x, 0, 5) if (x <= t) {
    dp[x][t] = dp[x][t - 1] + TX[{x, t}];
    if (x > 0) chmax(dp[x][t], dp[x - 1][t - 1] + TX[{x, t}]);
    if (x < 4) chmax(dp[x][t], dp[x + 1][t - 1] + TX[{x, t}]);
    chmax(res, dp[x][t]);
  }
  cout << res << endl;

  return 0;
}