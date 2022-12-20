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
using PII = pair<int, int>;

int main()
{
    IOS;
    int N;
    cin >> N;
    vector<PII> R, G;
    int x, y;
    forn(i, 0, N)
    {
        cin >> x >> y;
        R.push_back({x, y});
    }
    forn(i, 0, N)
    {
        cin >> x >> y;
        G.push_back({x, y});
    }

    sort(all(G), [](PII a, PII b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    VI matched(N, 0);

    int res = 0;

    forn(i, 0, N)
    {
        int best = -1, y = INT_MIN;
        forn(j, 0, N)
        {
            int dx = G[i].first - R[j].first, dy = G[i].second - R[j].second;
            if (dx > 0 && dy > 0 && !matched[j] && R[j].second > y)
            {
                y = R[j].second;
                best = j;
            }
        }
        if (best >= 0)
        {
            matched[best] = 1;
            res++;
        }
    }

    cout << res << endl;

    return 0;
}