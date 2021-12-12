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
  int N;
  cin >> N;

  VVI G(N);
  int x, y;
  REP(i, 0, N - 1) {
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int Q;
  cin >> Q;
  VI A(Q), B(Q);
  REP(i, 0, Q) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }

  int K = log2(N) + 1;
  VVI P(N, VI(K, -1));
  VI D(N);
  function<void(int, int, int)> dfs = [&](int u, int p, int d) {
    D[u] = d;
    P[u][0] = p;
    for (auto v : G[u]) {
      if (v == p)
        continue;
      dfs(v, u, d + 1);
    }
  };
  dfs(0, -1, 0);

  REP(k, 0, K - 1) REP(i, 0, N) {
    if (P[i][k] >= 0)
      P[i][k + 1] = P[P[i][k]][k];
  }

  auto query = [&](int u, int v) {
    if (D[u] < D[v])
      swap(u, v);

    REP(k, 0, K) {
      if ((D[u] - D[v]) & (1 << k))
        u = P[u][k];
    }

    if (u == v)
      return u;

    REPR(k, K - 1, 0) {
      if (P[u][k] != P[v][k]) {
        u = P[u][k];
        v = P[v][k];
      }
    }

    return P[u][0];
  };

  REP(i, 0, Q) {
    int v = query(A[i], B[i]);
    int d = D[A[i]] + D[B[i]] - D[v] * 2;
    cout << d + 1 << endl;
  }

  return 0;
}