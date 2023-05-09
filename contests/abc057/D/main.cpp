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

  LL C[51][51] = { 0 };
  REP(i, 0, 51) REP(j, 0, i + 1) {
    if (j == 0 || j == i) C[i][j] = 1;
    else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }

  int N, A, B; cin >> N >> A >> B;
  VLL V(N);
  REP(i, 0, N) cin >> V[i];
  sort(rall(V));

  double S = 0.;
  REP(i, 0, A) S += V[i];
  cout << fixed << setprecision(12) << S / A << endl;

  if (V[0] == V[A - 1]) {
    int v = 0;
    REP(i, 0, N) if (V[i] == V[A - 1]) v++;

    LL res = 0;
    REP(i, A, B + 1) res += C[v][i];
    cout << res << endl;
  }
  else {
    int v = 0, a = 0;
    REP(i, 0, N) if (V[i] == V[A - 1]) {
      if (i < A) a++;
      v++;
    }
    cout << C[v][a] << endl;
  }

  return 0;
}