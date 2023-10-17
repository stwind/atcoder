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

const int MAX = 200001;
long long fac[MAX], finv[MAX], inv[MAX];

void comb_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int main() {
  IOS;
  comb_init();

  int N; cin >> N;
  VVI G(N);
  REP(i, 0, N - 1) {
    int a, b; cin >> a >> b; a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  VI S(N);
  VLL dp(N, 1);
  function<void(int, int)> dfs1 = [&](int u, int p) {
    int sz = 0;
    for (auto v : G[u]) if (v != p) {
      dfs1(v, u);
      sz += S[v];
      dp[u] = mul(dp[u], mul(dp[v], finv[S[v]]));
    }
    dp[u] = mul(dp[u], fac[sz]);
    S[u] = sz + 1;
    };

  VLL res(N, 1);
  function<void(int, int, LL)> dfs2 = [&](int u, int p, LL d) {
    res[u] = d;
    for (auto v : G[u]) if (v != p) {
      res[u] = mul(res[u], mul(dp[v], finv[S[v]]));
    }

    int n = G[u].size();
    VLL L(n), R(n);
    REP(i, 0, n) {
      int v = G[u][i];
      L[i] = R[i] = v == p ? d : mul(dp[v], finv[S[v]]);
    }

    REP(i, 1, n) L[i] = mul(L[i], L[i - 1]);
    REPR(i, n - 2, 0) R[i] = mul(R[i], R[i + 1]);

    REP(i, 0, n) {
      int v = G[u][i];
      if (v == p) continue;

      LL a = i > 0 ? L[i - 1] : 1;
      if (i < n - 1) a = mul(a, R[i + 1]);

      dfs2(v, u, mul(mul(fac[N - S[v] - 1], a), finv[N - S[v]]));
    }
    };

  dfs1(0, -1);
  dfs2(0, -1, 1);

  REP(i, 0, N) cout << mul(fac[N - 1], res[i]) << endl;

  return 0;
}