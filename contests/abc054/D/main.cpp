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
#define MOD 998244353
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

int main() {
  IOS;

  int N, MA, MB; cin >> N >> MA >> MB;
  VI A(N), B(N), C(N);
  REP(i, 0, N) cin >> A[i] >> B[i] >> C[i];

  int INF = 1 << 30;
  int N2 = N / 2, n = 1 << N2;
  unordered_map<int, int> G;
  REP(s, 1, n) {
    int a = 0, b = 0, c = 0;
    REP(i, 0, N2) if (s >> i & 1)
      a += A[i], b += B[i], c += C[i];
    int k = MA * b - MB * a;
    if (G.count(k)) chmin(G[k], c);
    else G[k] = c;
  }

  int res = G.count(0) ? G[0] : INF;
  int M = N - N2, m = 1 << M;
  REP(s, 1, m) {
    int a = 0, b = 0, c = 0;
    REP(i, 0, M) if (s >> i & 1)
      a += A[i + N2], b += B[i + N2], c += C[i + N2];

    int k = MB * a - MA * b;
    if (k == 0) chmin(res, c);
    else if (G.count(k)) chmin(res, c + G[k]);
  }
  cout << (res < INF ? res : -1) << endl;

  return 0;
}