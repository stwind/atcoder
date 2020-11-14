#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    IOS;
    int K, S;
    cin >> K >> S;

    int res = 0;
    forn(x, 0, K + 1)
    {
        forn(y, 0, K + 1)
        {
            int z = S - x - y;
            if (0 <= z && z <= K)
                res += 1;
        }
    }
    cout << res << endl;

    return 0;
}