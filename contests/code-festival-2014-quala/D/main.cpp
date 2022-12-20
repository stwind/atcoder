#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a -= MOD; }
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
    string A;
    int K;
    cin >> A >> K;

    int n = A.length();

    LL res = LONG_MAX;
    forn(i, 0, n)
    {
        for (char c = '0'; c <= '9'; c++)
        {
            for (char d = '0'; d <= '9'; d++)
            {
                LL val = stoll(A.substr(0, i) + c + string(n - i - 1, d));
                string s = to_string(val);
                if (int(set<char>(all(s)).size()) <= K)
                {
                    res = min(res, abs(stoll(A) - val));
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}