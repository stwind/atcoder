// https://emtubasa.hateblo.jp/entry/2018/11/09/031048
// https://yottagin.com/?p=7786

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

  int R, C, K;
  cin >> R >> C >> K;
  vector<string> S(R);
  REP(r, 0, R) cin >> S[r];

  VVI M(R + 1, VI(C + 1));
  REP(r, 0, R) REP(c, 0, C) {
    if (S[r][c] == 'x') {
      REP(k, -K + 1, K) {
        int i = r + k;
        if (i < 0 || i > R) continue;
        M[i][max(0, min(C, c + abs(k) - K + 1))]++;
        M[i][max(0, min(C, c - abs(k) + K))]--;
      }
    }
  }

  REP(r, 0, R + 1) {
    REP(c, 0, C) M[r][c + 1] += M[r][c];
  }

  int res = 0;
  REP(r, K - 1, R - K + 1) REP(c, K - 1, C - K + 1) {
    if (M[r][c] == 0) res++;
  }
  cout << res << endl;

  return 0;
}