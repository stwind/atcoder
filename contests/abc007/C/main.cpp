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
    int R, C;
    int sx, sy, gx, gy;
    cin >> R >> C;
    cin >> sx >> sy >> gx >> gy;
    sx--, sy--, gx--, gy--;
    vector<string> G(R);
    forn(i, 0, R) cin >> G[i];

    queue<node> q;
    q.push({sx, sy, 0});
    unordered_set<int> seen({sx * R + sy});

    while (!q.empty())
    {
        auto [x, y, d] = q.front();
        q.pop();
        if (x == gx && y == gy)
        {
            cout << d << endl;
            return 0;
        }

        forn(i, 0, 4)
        {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx < 0 || R <= xx || yy < 0 || C <= y || G[xx][yy] == '#' || seen.count(xx * R + yy))
                continue;
            seen.insert(xx * R + yy);
            q.push({xx, yy, d + 1});
        }
    }

    return 0;
}