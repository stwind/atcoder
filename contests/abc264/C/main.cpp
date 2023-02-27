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

  int H1, W1; cin >> H1 >> W1;
  VVI A(H1, VI(W1));
  REP(i, 0, H1) REP(j, 0, W1) cin >> A[i][j];
  int H2, W2; cin >> H2 >> W2;
  VVI B(H2, VI(W2));
  REP(i, 0, H2) REP(j, 0, W2) cin >> B[i][j];

  REP(b1, 0, (1 << H1)) if (__builtin_popcount(b1) == H2) {
    REP(b2, 0, (1 << W1)) if (__builtin_popcount(b2) == W2) {
      int ii = 0;
      int good = 0;
      REP(i, 0, H1) if ((b1 >> i) & 1) {
        int jj = 0;
        REP(j, 0, W1) if ((b2 >> j) & 1) {
          if (A[i][j] == B[ii][jj]) good++;
          jj++;
        }
        ii++;
      }
      if (good == H2 * W2) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}