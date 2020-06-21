#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define forn(i, x, y) for(int i = x; i < y; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

using ll = long long;
// clang-format on

int main()
{
  IOS;

  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  forn(i, 0, N) cin >> w[i] >> v[i];

  vector<ll> dp(W + 1, 0);
  for (int i = 0; i < N; i++)
  {
    for (int j = W; j >= w[i]; j--)
    {
      chmax(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  cout << dp[W] << endl;

  return 0;
}
