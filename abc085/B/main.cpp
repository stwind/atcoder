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
    VI D(N);
    forn(i, 0, N) cin >> D[i];
    sort(all(D));

    int res = 1;
    forn(i, 1, N)
    {
        if (D[i] > D[i - 1])
            res++;
    }
    cout << res << endl;

    return 0;
}