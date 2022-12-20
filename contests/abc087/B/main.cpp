#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int res = 0;
    forn(i, 0, A + 1)
    {
        forn(j, 0, B + 1)
        {
            forn(k, 0, C + 1)
            {
                if (i * 500 + j * 100 + k * 50 == X)
                    res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}