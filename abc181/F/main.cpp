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

bool check(double r)
{
    UF<102> uf;
    forn(i, 0, N)
    {
        if (Y[i] - 2 * r < -100)
            uf(100, i);
        if (Y[i] + 2 * r > 100)
            uf(101, i);
    }

    forn(i, 0, N) forn(j, 0, N)
    {
        if (hypot(X[i] - X[j], Y[i] - Y[j]) < 2 * r)
            uf(i, j);
    }
    return uf[100] != uf[101];
}

int main()
{
    IOS;
    cin >> N;
    forn(i, 0, N) cin >> X[i] >> Y[i];

    double l = 0.0, r = 100.0, m;
    forn(i, 0, 100)
    {
        m = (l + r) / 2;
        if (check(m))
            l = m;
        else
            r = m;
    }
    cout << fixed << setprecision(10) << l << endl;

    return 0;
}
