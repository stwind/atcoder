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
    int N;
    cin >> N;

    int a, n = 0;
    forn(i, 0, N)
    {
        cin >> a;
        n += a % 2;
    }

    cout << (n % 2 == 0 ? "YES" : "NO") << endl;

    return 0;
}