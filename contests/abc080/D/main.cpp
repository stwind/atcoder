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
  int N, M;
  cin >> N >> M;
  vector<vector<PII>> C(M);
  int s, t, c;
  forn(i, 0, N) {
    cin >> s >> t >> c;
    C[--c].emplace_back(s, t);
  }

  vector<PII> X;
  int m = 0;

  for (auto &c : C) {
    sort(all(c));
    int n = c.size();
    for (int i = 0; i < n; i++) {
      int s = c[i].first, t = c[i].second;
      while (i < n - 1 && c[i + 1].first == t)
        t = c[++i].second;
      X.emplace_back(s, t);
      chmax(m, t);
    }
  }

  VI Y(m * 2);
  for (auto x : X) {
    Y[x.first]++;
    Y[x.second + 1]--;
  }
  forn(i, 1, m + 2) Y[i] += Y[i - 1];
  cout << *max_element(all(Y)) << endl;

  return 0;
}