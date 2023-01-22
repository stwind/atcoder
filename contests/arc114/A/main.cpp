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
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

LL __gcd(LL x, LL y) { return !y ? x : __gcd(y, x % y); }

int main() {
  IOS;

  int N;
  cin >> N;
  VLL X(N);
  REP(i, 0, N) cin >> X[i];

  LL P[] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47 };
  set<LL> S;
  for (auto& p : P) REP(i, 0, N) if (X[i] % p == 0) S.insert(p);

  VLL SS(all(S));
  int h = SS.size();

  LL ans = 1e18;
  for (int bit = 1, n = 1 << h;bit < n;bit++) {
    LL cur = 1;
    REP(k, 0, h) if ((bit >> k) & 1) cur *= SS[k];

    bool good = true;
    REP(i, 0, N) if (gcd(X[i], cur) == 1) {
      good = false;
      break;
    }
    if (good) chmin(ans, cur);
  }
  cout << ans << endl;

  return 0;
}