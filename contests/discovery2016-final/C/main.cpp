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

int main() {
  IOS;

  string S; cin >> S;
  int K; cin >> K;

  stack<int> stk({ 0 });
  VVI G({ { } });
  for (auto c : S) {
    if (c == '(') {
      stk.push(G.size());
      G.push_back({});
    }
    else {
      int k = stk.top(); stk.pop();
      G[stk.top()].push_back(k);
    }
  }

  int n = S.size();
  int N = G.size();

  VI sz(N, 2); sz[0] = 0;
  VVLL dp(N, VLL(n + 1));
  dp[0][0] = 1;

  function<void(int, int)> dfs = [&](int u, int p) {
    if (u > 0) dp[u][0] = 1, dp[u][1] = 2, dp[u][2] = 1;

    for (auto v : G[u]) if (v != p) {
      dfs(v, u);

      VLL cur(n + 1);
      REP(i, 0, sz[u] + 1) REP(j, 0, sz[v] + 1)
        cur[i + j] = add(cur[i + j], mul(dp[u][i], dp[v][j]));

      swap(dp[u], cur);
      sz[u] += sz[v];
    }

    if (u > 0) REP(i, 0, sz[u] + 1) if (abs(2 * i - sz[u]) > K) dp[u][i] = 0;
    };

  dfs(0, -1);
  LL res = 0;
  REP(i, 0, n + 1) res = add(res, dp[0][i]);
  cout << res << endl;

  return 0;
}