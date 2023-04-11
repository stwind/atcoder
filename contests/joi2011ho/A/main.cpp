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

  int M, N, K; cin >> M >> N >> K;
  vector<string> X(M); REP(i, 0, M) cin >> X[i];
  VI A(K), B(K), C(K), D(K);
  REP(i, 0, K) cin >> A[i] >> B[i] >> C[i] >> D[i];

  VVI SJ(M + 1, VI(N + 1)), SO(M + 1, VI(N + 1)), SI(M + 1, VI(N + 1));
  REP(i, 0, M) REP(j, 0, N) {
    SJ[i + 1][j + 1] = (X[i][j] == 'J') + SJ[i + 1][j] + SJ[i][j + 1] - SJ[i][j];
    SO[i + 1][j + 1] = (X[i][j] == 'O') + SO[i + 1][j] + SO[i][j + 1] - SO[i][j];
    SI[i + 1][j + 1] = (X[i][j] == 'I') + SI[i + 1][j] + SI[i][j + 1] - SI[i][j];
  }

  REP(i, 0, K) {
    int a = A[i], b = B[i], c = C[i], d = D[i];
    int x = SJ[c][d] - SJ[c][b - 1] - SJ[a - 1][d] + SJ[a - 1][b - 1];
    int y = SO[c][d] - SO[c][b - 1] - SO[a - 1][d] + SO[a - 1][b - 1];
    int z = SI[c][d] - SI[c][b - 1] - SI[a - 1][d] + SI[a - 1][b - 1];
    cout << x << " " << y << " " << z << endl;
  }

  return 0;
}