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
  VI A(N);
  REP(i, 0, N) cin >> A[i];

  VI L(N), R(N);
  L[0] = A[0];
  R[N - 1] = A[N - 1];
  REP(i, 1, N) L[i] = gcd(L[i - 1], A[i]);
  REPR(i, N - 2, 0) R[i] = gcd(R[i + 1], A[i]);

  int res = 1;
  REP(i, 0, N) {
    int cur = 1;
    if (i == 0) cur = R[1];
    else if (i == N - 1) cur = L[i - 1];
    else cur = gcd(L[i - 1], R[i + 1]);
    chmax(res, cur);
  }
  cout << res << endl;

  return 0;
}