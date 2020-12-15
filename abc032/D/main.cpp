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
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N, W;
    cin >> N >> W;
    VI A(N), B(N);
    int maxA = 0, maxB = 0;
    forn(i, 0, N)
    {
        cin >> A[i] >> B[i];
        chmax(maxA, A[i]);
        chmax(maxB, B[i]);
    }

    if (maxA <= 1000)
    {
        LL m = accumulate(all(A), 0LL);
        VVLL dp(N + 1, VLL(m + 1, W + 1));
        dp[0][0] = 0;

        forn(i, 0, N) forn(j, 0, m + 1)
        {
            dp[i + 1][j] = dp[i][j];
            if (j >= A[i])
                chmin(dp[i + 1][j], dp[i][j - A[i]] + B[i]);
        }

        for (int j = m; j >= 0; j--)
            if (dp[N][j] <= W)
            {
                cout << j << endl;
                return 0;
            }
    }
    else if (maxB <= 1000)
    {
        VVLL dp(N + 1, VLL(W + 1, 0));
        forn(i, 0, N) forn(j, 0, W + 1)
        {
            dp[i + 1][j] = dp[i][j];
            if (j >= B[i])
                chmax(dp[i + 1][j], dp[i][j - B[i]] + A[i]);
        }
        cout << *max_element(all(dp[N])) << endl;
        return 0;
    }
    else
    {
        vector<PLL> VWA;
        forn(bit, 0, 1 << (N / 2))
        {
            LL v = 0, w = 0;
            forn(i, 0, N / 2) if (bit & (1 << i))
            {
                v += A[i];
                w += B[i];
            }
            if (w <= W)
                VWA.push_back({v, w});
        }

        vector<PLL> VWB;
        forn(bit, 0, 1 << (N - (N / 2)))
        {
            LL v = 0, w = 0;
            forn(i, 0, N - (N / 2)) if (bit & (1 << i))
            {
                v += A[N / 2 + i];
                w += B[N / 2 + i];
            }
            if (w <= W)
                VWB.push_back({v, w});
        }
        sort(all(VWB), [](PLL a, PLL b) { return a.second < b.second; });

        LL cur = 0;
        for (auto &[v, w] : VWB)
        {
            chmax(cur, v);
            v = cur;
        }

        LL res = 0;
        for (auto [v, w] : VWA)
        {
            int i = upper_bound(all(VWB), W - w, [](LL w, PLL b) { return w < b.second; }) - VWB.begin() - 1;
            if (i >= 0)
                chmax(res, v + VWB[i].first);
        }
        cout << res << endl;
    }

    return 0;
}