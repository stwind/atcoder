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

  int M, N; cin >> M >> N;
  VVI A(M, VI(N)), B(M, VI(N));
  REP(i, 0, M) REP(j, 0, N) cin >> A[i][j];
  REP(i, 0, M) REP(j, 0, N) cin >> B[i][j];

  auto id = [&](int y, int x) { return y * N + x; };
  int N2 = M * N;
  int s = N2, t = N2 + 1;

  Dinic G(N2 + 2);
  int dif = 0;
  REP(y, 0, M) REP(x, 0, N) {
    if (A[y][x] != B[y][x]) dif++;

    if ((y + x) & 1) G.add(s, id(y, x), 1);
    else G.add(id(y, x), t, 1);

    if (x < N - 1 && A[y][x] != A[y][x + 1] && A[y][x] == B[y][x + 1] && A[y][x + 1] == B[y][x]) {
      if ((y + x) & 1) G.add(id(y, x), id(y, x + 1), 1);
      else G.add(id(y, x + 1), id(y, x), 1);
    }

    if (y < M - 1 && A[y][x] != A[y + 1][x] && A[y][x] == B[y + 1][x] && A[y + 1][x] == B[y][x]) {
      if ((y + x) & 1) G.add(id(y, x), id(y + 1, x), 1);
      else G.add(id(y + 1, x), id(y, x), 1);
    }
  }

  cout << dif - G.max_flow(s, t) << endl;

  return 0;
}