#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(v)              v.begin(), v.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    IOS;

    int N;
    cin >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    int res = 0;
    while (true)
    {
        for (auto &x : A)
        {
            if (x % 2 == 0)
                x /= 2;
            else
            {
                cout << res << endl;
                return 0;
            }
        }
        res++;
    }

    return 0;
}
