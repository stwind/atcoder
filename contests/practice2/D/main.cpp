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

struct Dinic {
  struct Edge { int v, cap, flow, rev; };

  int n;
  vector<vector<Edge>> adj;
  explicit Dinic(int n) : n(n), adj(n) {}

  void add(int u, int v, int cap) {
    adj[u].push_back({ v, cap, 0, (int)adj[v].size() });
    adj[v].push_back({ u, 0, 0, (int)adj[u].size() - 1 });
  }

  int max_flow(int s, int t) {
    VI levels(n);
    function<int(void)> bfs = [&]() {
      fill(all(levels), -1);
      levels[s] = 0;
      queue<int> q({ s });
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == t) break;
        for (auto& e : adj[u]) if (e.cap > e.flow && levels[e.v] < 0) {
          levels[e.v] = levels[u] + 1;
          q.push(e.v);
        }
      }

      return levels[t];
      };

    function<int(int, int)> dfs = [&](int u, int cur) {
      if (u == t) return cur;
      for (auto& e : adj[u]) {
        Edge& r = adj[e.v][e.rev];
        if (e.cap > e.flow && levels[u] < levels[e.v]) {
          int f = dfs(e.v, min(cur, e.cap - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return 0;
      };

    REP(u, 0, n) for (auto& e : adj[u]) e.flow = 0;

    int flow = 0;
    while (bfs() > 0)
      for (int f; (f = dfs(s, INT_MAX)) > 0;) flow += f;

    return flow;
  }
};

int main() {
  IOS;

  int N, M; cin >> N >> M;
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];

  int n = N * M;
  int s = n, t = n + 1;

  auto id = [&](int i, int j) { return i * M + j; };
  Dinic g(n + 2);

  REP(i, 0, N) REP(j, 0, M) if (S[i][j] == '.') {
    int u = id(i, j);
    if ((i + j) & 1) g.add(u, t, 1);
    else {
      g.add(s, u, 1);
      if (j > 0 && S[i][j - 1] == '.') g.add(u, id(i, j - 1), 1);
      if (j < M - 1 && S[i][j + 1] == '.') g.add(u, id(i, j + 1), 1);
      if (i > 0 && S[i - 1][j] == '.') g.add(u, id(i - 1, j), 1);
      if (i < N - 1 && S[i + 1][j] == '.') g.add(u, id(i + 1, j), 1);
    }
  }

  cout << g.max_flow(s, t) << endl;

  REP(u, 0, n) {
    int uy = u / M, ux = u % M;
    for (auto& e : g.adj[u]) if (e.v < n && e.flow > 0) {
      int vy = e.v / M, vx = e.v % M;
      if (uy + 1 == vy) S[uy][ux] = 'v', S[vy][vx] = '^';
      else if (uy - 1 == vy) S[uy][ux] = '^', S[vy][vx] = 'v';
      else if (ux + 1 == vx) S[uy][ux] = '>', S[vy][vx] = '<';
      else S[uy][ux] = '<', S[vy][vx] = '>';
    }
  }

  REP(i, 0, N) cout << S[i] << endl;

  return 0;
}