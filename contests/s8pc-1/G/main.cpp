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

  int N, M; cin >> N >> M;
  vector<vector<tuple<int, LL, LL>>> G(N);
  REP(i, 0, M) {
    int s, t;LL d, l; cin >> s >> t >> d >> l; s--, t--;
    G[s].push_back({ t,d,l });
    G[t].push_back({ s,d,l });
  }

  int n = 1 << N;
  LL INF = 1LL << 62;
  vector<vector<PLL>> dp(n, vector<PLL>(N, { INF,0 }));
  dp[0][0] = { 0,1 };

  for (int s = 0; s < n; s++) {
    REP(u, 0, N) if ((s == 0 && u == 0) || s >> u & 1) {
      for (auto [v, d, l] : G[u]) {
        int sv = s | (1 << v);
        LL dd = dp[s][u].first + d;
        if (dd > l || sv == s) continue;

        if (dp[sv][v].first > dd)
          dp[sv][v] = { dd,dp[s][u].second };
        else if (dp[sv][v].first == dd)
          dp[sv][v] = { dd,dp[sv][v].second + dp[s][u].second };
      }
    }
  }

  auto [d, l] = dp[n - 1][0];
  if (d == INF) cout << "IMPOSSIBLE" << endl;
  else cout << d << " " << l << endl;

  return 0;
}