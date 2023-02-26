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

  int N, M;cin >> N >> M;
  VI K(M);
  VVI A(M);
  REP(i, 0, M) {
    cin >> K[i];
    int a;
    REP(j, 0, K[i]) cin >> a, A[i].push_back(--a);
  }
  vector<set<int>> G(N);
  VI D(N);
  REP(i, 0, M) REP(k, 1, K[i]) {
    int u = A[i][k], v = A[i][k - 1];
    if (!G[u].count(v)) {
      G[u].insert(v);
      D[v]++;
    }
  }

  queue<int> q;
  REP(i, 0, N) if (D[i] == 0) q.push(i);
  set<int> seen;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    seen.insert(u);
    for (auto v : G[u]) {
      if (--D[v] == 0) {
        seen.insert(v);
        q.push(v);
      }
    }
  }
  cout << ((int)seen.size() == N ? "Yes" : "No") << endl;

  return 0;
}