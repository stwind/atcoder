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

  int N;
  cin >> N;
  VI X(N), Y(N);
  set<PII> S;
  REP(i, 0, N) {
    cin >> X[i] >> Y[i];
    S.insert({ X[i], Y[i] });
  }

  vector<PII> d = { {-1,-1},{-1,0},{0,-1},{0,1},{1,0},{1,1} };

  set<PII> seen;
  int res = 0;
  REP(i, 0, N) {
    if (seen.count({ X[i],Y[i] })) continue;
    seen.insert({ X[i],Y[i] });
    res++;

    queue<PII> q({ {X[i],Y[i]} });
    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();
      for (auto [j, k] : d) {
        int xx = x + j, yy = y + k;
        if (!S.count({ xx,yy }) || seen.count({ xx,yy })) continue;
        seen.insert({ xx,yy });
        q.push({ xx,yy });
      }
    }
  }
  cout << res << endl;

  return 0;
}