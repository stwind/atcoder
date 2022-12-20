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

const LL MOD = 1000000007;

int main()
{
    LL A, B, X;
    cin >> A >> B >> X;

    LL a = (A + X - 1) / X;
    LL b = B / X;
    cout << (b - a + 1) << endl;

    return 0;
}