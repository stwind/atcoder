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
    int W, H, N;
    cin >> W >> H >> N;
    VI X(N), Y(N), A(N);
    forn(i, 0, N) cin >> X[i] >> Y[i] >> A[i];

    int l = 0, r = W, b = 0, t = H;
    forn(i, 0, N)
    {
        if (A[i] == 1)
            l = max(l, X[i]);
        else if (A[i] == 2)
            r = min(r, X[i]);
        else if (A[i] == 3)
            b = max(b, Y[i]);
        else
            t = min(t, Y[i]);
    }

    cout << max(0, r - l) * max(0, t - b) << endl;

    return 0;
}