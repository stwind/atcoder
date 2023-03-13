// https://tutuz.hateblo.jp/entry/2018/08/23/231229

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

const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];

void comb_init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

long long comb(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  IOS;

  comb_init();

  LL R, C, X, Y, D, L;
  cin >> R >> C >> X >> Y >> D >> L;

  LL N = 0;
  for (int bit = 0;bit < 16;bit++) {
    int x = X, y = Y;
    if ((bit >> 0 & 1) == 1) x--;
    if ((bit >> 1 & 1) == 1) x--;
    if ((bit >> 2 & 1) == 1) y--;
    if ((bit >> 3 & 1) == 1) y--;
    if (x < 0 || y < 0) continue;
    LL M = mul(comb(x * y, D + L), comb(D + L, D));
    if (__builtin_popcount(bit) % 2 == 0)
      N = add(N, M);
    else
      N = sub(N, M);
  }
  cout << mul(N, mul(R - X + 1, C - Y + 1)) << endl;

  return 0;
}