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

  int N, M, K, S; cin >> N >> M >> K >> S;
  LL P, Q; cin >> P >> Q;
  VI C(K); REP(i, 0, K) cin >> C[i], C[i]--;
  VVI G(N);
  REP(i, 0, M) {
    int a, b; cin >> a >> b;a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  LL INF = 1LL << 60;
  VLL cost(N, P);
  for (auto c : C) {
    queue<int> q({ c });
    unordered_set<int> seen = { c };
    REP(s, 0, S) {
      int n = q.size();
      REP(j, 0, n) {
        int u = q.front(); q.pop();
        for (auto v : G[u]) if (!seen.count(v)) {
          cost[v] = Q;
          seen.insert(v);
          q.push(v);
        }
      }
    }
  }
  for (auto c : C) cost[c] = INF;
  cost[0] = cost[N - 1] = 0;

  VLL D(N, INF);
  D[0] = 0;

  priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
  q.push({ 0,0 });

  while (!q.empty()) {
    auto [d, u] = q.top(); q.pop();
    for (auto v : G[u]) if (D[v] > d + cost[v])
      q.push({ D[v] = d + cost[v], v });
  }
  cout << D[N - 1] << endl;

  return 0;
}