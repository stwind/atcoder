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

  int N, K; cin >> N >> K;
  VI A(N), B(N);
  REP(i, 0, N) cin >> A[i];
  REP(i, 0, N) cin >> B[i];

  vector<vector<bool>> dp(N, vector<bool>(2, false));
  dp[0][0] = dp[0][1] = true;
  REP(i, 1, N) {
    if (dp[i - 1][0]) {
      if (abs(A[i] - A[i - 1]) <= K) dp[i][0] = true;
      if (abs(B[i] - A[i - 1]) <= K) dp[i][1] = true;
    }
    if (dp[i - 1][1]) {
      if (abs(A[i] - B[i - 1]) <= K) dp[i][0] = true;
      if (abs(B[i] - B[i - 1]) <= K) dp[i][1] = true;
    }
  }
  cout << (dp[N - 1][0] || dp[N - 1][1] ? "Yes" : "No") << endl;

  return 0;
}