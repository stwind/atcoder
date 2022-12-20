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

    for (int a = sqrt(N); a >= 1; a--)
    {
        if (N % a == 0)
        {
            int x = N / a;
            int res = 0;
            while (x)
                res += 1, x /= 10;
            cout << res << endl;
            return 0;
        }
    }

    return 0;
}