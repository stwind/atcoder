#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    int N;
    cin >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    LL ans = LONG_MAX;
    for (int r = 0; r < 2; r++)
    {
        LL res = 0;
        LL cum = 0;
        forn(i, 0, N)
        {
            cum += A[i];
            if (i % 2 == r)
            {
                if (cum <= 0)
                {
                    int d = 1 - cum;
                    res += abs(d);
                    cum += d;
                }
            }
            else
            {
                if (cum >= 0)
                {
                    int d = -1 - cum;
                    res += abs(d);
                    cum += d;
                }
            }
        }
        ans = min(ans, res);
    }
    cout << ans << endl;

    return 0;
}