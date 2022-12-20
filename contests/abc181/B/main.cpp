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
    vector<LL> A(N), B(N);
    forn(i, 0, N) cin >> A[i] >> B[i];

    LL res = 0;
    forn(i, 0, N)
    {
        res += (B[i] * (B[i] + 1) - A[i] * (A[i] - 1)) / 2;
    }
    cout << res << endl;

    return 0;
}
