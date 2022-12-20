#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for (int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(v) v.begin(), v.end()
// clang-format on

using VI = vector<int>;

template <int n>
class UF
{
public:
    vector<int> par, rank, cnt;
    UF()
    {
        par = rank = vector<int>(n, 0);
        cnt = vector<int>(n, 1);
        forn(i, 0, n) par[i] = i;
    }
    void reset()
    {
        forn(i, 0, n) rank[i] = 0, cnt[i] = 1, par[i] = i;
    }
    int operator[](int x) { return (par[x] == x) ? (x) : (par[x] = operator[](par[x])); }
    int count(int x) { return cnt[operator[](x)]; }
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

int N;
int X[100], Y[100];

struct edge
{
    int u, v;
    double w;
};

int main()
{
    IOS;
    cin >> N;
    forn(i, 0, N) cin >> X[i] >> Y[i];

    vector<edge> edges;
    forn(i, 0, N)
    {
        edges.push_back({i, 100, 100.0 - Y[i]});
        edges.push_back({i, 101, Y[i] + 100.0});
        forn(j, 0, N)
            edges.push_back({i, j, hypot(X[i] - X[j], Y[i] - Y[j])});
    }
    sort(all(edges), [](edge a, edge b) {
        return a.w < b.w;
    });

    UF<102> uf;
    int n = edges.size();
    double res = 0.0;
    forn(i, 0, n)
    {
        auto &[u, v, w] = edges[i];
        uf(u, v);
        if (uf[100] == uf[101])
        {
            res = w / 2;
            break;
        }
    }

    cout << fixed << setprecision(10) << res << endl;

    return 0;
}
