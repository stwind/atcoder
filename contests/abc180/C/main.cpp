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

    LL N;
    cin >> N;

    set<LL> d;
    for (LL i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            d.insert(i);
            d.insert(N / i);
        }
    }
    for (auto x : d)
        cout << x << endl;

    return 0;
}
