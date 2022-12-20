#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

bool ng(int a, int b, int c)
{
    return a == 0 && b == 2 && c == 1;
};

int main()
{
    IOS;
    int N;
    cin >> N;
    vector<vector<VVI>> dp(N + 1, vector<VVI>(4, VVI(4, VI(4, 0))));

    // A=0,C=1,G=2,T=3
    // Use T as dummy value
    dp[0][3][3][3] = 1;

    forn(i, 0, N)
    {
        forn(a, 0, 4) forn(b, 0, 4) forn(c, 0, 4)
        {
            forn(d, 0, 4)
            {
                if (ng(b, c, d)) // xAGC
                    continue;
                if (ng(b, d, c)) // xACG
                    continue;
                if (ng(c, b, d)) // xGAC
                    continue;
                if (ng(a, c, d)) // AxGC
                    continue;
                if (ng(a, b, d)) // AGxC
                    continue;
                add(dp[i + 1][b][c][d], dp[i][a][b][c]);
            }
        }
    }

    int res = 0;
    forn(a, 0, 4) forn(b, 0, 4) forn(c, 0, 4) add(res, dp[N][a][b][c]);
    cout << res << endl;

    return 0;
}