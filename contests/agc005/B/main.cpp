#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
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

  int N;
  cin >> N;
  VI A(N);
  REP(i, 0, N) cin >> A[i];

  VLL L(N);
  stack<int> sl;
  sl.push(-1);
  REP(i, 0, N) {
    while (sl.top() >= 0 && A[sl.top()] >= A[i]) {
      int idx = sl.top();
      sl.pop();
      L[idx] = sl.top();
    }
    sl.push(i);
  }
  while (sl.top() >= 0) {
    int idx = sl.top();
    sl.pop();
    L[idx] = sl.top();
  }

  VLL R(N);
  stack<int> sr;
  sr.push(N);
  REPR(i, N - 1, 0) {
    while (sr.top() < N && A[sr.top()] >= A[i]) {
      int idx = sr.top();
      sr.pop();
      R[idx] = sr.top();
    }
    sr.push(i);
  }
  while (sr.top() < N) {
    int idx = sr.top();
    sr.pop();
    R[idx] = sr.top();
  }
  LL res = 0;
  for (LL i = 0;i < N;i++)
    res += (i - L[i]) * (R[i] - i) * A[i];
  cout << res << endl;

  return 0;
}