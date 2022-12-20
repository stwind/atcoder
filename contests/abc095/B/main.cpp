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
    int N, X;
    cin >> N >> X;
    VI M(N);
    forn(i, 0, N) cin >> M[i];

    int m = 1001;
    forn(i, 0, N)
    {
        X -= M[i];
        m = min(m, M[i]);
    }

    cout << N + X / m << endl;

    return 0;
}