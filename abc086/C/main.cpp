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
    VI T(N), X(N), Y(N);
    forn(i, 0, N) cin >> T[i] >> X[i] >> Y[i];

    int x = 0, y = 0, t = 0;
    for (int i = 0; i < N; i++)
    {
        int dd = abs(X[i] - x) + abs(Y[i] - y);
        int dt = T[i] - t;
        if (dd > dt || dd % 2 != dt % 2)
        {
            cout << "No" << endl;
            return 0;
        }
        x = X[i], y = Y[i], t = T[i];
    }
    cout << "Yes" << endl;

    return 0;
}