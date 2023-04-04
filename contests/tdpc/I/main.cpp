// https://tiramister.net/blog/posts/tdpc-i/

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

  string S; cin >> S;
  int N = S.size();

  vector<vector<bool>> C(N, vector<bool>(N, true));
  REP(i, 0, N) C[i][i] = false;
  REPR(i, N - 2, 0) REP(j, i + 1, N) {
    C[i][j] = false;
    if ((j - i + 1) % 3 == 0) {
      REP(k, i, j) if (S[i] == 'i' && S[k] == 'i' && S[j] == 'i')
        C[i][j] = C[i][j] || (C[i][k] && C[k + 1][j]);
      REP(k, i + 1, j) if (S[i] == 'i' && S[k] == 'w' && S[j] == 'i')
        C[i][j] = C[i][j] || (C[i + 1][k - 1] && C[k + 1][j - 1]);
    }
  }

  VVI dp(N, VI(N));
  REPR(i, N - 2, 0) REP(j, i + 2, N) {
    if (C[i][j]) dp[i][j] = (j - i + 1) / 3;
    else REP(k, i, j) chmax(dp[i][j], dp[i][k] + dp[k + 1][j]);
  }

  cout << dp[0][N - 1] << endl;

  return 0;
}