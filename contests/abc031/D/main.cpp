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

  int K, N; cin >> K >> N;
  vector<string> V(N), W(N);
  REP(i, 0, N) cin >> V[i] >> W[i];

  for (int s = 0, n = pow(3, K); s < n; s++) {
    VI L(K);
    REP(i, 0, K) L[i] = (int)(s / pow(3, i)) % 3 + 1;

    bool ok = true;
    REP(i, 0, N) {
      int l = 0;
      for (auto c : V[i]) l += L[c - '0' - 1];
      if (l != (int)W[i].size()) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;

    vector<string> S(K, "");
    bool good = true;
    REP(i, 0, N) {
      int l = 0;
      bool ok = true;
      for (auto c : V[i]) {
        int k = c - '0' - 1;
        string sub = W[i].substr(l, L[k]);
        if (S[k] == "") S[k] = sub, l += L[k];
        else if (S[k] == sub) l += L[k];
        else {
          ok = false;
          break;
        }
      }
      if (!ok) {
        good = false;
        break;
      }
    }
    if (good) {
      for (auto s : S) cout << s << endl;
      break;
    }
  }

  return 0;
}