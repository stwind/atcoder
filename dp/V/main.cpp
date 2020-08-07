#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

int N, M;
VI adj[101010];
LL dp[101010];
LL ans[101010];

void dfs1(int u, int p = 0) {
    dp[u] = 1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        dp[u] *= dp[v] + 1;
        dp[u] %= M;
    }
}

void dfs2(int u, int p = 0) {
    ans[u] = 1;
    for (auto v : adj[u])
        ans[u] = ans[u] * (dp[v] + 1) % M;

    int n = adj[u].size();
    VLL left(n), right(n);
    forn(i, 0, n) left[i] = right[i] = dp[adj[u][i]] + 1;
    forn(i, 1, n) left[i] = left[i] * left[i-1] % M;
    for (int i = n - 2; i >= 0; i--)
        right[i] = right[i] * right[i+1] % M;

    forn(i, 0, n) {
        int v = adj[u][i];
        if (v == p) continue;
        dp[u] = 1;
        if (i) dp[u] = dp[u] * left[i-1] % M;
        if (i < n - 1) dp[u] = dp[u] * right[i+1] % M;
        dfs2(v, u);
    }
}

int main() {
    IOS;

    cin >> N >> M;
    int x, y;
    forn(i, 0, N - 1) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs1(1);
    dfs2(1);

    for (int i = 1; i <= N; i++)
        cout << ans[i] << endl;

    return 0;
}
