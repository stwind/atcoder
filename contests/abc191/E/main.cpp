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

  int N, M; cin >> N >> M;
  vector<vector<PII>> G1(N), G2(N);
  VI A(M), B(M), C(M);
  REP(i, 0, M) {
    cin >> A[i] >> B[i] >> C[i]; A[i]--, B[i]--;
    G1[A[i]].emplace_back(B[i], C[i]);
    G2[B[i]].emplace_back(A[i], C[i]);
  }

  auto dijkstra = [&](int i, vector<vector<PII>>& G, VI& D) {
    D[i] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({ 0,i });
    while (!q.empty()) {
      auto [d, u] = q.top(); q.pop();
      for (auto [v, c] : G[u]) if (D[v] > D[u] + c) {
        D[v] = D[u] + c;
        q.push({ D[v],v });
      }
    }
    };

  const int INF = 200000001;
  REP(i, 0, N) {
    VI D1(N, INF), D2(N, INF);
    dijkstra(i, G1, D1);
    dijkstra(i, G2, D2);

    int res = INF;
    REP(j, 0, N) if (i != j) chmin(res, D1[j] + D2[j]);
    REP(j, 0, M) if (A[j] == B[j] && A[j] == i) chmin(res, C[j]);
    cout << (res < INF ? res : -1) << endl;
  }

  return 0;
}