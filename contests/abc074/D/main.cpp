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
    int N;
    cin >> N;
    VVI A(N, VI(N));
    forn(i, 0, N) forn(j, 0, N) cin >> A[i][j];

    VVI C(N, VI(N, 1));
    forn(i, 0, N) forn(j, i + 1, N)
    {
        forn(k, 0, N)
        {
            if (k == i || k == j)
                continue;

            int d = A[i][k] + A[k][j];
            if (d < A[i][j])
            {
                cout << -1 << endl;
                return 0;
            }
            if (d == A[i][j])
            {
                C[i][j] = 0;
                break;
            }
        }
    }

    LL res = 0;
    forn(i, 0, N) forn(j, i + 1, N) if (C[i][j]) res += A[i][j];
    cout << res << endl;

    return 0;
}