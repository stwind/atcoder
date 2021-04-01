#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
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
using PII = pair<int, int>;

int main()
{
    IOS;
    int N;
    cin >> N;
    VVI adj(N);
    int a, b;
    forn(i, 0, N - 1)
    {
        cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    vector<double> dp(N);
    function<void(int, int)> dfs = [&](int u, int p) {
        double res = 0.0;
        int n = 0;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            res += dp[v];
            n += 1;
        }
        dp[u] = n > 0 ? res / n + 1.0 : 0.0;
    };

    vector<double> res(N);
    function<void(int, int, double)> dfs2 = [&](int u, int p, double d_par) {
        double ret = 0.0;
        int n = adj[u].size();
        for (auto v : adj[u])
        {
            if (v == p)
                ret += d_par + 1.0;
            else
                ret += dp[v] + 1.0;
        }

        res[u] = ret / n;

        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            dfs2(v, u, (ret - dp[v] - 1.0) / max(1, n - 1));
        }
    };

    dfs(0, -1);
    dfs2(0, -1, 0.0);

    forn(i, 0, N)
    {
        cout << fixed << setprecision(15) << res[i] << endl;
    }

    return 0;
}