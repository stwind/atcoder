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
    string S, T;
    cin >> S >> T;

    int m = S.length(), n = T.length();
    for (int i = m - n; i >= 0; i--)
    {
        bool good = true;
        forn(j, 0, n)
        {
            if (S[i + j] != '?' && S[i + j] != T[j])
            {
                good = false;
                break;
            }
        }
        if (good)
        {
            S.replace(i, n, T);
            replace(all(S), '?', 'a');
            cout << S << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;

    return 0;
}