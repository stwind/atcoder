#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
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
  IOS;
  int Q;
  cin >> Q;
  VI T(Q), X(Q);
  forn(i, 0, Q) cin >> T[i] >> X[i];

  int n = 200001;

  VI D(n, 0);
  auto add = [&](int p, int x) {
    for (; p <= n; p += p & -p) {
      D[p] += x;
    }
  };
  auto sum = [&](int r) {
    int s = 0;
    for (; r > 0; r -= r & -r)
      s += D[r];
    return s;
  };

  forn(i, 0, Q) {
    if (T[i] == 1) {
      add(X[i], 1);
    } else {
      int lo = 0, hi = n, mid;
      while (hi - lo > 1) {
        mid = (lo + hi) / 2;
        if (sum(mid) < X[i])
          lo = mid;
        else
          hi = mid;
      }
      cout << hi << endl;
      add(hi, -1);
    }
  }

  return 0;
}