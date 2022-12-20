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
    int N, M;
    cin >> N >> M;
    vector<PII> I(M);
    int a, b;
    forn(i, 0, M)
    {
        cin >> a >> b;
        I[i] = make_pair(a, b);
    }
    sort(ALL(I), [](PII a, PII b) { return a.second < b.second; });

    int res = 0, cur = 0;
    forn(i, 0, M)
    {
        if (I[i].first >= cur)
        {
            res++;
            cur = I[i].second;
        }
        else
        {
            cur = min(cur, I[i].second);
        }
    }
    cout << res << endl;

    return 0;
}