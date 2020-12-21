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
    int N, M, P, Q, R;
    cin >> N >> M >> P >> Q >> R;
    VI X(R), Y(R), Z(R);
    forn(i, 0, R)
    {
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;
        Y[i]--;
    }

    VI B(R, 0);
    int res = 0;
    forn(bit, 0, 1 << N)
    {
        if (__builtin_popcount(bit) != P)
            continue;

        fill(all(B), 0);
        forn(i, 0, R) if (bit & (1 << X[i]))
        {
            B[Y[i]] += Z[i];
        }
        sort(all(B), greater());
        int score = 0;
        forn(i, 0, Q) score += B[i];
        chmax(res, score);
    }

    cout << res << endl;

    return 0;
}