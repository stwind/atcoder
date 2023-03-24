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
template <typename T> T mul(T a, T b) { return 1ULL * a * b % MOD; }
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
  explicit UnionFind(int n): n(n), p(n, -1) {};
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
  VI X(N), Y(N);
  REP(i, 0, N) cin >> X[i] >> Y[i];

  vector<tuple<int, int, int>> E;
  VI I(N); REP(i, 0, N) I[i] = i;
  sort(all(I), [&](int a, int b) { return X[a] < X[b]; });
  REP(i, 0, N - 1) {
    int ii = I[i], jj = I[i + 1];
    E.push_back({ abs(X[ii] - X[jj]),ii,jj });
  }
  sort(all(I), [&](int a, int b) { return Y[a] < Y[b]; });
  REP(i, 0, N - 1) {
    int ii = I[i], jj = I[i + 1];
    E.push_back({ abs(Y[ii] - Y[jj]),ii,jj });
  }
  sort(all(E));

  UnionFind uf(N);
  LL res = 0;
  for (auto [c, i, j] : E) {
    if (uf.query(i, j)) continue;
    res += c;
    uf.unite(i, j);
  }
  cout << res << endl;

  return 0;
}