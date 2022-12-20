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
  IOS;
  int R, C, K;
  cin >> R >> C >> K;
  vector<string> S(R);
  forn(i, 0, R) cin >> S[i];

  VVI D(R, VI(C + 1));
  forn(r, 0, R) forn(c, 0, C) {
    if (S[r][c] == 'o')
      continue;

    forn(k, 0, K) {
      if (r - k >= 0) {
        D[r - k][max(0, c - K + 1 + k)]++;
        D[r - k][min(C - 1, c + K - k)]--;
      }
      if (k > 0 && r + k < R) {
        D[r + k][max(0, c - K + 1 + k)]++;
        D[r + k][min(C - 1, c + K - k)]--;
      }
    }
  }
  forn(r, 0, R) forn(c, 1, C + 1) D[r][c] += D[r][c - 1];

  int res = 0;
  forn(r, K - 1, R - K + 1) forn(c, K - 1, C - K + 1) {
    if (D[r][c] == 0)
      res++;
  }
  cout << res << endl;

  return 0;
}