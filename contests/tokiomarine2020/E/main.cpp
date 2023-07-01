// https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2020/0613_tokiomarine2020#e_-_o_rand

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

  int N, K; cin >> N >> K;
  LL S, T; cin >> S >> T;

  VLL A;
  REP(i, 0, N) {
    int a; cin >> a;
    if ((a & S) == S && (a | T) == T) A.push_back(a);
  }

  int n = A.size();
  LL P[n + 1][n + 1] = { 0 };
  P[0][0] = 1;
  REP(i, 1, n + 1) {
    P[i][0] = P[i][i] = 1;
    REP(j, 1, i) P[i][j] = P[i - 1][j - 1] + P[i - 1][j];
  }

  LL B[n + 1] = { 0 };
  REP(m, 0, n + 1) {
    if (m <= K) B[m] = (1LL << m) - 1;
    else REP(k, 1, K + 1) B[m] += P[m][k];
  }

  LL res = B[n];
  int C[262144] = { 0 };
  for (LL dif = S ^ T, s = dif; s; s = (s - 1) & dif) {
    REP(i, 0, n) C[A[i] & s]++;

    LL c = 0;
    REP(i, 0, n)
      c += B[C[A[i] & s]], C[A[i] & s] = 0;

    res += (__builtin_popcountll(s) & 1) ? -c : c;
  }
  cout << res << endl;

  return 0;
}