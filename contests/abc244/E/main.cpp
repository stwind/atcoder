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

  int N, M, K, S, T, X;cin >> N >> M >> K >> S >> T >> X;
  VVI G(N + 1);
  REP(i, 0, M) {
    int u, v;cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<VVI> dp(K + 1, VVI(N + 1, VI(2, 0)));
  dp[0][S][0] = 1;
  REP(i, 0, K) REP(u, 1, N + 1) REP(f, 0, 2) for (auto v : G[u]) {
    dp[i + 1][v][f ^ (v == X)] = add(dp[i + 1][v][f ^ (v == X)], dp[i][u][f]);
  }
  cout << dp[K][T][0] << endl;

  return 0;
}