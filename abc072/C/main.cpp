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
    VI A(N);
    forn(i, 0, N) cin >> A[i];
    sort(all(A));

    int res = 0;
    for (int i = 0, j = 0; j < N; j++)
    {
        while (i < j && A[j] - A[i] > 2)
            i++;
        res = max(res, j - i + 1);
    }
    cout << res << endl;

    return 0;
}