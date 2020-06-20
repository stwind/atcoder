#include <bits/stdc++.h>
using namespace std;

// clang-format off
using ll = long long;
#define forn(i, N) for (int i = 0; i < N; i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// clang-format on

const long long INF = 1LL << 60;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  forn(i, N) cin >> H[i];

  vector<ll> dp(N, INF);
  dp[0] = 0;

  forn(i, N)
  {
    for (int k = 1; k <= K && i + k < N; k++)
      chmin(dp[i + k], dp[i] + abs(H[i] - H[i + k]));
  }
  cout << dp[N - 1] << endl;

  return 0;
}
