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
    vector<string> A(H);
    forn(i, 0, H) cin >> A[i];

    queue<node> q;
    forn(i, 0, H) forn(j, 0, W)
    {
        if (A[i][j] == '#')
            q.push({i, j});
    }

    int res = 0;
    while (!q.empty())
    {
        int n = q.size();
        forn(k, 0, n)
        {
            auto [i, j] = q.front();
            q.pop();
            forn(d, 0, 4)
            {
                int ii = i + dx[d], jj = j + dy[d];
                if (0 <= ii && ii < H && 0 <= jj && jj < W && A[ii][jj] == '.')
                {
                    A[ii][jj] = '#';
                    q.push({ii, jj});
                }
            }
        }
        if (q.empty())
        {
            cout << res << endl;
            return 0;
        }
        res++;
    }

    return 0;
}