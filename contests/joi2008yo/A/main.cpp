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

    int x = 1000 - N;
    int res = 0;
    while (x)
    {
        res++;
        if (x >= 500)
            x -= 500;
        else if (x >= 100)
            x -= 100;
        else if (x >= 50)
            x -= 50;
        else if (x >= 10)
            x -= 10;
        else if (x >= 5)
            x -= 5;
        else if (x >= 1)
            x -= 1;
    }

    cout << res << endl;

    return 0;
}