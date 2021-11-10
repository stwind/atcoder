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
  int A, B, Q;
  cin >> A >> B >> Q;
  VLL S(A), T(B), X(Q);
  forn(i, 0, A) cin >> S[i];
  forn(i, 0, B) cin >> T[i];
  forn(i, 0, Q) cin >> X[i];

  auto binary_search = [&](VLL &arr, LL x) -> PII {
    int lo = -1, hi = arr.size(), mid;
    while (hi - lo > 1) {
      mid = (lo + hi) / 2;
      if (arr[mid] <= x)
        lo = mid;
      else
        hi = mid;
    }
    return make_pair(lo, hi);
  };

  for (auto &x : X) {
    LL res = pow(10, 18);
    auto s = binary_search(S, x);
    if (s.first >= 0) {
      LL l = S[s.first];
      auto t = binary_search(T, l);
      if (t.first >= 0)
        chmin(res, abs(x - l) + abs(l - T[t.first]));
      if (t.second < B)
        chmin(res, abs(x - l) + abs(l - T[t.second]));
    }
    if (s.second < A) {
      LL r = S[s.second];
      auto t = binary_search(T, r);
      if (t.first >= 0)
        chmin(res, abs(r - x) + abs(r - T[t.first]));
      if (t.second < B)
        chmin(res, abs(r - x) + abs(r - T[t.second]));
    }

    auto t = binary_search(T, x);
    if (t.first >= 0) {
      LL l = T[t.first];
      auto s = binary_search(S, l);
      if (s.first >= 0)
        chmin(res, abs(x - l) + abs(l - S[s.first]));
      if (s.second < A)
        chmin(res, abs(x - l) + abs(l - S[s.second]));
    }
    if (t.second < B) {
      LL r = T[t.second];
      auto s = binary_search(S, r);
      if (s.first >= 0)
        chmin(res, abs(r - x) + abs(r - S[s.first]));
      if (s.second < A)
        chmin(res, abs(r - x) + abs(r - S[s.second]));
    }

    cout << res << endl;
  }

  return 0;
}