// https://tnyo43.hatenablog.com/entry/2020/04/29/184727
// https://betrue12.hateblo.jp/entry/2019/10/19/163736

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
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

  int N, M;
  cin >> N >> M;
  VI A(N);
  REP(i, 0, N) cin >> A[i], A[i]--;

  LL tot = 0;
  VLL B(2 * M);
  REP(i, 0, N - 1) {
    int s = A[i], t = A[i + 1];
    if (t < s) t += M;

    int d = t - s;
    tot += d;
    B[s + 2] -= 1;
    B[t + 1] += d;
    B[t + 2] -= d - 1;
  }

  REP(k, 0, 2) REP(i, 1, 2 * M) B[i] += B[i - 1];

  LL save = 0;
  REP(i, 0, M) chmin(save, B[i] + B[M + i]);
  cout << tot + save << endl;

  return 0;
}