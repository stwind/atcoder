#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    string S, T;
    cin >> S >> T;

    int m = S.length();
    VVI C(26, VI(m * 2, -1));
    forn(i, 0, 26)
    {
        for (int j = m * 2 - 2; j >= 0; j--)
        {
            C[i][j] = C[i][j + 1];
            if (S[j % m] == i + 'a')
                C[i][j] = j;
        }
    }

    LL j = 0;
    for (auto c : T)
    {
        int k = j % m;
        if (C[c - 'a'][k] == -1)
        {
            cout << -1 << endl;
            return 0;
        }
        else
        {
            j += C[c - 'a'][k] - k;
        }
        j++;
    }
    cout << j << endl;

    return 0;
}