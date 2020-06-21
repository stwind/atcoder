#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define printVector(a) for(auto it = a.begin() ; it != a.end(); it++) {cout << *it << endl;}

using VI = vector<int>;
using VVI = vector<VI>;
// clang-format on

const long long MOD = 1000000007;

int main()
{
  IOS;

  int H, W;
  cin >> H >> W;

  VVI dp(H, VI(W));
  dp[0][0] = 1;
  string line;
  forn(i, 0, H)
  {
    cin >> line;
    forn(j, 0, W)
    {
      if (line[j] == '#')
        continue;
      if (i > 0)
        dp[i][j] += dp[i - 1][j];
      if (j > 0)
        dp[i][j] += dp[i][j - 1];
      dp[i][j] %= MOD;
    }
  }
  cout << dp[H - 1][W - 1] << endl;

  return 0;
}
