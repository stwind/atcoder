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

int main()
{
    IOS;
    int N;
    cin >> N;
    VI T(N);
    forn(i, 0, N) cin >> T[i];

    int res = INT_MAX;
    forn(s, 0, 1 << N)
    {
        int sum[2] = {0, 0};
        forn(i, 0, N) sum[(s >> i) & 1] += T[i];

        res = min(res, max(sum[0], sum[1]));
    }
    cout << res << endl;

    return 0;
}