// https://hackmd.io/@amoshyc/Hklf2KMXP#F-Range-Set-Query

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

template <class T = int>
struct BinaryIndexTree {
  int n;
  vector<T> data;
public:
  BinaryIndexTree(int n) : n(n), data(n, 0) {}
  void set(int i, T x) {
    for (; i < n; i += i & -i)
      data[i] += x;
  }
  T query(T r) {
    T s = 0;
    for (; r > 0; r -= r & -r)
      s += data[r];
    return s;
  }
  int lower_bound(T x) {
    T s = 0;
    int p = 0;
    for (int i = log2(n); i >= 0; i--) {
      int b = 1 << i;
      if (p + b < n && s + data[p + b] < x) {
        s += data[p += b];
      }
    }
    return p + 1;
  }
};

int main() {
  IOS;

  int N, Q; cin >> N >> Q;
  VI C(N); REP(i, 0, N) cin >> C[i], C[i]--;
  VI L(Q), R(Q); REP(i, 0, Q) cin >> L[i] >> R[i];

  VI I(Q); REP(i, 0, Q) I[i] = i;
  sort(all(I), [&](int a, int b) { return R[a] < R[b]; });

  BinaryIndexTree bit(N + 2);
  VI res(Q), last(N, -1);
  int j = 0;
  for (auto i : I) {
    while (j < R[i]) {
      if (last[C[j]] >= 0)
        bit.set(last[C[j]] + 1, -1);

      last[C[j]] = j;
      bit.set(++j, 1);
    }
    res[i] = bit.query(N + 1) - bit.query(L[i] - 1);
  }

  REP(i, 0, Q) cout << res[i] << endl;

  return 0;
}