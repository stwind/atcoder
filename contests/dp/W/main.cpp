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

struct LST {
  int n = 1, h;
  VLL d, lz;
  explicit LST(int N) {
    while (n < N) n *= 2;
    d.resize(2 * n);
    lz.resize(2 * n);
    h = log2(n);
  }

  void apply(int i, LL x) {
    d[i] += x;
    if (i < n) lz[i] += x;
  }

  void build(int i) {
    while (i > 1) {
      i >>= 1;
      d[i] = max(d[i << 1], d[i << 1 | 1]) + lz[i];
    }
  }

  void push(int p) {
    REPR(k, h, 1) {
      int i = p >> k;
      apply(i << 1, lz[i]);
      apply(i << 1 | 1, lz[i]);
      lz[i] = 0;
    }
  }

  void set(int l, int r, LL x) {
    l += n, r += n;
    for (int ll = l, rr = r; ll < rr; ll >>= 1, rr >>= 1) {
      if (ll & 1) apply(ll++, x);
      if (rr & 1) apply(--rr, x);
    }
    build(l), build(r - 1);
  }

  LL query(int l, int r) {
    l += n, r += n;
    push(l), push(r - 1);
    LL res = LONG_MIN;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) chmax(res, d[l++]);
      if (r & 1) chmax(res, d[--r]);
    }
    return res;
  }
};

int main() {
  IOS;

  int N, M; cin >> N >> M;
  unordered_map<int, vector<pair<int, LL>>> R;
  REP(i, 0, M) {
    int l, r, a; cin >> l >> r >> a;
    R[r].emplace_back(l, a);
  }

  LST lst(N + 1);
  REP(i, 1, N + 1) {
    lst.set(i, i + 1, lst.query(0, i));
    for (auto& [l, a] : R[i])
      lst.set(l, i + 1, a);
  }
  cout << lst.query(0, N + 1) << endl;

  return 0;
}