// https://pekempey.hatenablog.com/entry/2016/05/29/132404

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
using PII = pair<int, int>;

int main()
{
    IOS;
    int N;
    cin >> N;
    vector<PII> S(N);
    int w, h;
    forn(i, 0, N)
    {
        cin >> w >> h;
        S[i] = make_pair(w, h);
    }
    sort(ALL(S), [](PII a, PII b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    VI dp(N + 1, INT_MAX);
    int res = 0;
    forn(i, 0, N)
    {
        int l = 0, r = N + 1, m;
        while (r - l > 1)
        {
            m = (l + r) / 2;
            if (dp[m] < S[i].second)
                l = m;
            else
                r = m;
        }
        dp[r] = S[i].second;
        res = max(res, r);
    }
    cout << res << endl;

    return 0;
}