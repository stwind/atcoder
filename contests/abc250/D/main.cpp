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

VI sieve_of_eratosthenes(int n) {
  VI P(n + 1, 1);
  P[0] = P[1] = 0;
  REP(p, 2, sqrt(n) + 1) {
    if (!P[p]) continue;
    for (int i = p; p * i <= n; i++)
      P[p * i] = 0;
  }
  return P;
}

int main() {
  IOS;

  LL N;
  cin >> N;

  int n = min(N, 1000000LL);
  VI P = sieve_of_eratosthenes(n);

  int res = 0;
  for (LL q = 2; q <= n; q++) {
    if (!P[q]) continue;
    LL q3 = q * q * q;
    for (LL p = 2;p < q && p * q3 <= N;p++) {
      if (P[p]) res++;
    }
  }
  cout << res << endl;

  return 0;
}