#include <bits/stdc++.h>
#include <math.h>
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
using PII = pair<int, int>;

int N;

int main()
{
    IOS;
    cin >> N;

    int inf = 1000000;
    VI dp(N + 1, inf);
    dp[0] = 0;

    forn(i, 0, N + 1)
    {
        for (int x = 1; x <= i; x *= 6)
            chmin(dp[i], 1 + dp[i - x]);
        for (int x = 1; x <= i; x *= 9)
            chmin(dp[i], 1 + dp[i - x]);
    }
    cout << dp[N] << endl;

    return 0;
}