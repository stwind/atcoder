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

template <class T>
struct FenwickTree
{
    int _n;
    vector<T> data;

    T sum(int r)
    {
        T s = 0;
        for (; r > 0; r -= r & -r)
            s += data[r - 1];

        return s;
    }

public:
    FenwickTree(int n) : _n(n), data(n, 0) {}

    void add(int p, T x)
    {
        assert(0 <= p && p < _n);
        for (p++; p <= _n; p += p & -p)
            data[p - 1] += x;
    }

    T sum(int l, int r)
    {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }
};

int main()
{
    IOS;
    int N, Q;
    cin >> N >> Q;

    FenwickTree<LL> ft(N);
    int a;
    forn(i, 0, N)
    {
        cin >> a;
        ft.add(i, a);
    }
    int t, l, r;
    forn(i, 0, Q)
    {
        cin >> t >> l >> r;
        if (t == 0)
        {
            ft.add(l, r);
        }
        else
        {
            cout << ft.sum(l, r) << endl;
        }
    }

    return 0;
}