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

  int N, M; cin >> N >> M;
  vector<map<int, VI>> G(N);
  REP(i, 0, M) {
    int p, q, c; cin >> p >> q >> c; p--, q--;
    G[p][c].push_back(q);
    G[q][c].push_back(p);
  }

  using TIII = tuple<int, int, int>;
  map<int, map<int, int>> D;
  deque<TIII> q;
  q.push_back({ 0,0,1 });

  while (!q.empty()) {
    auto [u, c, d] = q.front(); q.pop_front();
    if (u == N - 1) {
      cout << d << endl;
      return 0;
    }

    if (D.count(u) && D[u].count(c) && D[u][c] <= d) continue;
    D[u][c] = d;

    if (c == 0) {
      for (auto m : G[u]) for (auto v : m.second) {
        q.push_front({ v,m.first,d });
      }
    }
    else {
      q.push_back({ u,0,d + 1 });
      for (auto v : G[u][c]) q.push_front({ v,c,d });
    }
  }
  cout << -1 << endl;

  return 0;
}