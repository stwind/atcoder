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

  int N;
  cin >> N;
  VVI G(N);
  REP(i, 0, N - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  constexpr int imin = numeric_limits<int>::min();
  constexpr int imax = numeric_limits<int>::max();

  int m = 0;
  vector<PII> res(N);
  function<PII(int, int)> dfs = [&](int u, int p) {
    int mn = imax, mx = imin;
    for (auto v : G[u]) {
      if (v == p) continue;

      PII p = dfs(v, u);
      chmin(mn, p.first);
      chmax(mx, p.second);
    }
    if (mn == imax && mx == imin) mn = mx = ++m;
    return res[u] = make_pair(mn, mx);
  };
  dfs(0, -1);

  REP(i, 0, N) {
    auto [l, r] = res[i];
    cout << l << " " << r << endl;
  }

  return 0;
}