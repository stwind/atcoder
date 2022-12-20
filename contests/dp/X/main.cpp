#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
#define all(s) (s).begin(),(s).end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

struct value
{
    int w, s, v;
};

int main()
{
    IOS;
    int N;
    cin >> N;

    vector<value> X;
    int w, s, v;
    forn(i, 0, N)
    {
        cin >> w >> s >> v;
        X.push_back({w, s, v});
    }

    sort(all(X), [](value a, value b) {
        return a.w + a.s < b.w + b.s;
    });

    int maxW = 20000;

    VLL dp(maxW + 1, 0);
    forn(i, 0, N)
    {
        for (int j = X[i].s; j >= 0; j--)
        {
            chmax(dp[j + X[i].w], X[i].v + dp[j]);
        }
    }

    cout << *max_element(all(dp)) << endl;

    return 0;
}
