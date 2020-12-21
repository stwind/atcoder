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
    int H, W;
    cin >> H >> W;
    VVI C(10, VI(10, 0));
    forn(i, 0, 10) forn(j, 0, 10) cin >> C[i][j];
    VVI A(H, VI(W));
    forn(i, 0, H) forn(j, 0, W) cin >> A[i][j];

    forn(k, 0, 10) forn(i, 0, 10) forn(j, 0, 10)
        chmin(C[i][j], C[i][k] + C[k][j]);

    int res = 0;
    forn(i, 0, H) forn(j, 0, W) if (A[i][j] >= 0) res += C[A[i][j]][1];
    cout << res << endl;

    return 0;
}