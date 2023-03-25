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

  int N; cin >> N;
  VI A(N);
  REP(i, 0, N) cin >> A[i];

  VI dp(N + 1, INF);
  dp[0] = 0;
  VI L(N), R(N);
  REP(i, 0, N) {
    auto it = lower_bound(all(dp), A[i]);
    if (it != dp.end()) *it = A[i];
    L[i] = it - dp.begin();
  }

  fill(all(dp), INF);
  dp[0] = 0;
  REPR(i, N - 1, 0) {
    auto it = lower_bound(all(dp), A[i]);
    if (it != dp.end()) *it = A[i];
    R[i] = it - dp.begin();
  }

  int res = 0;
  REP(i, 0, N) {
    chmax(res, L[i] + R[i] - 1);
  }
  cout << res << endl;

  return 0;
}