#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define DEBUG(x) cout << #x << ": " << x << endl;
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

  int N, M, P; cin >> N >> M >> P;
  vector<vector<pair<int, LL>>> G(N);
  REP(i, 0, M) {
    int a, b, c; cin >> a >> b >> c; a--, b--;
    G[a].push_back({ b, P - c });
  }

  LL INF = 1e11;
  VLL D(N, INF); D[0] = 0;
  REP(i, 0, N * 2) REP(u, 0, N) if (D[u] < INF) {
    for (auto [v, c] : G[u]) {
      if (D[v] > D[u] + c)
        D[v] = i > N - 1 ? -INF : D[u] + c;
    }
  }

  cout << (D[N - 1] == -INF ? -1 : max(0LL, -D[N - 1])) << endl;

  return 0;
}