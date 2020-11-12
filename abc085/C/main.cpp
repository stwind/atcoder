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
using VLL = vector<LL>;

int main()
{
    int N, Y;
    cin >> N >> Y;

    forn(i, 0, N + 1)
    {
        if (10000 * i > Y)
            break;

        forn(j, 0, N - i + 1)
        {
            if (10000 * i + 5000 * j > Y)
                break;
            if (10000 * i + 5000 * j + 1000 * (N - i - j) == Y)
            {
                printf("%d %d %d\n", i, j, N - i - j);
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;

    return 0;
}