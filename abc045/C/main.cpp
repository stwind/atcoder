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
    string S;
    cin >> S;

    int n = S.size() - 1;
    LL res = 0;
    forn(s, 0, 1 << n)
    {
        LL sum = 0, cur = S[0] - '0';
        forn(i, 0, n)
        {
            if (s & (1 << i))
            {
                sum += cur;
                cur = S[i + 1] - '0';
            }
            else
            {
                cur = cur * 10 + (S[i + 1] - '0');
            }
        }
        res += sum + cur;
    }
    cout << res << endl;

    return 0;
}