#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(v) v.begin(), v.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    int N;
    cin >> N;
    VI L(N);
    forn(i, 0, N) cin >> L[i];
    sort(all(L));

    int res = 0;
    forn(i, 0, N)
    {
        forn(j, i + 1, N)
        {
            if (L[i] == L[j])
                continue;
            forn(k, j + 1, N)
            {
                if (L[j] == L[k])
                    continue;
                if (L[i] + L[j] > L[k])
                    res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}