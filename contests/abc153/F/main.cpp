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

  int N, D, A;
  cin >> N >> D >> A;
  VI X(N), H(N);
  REP(i, 0, N) cin >> X[i] >> H[i];

  VI I(N);
  REP(i, 0, N) I[i] = i;
  sort(all(I), [&](int a, int b) { return X[a] < X[b]; });

  VLL C(N + 1);
  LL res = 0;
  for (int i = 0, j = 0; i < N; i++) {
    if (i > 0) C[i] += C[i - 1];

    while (j < N && X[I[j]] - X[I[i]] <= D * 2) j++;

    H[I[i]] -= C[i];
    LL h = CEIL(max(0, H[I[i]]), A);
    res += h;

    C[i] += h * A;
    C[j] -= h * A;
  }
  cout << res << endl;

  return 0;
}