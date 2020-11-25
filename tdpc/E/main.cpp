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
template<typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
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
    int D;
    string N;
    cin >> D >> N;

    int n = N.length();
    vector<VVLL> dp(n + 1, VVLL(2, VLL(D, 0)));
    dp[0][0][0] = 1;

    forn(i, 0, n)
    {
        forn(small, 0, 2)
        {
            forn(j, 0, D)
            {
                for (int d = 0; d <= (small ? 9 : (N[i] - '0')); d++)
                {
                    add(dp[i + 1][small || d < N[i] - '0'][(j + d) % D], dp[i][small][j]);
                }
            }
        }
    }
    cout << (dp[n][0][0] + dp[n][1][0]) - 1 << endl;

    return 0;
}