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

  int N;
  cin >> N;
  VI LX(N), LY(N), RX(N), RY(N);
  REP(i, 0, N) cin >> LX[i] >> LY[i] >> RX[i] >> RY[i];

  int R = 1001, C = 1001;
  VVI M(R, VI(C));
  REP(i, 0, N) {
    M[LX[i]][LY[i]]++;
    M[RX[i]][LY[i]]--;
    M[LX[i]][RY[i]]--;
    M[RX[i]][RY[i]]++;
  }

  REP(r, 0, R - 1) REP(c, 0, C - 1) M[r][c + 1] += M[r][c];
  REP(r, 0, C - 1) REP(c, 0, C - 1) M[r + 1][c] += M[r][c];

  map<int, int> cnt;
  REP(r, 0, R - 1) REP(c, 0, C - 1) cnt[M[r][c]]++;

  REP(k, 1, N + 1) cout << cnt[k] << endl;

  return 0;
}