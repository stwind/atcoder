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
    int N;
    cin >> N;

    int x = 0;
    while (x <= N)
    {
        if ((N - x) % 7 == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
        x += 4;
    }
    cout << "No" << endl;

    return 0;
}