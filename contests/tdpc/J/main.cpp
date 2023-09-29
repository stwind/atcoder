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

  int N; cin >> N;
  int X = 0, m = 0;
  REP(i, 0, N) {
    int x; cin >> x;
    X |= 1 << x;
    chmax(m, x);
  }

  int n = 1 << (m + 1);
  vector<double> dp(n, 1e9);
  dp[0] = 0.;

  REP(bit, 0, n) if (bit & X) {

    double e = 1e9;
    REP(i, 1, m) {
      double a = dp[bit & ~(1 << (i - 1))];
      double b = dp[bit & ~(1 << i)];
      double c = dp[bit & ~(1 << (i + 1))];
      int pat = bit >> (i - 1) & 7;
      if (pat == 7) chmin(e, 1. + (a + b + c) / 3.);
      else if (pat == 6) chmin(e, (3. + b + c) / 2.);
      else if (pat == 5) chmin(e, (3. + a + c) / 2.);
      else if (pat == 3) chmin(e, (3. + a + b) / 2.);
      else if (pat == 4) chmin(e, c + 3.);
      else if (pat == 2) chmin(e, b + 3.);
      else if (pat == 1) chmin(e, a + 3.);
    }
    dp[bit] = e;
  }

  cout << fixed << setprecision(12) << dp[X] << endl;

  return 0;
}