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

  int N, M;cin >> N >> M;
  VVI G(N);
  REP(i, 0, M) {
    int u, v;cin >> u >> v;u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  int n = 1 << N;
  VVI dp(n, VI(N, INF));

  queue<PII> q;
  REP(i, 0, N) {
    q.push({ 0,i });
    dp[0][i] = 0;
  }

  while (!q.empty()) {
    auto [s, u] = q.front();q.pop();
    for (auto v : G[u]) {
      int ss = s ^ (1 << v);
      if (dp[ss][v] > dp[s][u] + 1) {
        dp[ss][v] = dp[s][u] + 1;
        q.push({ ss,v });
      }
    }
  }
  LL res = 0;
  REP(i, 0, n)
    res += *min_element(all(dp[i]));

  cout << res << endl;

  return 0;
}