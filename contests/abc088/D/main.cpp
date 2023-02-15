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
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];

  int white = 0;
  REP(i, 0, H) REP(j, 0, W)
    if ((i > 0 || j > 0) && (i < H - 1 || j < W - 1) && S[i][j] == '.') white++;

  VI dx = { -1,0,1,0 }, dy = { 0,-1,0,1 };

  VVI D(H, VI(W, -1));
  queue<PII> q({ {0,0} });
  D[0][0] = 0;
  while (!q.empty()) {
    auto [x, y] = q.front();q.pop();
    if (x == W - 1 && y == H - 1) break;
    REP(i, 0, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (0 <= xx && xx < W && 0 <= yy && yy < H && D[yy][xx] == -1 && S[yy][xx] == '.') {
        D[yy][xx] = D[y][x] + 1;
        q.push({ xx,yy });
      }
    }
  }
  if (D[H - 1][W - 1] == -1) {
    cout << -1 << endl;
    return 0;
  }

  cout << white - D[H - 1][W - 1] + 1 << endl;

  return 0;
}