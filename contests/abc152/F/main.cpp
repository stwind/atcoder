#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return ((a) * (b)) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

struct LCA {
  VVI parent;
  VI dist;

  LCA(const VVI& G, int root = 0) {
    int N = G.size(), K = 1;
    while ((1 << K) < N) K++;
    parent.assign(K, VI(N, -1));
    dist.assign(N, -1);
    dfs(G, root, -1, 0);
    REP(k, 0, K - 1) REP(u, 0, N) if (parent[k][u] >= 0)
      parent[k + 1][u] = parent[k][parent[k][u]];
  }

  void dfs(const VVI& G, int u, int p, int d) {
    parent[0][u] = p;
    dist[u] = d;
    for (auto v : G[u]) if (v != p) dfs(G, v, u, d + 1);
  }

  int query(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);
    int K = parent.size();
    REP(k, 0, K) if ((dist[u] - dist[v]) >> k & 1) u = parent[k][u];

    if (u == v) return u;
    REPR(k, K - 1, 0) if (parent[k][u] != parent[k][v])
      u = parent[k][u], v = parent[k][v];
    return parent[0][u];
  }

  int length(int u, int v) { return dist[u] + dist[v] - dist[query(u, v)] * 2; }
  int is_in(int u, int v, int a) { return length(u, a) + length(v, a) == length(u, v); }
};

int main() {
  IOS;

  int N, M; cin >> N;
  VI A(N - 1), B(N - 1);
  VVI G(N);
  REP(i, 0, N - 1) {
    cin >> A[i] >> B[i]; A[i]--, B[i]--;
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }
  cin >> M;
  VI U(M), V(M);
  REP(i, 0, M) cin >> U[i] >> V[i], U[i]--, V[i]--;

  LCA lca(G);

  VLL C(M, 0);
  REP(i, 0, M) REP(j, 0, N - 1)
    if (lca.is_in(U[i], V[i], A[j]) && lca.is_in(U[i], V[i], B[j]))
      C[i] |= 1LL << j;

  LL res = pow(2LL, N - 1);
  for (int bit = 1; bit < (1 << M); bit++) {
    LL c = 0;
    REP(i, 0, M) if (bit >> i & 1) c |= C[i];
    int k = N - 1 - __builtin_popcountll(c);
    int l = __builtin_popcount(bit);
    res += pow(-1LL, l) * pow(2LL, k);
  }
  cout << res << endl;

  return 0;
}