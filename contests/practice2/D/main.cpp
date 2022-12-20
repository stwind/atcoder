#include <bits/stdc++.h>
#include <math.h>
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
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a -= MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 0};

struct Dinic
{
    struct Edge
    {
        int u, v, cap, flow;
        size_t rev;
    };

    int n;
    vector<vector<Edge>> adj;

    Dinic(int n) : n(n), adj(n) {}

    void add_edge(int u, int v, int cap)
    {
        adj[u].push_back({u, v, cap, 0, adj[v].size()});
        adj[v].push_back({v, u, 0, 0, adj[u].size() - 1});
    }

    int max_flow(int s, int t)
    {
        vector<int> level(n), iter(n);
        function<int(void)> levelize = [&]() {
            level.assign(n, -1);
            level[s] = 0;
            queue<int> q;
            q.push(s);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                if (u == t)
                    break;
                for (auto &e : adj[u])
                {
                    if (e.cap > e.flow && level[e.v] < 0)
                    {
                        level[e.v] = level[u] + 1;
                        q.push(e.v);
                    }
                }
            }

            return level[t];
        };

        function<int(int, int)> augment = [&](int u, int cur) {
            if (u == t)
                return cur;
            for (int &i = iter[u]; i < (int)adj[u].size(); i++)
            {
                Edge &e = adj[u][i], &r = adj[e.v][e.rev];
                if (e.cap > e.flow && level[u] < level[e.v])
                {
                    int f = augment(e.v, min(cur, e.cap - e.flow));
                    if (f > 0)
                    {
                        e.flow += f;
                        r.flow -= f;
                        return f;
                    }
                }
            }
            return 0;
        };

        for (int u = 0; u < n; u++)
            for (auto &e : adj[u])
                e.flow = 0;

        int flow = 0;
        while (levelize() >= 0)
        {
            fill(iter.begin(), iter.end(), 0);
            for (int f; (f = augment(s, INT_MAX) > 0);)
                flow += f;
        }
        return flow;
    }
};

int main()
{
    IOS;
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    forn(i, 0, N) cin >> S[i];

    int n = N * M + 2;
    int s = n - 2, t = n - 1;

    auto id = [&](int i, int j) { return i * M + j; };

    Dinic g(n);

    forn(i, 0, N) forn(j, 0, M)
    {
        if (S[i][j] == '.')
        {
            int u = id(i, j);
            if ((i + j) % 2 == 0)
            {
                g.add_edge(s, u, 1);

                if (j > 0 && S[i][j - 1] == '.')
                    g.add_edge(u, id(i, j - 1), 1);
                if (j < M - 1 && S[i][j + 1] == '.')
                    g.add_edge(u, id(i, j + 1), 1);
                if (i > 0 && S[i - 1][j] == '.')
                    g.add_edge(u, id(i - 1, j), 1);
                if (i < N - 1 && S[i + 1][j] == '.')
                    g.add_edge(u, id(i + 1, j), 1);
            }
            else
            {
                g.add_edge(u, t, 1);
            }
        }
    }

    cout << g.max_flow(s, t) << endl;

    forn(u, 0, n - 2)
    {
        int uy = u / M, ux = u % M;
        for (auto &e : g.adj[u])
        {
            if (e.v < n - 2 && e.flow > 0)
            {
                int vy = e.v / M, vx = e.v % M;
                if (uy + 1 == vy)
                {
                    S[uy][ux] = 'v';
                    S[vy][vx] = '^';
                }
                else if (uy - 1 == vy)
                {
                    S[uy][ux] = '^';
                    S[vy][vx] = 'v';
                }
                else if (ux + 1 == vx)
                {
                    S[uy][ux] = '>';
                    S[vy][vx] = '<';
                }
                else
                {
                    S[uy][ux] = '<';
                    S[vy][vx] = '>';
                }
            }
        }
    }

    forn(i, 0, N)
    {
        cout << S[i] << endl;
    }

    return 0;
}