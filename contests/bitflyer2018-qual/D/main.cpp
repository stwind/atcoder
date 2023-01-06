// https://emtubasa.hateblo.jp/entry/2018/11/09/103321
// https://sen-comp.hatenablog.com/entry/2019/11/29/163258
// https://blog.hamayanhamayan.com/entry/2018/06/02/235536

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
  int H, W, N, M;
  cin >> H >> W >> N >> M;
  vector<string> A(N);
  REP(i, 0, N) cin >> A[i];

  VI xd, yd;
  REP(i, 0, N) REP(j, 0, M) {
    if (A[i][j] == '#') {
      yd.push_back(i);
      yd.push_back(H - N + i + 1);
      xd.push_back(j);
      xd.push_back(W - M + j + 1);
    }
  }

  sort(all(xd));
  sort(all(yd));
  xd.erase(unique(all(xd)), xd.end());
  yd.erase(unique(all(yd)), yd.end());

  int h = yd.size(), w = xd.size();
  VVI B(h, VI(w));
  REP(i, 0, N) REP(j, 0, M) if (A[i][j] == '#') {
    int x1 = lower_bound(all(xd), j) - xd.begin();
    int y1 = lower_bound(all(yd), i) - yd.begin();
    int x2 = lower_bound(all(xd), W - M + j + 1) - xd.begin();
    int y2 = lower_bound(all(yd), H - N + i + 1) - yd.begin();

    B[y1][x1]++;
    B[y1][x2]--;
    B[y2][x1]--;
    B[y2][x2]++;
  }

  REP(i, 0, h) REP(j, 1, w) B[i][j] += B[i][j - 1];
  REP(i, 1, h) REP(j, 0, w) B[i][j] += B[i - 1][j];

  LL res = 0;
  REP(i, 0, h - 1) REP(j, 0, w - 1) {
    if (B[i][j]) {
      int x1 = xd[j];
      int y1 = yd[i];
      int x2 = xd[j + 1];
      int y2 = yd[i + 1];

      res += (LL)(x2 - x1) * (LL)(y2 - y1);
    }
  }
  cout << res << endl;

  return 0;
}