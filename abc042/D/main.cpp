#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll MOD = 1000000007;

int main()
{
  ll H, W, A, B;
  cin >> H >> W >> A >> B;

  unordered_map<ll, ll> dp;
  dp[0] = 1;

  for (ll i = 0; i < H - A; i++)
  {
    for (ll j = 0; j < W; j++)
    {
      if (i > 0)
        dp[i * 1e6 + j] += dp[(i - 1) * 1e6 + j];
      if (j > 0)
        dp[i * 1e6 + j] += dp[i * 1e6 + (j - 1)];
      dp[i * 1e6 + j] %= MOD;
    }
  }

  for (ll i = H - A; i < H; i++)
  {
    for (ll j = B; j < W; j++)
    {
      if (i > 0)
        dp[i * 1e6 + j] += dp[(i - 1) * 1e6 + j];
      if (j > 0)
        dp[i * 1e6 + j] += dp[i * 1e6 + (j - 1)];
      dp[i * 1e6 + j] %= MOD;
    }
  }

  cout << dp[(H - 1) * 1e6 + (W - 1)] << endl;

  return 0;
}
