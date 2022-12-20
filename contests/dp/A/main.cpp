#include <bits/stdc++.h>
using namespace std;

#define from(i, x, N) for (int i = x; i < N; i++)
#define forn(i, N) for (int i = 0; i < N; i++)

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  vector<int> H(N);
  forn(i, N) cin >> H[i];

  vector<int> dp(N);
  dp[0] = 0;
  dp[1] = abs(H[1] - H[0]);

  from(i, 2, N)
  {
    dp[i] = min(abs(H[i] - H[i - 1]) + dp[i - 1], abs(H[i] - H[i - 2]) + dp[i - 2]);
  }
  cout << dp[N - 1] << endl;

  return 0;
}
