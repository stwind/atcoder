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
#define CEIL(a, b) (a + b - 1) / b
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

int main() {
  IOS;
  int N, K;
  cin >> N >> K;
  VI A(N);
  forn(i, 0, N) cin >> A[i];

  auto check = [&](int m) {
    int k = K, cur = 1;
    for (int i = 1; i < N; i++) {
      if (A[i] == A[i - 1])
        cur++;
      else
        cur = 1;

      if (cur > m) {
        k--;
        cur = 0;
      }

      if (k < 0)
        return false;
    }
    return true;
  };

  int lo = 0, hi = N, mid;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (!check(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << hi << endl;

  return 0;
}