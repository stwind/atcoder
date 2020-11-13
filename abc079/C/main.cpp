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

    int a = S[0] - '0';
    forn(i, 0, 2) forn(j, 0, 2) forn(k, 0, 2)
    {
        int b = i == 0 ? 1 : -1;
        int c = j == 0 ? 1 : -1;
        int d = k == 0 ? 1 : -1;
        if (a + b * (S[1] - '0') + c * (S[2] - '0') + d * (S[3] - '0') == 7)
        {
            cout << S[0] << (i == 0 ? '+' : '-') << S[1] << (j == 0 ? '+' : '-') << S[2] << (k == 0 ? '+' : '-') << S[3] << "=7" << endl;
            return 0;
        }
    }

    return 0;
}