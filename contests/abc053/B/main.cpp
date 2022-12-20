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

    int n = S.size();
    int a = n, z = 0;
    forn(i, 0, n)
    {
        if (S[i] == 'A')
            a = min(a, i);
        if (S[i] == 'Z')
            z = max(z, i);
    }

    cout << z - a + 1 << endl;

    return 0;
}