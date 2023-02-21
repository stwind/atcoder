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

  int N;cin >> N;
  VLL X(N), Y(N), P(N);
  REP(i, 0, N) cin >> X[i] >> Y[i] >> P[i];

  auto check = [&](LL s) {
    REP(i, 0, N) {
      set<int> S({ i });
      queue<int> q({ i });
      while (!q.empty()) {
        int u = q.front();q.pop();
        REP(v, 0, N) if (u != v && S.count(v) == 0) {
          if (P[u] * s >= abs(X[u] - X[v]) + abs(Y[u] - Y[v])) {
            S.insert(v);
            q.push(v);
          }
        }
      }
      if ((int)S.size() == N) return true;
    }
    return false;
  };

  LL l = -1, r = 4000000001LL, m;
  while (l + 1 < r) {
    m = (l + r) / 2;
    if (check(m)) r = m;
    else l = m;
  }
  cout << r << endl;

  return 0;
}