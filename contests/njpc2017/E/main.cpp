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

struct Edge {
  int v, c, w;
};

int main() {
  IOS;

  int N, D; cin >> N >> D;
  vector<vector<Edge>> G(N);
  REP(i, 0, N - 1) {
    int a, b, c; cin >> a >> b >> c; a--, b--;
    G[a].push_back({ b, c, 1 });
    G[b].push_back({ a, c, 0 });
  }

  VI C(N), W(N);
  function<void(int, int)> dfs1 = [&](int u, int p) {
    for (auto& e : G[u]) if (e.v != p) {
      dfs1(e.v, u);
      chmax(C[u], C[e.v] + e.c);
      W[u] += W[e.v] + e.w;
    }
    };

  int INF = 1 << 30;
  function<int(int, int, int, int)> dfs2 = [&](int u, int p, int d, int w) {
    vector<PII> children;
    int tot = 0;
    for (auto& e : G[u]) {
      if (e.v == p) {
        children.emplace_back(e.c + d, e.v);
        tot += w + e.w;
      }
      else {
        children.emplace_back(e.c + C[e.v], e.v);
        tot += W[e.v] + e.w;
      }
    }
    sort(rall(children));

    PII best = children[0];
    int res = best.first <= D ? tot : INF;
    for (auto& e : G[u]) if (e.v != p)
      chmin(res, dfs2(e.v, u, children[best.second == e.v].first, tot - e.w - W[e.v]));

    return res;
    };

  dfs1(0, -1);
  int res = dfs2(0, -1, 0, 0);
  cout << (res < INF ? res : -1) << endl;

  return 0;
}