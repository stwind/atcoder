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

LL gcd(LL a, LL b) {
  return (a ? gcd(b % a, a) : b);
}

int main() {
  IOS;

  LL X, Y; char c;
  cin >> X >> c >> Y;

  LL g = gcd(X, Y);
  X /= g, Y /= g;

  LL x4 = X * 4, ysq = Y * Y, y2 = Y * 2;
  LL x4my2 = x4 - y2;

  LL k1 = (x4my2 < 0) ? (x4my2 < -ysq ? -1 : 0) : CEIL(x4my2, ysq);
  LL k2 = (x4 + y2) / ysq;

  if (k1 > k2) {
    cout << "Impossible" << endl;
    return 0;
  }

  bool good = false;
  for (LL k = k1;k <= k2;k++) {
    if ((k * Y) % 2) continue;

    LL N = k * Y / 2;
    LL M = (N * (N + 1) - X * k);
    if (M % 2) continue;
    M /= 2;
    if (M <= 0 || M > N) continue;
    cout << N << " " << M << endl;
    good = true;
  }
  if (!good) cout << "Impossible" << endl;

  return 0;
}