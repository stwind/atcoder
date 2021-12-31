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
  string S, X;
  cin >> N >> S >> X;

  VVI dp(N + 1, VI(7));
  dp[N][0] = 1;

  REPR(i, N - 1, 0) {
    REP(r, 0, 7) {
      if (X[i] == 'T') {
        if (dp[i + 1][(10 * r) % 7] || dp[i + 1][(10 * r + (S[i] - '0')) % 7])
          dp[i][r] = 1;
      } else {
        if (dp[i + 1][(10 * r) % 7] && dp[i + 1][(10 * r + (S[i] - '0')) % 7])
          dp[i][r] = 1;
      }
    }
  }
  if (dp[0][0])
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;

  return 0;
}