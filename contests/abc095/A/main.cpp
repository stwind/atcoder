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
    IOS;

    string S;
    cin >> S;

    int res = 700;
    for (auto c : S)
        res += c == 'o' ? 100 : 0;
    cout << res << endl;

    return 0;
}
