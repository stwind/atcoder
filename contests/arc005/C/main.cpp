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

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct node
{
    int x, y, d;
};

int main()
{
    IOS;
    int H, W;
    cin >> H >> W;
    vector<vector<char>> G(H, vector<char>(W));
    int sx, sy, gx, gy;
    forn(i, 0, H) forn(j, 0, W)
    {
        cin >> G[i][j];
        if (G[i][j] == 's')
            sx = i, sy = j;
        if (G[i][j] == 'g')
            gx = i, gy = j;
    }

    auto enc = [&](int x, int y, int d) { return x * W * 3 + y * 3 + d; };

    queue<node> q({{sx, sy, 2}});
    unordered_set<int> seen({enc(sx, sy, 2)});

    while (!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        if (x == gx && y == gy)
        {
            cout << "YES" << endl;
            return 0;
        }
        forn(i, 0, 4)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || H <= xx || yy < 0 || W <= yy)
                continue;
            if (G[xx][yy] == '#')
            {
                if (d > 0 && !seen.count(enc(xx, yy, d - 1)))
                {
                    seen.insert(enc(xx, yy, d - 1));
                    q.push({xx, yy, d - 1});
                }
            }
            else if (!seen.count(enc(xx, yy, d)))
            {
                seen.insert(enc(xx, yy, d));
                q.push({xx, yy, d});
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}