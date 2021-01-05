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
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N, M;
    cin >> N >> M;

    LL s, t, d, time;
    VVLL adj(N, VLL(N, 0));
    VVLL lim(N, VLL(N, 0));
    forn(i, 0, M)
    {
        cin >> s >> t >> d >> time;
        s--;
        t--;
        adj[s][t] = d;
        adj[t][s] = d;
        lim[s][t] = time;
        lim[t][s] = time;
    }

    LL inf = LLONG_MAX;
    VVLL dp(N, VLL(1 << N, inf));
    dp[0][0] = 0;
    VVLL cnt(N, VLL(1 << N, 0));
    cnt[0][0] = 1;

    forn(s, 0, (1 << N) - 1)
    {
        forn(u, 0, N)
        {
            if (dp[u][s] == inf)
                continue;

            forn(v, 0, N) if (adj[u][v] > 0)
            {
                LL d = dp[u][s] + adj[u][v];
                int s1 = s | (1 << v);
                if (d > lim[u][v] || s == s1 || d > dp[v][s1])
                    continue;

                if (d < dp[v][s1])
                {
                    dp[v][s1] = d;
                    cnt[v][s1] = cnt[u][s];
                }
                else if (d == dp[v][s1])
                {
                    cnt[v][s1] += cnt[u][s];
                }
            }
        }
    }

    LL res = cnt[0][(1 << N) - 1];
    if (res > 0)
    {
        cout << dp[0][(1 << N) - 1] << " " << res << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}