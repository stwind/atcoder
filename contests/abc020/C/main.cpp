#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define PARENS ()
#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__
#define FOR_EACH(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define DBG(x) cout << #x << ": " << x << " ";
#define DEBUG(...) FOR_EACH(DBG, __VA_ARGS__) cout << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return 1ULL * a * b % MOD; }
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

  int H, W, T; cin >> H >> W >> T;
  vector<string> S(H); REP(i, 0, H) cin >> S[i];

  int sx = -1, sy = -1, gx = -1, gy = -1;
  REP(i, 0, H) REP(j, 0, W) {
    if (S[i][j] == 'S') sx = j, sy = i;
    if (S[i][j] == 'G') gx = j, gy = i;
  }

  VI dx = { -1,0,1,0 }, dy = { 0,-1,0,1 };

  function<LL(LL)> bfs = [&](LL k) {
    queue<PII> q({ {sy,sx} });
    VVLL D(H, VLL(W, LONG_MAX));
    D[sy][sx] = 0;

    while (!q.empty()) {
      auto [y, x] = q.front(); q.pop();
      REP(i, 0, 4) {
        int xx = x + dx[i], yy = y + dy[i];
        if (IN(xx, 0, W) && IN(yy, 0, H)) {
          LL dd = D[y][x] + (S[yy][xx] == '#' ? k : 1LL);
          if (D[yy][xx] <= dd) continue;
          D[yy][xx] = dd;

          if (S[yy][xx] != 'G') q.push({ yy,xx });
        }
      }
    }
    return D[gy][gx];
    };

  int l = 0, r = T, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    (bfs(m) <= T ? l : r) = m;
  }
  cout << l << endl;

  return 0;
}