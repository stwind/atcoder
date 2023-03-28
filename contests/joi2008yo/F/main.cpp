#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define DEBUG(x) cout << #x << ": " << x << endl;
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

  int N, K; cin >> N >> K;
  int INF = 1 << 29;
  vector<vector<PII>> G(N);

  REP(i, 0, K) {
    int t; cin >> t;
    if (t == 1) {
      int c, d, e; cin >> c >> d >> e; c--, d--;
      G[c].push_back({ d, e });
      G[d].push_back({ c, e });
    }
    else {
      int a, b; cin >> a >> b; a--, b--;
      VI D(N, INF); D[a] = 0;
      priority_queue<PII, vector<PII>, greater<PII>> q;
      q.push({ 0, a });
      while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        for (auto [v, c] : G[u])
          if (D[v] > d + c)
            q.push({ D[v] = d + c, v });
      }
      cout << (D[b] < INF ? D[b] : -1) << endl;
    }
  }

  return 0;
}