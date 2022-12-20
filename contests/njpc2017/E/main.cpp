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

struct Edge
{
    int v, c, t;
};

int main()
{
    IOS;
    int N, D;
    cin >> N >> D;

    vector<vector<Edge>> adj(N);
    int a, b, c;
    forn(i, 0, N - 1)
    {
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c, 1});
        adj[b].push_back({a, c, 0});
    }

    VI dist(N), weight(N);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto &e : adj[u])
        {
            if (e.v == p)
                continue;
            dfs(e.v, u);
            chmax(dist[u], dist[e.v] + e.c);
            weight[u] += weight[e.v] + e.t;
        }
    };

    function<int(int, int, int, int)> dfs2 = [&](int u, int p, int d_par, int d_weight) {
        vector<PII> d_child;
        d_child.emplace_back(0, -1);
        int tot = 0;
        for (auto &e : adj[u])
        {
            if (e.v == p)
            {
                d_child.emplace_back(e.c + d_par, e.v);
                tot += d_weight + e.t;
            }
            else
            {
                d_child.emplace_back(e.c + dist[e.v], e.v);
                tot += weight[e.v] + e.t;
            }
        }
        sort(rall(d_child));

        int res = INF;
        if (d_child[0].first <= D)
            chmin(res, tot);

        for (auto &e : adj[u])
        {
            if (e.v == p)
                continue;
            chmin(res, dfs2(e.v, u, d_child[d_child[0].second == e.v].first, tot - e.t - weight[e.v]));
        }
        return res;
    };

    dfs(0, -1);

    int res = dfs2(0, -1, 0, 0);
    cout << (res == INF ? -1 : res) << endl;

    return 0;
}