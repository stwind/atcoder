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
    int N;
    cin >> N;

    int res = -1, mx = -1;
    forn(i, 1, N + 1)
    {
        int x = i, cnt = 0;
        while (x % 2 == 0)
            x /= 2, cnt++;
        if (cnt > mx)
            res = i, mx = cnt;
    }

    cout << res << endl;

    return 0;
}