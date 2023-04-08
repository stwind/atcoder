// https://www.creativ.xyz/arc016c-605/
// https://kmjp.hatenablog.jp/entry/2013/11/05/0930
// https://noy72.com/articles/2017-10-27-arc-016-c/
// https://kyopro.hateblo.jp/entry/2019/07/15/013501

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

  LL H, W; cin >> H >> W;

  LL res = LONG_MAX;
  REP(i, 1, H) {
    LL a = W * i;
    LL w = W, h = H - i;
    LL r = w * h;
    LL b = w / 2 * h, c = r - b;
    chmin(res, max(a, max(b, c)) - min(a, min(b, c)));
    b = h / 2 * w, c = r - b;
    chmin(res, max(a, max(b, c)) - min(a, min(b, c)));
  }
  REP(i, 1, W) {
    LL a = H * i;
    LL w = W - i, h = H;
    LL r = w * h;
    LL b = w / 2 * h, c = r - b;
    chmin(res, max(a, max(b, c)) - min(a, min(b, c)));
    b = h / 2 * w, c = r - b;
    chmin(res, max(a, max(b, c)) - min(a, min(b, c)));
  }

  cout << res << endl;

  return 0;
}