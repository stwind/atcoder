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
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;
    vector<char> T(Q), D(Q);
    forn(i, 0, Q) cin >> T[i] >> D[i];

    auto check = [&](int x) {
        forn(i, 0, Q)
        {
            if (T[i] != S[x])
                continue;
            if (D[i] == 'L')
                x--;
            else
                x++;

            if (N <= x)
                return 1;
            if (x < 0)
                return -1;
        }
        return 0;
    };
    int l = -1, r = N;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (check(m) == -1)
            l = m;
        else
            r = m;
    }

    int left = r;
    l = -1, r = N;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (check(m) == 1)
            r = m;
        else
            l = m;
    }

    int right = N - r;
    cout << max(N - left - right, 0) << endl;

    return 0;
}