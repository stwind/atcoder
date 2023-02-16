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

  int N, M, K; cin >> N >> M >> K;
  VVI G(N * 2);
  REP(i, 0, M) {
    int u, v, a;cin >> u >> v >> a;u--, v--;
    u = u * 2 + a, v = v * 2 + a;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  map<int, bool> S;
  REP(i, 0, K) {
    int s;cin >> s;
    S[--s] = true;
  }

  VI D(N * 2, INF);
  deque<int> q({ 1 });
  D[1] = 0;

  while (!q.empty()) {
    int u = q.front();q.pop_front();
    if (u / 2 == N - 1) {
      cout << D[u] << endl;
      return 0;
    }

    if (S[u / 2]) {
      int uu = (u / 2) * 2 + 1 - (u % 2);
      if (D[uu] > D[u]) {
        D[uu] = D[u];
        q.push_front(uu);
      }
    }
    for (auto v : G[u]) {
      if (D[v] > D[u] + 1) {
        D[v] = D[u] + 1;
        q.push_back(v);
      }
    }
  }

  cout << -1 << endl;

  return 0;
}