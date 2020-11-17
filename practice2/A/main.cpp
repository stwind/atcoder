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

class UF
{
    int n;

public:
    VI par, rank, cnt;
    UF(int n) : n(n)
    {
        par = rank = VI(n, 0);
        cnt = VI(n, 1);
        forn(i, 0, n) par[i] = i;
    }
    void reset()
    {
        forn(i, 0, n) rank[i] = 0, cnt[i] = 1, par[i] = i;
    }
    int operator[](int x) { return (par[x] == x) ? (x) : (par[x] = operator[](par[x])); }
    int count(int x) { return cnt[operator[](x)]; }
    bool connected(int x, int y) { return operator[](x) == operator[](y); }
    int operator()(int x, int y)
    {
        if ((x = operator[](x)) == (y = operator[](y)))
            return x;
        cnt[y] = cnt[x] = cnt[x] + cnt[y];
        if (rank[x] > rank[y])
            return par[x] = y;
        rank[x] += rank[x] == rank[y];
        return par[y] = x;
    }
};

int main()
{
    IOS;
    int N, Q;
    cin >> N >> Q;

    UF uf(N);
    int t, u, v;
    forn(i, 0, Q)
    {
        cin >> t >> u >> v;
        if (t == 0)
        {
            uf(u, v);
        }
        else
        {
            cout << uf.connected(u, v) << endl;
        }
    }

    return 0;
}