#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

const long long MOD = 1000000007;

void dfs(VVI &tree, VVLL &dp, int u, int prev)
{
  for (auto v : tree[u])
  {
    if (v != prev)
    {
      dfs(tree, dp, v, u);
      dp[u][0] = dp[u][0] * ((dp[v][0] + dp[v][1]) % MOD) % MOD;
      dp[u][1] = (dp[u][1] * dp[v][0]) % MOD;
    }
  }
}

int main()
{
  IOS;
  int N;
  cin >> N;

  VVI tree(N + 1, VI());
  int x, y;
  forn(i, 0, N - 1)
  {
    cin >> x >> y;
    tree[x].push_back(y);
    tree[y].push_back(x);
  }

  VVLL dp(N + 1, VLL(2, 1));
  dfs(tree, dp, 1, -1);
  cout << (dp[1][0] + dp[1][1]) % MOD << endl;

  return 0;
}
