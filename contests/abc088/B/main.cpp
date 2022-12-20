#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(v) v.begin(), v.end()
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
    sort(all(A), greater<int>());

    int res = 0;
    forn(i, 0, N)
    {
        if (i % 2 == 0)
            res += A[i];
        else
            res -= A[i];
    }
    cout << res << endl;

    return 0;
}
