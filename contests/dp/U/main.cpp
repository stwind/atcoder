#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

int main()
{
    IOS;
    int N;
    cin >> N;
    VVI A(N, VI(N));
    forn(i, 0, N) forn(j, 0, N) cin >> A[i][j];
    int MAX = 1 << N;

    VLL G(MAX);
    forn(mask, 1, MAX)
    {
        forn(i, 0, N) if (mask & (1 << i))
        {
            forn(j, i + 1, N) if (mask & (1 << j))
                G[mask] += A[i][j];
        }
    }

    VLL dp(MAX);
    forn(mask, 1, MAX)
    {
        dp[mask] = G[mask];
        for (int g = mask; g > 0; g = (g - 1) & mask)
        {
            dp[mask] = max(dp[mask], dp[g] + G[g ^ mask]);
        }
    }

    cout << dp[MAX - 1] << endl;

    return 0;
}
