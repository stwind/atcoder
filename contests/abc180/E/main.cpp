#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
  (byte & 0x008 ? '1' : '0'), \
  (byte & 0x004 ? '1' : '0'), \
  (byte & 0x002 ? '1' : '0'), \
  (byte & 0x001 ? '1' : '0')
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
const int INF = 1e9 + 10;

int main()
{
    IOS;

    int N;
    cin >> N;
    VI X(N), Y(N), Z(N);
    forn(i, 0, N) cin >> X[i] >> Y[i] >> Z[i];

    VVI dist(N, VI(N, 0));
    forn(i, 0, N) forn(j, 0, N)
        dist[i][j] = abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + max(0, Z[j] - Z[i]);

    VVI dp(1 << N, VI(N, INF));
    dp[1][0] = 0;

    forn(S, 0, 1 << N)
    {
        // printf("S " BYTE_TO_BINARY_PATTERN "\n", BYTE_TO_BINARY(S));
        forn(u, 0, N)
        {
            // printf(" u %d\n", u);
            if (!(S & (1 << u)))
                continue;
            forn(v, 0, N)
            {
                // printf(" v %d\n", v);
                if (S & (1 << v))
                    continue;
                // printf("   min(%d + %d, %d)\n", dp[S][u], dist[u][v], dp[S | (1 << v)][v]);
                chmin(dp[S | (1 << v)][v], dp[S][u] + dist[u][v]);
            }
        }
    }

    int res = INF;
    forn(u, 1, N) chmin(res, dp[(1 << N) - 1][u] + dist[u][0]);
    cout << res << endl;

    return 0;
}
