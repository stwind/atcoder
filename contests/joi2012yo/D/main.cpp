#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define PARENS ()
#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__
#define FOR_EACH(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 10000
#define DBG(x) cout << #x << ": " << x << " ";
#define DEBUG(...) FOR_EACH(DBG, __VA_ARGS__) cout << endl;
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

int main() {
  IOS;

  int N, K; cin >> N >> K;
  VI H(N, -1);
  REP(i, 0, K) {
    int a, b; cin >> a >> b;
    H[--a] = --b;
  }

  vector<VVI> dp(N, VVI(3, VI(2)));
  if (H[0] >= 0) dp[0][H[0]][0] = 1;
  else REP(i, 0, 3) dp[0][i][0] = 1;

  REP(i, 1, N) {
    if (H[i] >= 0) {
      dp[i][H[i]][1] = add(dp[i][H[i]][1], dp[i - 1][H[i]][0]);
      REP(k, 1, 3) REP(l, 0, 2) dp[i][H[i]][0] = add(dp[i][H[i]][0], dp[i - 1][(H[i] + k) % 3][l]);
    }
    else {
      REP(j, 0, 3) {
        dp[i][j][1] = add(dp[i][j][1], dp[i - 1][j][0]);
        REP(k, 1, 3) REP(l, 0, 2) dp[i][j][0] = add(dp[i][j][0], dp[i - 1][(j + k) % 3][l]);
      }
    }
  }

  int res = 0;
  REP(i, 0, 3) REP(j, 0, 2) res = add(res, dp[N - 1][i][j]);
  cout << res << endl;

  return 0;
}