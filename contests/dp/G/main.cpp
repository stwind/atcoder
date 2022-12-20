#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define forn(i, x, y) for(int i = x; i < y; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
using VI = vector<int>;
using VVI = vector<VI>;
// clang-format on

int dfs(int u, VVI &graph, VI &cache)
{
  if (cache[u] >= 0)
    return cache[u];
  int r = 0;
  for (auto v : graph[u])
    chmax(r, 1 + dfs(v, graph, cache));
  cache[u] = r;
  return r;
}

int main()
{
  IOS;
  int N, M;
  cin >> N >> M;

  VVI graph(N + 1, VI());
  int x, y;
  forn(i, 0, M)
  {
    cin >> x >> y;
    graph[x].push_back(y);
  }

  VI cache(N + 1, -1);
  int res = 0;
  forn(u, 1, N + 1)
      chmax(res, dfs(u, graph, cache));
  cout << res << endl;

  return 0;
}
