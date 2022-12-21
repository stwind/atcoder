#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x;  i >= y; i--)
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
  cin >> N;
  VI X(N), Y(N);
  REP(i, 0, N)cin >> X[i] >> Y[i];

  auto calc = [](double x) -> double {
    return min(abs(x), M_PI * 2 - abs(x)) * 180 / M_PI;
  };

  double res = 0;
  REP(i, 0, N) {
    vector<double> angles;

    REP(j, 0, N) {
      if (i == j) continue;
      double x = X[j] - X[i], y = Y[j] - Y[i];
      angles.push_back(atan2(y, x));
    }
    sort(all(angles));

    REP(j, 0, N - 1) {
      double a = angles[j];
      auto lower = lower_bound(all(angles), a + M_PI);
      if (lower != angles.end())
        chmax(res, calc(a - *lower));
      chmax(res, calc(a - *(lower - 1)));
    }
  }
  cout << fixed << setprecision(15) << res << endl;

  return 0;
}