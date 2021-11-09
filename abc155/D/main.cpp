// ref: https://drken1215.hatenablog.com/entry/2020/04/23/142200

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 31)
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
  LL N, K;
  cin >> N >> K;
  VLL A(N);
  forn(i, 0, N) cin >> A[i];
  sort(all(A));

  LL lo = -pow(10, 18), hi = pow(10, 18), x;
  while (hi - lo > 1) {
    x = (lo + hi) / 2;
    LL S = 0, T = 0;
    forn(i, 0, N) {
      if (A[i] > 0) {
        int l = -1, r = N, m;
        while (r - l > 1) {
          m = (l + r) / 2;
          if (A[i] * A[m] <= x)
            l = m;
          else
            r = m;
        }
        S += r;
      } else if (A[i] < 0) {
        int l = -1, r = N, m;
        while (r - l > 1) {
          m = (l + r) / 2;
          if (A[i] * A[m] <= x)
            r = m;
          else
            l = m;
        }
        S += N - r;
      } else if (x >= 0)
        S += N;

      if (A[i] * A[i] <= x)
        T++;
    }

    LL n = (S - T) / 2;
    if (n < K)
      lo = x;
    else
      hi = x;
  }
  cout << hi << endl;

  return 0;
}