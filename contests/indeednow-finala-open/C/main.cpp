#include <bits/stdc++.h>
#include <math.h>
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
using PII = pair<int, int>;

int main()
{
    IOS;
    int N, M;
    cin >> N >> M;
    VI A(N), B(N), C(N), W(N), X(M), Y(M), Z(M);
    forn(i, 0, N) cin >> A[i] >> B[i] >> C[i] >> W[i];
    forn(i, 0, M) cin >> X[i] >> Y[i] >> Z[i];

    vector<VVI> dp(102, VVI(102, VI(102, 0)));

    forn(i, 0, N) chmax(dp[A[i]][B[i]][C[i]], W[i]);
    forn(i, 0, 101) forn(j, 0, 101) forn(k, 0, 101)
    {
        chmax(dp[i + 1][j][k], dp[i][j][k]);
        chmax(dp[i][j + 1][k], dp[i][j][k]);
        chmax(dp[i][j][k + 1], dp[i][j][k]);
    }
    forn(i, 0, M)
    {
        cout << dp[X[i]][Y[i]][Z[i]] << endl;
    }

    return 0;
}