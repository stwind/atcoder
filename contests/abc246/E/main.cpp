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

  int N; cin >> N;
  int ax, ay, bx, by;cin >> ax >> ay >> bx >> by;
  ax--, ay--, bx--, by--;
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];

  using TIII = tuple<int, int, int>;
  vector<PII> dir = { {1,-1},{1,1},{-1,1},{-1,-1} };

  vector<VVI> D(N, VVI(N, VI(4, INF)));
  deque<TIII> q({ {ax,ay,-1} });
  REP(i, 0, 4) {
    auto [dx, dy] = dir[i];
    int xx = ax + dx, yy = ay + dy;
    if (0 <= xx && xx < N && 0 <= yy && yy < N && S[xx][yy] == '.') {
      D[xx][yy][i] = 1;
      q.push_front({ xx,yy,i });
    }
  }

  while (!q.empty()) {
    auto [x, y, j] = q.front(); q.pop_front();
    if (x == bx && y == by) {
      cout << D[x][y][j] << endl;
      return 0;
    }

    REP(i, 0, 4) {
      auto [dx, dy] = dir[i];
      int xx = x + dx, yy = y + dy;
      if (0 <= xx && xx < N && 0 <= yy && yy < N && S[xx][yy] == '.') {
        if (i == j && D[xx][yy][j] > D[x][y][j]) {
          D[xx][yy][j] = D[x][y][j];
          q.push_front({ xx,yy,j });
        }
        else if (i != j && D[xx][yy][i] > D[x][y][j] + 1) {
          D[xx][yy][i] = D[x][y][j] + 1;
          q.push_back({ xx,yy,i });
        }
      }
    }
  }
  cout << -1 << endl;

  return 0;
}