// https://qiita.com/HNJ/items/564f15316719209df73c

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

LL floorSum(LL n, LL m, LL a, LL b)
{
    LL res = 0;
    if (b >= m)
    {
        res += n * (b / m);
        b %= m;
    }
    if (a >= m)
    {
        res += n * (n - 1) * (a / m) / 2;
        a %= m;
    }

    LL ymax = (a * n + b) / m, xmax = m * ymax - b;
    if (ymax == 0)
        return res;
    res += (n - (xmax + a - 1) / a) * ymax;
    res += floorSum(ymax, a, m, (a - xmax % a) % a);
    return res;
}

int main()
{
    IOS;
    int T;
    cin >> T;
    VI N(T), M(T), A(T), B(T);
    forn(i, 0, T) cin >> N[i] >> M[i] >> A[i] >> B[i];

    forn(i, 0, T)
    {
        cout << floorSum(N[i], M[i], A[i], B[i]) << endl;
    }

    return 0;
}