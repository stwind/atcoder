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
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int res = INT_MAX;
    int n = max(X, Y) * 2;
    for (int c = 0; c <= n; c += 2)
    {
        int a = max(0, X - c / 2), b = max(0, Y - c / 2);
        res = min(res, a * A + b * B + c * C);
    }
    cout << res << endl;

    return 0;
}