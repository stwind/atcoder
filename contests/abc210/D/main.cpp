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

  int H, W; LL C; cin >> H >> W >> C;
  VVLL A(H, VLL(W));
  REP(i, 0, H) REP(j, 0, W) cin >> A[i][j];

  const LL INF = 1LL << 60;
  function<LL()> solve = [&]() {
    VVLL M(H + 1, VLL(W + 1, INF));
    REP(i, 0, H) REP(j, 0, W) {
      M[i + 1][j + 1] = A[i][j] - C * (i + j);
      chmin(M[i + 1][j + 1], min(M[i + 1][j], M[i][j + 1]));
    }

    LL res = INF;
    REP(i, 0, H) REP(j, 0, W)
      chmin(res, A[i][j] + C * (i + j) + min(M[i + 1][j], M[i][j + 1]));

    return res;
    };

  LL res = solve();
  reverse(all(A));
  chmin(res, solve());
  REP(i, 0, H) reverse(all(A[i]));
  chmin(res, solve());
  reverse(all(A));
  chmin(res, solve());

  cout << res << endl;

  return 0;
}