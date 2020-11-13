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

int main()
{
    IOS;
    int D, G;
    cin >> D >> G;
    VI P(D), C(D);
    forn(i, 0, D) cin >> P[i] >> C[i];

    int res = 10001;
    forn(s, 0, 1 << D)
    {
        int score = 0, cnt = 0;
        forn(i, 0, D)
        {
            if (s & (1 << i))
            {
                score += P[i] * (i + 1) * 100 + C[i];
                cnt += P[i];
            }
        }
        int j = D - 1;
        while (score < G && j >= 0)
        {
            if (!(s & (1 << j)))
            {
                int diff = G - score;
                int c = min(P[j] - 1, (int)ceil(diff / ((j + 1) * 100)));
                cnt += c;
                score += c * (j + 1) * 100;
            }
            j--;
        }
        if (score >= G && cnt < res)
            res = cnt;
    }
    cout << res << endl;

    return 0;
}