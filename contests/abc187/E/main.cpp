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

  LL N; cin >> N;
  VI A(N - 1), B(N - 1); VVI G(N);
  unordered_map<LL, int> H;

  function<LL(LL, LL)> edge = [&](LL a, LL b) { return min(a, b) * N + max(a, b); };

  REP(i, 0, N - 1) {
    cin >> A[i] >> B[i]; A[i]--, B[i]--;
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
    H[edge(A[i], B[i])] = i;
  }
  int Q; cin >> Q;
  VI T(Q), E(Q); VLL X(Q);
  REP(i, 0, Q) cin >> T[i] >> E[i] >> X[i], E[i]--;

  VI D(N - 1);
  function<void(int, int)> dfs1 = [&](int u, int p) {
    for (auto v : G[u]) if (v != p) {
      int e = H[edge(u, v)];
      D[e] = A[e] == u && B[e] == v ? 1 : -1;
      dfs1(v, u);
    }
    };
  dfs1(0, -1);

  VLL C(N);
  REP(i, 0, Q) {
    int e = E[i];
    if (T[i] == 1) {
      if (D[e] == -1) C[A[e]] += X[i];
      else {
        C[0] += X[i];
        C[B[e]] -= X[i];
      }
    }
    else {
      if (D[e] == 1) C[B[e]] += X[i];
      else C[0] += X[i], C[A[e]] -= X[i];
    }
  }

  function<void(int, int)> dfs2 = [&](int u, int p) {
    for (auto v : G[u]) if (v != p) {
      C[v] += C[u];
      dfs2(v, u);
    }
    };
  dfs2(0, -1);

  REP(i, 0, N) cout << C[i] << endl;

  return 0;
}