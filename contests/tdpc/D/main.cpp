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
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a -= MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PLL = pair<LL, LL>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VVVVD = vector<VVVD>;

int main()
{
    IOS;
    int N;
    cin >> N;
    LL D;
    cin >> D;

    int tw = 0, tr = 0, fi = 0;
    while (D)
    {
        if (D % 2 == 0)
            D /= 2, tw++;
        else if (D % 3 == 0)
            D /= 3, tr++;
        else if (D % 5 == 0)
            D /= 5, fi++;
        else
            break;
    }

    if (D > 1)
    {
        cout << 0 << endl;
        return 0;
    }

    VVVVD dp(N + 1, VVVD(tw + 1, VVD(tr + 1, VD(fi + 1, 0))));
    dp[0][0][0][0] = 1;

    forn(i, 0, N)
    {
        forn(j, 0, tw + 1)
        {
            forn(k, 0, tr + 1)
            {
                forn(l, 0, fi + 1)
                {
                    // printf("i=%d,j=%d,k=%d,l=%d\n", i, j, k, l);
                    dp[i + 1][j][k][l] += dp[i][j][k][l] / 6;                           // 1
                    dp[i + 1][min(j + 1, tw)][k][l] += dp[i][j][k][l] / 6;              // 2
                    dp[i + 1][j][min(k + 1, tr)][l] += dp[i][j][k][l] / 6;              // 3
                    dp[i + 1][min(j + 2, tw)][k][l] += dp[i][j][k][l] / 6;              // 4
                    dp[i + 1][j][k][min(l + 1, fi)] += dp[i][j][k][l] / 6;              // 5
                    dp[i + 1][min(j + 1, tw)][min(k + 1, tr)][l] += dp[i][j][k][l] / 6; // 6
                }
            }
        }
    }

    cout << fixed << setprecision(15) << dp[N][tw][tr][fi] << endl;

    return 0;
}