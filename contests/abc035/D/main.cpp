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

  int N, M;
  LL T; cin >> N >> M >> T;
  VLL A(N); REP(i, 0, N) cin >> A[i];

  vector<vector<PLL>> G1(N), G2(N);
  REP(i, 0, M) {
    int a, b, c; cin >> a >> b >> c;a--, b--;
    G1[a].push_back({ b, c });
    G2[b].push_back({ a, c });
  }

  LL INF = 1LL << 60;
  VLL D1(N, INF); D1[0] = 0;
  priority_queue<PLL, vector<PLL>, greater<PLL>> q1;
  q1.push({ 0, 0 });
  while (!q1.empty()) {
    auto [d, u] = q1.top(); q1.pop();
    for (auto [v, c] : G1[u]) if (D1[v] > d + c) {
      q1.push({ D1[v] = d + c,v });
    }
  }

  VLL D2(N, INF); D2[0] = 0;
  priority_queue<PLL, vector<PLL>, greater<PLL>> q2;
  q2.push({ 0, 0 });
  while (!q2.empty()) {
    auto [d, u] = q2.top(); q2.pop();
    for (auto [v, c] : G2[u]) if (D2[v] > d + c) {
      q2.push({ D2[v] = d + c,v });
    }
  }

  LL res = 0;
  REP(i, 0, N) if (D1[i] + D2[i] <= T) chmax(res, (T - D1[i] - D2[i]) * A[i]);
  cout << res << endl;

  return 0;
}