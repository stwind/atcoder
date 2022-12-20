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
using VVLL = vector<VLL>;
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

    VVLL dp(N, VLL(2));

    function<void(int, int)> dfs = [&](int u, int p) {
        LL b = 1, w = 1;
        for (auto &v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            w = w * (dp[v][0] + dp[v][1]) % MOD;
            b = b * dp[v][1] % MOD;
        }
        dp[u][0] = b;
        dp[u][1] = w;
    };

    dfs(0, -1);

    cout << (dp[0][0] + dp[0][1]) % MOD << endl;

    return 0;
}