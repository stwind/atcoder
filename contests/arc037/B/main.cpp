#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define ALL(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define MOD 1000000007
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    IOS;
    int N, M;
    cin >> N >> M;
    VVI G(N, VI(N, 0));
    forn(i, 0, N) G[i][i] = 1;
    int u, v;
    forn(i, 0, M)
    {
        cin >> u >> v;
        u--, v--;
        G[u][v] = G[v][u] = 1;
    }

    VI U(N, 0);

    function<bool(int, int, int)> dfs = [&](int u, int p, int t) {
        U[u] = t;
        bool good = true;
        forn(v, 0, N)
        {
            if (v != u && v != p && G[u][v] == 1)
            {
                if (U[v] == t || !dfs(v, u, t))
                    good = false;
            }
        }
        return good;
    };

    int t = 0;
    int res = 0;
    forn(u, 0, N)
    {
        if (U[u] == 0 && dfs(u, -1, ++t))
            res++;
    }
    cout << res << endl;

    return 0;
}