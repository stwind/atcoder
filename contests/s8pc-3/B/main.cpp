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

int main() {
  IOS;

  int H, W, K; cin >> H >> W >> K;
  VVI C(W);
  REP(i, 0, H) {
    string s; cin >> s;
    REP(j, 0, W) C[j].push_back(s[j] - '0');
  }
  REP(j, 0, W) reverse(all(C[j]));

  auto kesu = [&](VVI& C) -> int {
    int p = 0;
    VVI X(W);
    REP(i, 0, H) {
      for (int j = 0, k = 0; j < W;j = k) {
        while (k < W && (j > k || C[j][i] == C[k][i])) k++;
        if (k - j >= K) while (j < k) X[j].push_back(i), p += C[j++][i];
      }
    }

    REP(j, 0, W) {
      reverse(all(X[j]));
      for (auto i : X[j]) C[j].erase(C[j].begin() + i), C[j].push_back(0);
    }
    return p;
  };

  auto run = [&](VVI C, int r, int c) -> int {
    int tot = 0;
    C[c].erase(C[c].begin() + r); C[c].push_back(0);
    for (int i = 1, p = kesu(C); p; p = kesu(C), i *= 2)
      tot += i * p;
    return tot;
  };

  int res = 0;
  REP(r, 0, H) REP(c, 0, W) chmax(res, run(C, r, c));
  cout << res << endl;

  return 0;
}