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
    int N, K;
    cin >> N >> K;
    VI C(N), R(N);
    forn(i, 0, N) cin >> C[i] >> R[i];
    int a, b;
    VVI adj(N);
    forn(i, 0, K)
    {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    VVI cost(N, VI(N, INT_MAX));
    forn(i, 0, N)
    {
        cost[i][i] = 0;

        queue<int> q;
        q.push(i);
        unordered_set<int> seen = {i};
        forn(j, 0, R[i])
        {
            int n = q.size();
            forn(k, 0, n)
            {
                int u = q.front();
                q.pop();
                for (auto v : adj[u])
                {
                    if (seen.count(v))
                        continue;
                    seen.insert(v);
                    q.push(v);
                    cost[i][v] = C[i];
                }
            }
        }
    }

    VI dist(N, INT_MAX);
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [_, u] = pq.top();
        pq.pop();
        forn(v, 0, N) if (cost[u][v] < INT_MAX)
        {
            if (dist[v] > dist[u] + cost[u][v])
            {
                dist[v] = dist[u] + cost[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[N - 1] << endl;

    return 0;
}