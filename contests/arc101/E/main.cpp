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
#define MOD 1000000007
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

LL dp[5001][5001][2], tmp[5001][2];

int main() {
  IOS;

  int N; cin >> N;
  VVI G(N);
  REP(i, 0, N - 1) {
    int x, y; cin >> x >> y; x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  VLL F(N + 1); F[2] = 1;
  for (LL i = 4; i <= N;i += 2) F[i] = mul((i - 1), F[i - 2]);

  VI S(N, 1);
  function<void(int, int)> dfs = [&](int u, int p) {
    dp[u][1][0] = 1;
    for (auto v : G[u]) if (v != p) {
      dfs(v, u);
      REP(i, 0, N + 1) tmp[i][0] = tmp[i][1] = 0;

      REP(i, 1, S[u] + 1) REP(j, 1, S[v] + 1) {
        tmp[i + j][0] = add(tmp[i + j][0], mul(dp[u][i][0], dp[v][j][0]));
        tmp[i + j][0] = add(tmp[i + j][0], mul(dp[u][i][1], dp[v][j][1]));
        tmp[i + j][1] = add(tmp[i + j][1], mul(dp[u][i][0], dp[v][j][1]));
        tmp[i + j][1] = add(tmp[i + j][1], mul(dp[u][i][1], dp[v][j][0]));

        tmp[i][1] = add(tmp[i][1], mul(mul(dp[u][i][0], dp[v][j][0]), F[j]));
        tmp[i][1] = add(tmp[i][1], mul(mul(dp[u][i][1], dp[v][j][1]), F[j]));
        tmp[i][0] = add(tmp[i][0], mul(mul(dp[u][i][0], dp[v][j][1]), F[j]));
        tmp[i][0] = add(tmp[i][0], mul(mul(dp[u][i][1], dp[v][j][0]), F[j]));
      }
      swap(dp[u], tmp);
      S[u] += S[v];
    }
    };

  dfs(0, -1);

  LL res = 0;
  REP(i, 0, S[0] + 1) {
    res = add(res, mul(dp[0][i][0], F[i]));
    res = sub(res, mul(dp[0][i][1], F[i]));
  }
  cout << res << endl;

  return 0;
}