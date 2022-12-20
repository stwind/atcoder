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

int main()
{
    IOS;
    int W, N, K;
    cin >> W >> N >> K;
    VI A(N), B(N);
    forn(i, 0, N) cin >> A[i] >> B[i];

    vector<VVI> dp(N + 1, VVI(W + 1, VI(K + 1, 0)));

    forn(i, 0, N)
    {
        forn(j, 0, W + 1)
        {
            forn(k, 0, K + 1)
            {
                dp[i + 1][j][k] = dp[i][j][k];
                if (j >= A[i] && k > 0)
                    chmax(dp[i + 1][j][k], B[i] + dp[i][j - A[i]][k - 1]);
            }
        }
    }

    int res = 0;
    forn(j, 0, W + 1) forn(k, 0, K + 1) res = max(res, dp[N][j][k]);
    cout << res << endl;

    return 0;
}