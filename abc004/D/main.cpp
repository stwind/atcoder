// https://competitive-kivantium.hateblo.jp/entry/2016/12/15/104215

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
  int R, G, B;
  cin >> R >> G >> B;

  int tot = R + G + B;
  auto cost = [&](int i, int j) -> int {
    if (j >= R + G)
      return abs(400 - i);
    else if (j >= R)
      return abs(500 - i);
    return abs(600 - i);
  };

  int n = 1000;
  VVI dp(n, VI(n, 1 << 30));
  REP(i, 0, n) dp[i][tot] = 0;
  REP(i, 1, n) REP(j, 0, tot) {
    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1] + cost(i, j));
  }
  int res = 1 << 30;
  REP(i, 0, n) chmin(res, dp[i][0]);
  cout << res << endl;

  return 0;
}