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

  int X, Y, Z, K; cin >> X >> Y >> Z >> K;
  VLL A(X), B(Y), C(Z);
  REP(i, 0, X) cin >> A[i];
  REP(i, 0, Y) cin >> B[i];
  REP(i, 0, Z) cin >> C[i];
  sort(rall(A));
  sort(rall(B));
  sort(rall(C));

  using T = tuple<LL, int, int, int>;
  priority_queue<T, vector<T>, less<T>> q;
  q.push({ A[0] + B[0] + C[0],0,0,0 });

  auto id = [](int i, int j, int k) { return 1000000 * i + 1000 * j + k; };
  unordered_set<int> S;
  S.insert(0);

  REP(_, 0, K) {
    auto [x, i, j, k] = q.top(); q.pop();
    cout << x << endl;

    if (i < X - 1 && S.count(id(i + 1, j, k)) == 0) {
      S.insert(id(i + 1, j, k));
      q.push({ A[i + 1] + B[j] + C[k],i + 1,j,k });
    }
    if (j < Y - 1 && S.count(id(i, j + 1, k)) == 0) {
      S.insert(id(i, j + 1, k));
      q.push({ A[i] + B[j + 1] + C[k],i,j + 1,k });
    }
    if (k < Z - 1 && S.count(id(i, j, k + 1)) == 0) {
      S.insert(id(i, j, k + 1));
      q.push({ A[i] + B[j] + C[k + 1],i,j,k + 1 });
    }
  }

  return 0;
}