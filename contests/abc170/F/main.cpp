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

  int H, W, K; cin >> H >> W >> K;
  int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;x1--, y1--, x2--, y2--;
  vector<string> C(H);
  REP(i, 0, H) cin >> C[i];

  vector<PII> dir = { {-1,0},{1,0},{0,-1},{0,1} };
  VVI D(H, VI(W, INF));
  D[x1][y1] = 0;
  queue<PII> q({ {x1,y1} });

  while (!q.empty()) {
    auto [x, y] = q.front();q.pop();
    REP(i, 0, 4) REP(k, 1, K + 1) {
      auto [dx, dy] = dir[i];
      int xx = x + k * dx, yy = y + k * dy;
      if (!(0 <= xx && xx < H && 0 <= yy && yy < W)) break;
      if (C[xx][yy] == '@') break;
      if (D[xx][yy] <= D[x][y]) break;
      if (D[xx][yy] > D[x][y] + 1) {
        D[xx][yy] = D[x][y] + 1;
        q.push({ xx,yy });
      }
    }
  }
  cout << (D[x2][y2] < INF ? D[x2][y2] : -1) << endl;

  return 0;
}