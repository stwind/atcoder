#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define ALL(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define MOD 1000000007
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    IOS;
    int N, M;
    cin >> N >> M;
    VI F(N);
    forn(i, 0, N) cin >> F[i];

    VLL dp(N + 1, 0), cum(N + 2, 0);
    dp[0] = cum[1] = 1;

    unordered_map<int, int> seen;
    int m = 0;
    for (int i = 0, j = 0; i < N; i++)
    {
        m = max(m, ++seen[F[i]]);
        while (m > 1)
        {
            if (seen[F[j]] == m)
                m--;
            seen[F[j++]]--;
        }

        dp[i + 1] = sub(cum[i + 1], cum[j]);
        cum[i + 2] = add(cum[i + 1], dp[i + 1]);
    }

    cout << dp[N] << endl;

    return 0;
}