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

  VI K, L;
  REP(k, 0, (int)sqrt(M) + 1) {
    int y = M - k * k;
    int l = sqrt(y);
    if (l * l == y) {
      K.push_back(k); L.push_back(l);
      K.push_back(-k); L.push_back(l);
      K.push_back(k); L.push_back(-l);
      K.push_back(-k); L.push_back(-l);
    }
  }
  int n = K.size();

  auto id = [&](int x, int y) { return y * N + x; };

  VVI D(N, VI(N, -1));
  VI seen(N * N);
  queue<tuple<int, int, int>> q({ {0, 0, 0} });
  while (!q.empty()) {
    auto [x, y, d] = q.front();
    q.pop();
    int idx = id(x, y);
    if (seen[idx]) continue;
    seen[idx] = 1;
    D[y][x] = d;

    REP(i, 0, n) {
      int xx = x + K[i], yy = y + L[i];
      if (0 <= xx && xx < N && 0 <= yy && yy < N && seen[id(xx, yy)] == 0)
        q.push({ xx,yy,d + 1 });
    }
  }
  REP(i, 0, N) {
    REP(j, 0, N) cout << D[i][j] << " ";
    cout << endl;
  }

  return 0;
}