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

  int N, M, NR; cin >> N >> M >> NR;
  VI R(NR); REP(i, 0, NR) cin >> R[i], R[i]--; sort(all(R));
  VVLL C(N, VLL(N, INF));
  REP(i, 0, N) C[i][i] = 0;
  REP(i, 0, M) {
    int a, b, c; cin >> a >> b >> c;a--, b--;
    C[a][b] = C[b][a] = c;
  }

  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N)
    chmin(C[i][j], C[i][k] + C[k][j]);

  LL res = INF;
  do {
    LL cur = 0;
    REP(i, 0, NR - 1) cur += C[R[i]][R[i + 1]];
    chmin(res, cur);

  } while (next_permutation(all(R)));
  cout << res << endl;

  return 0;
}