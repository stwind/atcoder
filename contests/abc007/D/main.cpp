#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PLL = pair<LL, LL>;

LL solve(string N)
{
    int n = N.length();
    vector<VVLL> dp(n + 1, VVLL(2, VLL(2, 0)));
    dp[0][0][0] = 1;

    forn(i, 0, n)
    {
        forn(small, 0, 2)
        {
            forn(k, 0, 2)
            {
                forn(d, 0, (small ? 9 : N[i] - '0') + 1)
                {
                    dp[i + 1][small || d < N[i] - '0'][k || d == 4 || d == 9] += dp[i][small][k];
                }
            }
        }
    }

    return dp[n][0][1] + dp[n][1][1];
}

int main()
{
    IOS;
    LL A, B;
    cin >> A >> B;

    cout << solve(to_string(B)) - solve(to_string(A - 1)) << endl;

    return 0;
}