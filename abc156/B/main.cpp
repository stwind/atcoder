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
    int N, K;
    cin >> N >> K;

    int res = 0;
    int k = K;
    while (N)
    {
        res++;
        N -= (N % k);
        k *= K;
    }
    cout << res << endl;

    return 0;
}