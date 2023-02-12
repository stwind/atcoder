#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
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

  int N, Q;
  cin >> N >> Q;
  VI X(N);
  REP(i, 0, N) cin >> X[i];
  VVI G(N);
  REP(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  VI V(Q), K(Q);
  REP(i, 0, Q) cin >> V[i] >> K[i], V[i]--, K[i]--;

  VVI P(N);
  function<void(int, int)> dfs = [&](int u, int p) {
    P[u].push_back(X[u]);
    for (auto v : G[u]) {
      if (v == p) continue;
      dfs(v, u);
      for (auto x : P[v]) P[u].push_back(x);
    }
    sort(rall(P[u]));
    int n = P[u].end() - P[u].begin();
    P[u].erase(P[u].begin() + min(20, n), P[u].end());
  };
  dfs(0, -1);

  REP(i, 0, Q) {
    cout << P[V[i]][K[i]] << endl;
  }

  return 0;
}