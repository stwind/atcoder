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

  int N, M; cin >> N >> M;
  VVI G(N);
  REP(i, 0, N - 1) {
    int x, y; cin >> x >> y;x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  VLL dp(N, 1);
  function<void(int, int)> dfs1 = [&](int u, int p) {
    for (auto v : G[u]) if (v != p) {
      dfs1(v, u);
      dp[u] = dp[u] * (dp[v] + 1) % M;
    }
    };

  VLL res(N, 1);
  function<void(int, int, int a)> dfs2 = [&](int u, int p, int a) {
    res[u] = a % M;
    for (auto v : G[u]) if (v != p)
      res[u] = res[u] * (dp[v] + 1) % M;

    int n = G[u].size();
    VLL L(n), R(n);
    REP(i, 0, n)
      L[i] = R[i] = G[u][i] == p ? a : (dp[G[u][i]] + 1);

    REP(i, 1, n) L[i] = L[i] * L[i - 1] % M;
    REPR(i, n - 2, 0) R[i] = R[i] * R[i + 1] % M;

    REP(i, 0, n) if (G[u][i] != p) {
      int a = i > 0 ? L[i - 1] : 1;
      if (i < n - 1) a = a * R[i + 1] % M;
      dfs2(G[u][i], u, a + 1);
    }
    };

  dfs1(0, -1);
  dfs2(0, -1, 1);

  REP(i, 0, N) cout << res[i] << endl;

  return 0;
}