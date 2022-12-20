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
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a -= MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;

int H, N;
VI A, B;

int main()
{
    IOS;
    cin >> H >> N;
    A.resize(N);
    B.resize(N);
    forn(i, 0, N) cin >> A[i] >> B[i];

    int inf = 100000000;
    VVI dp(N + 1, VI(H + 1, inf));
    dp[0][0] = 0;

    forn(i, 0, N) forn(j, 0, H + 1)
    {
        // O(NH)
        dp[i + 1][j] = dp[i][j];
        chmin(dp[i + 1][j], dp[i + 1][max(0, j - A[i])] + B[i]);

        // O(NH^2)
        // for (int k = 0; k <= CEIL(j, A[i]); k++)
        //     chmin(dp[i + 1][j], dp[i][max(0, j - k * A[i])] + k * B[i]);
    }

    cout << dp[N][H] << endl;

    return 0;
}