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
    int A, B, C;
    cin >> A >> B >> C;

    int m = max(A, max(B, C));
    int r = m - A + m - B + m - C;
    if (r % 2 == 1)
        r += 3;
    r /= 2;
    cout << r << endl;

    return 0;
}