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
    int N;
    double T, A;
    cin >> N >> T >> A;
    VI H(N);
    forn(i, 0, N) cin >> H[i];

    int res = 0;
    forn(i, 1, N)
    {
        double a = abs(T - H[i] * 0.006 - A);
        double b = abs(T - H[res] * 0.006 - A);
        if (a < b)
            res = i;
    }
    cout << res + 1 << endl;

    return 0;
}