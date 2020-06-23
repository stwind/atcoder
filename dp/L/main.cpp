#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

int main()
{
  IOS;
  int N;
  cin >> N;
  VI A(N);
  forn(i, 0, N) cin >> A[i];

  // O(N^2) space
  // ----
  // VVLL dp(N, VLL(N, 0));
  // for (int i = N - 1; i >= 0; i--)
  // {
  //   dp[i][i] = A[i];
  //   for (int j = i + 1; j < N; j++)
  //   {
  //     LL a = A[i] - dp[i + 1][j];
  //     LL b = A[j] - dp[i][j - 1];
  //     dp[i][j] = max(a, b);
  //   }
  // }
  // cout << dp[0][N - 1] << endl;

  // O(N) space
  // ----
  VLL dp(N, 0);
  for (int i = 0; i < N; i++)
  {
    dp[i] = A[i];
    for (int j = i - 1; j >= 0; j--)
      dp[j] = max(A[j] - dp[j + 1], A[i] - dp[j]);
  }
  cout << dp[0] << endl;

  return 0;
}
