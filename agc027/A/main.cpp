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
    int N, X;
    cin >> N >> X;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    sort(all(A));

    int i = 0;
    while (i < N && X >= A[i])
        X -= A[i++];
    if (X > 0 && i == N)
        i -= 1;

    cout << i << endl;

    return 0;
}