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

  int H, W, Q;
  cin >> H >> W >> Q;
  VLL A(H), B(W);
  REP(i, 0, H) cin >> A[i];
  REP(i, 0, W) cin >> B[i];

  VI PX(Q), PY(Q), QX(Q), QY(Q);
  REP(i, 0, Q) cin >> PX[i] >> PY[i] >> QX[i] >> QY[i];

  VVLL R(2, VLL(H + 1)), C(2, VLL(W + 1));
  REP(i, 0, H) {
    R[i % 2][i + 1] += R[i % 2][i] + A[i];
    R[i % 2 ^ 1][i + 1] += R[i % 2 ^ 1][i];
  }
  REP(i, 0, W) {
    C[i % 2][i + 1] += C[i % 2][i] + B[i];
    C[i % 2 ^ 1][i + 1] += C[i % 2 ^ 1][i];
  }

  REP(i, 0, Q) {
    int px = PX[i] - 1, py = PY[i] - 1, qx = QX[i], qy = QY[i];
    LL a = (R[0][qx] - R[0][px]) * (C[0][qy] - C[0][py]) + (R[1][qx] - R[1][px]) * (C[1][qy] - C[1][py]);
    LL b = (R[0][qx] - R[0][px]) * (C[1][qy] - C[1][py]) + (R[1][qx] - R[1][px]) * (C[0][qy] - C[0][py]);
    cout << a - b << endl;
  }

  return 0;
}