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

int fac(int n) {
  int res = 1;
  REPR(i, n, 1) res *= i;
  return res;
};

int main() {
  IOS;

  int N; cin >> N;
  VI P(N), Q(N);
  REP(i, 0, N) cin >> P[i];
  REP(i, 0, N) cin >> Q[i];

  VI I(N); REP(i, 0, N) I[i] = i;

  int p = -1, q = -1, k = 0;
  do {
    bool gp = true, gq = true;
    REP(i, 0, N) {
      if (P[i] - 1 != I[i]) gp = false;
      if (Q[i] - 1 != I[i]) gq = false;
    }
    if (gp) p = k;
    if (gq) q = k;

    k++;
  } while (next_permutation(all(I)));
  cout << abs(p - q) << endl;

  return 0;
}