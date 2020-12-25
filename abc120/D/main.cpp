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

class UnionFind
{
    int n;

public:
    VI par, rank, cnt;
    UnionFind(int n) : n(n)
    {
        par = rank = VI(n, 0);
        cnt = VI(n, 1);
        forn(i, 0, n) par[i] = i;
    }
    void reset() { forn(i, 0, n) rank[i] = 0, cnt[i] = 1, par[i] = i; }
    int find(int x) { return (par[x] == x) ? (x) : (par[x] = find(par[x])); }
    int unite(int x, int y)
    {
        if ((x = find(x)) == (y = find(y)))
            return x;
        cnt[y] = cnt[x] = cnt[x] + cnt[y];
        if (rank[x] > rank[y])
            return par[x] = y;
        rank[x] += rank[x] == rank[y];
        return par[y] = x;
    }
    int count(int x) { return cnt[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

int main()
{
    IOS;
    int N, M;
    cin >> N >> M;
    VI A(M), B(M);
    forn(i, 0, M)
    {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    LL c = (LL)N * (N - 1) / 2;
    UnionFind uf(N);
    VLL res(M + 1);
    res[M] = c;

    for (int i = M - 1; i >= 0; i--)
    {
        if (!uf.same(A[i], B[i]))
        {
            c -= uf.count(A[i]) * uf.count(B[i]);
        }
        res[i] = c;
        uf.unite(A[i], B[i]);
    }
    forn(i, 1, M + 1)
    {
        cout << res[i] << endl;
    }

    return 0;
}