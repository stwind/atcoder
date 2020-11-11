#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(v) v.begin(), v.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    int res = 0;
    forn(i, 1, N + 1)
    {
        int x = i, s = 0;
        while (x)
        {
            s += x % 10;
            x /= 10;
        }
        if (A <= s && s <= B)
            res += i;
    }
    cout << res << endl;

    return 0;
}