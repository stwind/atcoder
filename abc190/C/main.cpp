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
  int N, M, K;
  cin >> N >> M;
  VI A(M), B(M);
  REP(i, 0, M) {
    cin >> A[i] >> B[i];
    A[i]--, B[i]--;
  }
  cin >> K;
  VI C(K), D(K);
  REP(i, 0, K) {
    cin >> C[i] >> D[i];
    C[i]--, D[i]--;
  }

  int res = 0;
  for (int bit = 0; bit < (1 << K); bit++) {
    vector<bool> balls(N);
    REP(i, 0, K) balls[bit & (1 << i) ? C[i] : D[i]] = true;

    int tot = 0;
    REP(i, 0, M) if (balls[A[i]] && balls[B[i]]) tot++;
    chmax(res, tot);
  }
  cout << res << endl;

  return 0;
}