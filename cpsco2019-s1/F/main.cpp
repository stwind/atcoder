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
  int N;
  cin >> N;
  VI T(N), A(N), B(N);
  forn(i, 0, N) {
    cin >> T[i] >> A[i] >> B[i];
    T[i]--;
  }

  auto check = [&](int x) -> bool {
    VI L2R[20000];
    forn(i, 0, N) {
      int d = (A[i] - x) / B[i];
      int l = max(0, T[i] - d), r = min(T[i] + d, N - 1);
      L2R[l].push_back(r);
    }

    priority_queue<int, VI, greater<int>> R;
    forn(l, 0, N) {
      for (auto r : L2R[l])
        R.push(r);
      if (R.size() == 0)
        return false;
      int r = R.top();
      R.pop();
      if (r < l)
        return false;
    }
    return true;
  };

  int lo = -1000000001, hi = *min_element(all(A)) + 1, mid;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  cout << lo << endl;

  return 0;
}