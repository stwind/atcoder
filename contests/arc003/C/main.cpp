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

  int N, M;cin >> N >> M;
  vector<string> C(N);
  REP(i, 0, N) cin >> C[i];

  int sx = -1, sy = -1, gx = -1, gy = -1;
  REP(i, 0, N) REP(j, 0, M) {
    if (C[i][j] == 's') sy = i, sx = j;
    if (C[i][j] == 'g') gy = i, gx = j;
  }

  VI dx = { -1,0,1,0 }, dy = { 0,-1,0,1 };

  using T = tuple<double, int, int>;
  priority_queue<T, vector<T>, less<T>> q;
  q.push({ 10,gy,gx });
  vector<vector<double>> D(N, vector<double>(M, -1));
  D[gy][gx] = 10;

  while (!q.empty()) {
    auto [d, y, x] = q.top(); q.pop();
    if (D[y][x] > d) continue;

    d *= .99;

    REP(i, 0, 4) {
      int yy = y + dy[i], xx = x + dx[i];
      if (IN(yy, 0, N) && IN(xx, 0, M) && C[yy][xx] != '#') {
        if (C[yy][xx] == 's') {
          cout << fixed << setprecision(12) << d << endl;
          return 0;
        }

        double dd = C[yy][xx] - '0';
        chmin(dd, d);

        if (D[yy][xx] < dd) {
          D[yy][xx] = dd;
          q.push({ dd,yy,xx });
        }
      }
    }
  }

  cout << -1 << endl;

  return 0;
}