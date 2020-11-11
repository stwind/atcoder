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

    string S, T;
    cin >> S >> T;

    sort(S.begin(), S.end());
    sort(T.begin(), T.end(), greater<char>());

    cout << (S < T ? "Yes" : "No") << endl;

    return 0;
}
