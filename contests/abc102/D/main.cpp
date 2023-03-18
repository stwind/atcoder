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

int main() {
  IOS;

  int N; cin >> N;
  VLL A(N), C(N + 1);
  REP(i, 0, N) cin >> A[i], C[i + 1] = C[i] + A[i];

  LL res = numeric_limits<LL>::max();
  for (int i = 1, j = 2, k = 3; j < N - 1; j++) {
    while (i + 1 < j && abs(C[j] - C[i] * 2) > abs(C[j] - C[i + 1] * 2)) i++;
    while (k <= j || (k < N && abs(C[N] - C[k] * 2 + C[j]) > abs(C[N] - C[k + 1] * 2 + C[j]))) k++;
    LL P = C[i], Q = C[j] - C[i], R = C[k] - C[j], S = C[N] - C[k];
    chmin(res, max(P, max(Q, max(R, S))) - min(P, min(Q, min(R, S))));
  }
  cout << res << endl;

  return 0;
}