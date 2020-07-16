#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

const long long MOD = 1000000007;

using LL = long long;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VVLL = vector<VLL>;

template <typename T>
void add(T &a, T b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
}

int main()
{
  IOS;

  int N;
  cin >> N;
  string s;
  cin >> s;

  VLL dp0(N, 1);

  forn(i, 0, N - 1)
  {
    VLL dp1(N);
    if (s[i] == '<')
    {
      for (int j = 0; j < N - i - 1; j++)
      {
        dp1[j] = dp0[j];
        if (j > 0)
          add(dp1[j], dp1[j - 1]);
      }
    }
    else
    {
      for (int j = N - i - 2; j >= 0; j--)
      {
        dp1[j] = dp1[j + 1];
        add(dp1[j], dp0[j + 1]);
      }
    }
    dp0 = dp1;
  }

  cout << dp0[0] << endl;

  return 0;
}
