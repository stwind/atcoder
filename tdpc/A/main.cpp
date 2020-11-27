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
    int N;
    cin >> N;
    VI P(N);
    forn(i, 0, N) cin >> P[i];

    int max = accumulate(all(P), 0);
    VVI dp(N + 1, VI(max + 1, 0));
    dp[0][0] = 1;

    forn(i, 0, N)
    {
        forn(j, 0, max + 1)
        {
            dp[i + 1][j] = dp[i][j];
            if (j >= P[i])
                dp[i + 1][j] |= dp[i][j - P[i]];
        }
    }

    cout << accumulate(all(dp[N]), 0) << endl;

    return 0;
}