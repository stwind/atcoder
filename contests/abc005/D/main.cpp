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

  int N, Q;
  cin >> N;
  VVI D(N, VI(N));
  REP(i, 0, N) REP(j, 0, N) cin >> D[i][j];
  cin >> Q;
  VI P(Q);
  REP(i, 0, Q) cin >> P[i];

  VVI S(N + 1, VI(N + 1));
  REP(i, 0, N) REP(j, 0, N)
    S[i + 1][j + 1] = D[i][j] + S[i + 1][j] + S[i][j + 1] - S[i][j];

  VI A(N * N + 1);
  REP(i, 0, N) REP(j, 0, N) REP(r, 0, i + 1) REP(c, 0, j + 1) {
    int a = S[i + 1][j + 1] - S[i + 1][c] - S[r][j + 1] + S[r][c];
    int p = (i - r + 1) * (j - c + 1);
    chmax(A[p], a);
  }

  int n = A.size();
  VI C(n + 1);
  REP(i, 0, n) C[i + 1] = max(C[i], A[i]);

  REP(i, 0, Q) cout << C[P[i] + 1] << endl;

  return 0;
}