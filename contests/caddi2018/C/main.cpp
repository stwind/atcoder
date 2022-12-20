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

map<LL, int> enumpr(LL n)
{
    map<LL, int> V;
    for (LL i = 2; i * i <= n; i++)
        while (n % i == 0)
            V[i]++, n /= i;
    if (n > 1)
        V[n]++;
    return V;
}

LL fastpow(LL x, LL n)
{
    LL ret = 1;
    while (n > 0)
    {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

int main()
{
    IOS;
    LL N, P;
    cin >> N >> P;

    map<LL, int> pr = enumpr(P);
    LL res = 1;
    for (auto p : pr)
        res *= fastpow(p.first, p.second / N);

    cout << res << endl;

    return 0;
}