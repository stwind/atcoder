#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
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
  int N;
  cin >> N;
  vector<string> A(N), B(N);

  vector<unordered_set<int>> G(26);
  string a, b;
  REP(i, 0, N) {
    cin >> a >> b;
    int n = a.size(), m = b.size();
    bool f = false;
    REP(j, 0, min(n, m)) {
      if (a[j] != b[j]) {
        G[a[j] - 'a'].insert(b[j] - 'a');
        f = true;
        break;
      }
    }
    if (!f && n >= m) {
      cout << -1 << endl;
      return 0;
    }
  }

  VI D(G.size());
  for (auto vs : G)
    for (auto v : vs)
      D[v]++;

  priority_queue<int, VI, greater<int>> q;
  REP(i, 0, 26) {
    if (D[i] == 0)
      q.push(i);
  }

  VI X;
  while (!q.empty()) {
    int u = q.top();
    q.pop();
    X.push_back(u);
    for (auto v : G[u]) {
      if (--D[v] == 0)
        q.push(v);
    }
  }
  if ((int)X.size() != 26) {
    cout << -1 << endl;
    return 0;
  }
  string res = "";
  for (auto x : X)
    res.push_back('a' + x);
  cout << res << endl;

  return 0;
}