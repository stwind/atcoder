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

  int N, M;
  cin >> N >> M;
  VVI G(N);
  REP(i, 0, M) {
    int a, b;cin >> a >> b;a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  VI D(N, -1), C(N, 0);
  queue<int> q({ 0 });
  D[0] = 0;
  C[0] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : G[u]) {
      if (D[v] == -1) {
        D[v] = D[u] + 1;
        C[v] = C[u];
        q.push(v);
      }
      else if (D[v] == D[u] + 1) {
        C[v] = add(C[v], C[u]);
      }
    }
  }
  cout << C[N - 1] << endl;

  return 0;
}