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

template <typename T>
vector<T> compress(vector<T>& X) {
  vector<T> vals = X;
  sort(all(vals));

  vals.erase(unique(all(vals)), vals.end());

  REP(i, 0, (int)X.size())
    X[i] = lower_bound(all(vals), X[i]) - vals.begin();

  return vals;
}

int main() {
  IOS;

  int H, W;
  cin >> H >> W;

  VI R(H), C(W);
  vector<string> A(H);
  REP(i, 0, H) {
    cin >> A[i];
    REP(j, 0, W) {
      if (A[i][j] == '#') R[i] = C[j] = 1;
    }
  }

  REP(i, 0, H) {
    if (R[i] == 0) continue;
    REP(j, 0, W) {
      if (C[j]) cout << A[i][j];
    }
    cout << endl;
  }

  return 0;
}