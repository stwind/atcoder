#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
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
  int X0, Y0, XN2, YN2;
  cin >> X0 >> Y0 >> XN2 >> YN2;

  double dx = XN2 - X0, dy = YN2 - Y0;
  double D = sqrt(dx * dx + dy * dy);
  double beta = (N - 2) * .5 * M_PI / N;
  double alpha = 2.0 * M_PI / N;
  double S = sin(alpha) / sin(beta) * D / 2.;

  double ang = atan2(dy, dx) - beta;
  double x = X0 + S * cos(ang), y = Y0 + S * sin(ang);
  cout << fixed << setprecision(12) << x << " " << y << endl;

  return 0;
}