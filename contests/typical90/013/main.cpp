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

  LL INF = 1LL << 60;
  int N, M; cin >> N >> M;
  vector<vector<PLL>> G(N);
  REP(i, 0, M) {
    int a, b, c; cin >> a >> b >> c; a--, b--;
    G[a].push_back({ b, c });
    G[b].push_back({ a, c });
  }

  VLL D1(N, INF); D1[0] = 0;
  priority_queue<PLL, vector<PLL>, greater<PLL>> q1;
  q1.push({ 0, 0 });
  while (!q1.empty()) {
    auto [d, u] = q1.top(); q1.pop();
    for (auto [v, c] : G[u]) if (D1[v] > d + c) {
      q1.push({ D1[v] = d + c,v });
    }
  }

  VLL D2(N, INF); D2[N - 1] = 0;
  priority_queue<PLL, vector<PLL>, greater<PLL>> q2;
  q2.push({ 0, N - 1 });
  while (!q2.empty()) {
    auto [d, u] = q2.top(); q2.pop();
    for (auto [v, c] : G[u]) if (D2[v] > d + c) {
      q2.push({ D2[v] = d + c,v });
    }
  }

  REP(i, 0, N) cout << D1[i] + D2[i] << endl;

  return 0;
}