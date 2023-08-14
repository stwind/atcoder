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

  VVI B(2, VI(3));
  REP(i, 0, 2) REP(j, 0, 3) cin >> B[i][j];
  VVI C(3, VI(2));
  REP(i, 0, 3) REP(j, 0, 2) cin >> C[i][j];

  VVI X(3, VI(3, -1));
  function<int()> score = [&]() {
    int a = 0, b = 0;
    REP(i, 0, 2) REP(j, 0, 3) (X[i][j] == X[i + 1][j] ? a : b) += B[i][j];
    REP(i, 0, 3) REP(j, 0, 2) (X[i][j] == X[i][j + 1] ? a : b) += C[i][j];
    return a * 1000 + b;
    };

  function<int(int)> dfs = [&](int k) {
    if (k == 9) return score();

    int r = k % 2;
    int x = 0, md = r ? 1001 : -1001;
    REP(i, 0, 3) REP(j, 0, 3) {
      if (X[i][j] >= 0)  continue;

      X[i][j] = r;

      int s = dfs(k + 1);
      int diff = s / 1000 - s % 1000;
      if (r) {
        if (diff < md) md = diff, x = s;
      }
      else {
        if (diff > md) md = diff, x = s;
      }

      X[i][j] = -1;
    }
    return x;
    };

  int s = dfs(0);
  cout << s / 1000 << endl;
  cout << s % 1000 << endl;

  return 0;
}