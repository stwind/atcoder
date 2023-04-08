// https://www.creativ.xyz/arc016c-605/
// https://kmjp.hatenablog.jp/entry/2013/11/05/0930
// https://noy72.com/articles/2017-10-27-arc-016-c/
// https://kyopro.hateblo.jp/entry/2019/07/15/013501

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

  int N; LL X; cin >> N >> X;
  VLL V(N), W(N);
  REP(i, 0, N) cin >> V[i] >> W[i];

  LL MV = *max_element(all(V)), MW = *max_element(all(W));

  if (N <= 30) {
    int N2 = N / 2, n = 1 << N2;
    VLL V1, W1;
    REP(s, 0, n) {
      LL v = 0, w = 0;
      REP(i, 0, N2) if (s >> i & 1) v += V[i], w += W[i];
      if (w > X) continue;
      V1.push_back(v);
      W1.push_back(w);
    }
    VI I(V1.size()); REP(i, 0, (int)V1.size()) I[i] = i;
    sort(all(I), [&](int a, int b) { return W1[a] < W1[b]; });
    LL cv = 0;
    for (auto i : I) chmax(cv, V1[i]), V1[i] = cv;

    LL res = 0;
    int M = N - N2, m = 1 << M;
    REP(s, 0, m) {
      LL v = 0, w = 0;
      REP(i, 0, M) if (s >> i & 1) v += V[i + N2], w += W[i + N2];
      if (w > X) continue;
      int i = upper_bound(all(I), X - w, [&](LL w, int a) { return w < W1[a]; }) - I.begin() - 1;
      chmax(res, v + V1[I[i]]);
    }
    cout << res << endl;
    return 0;
  }
  else if (MW <= 1000) {
    VVLL dp(N + 1, VLL(X + 1));
    REP(i, 0, N) REP(j, 1, X + 1) {
      dp[i + 1][j] = dp[i][j];
      if (j >= W[i]) chmax(dp[i + 1][j], dp[i][j - W[i]] + V[i]);
    }

    cout << *max_element(all(dp[N])) << endl;
    return 0;
  }
  else if (MV <= 1000) {
    int VM = accumulate(all(V), 0);
    VVLL dp(N + 1, VLL(VM + 1, 1LL << 60));
    dp[0][0] = 0;
    REP(i, 0, N) REP(j, 0, VM + 1) {
      dp[i + 1][j] = dp[i][j];
      if (j >= V[i]) chmin(dp[i + 1][j], dp[i][j - V[i]] + W[i]);
    }
    int res = 0;
    REP(j, 0, VM) if (dp[N][j] <= X) chmax(res, j);
    cout << res << endl;
    return 0;
  }

  return 0;
}