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

  LL N; cin >> N;
  VLL H(N), S(N);
  REP(i, 0, N) cin >> H[i] >> S[i];

  auto check = [&](LL X) -> bool {
    VLL C(N + 1);
    REP(i, 0, N) {
      if (X < H[i]) return false;

      LL d = (X - H[i]) / S[i];
      C[min(d, N)]++;
    }
    LL s = 0;
    REP(i, 0, N) {
      s += C[i];
      if (s > i + 1) return false;
    }
    return true;
  };

  LL l = 0, r = numeric_limits<LL>::max(), m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (check(m)) r = m;
    else l = m;
  }
  cout << r << endl;

  return 0;
}