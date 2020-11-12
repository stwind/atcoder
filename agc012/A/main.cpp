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
    VI A(N * 3);
    forn(i, 0, N * 3) cin >> A[i];

    sort(all(A));
    LL res = 0;
    for (int i = N; i < N * 3; i += 2)
        res += A[i];

    cout << res << endl;

    return 0;
}