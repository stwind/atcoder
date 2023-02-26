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

class UnionFind {
  int n;
  VI p;
public:
  UnionFind(int n): n(n), p(n, -1) {};
  int unite(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return x;
    if (-p[x] < -p[y]) std::swap(x, y);
    p[x] += p[y];
    return p[y] = x;
  }
  bool query(int a, int b) { return find(a) == find(b); }
  int find(int a) { return p[a] < 0 ? a : p[a] = find(p[a]); }
  int size(int a) { return -p[find(a)]; }

  VVI groups() {
    VVI res(n);
    REP(i, 0, n) res[find(i)].push_back(i);
    res.erase(remove_if(all(res), [&](const VI& v) { return v.empty(); }), res.end());
    return res;
  }
};

int main() {
  IOS;

  int N; cin >> N;
  LL Sx, Sy, Tx, Ty; cin >> Sx >> Sy >> Tx >> Ty;
  VLL X(N + 2), Y(N + 2), R(N + 2);
  REP(i, 0, N) cin >> X[i] >> Y[i] >> R[i];
  X[N] = Sx, Y[N] = Sy, R[N] = 0;
  X[N + 1] = Tx, Y[N + 1] = Ty, R[N + 1] = 0;

  auto dist = [](LL x1, LL y1, LL x2, LL y2) {
    LL dx = x2 - x1, dy = y2 - y1;
    return dx * dx + dy * dy;
  };

  auto is_crossed = [&](int i, int j) {
    LL d = dist(X[i], Y[i], X[j], Y[j]);
    LL r0 = R[i] - R[j], r1 = R[i] + R[j];
    return r0 * r0 <= d && d <= r1 * r1;
  };

  UnionFind uf(N + 2);
  REP(i, 0, N + 2) REP(j, i + 1, N + 2) {
    if (is_crossed(i, j)) uf.unite(i, j);
  }

  cout << (uf.query(N, N + 1) ? "Yes" : "No") << endl;

  return 0;
}