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

  int N, M, E; cin >> N >> M >> E;
  VI U(E), V(E);
  REP(i, 0, E) {
    cin >> U[i] >> V[i];
    chmin(--U[i], N);
    chmin(--V[i], N);
  }

  int Q; cin >> Q;
  VI X(Q);
  vector<bool> Xs(E, true);
  REP(i, 0, Q) cin >> X[i], Xs[--X[i]] = false;

  UnionFind uf(N + 1);
  REP(i, 0, E) if (Xs[i]) uf.unite(U[i], V[i]);

  VI res(Q);
  REPR(i, Q - 1, 0) {
    res[i] = uf.size(N) - 1;
    uf.unite(U[X[i]], V[X[i]]);
  }

  REP(i, 0, Q) cout << res[i] << endl;

  return 0;
}