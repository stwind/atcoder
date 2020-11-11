#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    int N, D;
    cin >> N >> D;
    VVI X(N, VI(D, 0));
    forn(i, 0, N) forn(j, 0, D) cin >> X[i][j];

    int res = 0;
    forn(i, 0, N)
    {
        forn(j, i + 1, N)
        {
            double par = 0;
            forn(k, 0, D) par += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
            par = sqrt(par);
            if (par == floor(par))
                res++;
        }
    }

    cout << res << endl;

    return 0;
}