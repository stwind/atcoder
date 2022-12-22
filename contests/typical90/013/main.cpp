#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x;  i >= y; i--)
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
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

VI dijkstra(vector<vector<PII>>& G, int s) {
  priority_queue<PII, vector<PII>, greater<PII>> q;
  VI dist(G.size(), INF);
  dist[s] = 0;
  q.push({ 0, s });

  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    for (auto& [v, c] : G[u]) {
      if (dist[v] > d + c) {
        dist[v] = d + c;
        q.push({ dist[v], v });
      }
    }
  }
  return dist;
};

int main() {
  IOS;
  int N, M;
  cin >> N >> M;
  vector<vector<PII>> G(N);
  int a, b, c;
  REP(i, 0, M) {
    cin >> a >> b >> c;
    a--, b--;
    G[a].push_back({ b, c });
    G[b].push_back({ a, c });
  }

  VI dist0 = dijkstra(G, 0);
  VI distN = dijkstra(G, N - 1);

  REP(i, 0, N) cout << dist0[i] + distN[i] << endl;

  return 0;
}