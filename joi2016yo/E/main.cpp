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
    int N, M, K, S, P, Q;
    cin >> N >> M >> K >> S >> P >> Q;
    VI C(K);
    forn(i, 0, K)
    {
        cin >> C[i];
        C[i]--;
    }
    VVI adj(N);
    int a, b;
    forn(i, 0, M)
    {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    VI cost(N, P);
    forn(i, 0, K)
    {
        queue<int> q;
        q.push(C[i]);
        unordered_set<int> seen = {C[i]};
        forn(j, 0, S + 1)
        {
            int n = q.size();
            forn(k, 0, n)
            {
                int u = q.front();
                q.pop();
                cost[u] = Q;
                for (auto v : adj[u])
                {
                    if (!seen.count(v))
                    {
                        seen.insert(v);
                        q.push(v);
                    }
                }
            }
        }
    }

    struct Comp
    {
        constexpr bool operator()(PII const &a, PII const &b) const noexcept
        {
            return a.second > b.second;
        }
    };

    VLL dist(N, LONG_MAX);
    dist[0] = 0;
    forn(i, 0, K) dist[C[i]] = -1;
    priority_queue<PII, vector<PII>, Comp> q;
    q.push({0, 0});
    while (!q.empty())
    {
        auto [u, _] = q.top();
        q.pop();
        for (auto v : adj[u])
        {
            if (dist[v] == -1)
                continue;
            if (dist[v] > dist[u] + cost[v])
            {
                dist[v] = dist[u] + cost[v];
                q.push({v, dist[v]});
            }
        }
    }
    cout << dist[N - 1] - cost[N - 1] << endl;

    return 0;
}