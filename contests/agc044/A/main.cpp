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

  int T;  cin >> T;
  VLL N(T), A(T), B(T), C(T), D(T);
  REP(i, 0, T) cin >> N[i] >> A[i] >> B[i] >> C[i] >> D[i];

  REP(t, 0, T) {
    map<LL, LL> M = { {0,0},{1,D[t]} };
    function<LL(LL)> f = [&](LL n) {
      if (M.count(n)) return M[n];

      LL res = 1e18;
      if (n < res / D[t]) res = n * D[t];

      if (n >= 2) chmin(res, A[t] + min(
        f(n / 2) + abs(n - n / 2 * 2) * D[t],
        f(CEIL(n, 2)) + abs(n - CEIL(n, 2) * 2) * D[t]));
      if (n >= 3) chmin(res, B[t] + min(
        f(n / 3) + abs(n - n / 3 * 3) * D[t],
        f(CEIL(n, 3)) + abs(n - CEIL(n, 3) * 3) * D[t]));
      if (n >= 5) chmin(res, C[t] + min(
        f(n / 5) + abs(n - n / 5 * 5) * D[t],
        f(CEIL(n, 5)) + abs(n - CEIL(n, 5) * 5) * D[t]));

      return M[n] = res;
      };

    cout << f(N[t]) << endl;
  }

  return 0;
}