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
    VVI C(3, VI(3, 0));
    forn(i, 0, 3) forn(j, 0, 3) cin >> C[i][j];

    forn(i, 1, 3)
    {
        forn(j, 0, i)
        {
            int a = C[i][0] - C[j][0], b = C[i][1] - C[j][1], c = C[i][2] - C[j][2];
            if (a != b || b != c || a != c)
            {
                cout << "No" << endl;
                return 0;
            }
            int d = C[0][i] - C[0][j], e = C[1][i] - C[1][j], f = C[2][i] - C[2][j];
            if (d != e || e != f || d != f)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}