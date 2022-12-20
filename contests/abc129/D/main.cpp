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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];

  VVI R(H), C(W);
  REP(i, 0, H) R[i].push_back(-1);
  REP(i, 0, W) C[i].push_back(-1);

  REP(i, 0, H) REP(j, 0, W) {
    if (S[i][j] == '#') {
      R[i].push_back(j);
      C[j].push_back(i);
    }
  }
  REP(i, 0, H) R[i].push_back(W);
  REP(i, 0, W) C[i].push_back(H);

  auto get = [&](VI &a, int x) {
    int lo = 0, hi = a.size(), mid;
    while (hi - lo > 1) {
      mid = (lo + hi) / 2;
      if (a[mid] < x)
        lo = mid;
      else
        hi = mid;
    }
    return a[hi] - a[lo] - 1;
  };

  int res = 0;
  REP(i, 0, H) {
    REP(j, 0, W) {
      if (S[i][j] == '#')
        continue;

      int r = get(R[i], j);
      int c = get(C[j], i);
      chmax(res, r + c - 1);
    }
  }
  cout << res << endl;

  return 0;
}