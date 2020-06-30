#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

int main()
{
  IOS;

  int N;
  cin >> N;
  VLL A(N);
  forn(i, 0, N) cin >> A[i];

  VVLL dp(N, VLL(N));
  for (int i = N - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < N; j++)
    {
      LL sum = A[j], p = LONG_MAX;
      for (int k = i; k < j; k++)
      {
        sum += A[k];
        p = min(p, dp[i][k] + dp[k + 1][j]);
      }
      dp[i][j] = sum + p;
    }
  }
  cout << dp[0][N - 1] << endl;

  return 0;
}
