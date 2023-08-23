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

  string first, last; cin >> first >> last;
  int N; cin >> N;
  vector<string> S(N); REP(i, 0, N) cin >> S[i];
  S.push_back(last);

  if (first == last) {
    cout << 0 << endl;
    cout << first << endl;
    cout << first << endl;
    return 0;
  }

  int n = S[0].size();
  auto diff = [&](string a, string b) {
    int m = 0;
    REP(i, 0, n) m += a[i] != b[i];
    return m;
    };

  queue<pair<string, int>> q({ {first,0} });
  unordered_map<string, pair<string, int>> P;
  P[first] = { "",0 };

  while (!q.empty()) {
    auto [cur, d] = q.front(); q.pop();
    if (diff(cur, last) == 0) break;

    REP(i, 0, N + 1) if (S[i] != first && diff(S[i], cur) == 1 && P.count(S[i]) == 0) {
      P[S[i]] = { cur, d + 1 };
      q.push({ S[i],d + 1 });
    }
  }

  if (P.count(last) == 0) {
    cout << -1 << endl;
    return 0;
  }
  else {
    auto [p, d] = P[last];

    cout << d - 1 << endl;
    vector<string> W;
    W.push_back(last);
    W.push_back(p);
    while (P[p].second) {
      W.push_back(P[p].first);
      p = P[p].first;
    }
    REPR(i, d, 0) cout << W[i] << endl;
  }

  return 0;
}