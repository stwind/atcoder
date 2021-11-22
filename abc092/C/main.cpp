// https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2019/0727_abc135#f_-_strings_of_eternity

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 61)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main() {
  int N;
  cin >> N;
  VI A(N);
  REP(i, 0, N) cin >> A[i];

  VLL D(N + 1);
  D[0] = abs(A[0]);
  D[N] = abs(A[N - 1]);
  REP(i, 0, N - 1) D[i + 1] = abs(A[i + 1] - A[i]);

  VI C(N);
  C[0] = abs(A[1]);
  C[N - 1] = abs(A[N - 2]);
  REP(i, 1, N - 1) C[i] = abs(A[i - 1] - A[i + 1]);

  LL s = accumulate(all(D), 0);
  REP(i, 0, N) cout << s - D[i] - D[i + 1] + C[i] << endl;

  return 0;
}