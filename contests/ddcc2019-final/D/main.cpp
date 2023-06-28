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

int ceil_pow2(int x) {
  x--;
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return ++x;
};

using Mat = vector<unsigned int>;

Mat eye() {
  Mat m(36);
  REP(i, 0, 6) m[i * 6 + i] = 1;
  return m;
}

Mat matmul(Mat& a, Mat& b) {
  Mat out(36);
  REP(i, 0, 6) REP(j, 0, 6) REP(k, 0, 6)
    out[i * 6 + j] += b[i * 6 + k] * a[k * 6 + j];
  return out;
};

int main() {
  IOS;

  string S; cin >> S;
  int Q; cin >> Q;
  VI L(Q), R(Q);
  REP(i, 0, Q) cin >> L[i] >> R[i], L[i]--;

  int N = S.length();
  int M = ceil_pow2(N);

  vector<Mat> d(M * 2, eye());
  REP(i, 0, N) {
    Mat m = eye();
    if (S[i] == 'D') m[1 * 6 + 0] = 1;
    if (S[i] == 'I') m[2 * 6 + 1] = 1;
    if (S[i] == 'S') m[3 * 6 + 2] = 1;
    if (S[i] == 'C') m[4 * 6 + 3] = 1;
    if (S[i] == 'O') m[5 * 6 + 4] = 1;
    d[i + M] = m;
  }

  for (int i = M - 1;i > 0;i--)
    d[i] = matmul(d[i * 2], d[i * 2 + 1]);

  auto query = [&](int l, int r) {
    Mat sml = eye(), smr = eye();
    for (l += M, r += M;l < r;l >>= 1, r >>= 1) {
      if (l & 1) sml = matmul(sml, d[l++]);
      if (r & 1) smr = matmul(d[--r], smr);
    }
    return matmul(sml, smr);
    };


  REP(k, 0, Q) {
    Mat m = query(L[k], R[k]);
    cout << m[5 * 6] << endl;
  }

  return 0;
}