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

struct CC {
  LL a;
  bool p;
};

int main() {
  IOS;

  int N; cin >> N;
  VI A(N); REP(i, 0, N) cin >> A[i];
  VVI G(N);
  REP(i, 0, N - 1) {
    int u, v; cin >> u >> v; u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  VI S(N, 1);
  vector<vector<CC>> dp(N);
  function<void(int, int)> dfs = [&](int u, int p) {
    dp[u].resize(1);
    dp[u][0] = { A[u], A[u] > 0 };
    for (auto v : G[u]) if (v != p) {
      dfs(v, u);

      vector<CC> res(S[u] + S[v], { 1LL << 60,false });
      REP(i, 0, S[u]) REP(j, 0, S[v]) {
        chmin(res[i + j].a, dp[u][i].a + dp[v][j].a);
        if (dp[u][i].p && dp[v][j].p) res[i + j].p = true;

        if (dp[v][j].a < 0 || dp[v][j].p) {
          chmin(res[i + j + 1].a, dp[u][i].a);
          if (dp[u][i].p) res[i + j + 1].p = true;
        }
      }
      swap(dp[u], res);
      S[u] += S[v];
    }
    };

  dfs(0, -1);
  REP(i, 0, S[0]) if (dp[0][i].a < 0 || dp[0][i].p) {
    cout << i << endl;
    break;
  }

  return 0;
}