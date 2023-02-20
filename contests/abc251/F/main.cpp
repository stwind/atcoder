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

  int N, M;cin >> N >> M;
  VVI G(N);
  REP(i, 0, M) {
    int u, v;cin >> u >> v;u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<PII> T1, T2;
  unordered_set<int> s1({ 0 });

  function<void(int)> dfs = [&](int u) {
    for (auto v : G[u]) if (!s1.count(v)) {
      T1.push_back({ u,v });
      s1.insert(v);
      dfs(v);
    }
  };
  dfs(0);

  unordered_set<int> s2({ 0 });
  queue<int> q({ 0 });
  while (!q.empty()) {
    int u = q.front();q.pop();
    for (auto v : G[u]) if (!s2.count(v)) {
      s2.insert(v);
      q.push(v);
      T2.push_back({ u,v });
    }
  }
  for (auto [u, v] : T1)
    cout << ++u << " " << ++v << endl;
  for (auto [u, v] : T2)
    cout << ++u << " " << ++v << endl;

  return 0;
}