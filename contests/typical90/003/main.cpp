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
  int N;
  cin >> N;

  VVI G(N);
  int u, v;
  REP(i, 0, N - 1) {
    cin >> u >> v;
    G[--u].push_back(--v);
    G[v].push_back(u);
  }

  queue<PII> q;
  q.push({ 0,0 });
  unordered_set<int> seen = { 0 };

  int dist = 0, x = 0;
  while (!q.empty()) {
    auto& [d, u] = q.front();
    q.pop();
    if (d > dist) {
      dist = d;
      x = u;
    }

    for (auto v : G[u]) {
      if (seen.count(v)) continue;
      q.push({ d + 1, v });
      seen.insert(v);
    }
  }

  function<int(int, int)> dfs = [&](int u, int p) {
    int res = 0;
    for (auto v : G[u]) {
      if (v == p) continue;
      chmax(res, dfs(v, u) + 1);
    }
    return res;
  };

  cout << dfs(x, -1) + 1 << endl;

  return 0;
}