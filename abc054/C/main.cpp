#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
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
    int a, b;
    VVI G(N + 1, VI(N + 1, 0));
    forn(i, 0, M)
    {
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }

    unordered_set<int> seen = {1};

    function<int(int)> dfs = [&](int u) {
        if ((int)seen.size() == N)
            return 1;

        int res = 0;
        forn(v, 1, N + 1)
        {
            if (u == v || seen.count(v) || G[u][v] == 0)
                continue;

            seen.insert(v);
            res += dfs(v);
            seen.erase(v);
        }
        return res;
    };

    cout << dfs(1) << endl;

    return 0;
}