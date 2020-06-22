#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define printVector(a) for(auto it = a.begin() ; it != a.end(); it++) {cout << *it << endl;}
// clang-format on

using VD = vector<double>;

int main()
{
  IOS;

  int N;
  cin >> N;
  double p;

  VD dp(N + 1);
  dp[0] = 1.0;
  for (int i = 0; i < N; i++)
  {
    cin >> p;
    for (int j = i + 1; j >= 0; j--)
    {
      dp[j] *= (1 - p);
      if (j > 0)
        dp[j] += dp[j - 1] * p;
    }
  }

  double res = 0;
  for (int i = N / 2 + 1; i <= N; i++)
    res += dp[i];
  cout << fixed << setprecision(10) << res << endl;

  return 0;
}
