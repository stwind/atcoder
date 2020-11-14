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

struct node
{
    int x, y;
};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    IOS;
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    forn(i, 0, H) cin >> S[i];

    VVI dist(H, VI(W, INT_MAX));
    dist[0][0] = 1;

    queue<node> q({{0, 0}});
    while (!q.empty())
    {
        auto [i, j] = q.front();
        if (i == H - 1 && j == W - 1)
            break;

        q.pop();
        forn(k, 0, 4)
        {
            int ii = i + dx[k], jj = j + dy[k];
            if (0 <= ii && ii < H && 0 <= jj && jj < W && S[ii][jj] == '.' && dist[ii][jj] == INT_MAX)
            {
                dist[ii][jj] = dist[i][j] + 1;
                q.push({ii, jj});
            }
        }
    }
    if (dist[H - 1][W - 1] == INT_MAX)
    {
        cout << -1 << endl;
        return 0;
    }

    int white = 0;
    forn(i, 0, H) forn(j, 0, W)
    {
        if (S[i][j] == '.')
            white++;
    }
    cout << white - dist[H - 1][W - 1] << endl;

    return 0;
}