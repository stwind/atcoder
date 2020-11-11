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
    int A, B;
    cin >> A >> B;

    int res = 0;
    forn(x, A, B + 1)
    {
        int a = x % 10, d = x / 10000;
        int c = x / 1000 % 10, b = x / 10 % 10;
        if (a == d && b == c)
            res++;
    }
    cout << res << endl;

    return 0;
}