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
  int N, M;
  cin >> N >> M;
  VI F(N);
  REP(i, 0, N) cin >> F[i];

  VLL dp(N + 1, 0), S(N + 2, 0);
  dp[0] = S[1] = 1;

  unordered_map<int, int> C;
  int m = 0;
  for (int i = 0, j = 0; i < N; i++) {
    m = max(m, ++C[F[i]]);
    while (m > 1) {
      if (C[F[j]] == m)
        m--;
      C[F[j++]]--;
    }
    dp[i + 1] = sub(S[i + 1], S[j]);
    S[i + 2] = add(S[i + 1], dp[i + 1]);
  }

  cout << dp[N] << endl;

  return 0;
}