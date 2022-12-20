#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
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
  LL N, M, X, Y;
  cin >> N >> M >> X >> Y;
  VLL A(N), B(M);
  forn(i, 0, N) cin >> A[i];
  forn(i, 0, M) cin >> B[i];

  auto lge = [&](VLL &arr, LL x) -> int {
    int lo = -1, hi = arr.size(), mid;
    while (hi - lo > 1) {
      mid = (lo + hi) / 2;
      if (arr[mid] < x)
        lo = mid;
      else
        hi = mid;
    }
    return hi;
  };

  LL cur = 0;
  int tot = 0;
  while (true) {
    int idx = lge(A, cur);
    if (!IN(idx, 0, N))
      break;
    cur = A[idx] + X;
    idx = lge(B, cur);
    if (!IN(idx, 0, M))
      break;
    cur = B[idx] + Y;
    tot++;
  }
  cout << tot << endl;

  return 0;
}