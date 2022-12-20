#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

const long long MOD = 1000000007;

using LL = long long;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;

void add(LL &a, LL b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
}

int main()
{
  IOS;

  string K;
  cin >> K;
  int D;
  cin >> D;

  int n = K.size();
  VVVLL dp(10001, VVLL(2, VLL(100)));
  dp[0][0][0] = 1;

  forn(i, 0, n) forn(s, 0, 2) forn(d, 0, D)
  {
    for (int x = 0; x <= (s ? 9 : K[i] - '0'); x++)
      add(dp[i + 1][s || x < K[i] - '0'][(d + x) % D], dp[i][s][d]);
  }
  LL res = dp[n][0][0] + dp[n][1][0] - 1;
  if (res < 0)
    res += MOD;
  cout << res << endl;

  return 0;
}
