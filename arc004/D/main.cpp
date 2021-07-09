#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) (a + b - 1) / b
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

const int MAX = 300000;
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
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

template <typename T> T powm(T x, T k) {
  T res = 1;
  while (k) {
    if (k & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return res;
}

int main() {
  IOS;
  int N, M;
  cin >> N >> M;

  comb_init();

  N = abs(N);
  LL res = 1;
  for (int i = 2; i <= sqrt(N); i++) {
    if (N % i != 0)
      continue;

    int k = 0;
    while (N % i == 0) {
      k++;
      N /= i;
    }
    res = res * comb(M + k - 1, k) % MOD;
  }
  if (N > 1)
    res = res * comb(M, 1) % MOD;

  res = res * powm(2LL, (LL)M - 1) % MOD;
  cout << res << endl;

  return 0;
}