// https://smijake3.hatenablog.com/entry/2018/05/04/015500

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

template <class T = int>
struct Dinic {
  struct Edge { int v, rev; T cap; };

  int n;
  vector<vector<Edge>> G;
  explicit Dinic(int n) : n(n), G(n) {}

  void add(int u, int v, T cap) {
    G[u].push_back({ v, (int)G[v].size(), cap });
    G[v].push_back({ u, (int)G[u].size() - 1, 0 });
  }

  T max_flow(int s, int t) {
    vector<bool> used(n);
    function<T(int, T)> dfs = [&](int u, T cur) {
      if (u == t) return cur;
      used[u] = true;
      for (auto& e : G[u]) {
        if (!used[e.v] && e.cap > 0) {
          T f = dfs(e.v, min(cur, e.cap));
          if (f > 0) {
            e.cap -= f;
            G[e.v][e.rev].cap += f;
            return f;
          }
        }
      }
      return static_cast<T>(0);
      };

    const T INF = numeric_limits<T>::max();
    T flow = 0;
    while (true) {
      fill(all(used), false);
      T f = dfs(s, INF);
      if (f == 0) return flow;
      flow += f;
    }
  }
};

int main() {
  IOS;

  int N; cin >> N;
  VLL A(N); REP(i, 0, N) cin >> A[i];

  const LL INF = INT_MAX;
  Dinic<LL> G(N + 2);
  LL S = 0;
  REP(i, 0, N) {
    if (A[i] > 0) G.add(N, i, A[i]), S += A[i];
    else G.add(i, N + 1, -A[i]);

    for (int j = (i + 1) * 2; j <= N;j += i + 1)
      G.add(j - 1, i, INF);
  }

  cout << S - G.max_flow(N, N + 1) << endl;

  return 0;
}