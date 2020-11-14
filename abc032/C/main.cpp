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
    int N, K;
    cin >> N >> K;
    VI S(N);
    forn(i, 0, N) cin >> S[i];

    LL cum = 1;
    int res = 0;
    for (int i = 0, j = 0; i < N; i++)
    {
        if (S[i] == 0)
        {
            cout << N << endl;
            return 0;
        }
        cum *= S[i];
        while (cum > K && j <= i)
            cum /= S[j++];
        res = max(res, i - j + 1);
    }
    cout << res << endl;

    return 0;
}