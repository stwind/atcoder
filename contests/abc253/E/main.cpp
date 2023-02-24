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

int main() {
  IOS;

  int N, M, K;cin >> N >> M >> K;

  VVI dp(N, VI(M + 2));
  dp[0][1] = 1;
  dp[0][M + 1] = -1;
  REP(i, 0, N - 1) {
    REP(j, 1, M + 2) dp[i][j] = add(dp[i][j], dp[i][j - 1]);
    REP(j, 1, M + 1) {
      if (K == 0) {
        dp[i + 1][1] = add(dp[i + 1][1], dp[i][j]);
        dp[i + 1][M + 1] = sub(dp[i + 1][M + 1], dp[i][j]);
      }
      else {
        dp[i + 1][1] = add(dp[i + 1][1], dp[i][j]);
        dp[i + 1][max(1, j - K + 1)] = sub(dp[i + 1][max(1, j - K + 1)], dp[i][j]);
        dp[i + 1][min(M + 1, j + K)] = add(dp[i + 1][min(M + 1, j + K)], dp[i][j]);
        dp[i + 1][M + 1] = sub(dp[i + 1][M + 1], dp[i][j]);
      }
    }
  }
  REP(j, 1, M + 2) dp[N - 1][j] = add(dp[N - 1][j], dp[N - 1][j - 1]);

  int res = 0;
  REP(i, 1, M + 2) res = add(res, dp[N - 1][i]);
  cout << res << endl;

  return 0;
}