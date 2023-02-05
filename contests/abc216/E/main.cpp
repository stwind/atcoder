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

int main() {
  IOS;

  LL N, K;
  cin >> N >> K;
  VLL A(N);
  REP(i, 0, N) cin >> A[i];

  sort(all(A));

  LL l = 0, r = A[N - 1] + 1;
  while (l + 1 < r) {
    LL m = (l + r) / 2;
    LL c = 0;
    REPR(i, N - 1, 0) c += max(0LL, A[i] - m);
    if (c >= K) l = m;
    else r = m;
  }

  LL res = 0;
  REP(i, 0, N) if (A[i] >= r) {
    res += A[i] * (A[i] + 1) / 2 - r * (r + 1) / 2;
    K -= A[i] - r;
  }
  cout << res + min(N, K) * r << endl;

  return 0;
}