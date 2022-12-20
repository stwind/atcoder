#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(v) v.begin(), v.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    int N;
    cin >> N;

    auto sum = [](int x) {
        int res = 0;
        while (x)
            res += x % 10, x /= 10;
        return res;
    };

    int res = 100;
    forn(a, 1, N / 2 + 1)
        res = min(res, sum(a) + sum(N - a));
    cout << res << endl;

    return 0;
}