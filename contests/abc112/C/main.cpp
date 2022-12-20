#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define printVector(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define all(s) s.begin(), s.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    LL N;
    cin >> N;
    VI X(N), Y(N), H(N);
    int pos;
    forn(i, 0, N)
    {
        cin >> X[i] >> Y[i] >> H[i];

        if (H[i])
            pos = i;
    }

    forn(x, 0, 101) forn(y, 0, 101)
    {
        int h = H[pos] + abs(x - X[pos]) + abs(y - Y[pos]);
        bool good = true;
        for (int i = 0; i < N; i++)
        {
            if (max(h - abs(X[i] - x) - abs(Y[i] - y), 0) != H[i])
            {
                good = false;
                break;
            }
        }

        if (good)
        {
            printf("%d %d %d\n", x, y, h);
            return 0;
        }
    }

    return 0;
}