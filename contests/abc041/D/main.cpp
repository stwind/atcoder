// ref:
// https://ikatakos.com/pot/programming_algorithm/graph_theory/topological_sort

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 61)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main() {
  int N, M;
  cin >> N >> M;

  int x, y;
  VI G(N);
  forn(i, 0, M) {
    cin >> x >> y;
    x--, y--;
    G[x] |= 1 << y;
  }

  VLL dp(1 << N);
  dp[0] = 1;
  forn(i, 0, 1 << N) {
    forn(j, 0, N) {
      int x = 1 << j;
      if ((i & x) == 0 && (G[j] & i) == 0) {
        dp[i | x] += dp[i];
      }
    }
  }
  cout << dp[(1 << N) - 1] << endl;

  return 0;
}