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
template <typename T> T mul(T a, T b) { return ((a) * (b)) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

LL invm(LL a, LL m = MOD) {
  LL b = m, u = 1, v = 0;
  while (b) {
    LL t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  return (u % m + m) % m;
}

int main() {
  IOS;

  int T;cin >> T;
  int N, S, K;
  REP(i, 0, T) {
    cin >> N >> S >> K;
    int d = gcd(gcd(K, N), S);
    N /= d, S /= d, K /= d;
    if (gcd(K, N) == 1)
      cout << invm(K, N) * (-S % N + N) % N << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}