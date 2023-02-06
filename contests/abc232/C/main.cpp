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

  int N, M;
  cin >> N >> M;

  VVI G1(N, VI(N)), G2(N, VI(N));
  int a, b;
  REP(i, 0, M) {
    cin >> a >> b;
    a--, b--;
    G1[a][b] = G1[b][a] = 1;
  }
  REP(i, 0, M) {
    cin >> a >> b;
    a--, b--;
    G2[a][b] = G2[b][a] = 1;
  }

  VI P;
  REP(i, 0, N) P.push_back(i);
  do {
    bool good = true;
    REP(i, 0, N) REP(j, 0, N) {
      if (G1[i][j] && !G2[P[i]][P[j]]) good = false;
      if (!G1[i][j] && G2[P[i]][P[j]]) good = false;
    }
    if (good) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(all(P)));

  cout << "No" << endl;

  return 0;
}