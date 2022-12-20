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

int main() {
  IOS;
  int N, Q;
  cin >> N;
  VVI D(N, VI(N));
  forn(i, 0, N) forn(j, 0, N) cin >> D[i][j];
  cin >> Q;
  VI P(Q);
  forn(i, 0, Q) cin >> P[i];

  VVI C(N + 1, VI(N + 1));
  forn(i, 0, N) forn(j, 0, N) {
    C[i + 1][j + 1] = D[i][j] + C[i + 1][j] + C[i][j + 1] - C[i][j];
  }

  VI A(N * N + 1);
  forn(i, 0, N) forn(j, 0, N) forn(k, 0, i + 1) forn(l, 0, j + 1) {
    int a = C[i + 1][j + 1] - C[i + 1][l] - C[k][j + 1] + C[k][l];
    int p = (i - k + 1) * (j - l + 1);
    A[p] = max(A[p], a);
  }

  int n = A.size();
  VI S(n + 1);
  forn(i, 0, n) S[i + 1] = max(S[i], A[i]);

  for (auto &p : P)
    cout << S[p + 1] << endl;

  return 0;
}