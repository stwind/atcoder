// https://kmjp.hatenablog.jp/entry/2015/09/30/0900

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

  int N, M, K; cin >> N >> M >> K;
  VI A(N + 1, INF);
  REP(i, 0, K) {
    int v, a; cin >> v >> a;
    A[v] = a;
  }
  VI U(M), W(M), C(M);
  REP(i, 0, M) cin >> U[i] >> W[i] >> C[i];

  auto check = [&](double T)  -> bool {
    vector<vector<pair<int, double>>> G(N + 1);
    REP(i, 1, N + 1) if (A[i] < INF) {
      G[0].push_back({ i, A[i] });
      G[i].push_back({ 0, -A[i] });
    }
    REP(i, 0, M) G[W[i]].push_back({ U[i], T - C[i] });
    vector<double> D(N + 1, 1e10);
    D[0] = 0;
    REP(i, 0, N + 1) {
      bool updated = false;
      REP(u, 0, N + 1) {
        for (auto [v, c] : G[u])
          if (D[v] > D[u] + c) D[v] = D[u] + c, updated = true;
      }
      if (!updated) return true;
    }
    return false;
  };

  double L = -1e10, R = 1e10;
  while (R - L > 1e-8) {
    double M = (L + R) / 2;
    if (check(M)) R = M;
    else L = M;
  }

  if (L < -1e9) printf("#\n");
  else printf("%.12lf\n", L);

  return 0;
}