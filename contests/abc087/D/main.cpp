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

template<class T>
class WeightedUnionFind {
  int n;
  VI p;
  vector<T> W;
public:
  explicit WeightedUnionFind(int n): n(n), p(n, -1), W(n) {};
  int unite(int a, int b, T w) {
    int x = find(a), y = find(b);
    if (x == y) return x;

    w += weight(a) - weight(b);
    if (-p[x] < -p[y]) swap(x, y), w = -w;

    W[y] = w;
    p[x] += p[y];
    return p[y] = x;
  }
  bool query(int a, int b) { return find(a) == find(b); }
  int find(int a) {
    if (p[a] < 0) return a;

    int r = find(p[a]);
    W[a] += W[p[a]];
    return p[a] = r;
  }
  int size(int a) { return -p[find(a)]; }
  T weight(int a) { find(a); return W[a]; }
  T diff(int a, int b) { return weight(b) - weight(a); }

  VVI groups() {
    VVI res(n);
    REP(i, 0, n) res[find(i)].push_back(i);
    res.erase(remove_if(all(res), [&](const VI& v) { return v.empty(); }), res.end());
    return res;
  }
};

int main() {
  IOS;

  int N, M; cin >> N >> M;
  VI L(M), R(M), D(M);
  REP(i, 0, M) cin >> L[i] >> R[i] >> D[i], L[i]--, R[i]--;

  WeightedUnionFind<int> uf(N);
  REP(i, 0, M) {
    if (uf.query(L[i], R[i])) {
      if (uf.diff(L[i], R[i]) != D[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
    else {
      uf.unite(L[i], R[i], D[i]);
    }
  }
  cout << "Yes" << endl;

  return 0;
}