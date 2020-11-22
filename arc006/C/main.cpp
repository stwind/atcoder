#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N;
    cin >> N;
    VI W(N);
    forn(i, 0, N) cin >> W[i];

    VI stks(N, INT_MAX);

    forn(i, 0, N)
    {
        int diff = INT_MAX, best = 0;
        for (int j = 0; j < N; j++)
        {
            if (W[i] <= stks[j] && (stks[j] - W[i]) < diff)
            {
                diff = stks[j] - W[i];
                best = j;
            }
        }
        stks[best] = W[i];
    }

    int res = 0;
    forn(i, 0, N)
    {
        if (stks[i] < INT_MAX)
            res++;
    }
    cout << res << endl;

    return 0;
}