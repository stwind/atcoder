#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    forn(i, 0, H) cin >> S[i];

    forn(i, 0, H) forn(j, 0, W)
    {
        if (S[i][j] == '.')
            continue;

        if (i > 0 && S[i - 1][j] == '#')
            continue;
        if (i < H - 1 && S[i + 1][j] == '#')
            continue;
        if (j > 0 && S[i][j - 1] == '#')
            continue;
        if (j < W - 1 && S[i][j + 1] == '#')
            continue;

        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    return 0;
}