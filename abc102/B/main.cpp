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
    cin >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    int res = 0;
    forn(i, 0, N)
    {
        forn(j, i + 1, N)
        {
            res = max(res, abs(A[i] - A[j]));
        }
    }
    cout << res << endl;

    return 0;
}