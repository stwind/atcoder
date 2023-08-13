#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define PARENS ()
#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__
#define FOR_EACH(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define DBG(x) cout << #x << ": " << x << " ";
#define DEBUG(...) FOR_EACH(DBG, __VA_ARGS__) cout << endl;
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
  UnionFind(int n) : n(n), p(n, -1) {};
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
  VI A(N), B(N);
  int m = 0;
  REP(i, 0, N) cin >> A[i] >> B[i], chmax(m, max(A[i], B[i]));

  VVI G(m + 1);
  UnionFind uf(m + 1);
  REP(i, 0, N) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
    uf.unite(A[i], B[i]);
  }

  VI seen(m + 1);
  function<bool(int, int)> dfs = [&](int u, int p) {
    if (seen[u]) return false;

    seen[u] = 1;
    for (auto v : G[u]) if (v != p) {
      if (!dfs(v, u)) return false;
    }
    return true;
    };

  VI S(m + 1);
  int res = 0;
  REP(i, 1, m + 1) {
    int r = uf.find(i);
    if (S[r]) continue;

    S[r] = uf.size(r);
    res += dfs(r, -1) ? S[r] - 1 : S[r];
  }
  cout << res << endl;

  return 0;
}