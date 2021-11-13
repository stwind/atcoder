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
  int N;
  cin >> N;
  VI A(N);
  forn(i, 0, N) cin >> A[i];

  VI B(A), C(N);
  sort(all(B));
  unordered_map<int, int> V2I;
  forn(i, 0, N) V2I[B[i]] = i + 1;
  forn(i, 0, N) C[i] = V2I[A[i]];

  int n = 100001;
  VI D(n);
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

  LL tot = 0;
  forn(i, 0, N) {
    int l = sum(C[i]);
    tot += C[i] - 1 - l;
    add(C[i], 1);
  }
  cout << tot << endl;

  return 0;
}