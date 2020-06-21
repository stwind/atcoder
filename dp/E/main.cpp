#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define forn(i, x, y) for(int i = x; i < y; i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
// clang-format on

const long long INF = 1LL << 60;

int main()
{
  IOS;

  ll N, W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  forn(i, 0, N) cin >> w[i] >> v[i];

  const ll sum_v = accumulate(v.begin(), v.end(), 0LL);

  vector<ll> dp(sum_v + 1, INF);
  dp[0] = 0;

  for (int i = 0; i < N; i++)
    for (int j = sum_v; j >= v[i]; j--)
      chmin(dp[j], w[i] + dp[j - v[i]]);

  for (int i = sum_v; i >= 0; i--)
    if (dp[i] <= W)
    {
      cout << i << endl;
      break;
    }

  return 0;
}
