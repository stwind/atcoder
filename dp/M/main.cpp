#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define printVector(a) for(auto it = a.begin() ; it != a.end(); it++) {cout << *it << endl;}
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

const LL MOD = 1000000007;

// LL rec(VI &A, int k, int start)
// {
//   if (k == 0)
//     return 1;
//   if (start == int(A.size()))
//     return 0;

//   LL res = 0;
//   for (int i = 0; i <= A[start]; i++)
//   {
//     A[start] -= i;
//     res += rec(A, k - i, start + 1);
//     res %= MOD;
//     A[start] += i;
//   }

//   return res;
// }

int main()
{
  IOS;
  int N, K;
  cin >> N >> K;
  VI A(N);
  forn(i, 0, N) cin >> A[i];

  // cout << rec(A, K, 0) << endl;

  VVLL dp(N + 1, VLL(K + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= N; i++)
  {
    dp[i][0] = 1;
    for (int j = 1; j <= K; j++)
    {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
      if (j - A[i - 1] - 1 >= 0)
        dp[i][j] = (dp[i][j] + MOD - dp[i - 1][j - A[i - 1] - 1]) % MOD;
    }
  }
  cout << dp[N][K] << endl;

  return 0;
}
