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
    string S;
    cin >> S;

    string res;
    int n = S.size();
    for (int i = 0; i < n; i += 2)
        res += S[i];

    cout << res << endl;

    return 0;
}