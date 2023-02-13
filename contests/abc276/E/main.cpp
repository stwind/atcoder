#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
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

  int H, W;
  cin >> H >> W;
  vector<string> C(H);
  REP(i, 0, H) cin >> C[i];

  int sx = -1, sy = -1;
  REP(i, 0, H) REP(j, 0, W) if (C[i][j] == 'S') sy = i, sx = j;

  VI dx = { -1,0,1,0 }, dy = { 0,-1,0,1 };

  REP(i, 0, 4) {
    int x = sx + dx[i], y = sy + dy[i];
    if (0 <= y && y < H && 0 <= x && x < W && C[y][x] == '.') {
      set<PII> seen;
      queue<PII> q({ { x, y } });
      seen.insert({ x, y });
      seen.insert({ sx, sy });

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        REP(j, 1, 4) {
          int k = (i + j) % 4;
          int tx = sx + dx[k], ty = sy + dy[k];
          if (0 <= ty && ty < H && 0 <= tx && tx < W && C[ty][tx] == '.' && x == tx && y == ty) {
            cout << "Yes" << endl;
            return 0;
          }
        }

        REP(j, 0, 4) {
          int nx = x + dx[j], ny = y + dy[j];
          if (0 <= ny && ny < H && 0 <= nx && nx < W && C[y][x] == '.' && seen.count({ nx, ny }) == 0) {
            seen.insert({ nx, ny });
            q.push({ nx, ny });
          }
        }
      }
    }
  }

  cout << "No" << endl;

  return 0;
}