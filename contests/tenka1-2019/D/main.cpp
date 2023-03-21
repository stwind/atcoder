// https://kyopro.hateblo.jp/entry/2019/04/21/015945
// https://betrue12.hateblo.jp/entry/2019/04/21/150214

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
template <typename T> T mul(T a, T b) { return 1ULL * a * b % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

LL powm(LL x, LL k) {
  LL res = 1;
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

  int N; cin >> N;
  VI A(N); REP(i, 0, N) cin >> A[i];

  int S = accumulate(all(A), 0);

  VVLL dp1(N + 1, VLL(S + 1, 0)), dp2(N + 1, VLL(S + 1, 0));
  dp1[0][0] = dp2[0][0] = 1;
  REP(i, 0, N) {
    REP(s, 0, S + 1) {
      dp1[i + 1][s] = mul(dp1[i][s], 2LL);
      if (A[i] <= s) dp1[i + 1][s] = add(dp1[i + 1][s], dp1[i][s - A[i]]);

      dp2[i + 1][s] = dp2[i][s];
      if (A[i] <= s) dp2[i + 1][s] = add(dp2[i + 1][s], dp2[i][s - A[i]]);
    }
  }

  LL s = 0;
  REP(i, CEIL(S, 2), S + 1) s = add(s, dp1[N][i]);

  LL res = sub(powm(3LL, N), mul(s, 3LL));
  if (S % 2 == 0) res = add(res, mul(dp2[N][S / 2], 3LL));
  cout << res << endl;

  return 0;
}