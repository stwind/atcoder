#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    IOS;
    int N;
    cin >> N;
    VVI A(2, VI(N));
    forn(i, 0, 2) forn(j, 0, N) cin >> A[i][j];

    VI C1(N + 1, 0), C2(N + 1, 0);
    forn(i, 0, N)
    {
        C1[i + 1] += C1[i] + A[0][i];
        C2[i + 1] += C2[i] + A[1][i];
    }

    int res = 0;
    forn(i, 1, N + 1)
    {
        res = max(res, C1[i] - C1[0] + C2[N] - C2[i - 1]);
    }
    cout << res << endl;

    return 0;
}