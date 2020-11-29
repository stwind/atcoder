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
    int D, N;
    cin >> D >> N;
    VI T(D), A(N), B(N), C(N);
    forn(i, 0, D) cin >> T[i];
    forn(i, 0, N) cin >> A[i] >> B[i] >> C[i];

    VVI dp(D, VI(N, -1));
    forn(j, 0, N)
    {
        if (A[j] <= T[0] && T[0] <= B[j])
            dp[0][j] = 0;
    }

    forn(i, 1, D)
    {
        forn(j, 0, N)
        {
            if (A[j] <= T[i] && T[i] <= B[j])
            {
                forn(k, 0, N)
                {
                    if (dp[i - 1][k] == -1)
                        continue;
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(C[j] - C[k]));
                }
            }
        }
    }
    int res = 0;
    forn(j, 0, N) res = max(res, dp[D - 1][j]);
    cout << res << endl;

    return 0;
}