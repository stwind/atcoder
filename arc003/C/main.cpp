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
#define IN(a, b, x) (a<=x&&x<b)
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
  int N, M;
  cin >> N >> M;
  vector<string> C(N);
  forn(i, 0, N) cin >> C[i];

  int sx, sy, gx, gy;
  forn(i, 0, N) forn(j, 0, M) {
    if (C[i][j] == 's')
      sx = j, sy = i;
    if (C[i][j] == 'g')
      gx = j, gy = i;
  }

  double po[N * M];
  po[0] = 1;
  forn(i, 1, N * M + 1) po[i] = po[i - 1] * 0.99;
  int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

  auto check = [&](double m) -> bool {
    priority_queue<VI, VVI, greater<VI>> que;
    que.push({0, sy, sx});
    VVI d(N, VI(M, INF));
    d[sy][sx] = 0;
    while (que.size()) {
      VI v = que.top();
      que.pop();
      int y = v[1], x = v[2];
      if (x == gx && y == gy)
        break;
      if (v[0] > d[y][x])
        continue;
      forn(i, 0, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx == M || ny < 0 || ny == N || C[ny][nx] == '#')
          continue;
        if (d[ny][nx] <= d[y][x] + 1)
          continue;

        if (C[ny][nx] == 'g') {
          d[ny][nx] = d[y][x] + 1;
          que.push({d[ny][nx], ny, nx});
        } else {
          double val = (C[ny][nx] - '0') * po[v[0] + 1];
          if (val >= m) {
            d[ny][nx] = d[y][x] + 1;
            que.push({d[ny][nx], ny, nx});
          }
        }
      }
    }
    return d[gy][gx] < INF;
  };
  if (!check(-1)) {
    cout << -1 << endl;
    return 0;
  }

  double lb = 0, hi = 9;
  forn(i, 0, 40) {
    double mid = (lb + hi) / 2;
    if (check(mid))
      lb = mid;
    else
      hi = mid;
  }

  cout << fixed << setprecision(10) << hi << endl;

  return 0;
}