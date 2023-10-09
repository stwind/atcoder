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

  int N; LL C; cin >> N >> C;
  VLL H(N); REP(i, 0, N) cin >> H[i];

  VLL A(N), B(N);
  auto check = [&](int i, int j, int k) {
    return (B[k] - B[j]) * (A[j] - A[i]) >= (B[j] - B[i]) * (A[k] - A[j]);
    };
  auto f = [&](int i, LL x) { return A[i] * x + B[i]; };

  VLL dp(N, LONG_MAX);
  dp[0] = 0;
  A[0] = -2LL * H[0];
  B[0] = H[0] * H[0];

  deque<int> q;
  REP(i, 1, N) {
    while (q.size() >= 2 && check(q[q.size() - 2], q[q.size() - 1], i - 1))
      q.pop_back();
    q.push_back(i - 1);

    while (q.size() >= 2 && f(q[0], H[i]) >= f(q[1], H[i])) q.pop_front();

    dp[i] = H[i] * H[i] + C + f(q[0], H[i]);
    A[i] = -2LL * H[i];
    B[i] = dp[i] + H[i] * H[i];
  }

  cout << dp[N - 1] << endl;

  return 0;
}