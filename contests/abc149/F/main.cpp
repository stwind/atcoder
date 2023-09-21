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

LL mpow(LL x, LL k) {
  LL res = 1;
  while (k) {
    if (k & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return res;
}

LL minv(LL a, LL m = MOD) {
  LL b = m, u = 1, v = 0;
  while (b) {
    LL t = a / b;
    swap(a -= t * b, b);
    swap(u -= t * v, v);
  }
  return (u % m + m) % m;
}

int main() {
  IOS;

  int N; cin >> N;
  vector<vector<PII>> G(N);
  REP(i, 0, N - 1) {
    int a, b; cin >> a >> b; a--, b--;
    G[a].emplace_back(b, i);
    G[b].emplace_back(a, i);
  }

  VI X(N - 1);
  function<int(int, int)> dfs = [&](int u, int p) {
    int x = 0;
    for (auto& [v, i] : G[u]) if (v != p) {
      X[i] = dfs(v, u) + 1;
      x += X[i];
    }
    return x;
    };

  dfs(0, -1);

  LL M = mpow(2, N - 1);
  LL cum = 0;
  function<void(int, int)> dfs2 = [&](int u, int p) {
    VI Y;
    for (auto& [v, i] : G[u]) {
      int x = v == p ? N - X[i] : X[i];
      Y.push_back(x);
      if (v != p) dfs2(v, u);
    }

    if (Y.size() < 2) return;

    LL tot = 1;
    for (auto x : Y)
      tot = add(tot, sub(mpow(2, x), 1LL));

    cum = add(cum, sub(M, tot));
    };

  dfs2(0, -1);

  cout << mul(cum, minv(mpow(2, N))) << endl;

  return 0;
}