#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 10007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
#define BYTE_TO_BINARY_PATTERN "%c%c%c"
#define BYTE_TO_BINARY(byte) \
  (byte & 0x004 ? '1' : '0'), \
  (byte & 0x002 ? '1' : '0'), \
  (byte & 0x001 ? '1' : '0')
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N;
    cin >> N;
    string S;
    cin >> S;

    unordered_map<char, int> C = {{'J', 0}, {'O', 1}, {'I', 2}};

    VVI dp(N + 1, VI(8, 0));
    dp[0][1] = 1;

    forn(i, 0, N)
    {
        forn(b, 0, 8)
        {
            if (!(b & (1 << C[S[i]])))
                continue;
            forn(s, 0, 8) if (b & s)
            {
                add(dp[i + 1][b], dp[i][s]);
            }
        }
    }

    int res = 0;
    forn(i, 0, 8) add(res, dp[N][i]);
    cout << res << endl;

    return 0;
}