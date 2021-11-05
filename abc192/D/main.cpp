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
  string X;
  LL M;
  cin >> X >> M;

  if (X.size() == 1) {
    cout << (stoi(X) <= M) << endl;
    return 0;
  }

  int d = 0;
  for (auto &c : X)
    chmax(d, c - '0');

  auto check = [&](LL b) -> bool {
    LL res = 0, p = 1;
    for (int i = X.size() - 1; i >= 0; i--) {
      LL n = p * (X[i] - '0');
      if (n > M - res)
        return false;
      res += n;
      if (M / p < b && i)
        return false;
      p *= b;
    }
    return true;
  };

  LL lo = d, hi = M + 1;
  while (hi - lo > 1) {
    LL mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }

  cout << lo - d << endl;
  return 0;
}