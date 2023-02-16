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

  int H, W; cin >> H >> W;
  vector<string> C(H);
  REP(i, 0, H) cin >> C[i];

  int sx = -1, sy = -1;
  REP(i, 0, H) REP(j, 0, W) if (C[i][j] == 's') sy = i, sx = j;

  VI dx = { -1,0,1,0 }, dy = { 0,-1,0,1 };

  set<tuple<int, int, int>> seen;
  seen.insert({ sx,sy,2 });
  queue<tuple<int, int, int>> q({ {sx,sy,2} });

  while (!q.empty()) {
    auto [x, y, d] = q.front(); q.pop();

    REP(i, 0, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (0 <= xx && xx < W && 0 <= yy && yy < H) {
        if (C[yy][xx] == 'g') {
          cout << "YES" << endl;
          return 0;
        }

        if (C[yy][xx] == '#' && d > 0 && seen.count({ xx,yy,d - 1 }) == 0) {
          seen.insert({ xx,yy,d - 1 });
          q.push({ xx,yy,d - 1 });
        }
        if (C[yy][xx] == '.' && seen.count({ xx,yy,d }) == 0) {
          seen.insert({ xx,yy,d });
          q.push({ xx,yy,d });
        }
      }
    }
  }
  cout << "NO" << endl;

  return 0;
}