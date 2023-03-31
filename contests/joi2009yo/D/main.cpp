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

  int M, N; cin >> M >> N;
  VVI A(M, VI(N));
  REP(i, 0, M) REP(j, 0, N) cin >> A[i][j];

  VI dx = { 1,0,-1,0 }, dy = { 0,1,0,-1 };

  VVI S(M, VI(N));
  function<int(int, int)> dfs = [&](int y, int x) -> int {
    S[y][x] = 1;
    int cur = 0;
    REP(i, 0, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      if (0 <= xx && x < N && 0 <= yy && yy < M && S[yy][xx] == 0 && A[yy][xx] == 1) {
        chmax(cur, dfs(yy, xx));
      }
    }
    S[y][x] = 0;
    return cur + 1;
  };

  int res = 0;
  REP(i, 0, M) REP(j, 0, N) if (A[i][j] == 1) chmax(res, dfs(i, j));
  cout << res << endl;

  return 0;
}