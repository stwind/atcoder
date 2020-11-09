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
    IOS;

    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    forn(i, 0, N) cin >> X[i] >> Y[i];

    forn(i, 0, N)
    {
        forn(j, i + 1, N)
        {
            int x1 = X[j] - X[i], y1 = Y[j] - Y[i];
            forn(k, j + 1, N)
            {
                int x2 = X[k] - X[i], y2 = Y[k] - Y[i];
                if (y1 * x2 == y2 * x1)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
