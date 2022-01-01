#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main() {
  IOS;
  int M, R;
  cin >> M >> R;

  int keys[4][3] = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}, {0, -1, -1}};
  int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
  int dist[4][3][100010];
  REP(i, 0, 4) REP(j, 0, 3) REP(m, 0, M) dist[i][j][m] = INF;
  dist[3][0][0] = 0;

  bool vis[4][3][100010];

  queue<tuple<int, int, int>> q;
  q.push({3, 0, 0});

  while (!q.empty()) {
    auto [y, x, r] = q.front();
    q.pop();

    REP(d, 0, 4) {
      int xx = x + dx[d], yy = y + dy[d];
      if (IN(xx, 0, 3) && IN(yy, 0, 4) && keys[yy][xx] >= 0) {
        chmin(dist[yy][xx][r], dist[y][x][r] + 1);
        if (!vis[yy][xx][r]) {
          vis[yy][xx][r] = true;
          q.push({yy, xx, r});
        }
      }
    }

    int r1 = (r * 10 + keys[y][x]) % M;
    chmin(dist[y][x][r1], dist[y][x][r] + 1);
    if (!vis[y][x][r1]) {
      vis[y][x][r1] = true;
      q.push({y, x, r1});
    }
  }

  int res = INF;
  REP(i, 0, 4) REP(j, 0, 3) chmin(res, dist[i][j][R]);
  cout << res << endl;

  return 0;
}