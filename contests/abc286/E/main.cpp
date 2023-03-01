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

  int N;cin >> N;
  VLL A(N);
  REP(i, 0, N) cin >> A[i];
  vector<string> S(N);
  REP(i, 0, N) cin >> S[i];
  int Q;cin >> Q;
  VI U(Q), V(Q);
  REP(i, 0, Q) cin >> U[i] >> V[i], U[i]--, V[i]--;

  vector<vector<PLL>> D(N, vector<PLL>(N, { INF, 0 }));
  REP(i, 0, N) REP(j, 0, N) {
    if (i == j) D[i][j] = { 0,0 };
    else if (S[i][j] == 'Y') D[i][j] = { 1,A[j] };
  }

  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) {
    auto [d1, a1] = D[i][k];
    auto [d2, a2] = D[k][j];
    auto [d, a] = D[i][j];
    if (d == d1 + d2) D[i][j] = { d,max(a1 + a2,a) };
    if (d > d1 + d2) D[i][j] = { d1 + d2,a1 + a2 };
  }

  REP(i, 0, Q) {
    int u = U[i], v = V[i];
    auto [d, a] = D[u][v];
    if (d == INF)
      cout << "Impossible" << endl;
    else
      cout << d << " " << a + A[u] << endl;
  }

  return 0;
}