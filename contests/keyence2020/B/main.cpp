#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N;
    cin >> N;
    int x, l;
    vector<PLL> R;
    forn(i, 0, N)
    {
        cin >> x >> l;
        R.push_back(make_pair(x - l, x + l));
    }
    sort(all(R), [](PLL a, PLL b) { return a.second < b.second; });

    int res = 0;
    LL cur = LONG_MIN;
    forn(i, 0, N)
    {
        if (R[i].first >= cur)
        {
            res++;
            cur = max(cur, R[i].second);
        }
    }
    cout << res << endl;

    return 0;
}