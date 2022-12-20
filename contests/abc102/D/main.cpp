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
  IOS;
  int N;
  cin >> N;
  int a;
  VLL S(N + 1);

  REP(i, 0, N) {
    cin >> a;
    S[i + 1] = S[i] + a;
  }

  auto calc = [&](int l, int r) -> PLL {
    int lo = l + 1, hi = r - 1;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (S[mid] - S[l] < S[r] - S[mid])
        lo = mid;
      else
        hi = mid;
    }
    LL p0 = S[hi] - S[l], q0 = S[r] - S[hi];
    LL p1 = S[lo] - S[l], q1 = S[r] - S[lo];
    if (abs(p0 - q0) > abs(p1 - q1))
      return {p1, q1};

    return {p0, q0};
  };

  LL res = 1e18;
  REP(i, 2, N - 1) {
    PLL pq = calc(0, i), rs = calc(i, N);
    auto v = {pq.first, pq.second, rs.first, rs.second};
    res = min(res, max(v) - min(v));
  }
  cout << res << endl;

  return 0;
}