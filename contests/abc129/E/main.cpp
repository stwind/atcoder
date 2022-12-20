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
    string L;
    cin >> L;

    int n = L.length();
    VVLL dp(n + 1, VLL(2, 0));
    dp[0][0] = 1;

    forn(i, 0, n)
    {
        add(dp[i + 1][1], dp[i][1]); // a=0,b=0
        add(dp[i + 1][1], dp[i][1]); // a=0,b=1
        add(dp[i + 1][1], dp[i][1]); // a=1,b=0

        if (L[i] == '1')
        {
            add(dp[i + 1][1], dp[i][0]); // a=0,b=0
            add(dp[i + 1][0], dp[i][0]); // a=0,b=1
            add(dp[i + 1][0], dp[i][0]); // a=1,b=0
        }
        else
        {
            add(dp[i + 1][0], dp[i][0]); // a=0,b=0
        }
    }

    cout << (dp[n][0] + dp[n][1]) % MOD << endl;

    return 0;
}