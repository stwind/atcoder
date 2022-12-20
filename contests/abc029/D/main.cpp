#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    string N;
    cin >> N;

    int M = N.length();
    vector<VVLL> dp(M + 1, VVLL(2, VLL(10, 0)));
    dp[0][0][0] = 1;

    forn(i, 0, M)
    {
        forn(smaller, 0, 2)
        {
            forn(j, 0, i + 1)
            {
                for (int d = 0; d <= (smaller ? 9 : N[i] - '0'); d++)
                {
                    if (d == 1)
                    {
                        dp[i + 1][smaller || d < N[i] - '0'][j + 1] += dp[i][smaller][j];
                    }
                    else
                    {
                        dp[i + 1][smaller || d < N[i] - '0'][j] += dp[i][smaller][j];
                    }
                }
            }
        }
    }
    LL res = 0;
    forn(j, 0, 10) res += j * (dp[M][0][j] + dp[M][1][j]);
    cout << res << endl;

    return 0;
}