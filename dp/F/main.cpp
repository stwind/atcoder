#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  cin >> s >> t;
  int m = s.size(), n = t.size();

  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (s[i] == t[j])
        dp[i + 1][j + 1] = dp[i][j] + 1;
      else
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    }
  }

  string res = "";
  int i = m, j = n;
  while (i > 0 && j > 0)
  {
    if (dp[i][j] == dp[i - 1][j])
      i--;
    else if (dp[i][j] == dp[i][j - 1])
      j--;
    else
    {
      res = s[i - 1] + res;
      i--, j--;
    }
  }
  cout << res << endl;

  return 0;
}
