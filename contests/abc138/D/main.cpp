#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 61)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
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
using PLL = pair<LL, LL>;

int main() {
  IOS;
  int N, Q;
  cin >> N >> Q;

  VVI E(N);
  int a, b;
  forn(i, 0, N - 1) {
    cin >> a >> b;
    a--, b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  VLL C(N);
  int p, x;
  forn(i, 0, Q) {
    cin >> p >> x;
    p--;
    C[p] += x;
  }

  function<void(int, int)> dfs = [&](int u, int p = -1) {
    for (auto v : E[u])
      if (v != p) {
        C[v] += C[u];
        dfs(v, u);
      }
  };
  dfs(0, -1);

  forn(i, 0, N) {
    if (i)
      cout << " ";
    cout << C[i];
  }
  cout << endl;

  return 0;
}