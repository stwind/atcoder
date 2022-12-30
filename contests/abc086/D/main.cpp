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

  int N, K;
  cin >> N >> K;
  int K2 = K * 2, K4 = K2 * 2;

  VI X(N), Y(N);

  char c;
  VVI C0(K2, VI(K2));
  REP(i, 0, N) {
    cin >> X[i] >> Y[i] >> c;
    if (c == 'W') Y[i] += K;
    C0[Y[i] % K2][X[i] % K2]++;
  }

  VVI C(K4, VI(K4));
  REP(i, 0, K4) REP(j, 0, K4) C[i][j] = C0[i % K2][j % K2];

  VVI S(K4 + 1, VI(K4 + 1));
  REP(i, 0, K4) REP(j, 0, K4)
    S[i + 1][j + 1] = C[i][j] + S[i + 1][j] + S[i][j + 1] - S[i][j];

  auto get = [&](int sx, int sy) {
    int ty = sy + K, tx = sx + K;
    return S[ty][tx] - S[ty][sx] - S[sy][tx] + S[sy][sx];
  };

  int res = 0;
  REP(i, 0, K2) REP(j, 0, K2) {
    chmax(res, get(i, j) + get(i + K, j + K));
  }
  cout << res << endl;

  return 0;
}