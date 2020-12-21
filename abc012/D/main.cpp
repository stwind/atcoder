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

    int INF = 1000000000;
    VVI adj(N, VI(N, INF));
    forn(i, 0, N) adj[i][i] = 0;
    int a, b, t;
    forn(i, 0, M)
    {
        cin >> a >> b >> t;
        a--;
        b--;
        adj[a][b] = adj[b][a] = t;
    }

    forn(k, 0, N) forn(i, 0, N) forn(j, 0, N)
        chmin(adj[i][j], adj[i][k] + adj[k][j]);

    int res = INF;
    forn(i, 0, N) chmin(res, *max_element(all(adj[i])));
    cout << res << endl;

    return 0;
}