// https://kyopro.hateblo.jp/entry/2019/02/06/010004

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
using VVLL = vector<VLL>;\
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

constexpr double EPS = 1e-10;

int main() {
  IOS;

  LL N;
  cin >> N;
  VI X(N), Y(N);
  REP(i, 0, N) cin >> X[i] >> Y[i];

  LL right = 0, obtuse = 0;
  REP(i, 0, N) {
    vector<double> rad;
    REP(j, 0, N) if (j != i)
      rad.push_back(atan2(Y[j] - Y[i], X[j] - X[i]));
    sort(all(rad));
    REP(j, 0, N - 1)
      rad.push_back(rad[j] + M_PI * 2);

    int a = 1, b = 1;
    REP(j, 0, N - 1) {
      while (rad[a] - rad[j] < M_PI_2 - EPS) a++;
      while (rad[b] - rad[j] <= M_PI + EPS) b++;
      if (abs(rad[a] - rad[j] - M_PI_2) <= EPS) {
        right++;
        a++;
      }
      obtuse += b - a;
    }
  }
  LL acute = N * (N - 1) * (N - 2) / 6LL - right - obtuse;
  cout << acute << " " << right << " " << obtuse << endl;

  return 0;
}