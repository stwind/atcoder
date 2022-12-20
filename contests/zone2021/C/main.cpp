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
  int N;
  cin >> N;
  VI A(N), B(N), C(N), D(N), E(N);
  forn(i, 0, N) cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];

  auto check = [&](int thres) -> bool {
    set<int> s;
    forn(i, 0, N) {
      int bit = 0;
      if (A[i] >= thres)
        bit |= 1 << 4;
      if (B[i] >= thres)
        bit |= 1 << 3;
      if (C[i] >= thres)
        bit |= 1 << 2;
      if (D[i] >= thres)
        bit |= 1 << 1;
      if (E[i] >= thres)
        bit |= 1 << 0;
      s.insert(bit);
    }
    for (auto &a : s)
      for (auto &b : s)
        for (auto &c : s) {
          if ((a | b | c) == 31)
            return true;
        }
    return false;
  };

  int lo = 0, hi = 1000000001;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }

  cout << lo << endl;

  return 0;
}