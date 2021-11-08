#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
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
  int H, W, T;
  cin >> H >> W >> T;
  vector<string> S(H);
  forn(i, 0, H) cin >> S[i];

  int sx, sy, gx, gy;
  forn(i, 0, H) forn(j, 0, W) {
    if (S[i][j] == 'S')
      sx = j, sy = i;
    if (S[i][j] == 'G')
      gx = j, gy = i;
  }

  auto check = [&](int m) -> bool {
    VVLL D(H, VLL(W, INF));
    D[sy][sx] = 0;
    priority_queue<VI, VVI, greater<VI>> pq;
    pq.push({0, sx, sy});

    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int c = p[0], x = p[1], y = p[2];
      if (D[y][x] < c)
        continue;

      int pos[4][2] = {{y - 1, x}, {y + 1, x}, {y, x - 1}, {y, x + 1}};
      for (auto &p : pos) {
        int xx = p[1], yy = p[0];

        if (xx < 0 || xx >= W || yy < 0 || yy >= H)
          continue;

        int d = S[yy][xx] == '.' || S[yy][xx] == 'G' ? 1 : m;

        if (c + d < D[yy][xx]) {
          D[yy][xx] = c + d;
          pq.push({c + d, xx, yy});
        }
      }
    }
    return D[gy][gx] <= T;
  };

  int lo = 0, hi = T, mid;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << lo << endl;

  return 0;
}