#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using VI = vector<int>;

int main()
{
  IOS;
  int N, K;
  cin >> N >> K;
  VI A(N);
  forn(i, 0, N) cin >> A[i];

  VI dp(K + 1);
  for (int i = 0; i <= K; i++)
  {
    if (!dp[i]) // could win at this state
      for (int j = 0; j < N && i + A[j] <= K; j++)
        dp[i + A[j]] = 1;
  }
  cout << (dp[K] ? "First" : "Second") << endl;

  return 0;
}
