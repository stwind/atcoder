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

  int N, M; cin >> N >> M;
  VI L(M), R(M); REP(i, 0, M) cin >> L[i] >> R[i], L[i]--, R[i]--;

  VI A(N), B(N + 1), C(N);
  REP(i, 0, M) {
    A[L[i]]++, B[R[i]]++;
    C[L[i]]++, C[R[i]]++;
  }

  LL P1 = 0;
  REP(i, 0, N) P1 += 1LL * C[i] * (C[i] - 1) / 2;

  LL P2 = 0, S = 0;
  REP(i, 0, N) {
    P2 += S * A[i];
    S += B[i];
  }

  VI I(M); REP(i, 0, M) I[i] = i;
  sort(all(I), [&](int a, int b) { return R[a] == R[b] ? L[a] < L[b] : R[a] < R[b]; });

  LL P3 = 0;
  BinaryIndexTree<LL> bit(N + 2);
  for (auto i : I) {
    P3 += bit.query(N + 1) - bit.query(L[i] + 1);
    bit.set(L[i] + 1, 1);
  }

  LL tot = 1LL * M * (M - 1) / 2;
  cout << tot - P1 - P2 - P3 << endl;

  return 0;
}