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

  int N; cin >> N;

  function<bool(string)> check = [](string s) {
    if (s[1] == 'A' && s[2] == 'G' && s[3] == 'C') return false;
    if (s[1] == 'G' && s[2] == 'A' && s[3] == 'C') return false;
    if (s[1] == 'A' && s[2] == 'C' && s[3] == 'G') return false;
    if (s[0] == 'A' && s[2] == 'G' && s[3] == 'C') return false;
    if (s[0] == 'A' && s[1] == 'G' && s[3] == 'C') return false;
    return true;
    };

  vector<unordered_map<string, LL>> dp(N);
  function<LL(int, string)> dfs = [&](int i, string s) {
    if (i == N) return 1LL;
    if (dp[i].count(s)) return dp[i][s];

    string t = s.substr(1);
    LL res = dfs(i + 1, t + 'T');
    if (check(s + 'A')) res = add(res, dfs(i + 1, t + 'A'));
    if (check(s + 'C')) res = add(res, dfs(i + 1, t + 'C'));
    if (check(s + 'G')) res = add(res, dfs(i + 1, t + 'G'));

    return dp[i][s] = res;
    };

  cout << dfs(0, "TTT") << endl;

  return 0;
}