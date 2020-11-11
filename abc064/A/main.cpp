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

    int R, G, B;
    cin >> R >> G >> B;

    int x = R * 100 + G * 10 + B;
    cout << (x % 4 == 0 ? "YES" : "NO") << endl;

    return 0;
}
