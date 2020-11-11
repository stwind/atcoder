#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

LL X, Y, A, B;

int main()
{
    IOS;

    cin >> X >> Y >> A >> B;

    LL res = 0;
    while (X <= (X + B) / A && X < Y / A)
    {
        X *= A;
        res++;
    }

    cout << res + (Y - 1 - X) / B << endl;

    return 0;
}
