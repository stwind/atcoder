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
public:
  VI root, rank, cnt;
  UnionFind(int n): n(n) {
    root = rank = VI(n, 0);
    cnt = VI(n, 1);
    REP(i, 0, n) root[i] = i;
  }
  int find(int x) {
    return root[x] == x ? x : root[x] = find(root[x]);
  }
  int link(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return x;

    cnt[y] = cnt[x] = cnt[x] + cnt[y];

    if (rank[x] > rank[y]) return root[y] = x;
    else if (rank[x] < rank[y]) return root[x] = y;

    rank[x] += rank[x] == rank[y];
    return root[y] = x;
  }
  int count(int x) {
    return cnt[find(x)];
  }
  bool query(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  IOS;

  int N, M;cin >> N >> M;

  UnionFind uf(N);
  map<int, int> C;

  REP(i, 0, M) {
    int a, b;cin >> a >> b;a--, b--;
    if (++C[a] > 2 || ++C[b] > 2 || uf.query(a, b)) {
      cout << "No" << endl;
      return 0;
    }
    uf.link(a, b);
  }
  cout << "Yes" << endl;

  return 0;
}