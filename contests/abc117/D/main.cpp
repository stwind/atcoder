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
    LL N, K;
    cin >> N >> K;
    VLL A(N);
    forn(i, 0, N) cin >> A[i];

    int M = 43;

    VI ones(M, 0);
    forn(i, 0, M) forn(k, 0, N) ones[i] += (A[k] >> i) & 1;

    VVLL dp(M + 1, VLL(2, -1));
    dp[0][0] = 0;

    forn(i, 0, M)
    {
        int b = M - i - 1;
        LL mask = 1LL << b;
        LL v0 = mask * ones[b], v1 = mask * (N - ones[b]);

        // can be zero or one
        if (dp[i][1] != -1)
            chmax(dp[i + 1][1], dp[i][1] + max(v0, v1));

        // can only be zero
        if (dp[i][0] != -1 && (K & mask))
            chmax(dp[i + 1][1], dp[i][0] + v0);

        if (dp[i][0] != -1)
            chmax(dp[i + 1][0], dp[i][0] + ((K & mask) ? v1 : v0));
    }

    cout << max(dp[M][0], dp[M][1]) << endl;

    return 0;
}