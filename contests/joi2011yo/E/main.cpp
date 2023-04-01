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
#define MOD 998244353
#define DEBUG1(x) cout << #x << ": " << x << " ";
#define DEBUG(...) FOR_EACH(DEBUG1, __VA_ARGS__) cout << endl;
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

  int H, W, N; cin >> H >> W >> N;
  vector<string> A(H);
  REP(i, 0, H) cin >> A[i];

  int sx = -1, sy = -1;
  REP(i, 0, H) REP(j, 0, W)
    if (A[i][j] == 'S') sx = j, sy = i;

  vector<PII> dirs = { {0,1},{1,0},{0,-1},{-1,0} };

  unordered_set<int> S;
  auto id = [&](int y, int x, int d) -> int { return d * H * W + y * W + x; };

  queue<tuple<int, int, int, int>> q;
  q.push({ sy, sx, 1, 0 });
  S.insert(id(sy, sx, 1));

  while (!q.empty()) {
    auto [y, x, h, d] = q.front();q.pop();
    if (h == N + 1) {
      cout << d << endl;
      return 0;
    }

    for (auto [dx, dy] : dirs) {
      int xx = x + dx, yy = y + dy;
      if (0 <= xx && xx < W && 0 <= yy && yy < H && A[yy][xx] != 'X') {
        int c = A[yy][xx] - '0';
        if (0 < c && c < 10 && h == c && !S.count(id(yy, xx, h + 1))) {
          S.insert(id(yy, xx, h + 1));
          q.push({ yy,xx, h + 1, d + 1 });
        }
        else if (!S.count(id(yy, xx, h))) {
          S.insert(id(yy, xx, h));
          q.push({ yy,xx, h, d + 1 });
        }
      }
    }
  }

  return 0;
}