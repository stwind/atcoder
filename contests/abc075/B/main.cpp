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

    forn(i, 0, H)
    {
        string res;
        forn(j, 0, W)
        {
            if (S[i][j] == '#')
            {
                res += '#';
                continue;
            }

            int n = 0;
            if (i > 0)
            {
                if (j > 0 && S[i - 1][j - 1] == '#')
                    n += 1;
                if (j < W - 1 && S[i - 1][j + 1] == '#')
                    n += 1;
                if (S[i - 1][j] == '#')
                    n += 1;
            }
            if (j > 0 && S[i][j - 1] == '#')
                n += 1;
            if (j < W - 1 && S[i][j + 1] == '#')
                n += 1;
            if (i < H - 1)
            {
                if (j > 0 && S[i + 1][j - 1] == '#')
                    n += 1;
                if (j < W - 1 && S[i + 1][j + 1] == '#')
                    n += 1;
                if (S[i + 1][j] == '#')
                    n += 1;
            }
            res += to_string(n);
        }
        cout << res << endl;
    }

    return 0;
}