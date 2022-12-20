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
  int N, Q;
  string S;
  cin >> N >> Q;
  cin >> S;
  vector<char> T(Q), D(Q);
  forn(i, 0, Q) cin >> T[i] >> D[i];

  auto check = [&](int k, bool left) -> bool {
    int j = k;
    char c = S[k];
    forn(i, 0, Q) {
      if (T[i] != c)
        continue;

      j += D[i] == 'L' ? -1 : 1;

      if (j < 0)
        return left;
      else if (j == N)
        return !left;

      c = S[j];
    }
    return false;
  };

  int res = N;
  int lo = -1, hi = N, mid;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (check(mid, true))
      lo = mid;
    else
      hi = mid;
  }
  res -= hi;

  lo = -1, hi = N;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (check(mid, false))
      hi = mid;
    else
      lo = mid;
  }
  res -= N - lo - 1;
  cout << res << endl;

  return 0;
}