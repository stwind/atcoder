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
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
  (byte & 0x010 ? '1' : '0'), \
  (byte & 0x008 ? '1' : '0'), \
  (byte & 0x004 ? '1' : '0'), \
  (byte & 0x002 ? '1' : '0'), \
  (byte & 0x001 ? '1' : '0')
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
    VI G(N, 0);
    int x, y;
    forn(i, 0, M)
    {
        cin >> x >> y;
        x--, y--;
        G[x] |= (1 << x) | (1 << y);
        G[y] |= (1 << x) | (1 << y);
    }

    int res = 1;
    forn(s, 0, 1 << N)
    {
        int t = (1 << N) - 1;
        forn(i, 0, N)
        {
            if (!(s & (1 << i)))
                continue;

            t &= G[i];
        }

        if (s == t)
            res = max(res, __builtin_popcount(s));
    }
    cout << res << endl;

    return 0;
}