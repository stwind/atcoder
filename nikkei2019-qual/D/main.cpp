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
  int N, M;
  cin >> N >> M;
  VI D(N);
  VVI G(N);
  int a, b;
  forn(i, 0, N + M - 1) {
    cin >> a >> b;
    a--, b--;
    D[b]++;
    G[a].push_back(b);
  }

  unordered_map<int, int> P;
  queue<int> q;
  forn(i, 0, N) {
    if (D[i] == 0) {
      q.push(i);
      P[i] = -1;
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v : G[u]) {
      D[v]--;
      if (D[v] == 0) {
        q.push(v);
        P[v] = u;
      }
    }
  }
  forn(i, 0, N) cout << P[i] + 1 << endl;

  return 0;
}