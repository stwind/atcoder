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

int main()
{
    IOS;
    string S;
    cin >> S;

    string T = "yahoo";
    int n = S.length();
    VVI dp(n + 1, VI(5, INT_MAX));
    dp[0][0] = 0;

    forn(i, 0, n)
    {
        forn(j, 0, 5)
        {
            forn(k, 1, 5)
                chmin(dp[i][(j + k) % 5], dp[i][j] + k);
        }

        forn(j, 0, 5)
        {

            chmin(dp[i + 1][(j + 1) % 5], dp[i][j] + (S[i] != T[j]));
            chmin(dp[i + 1][j], dp[i][j] + 1);
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}