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

// O(n)
// int main() {
//   int N;
//   cin >> N;
//   VI A(N);
//   forn(i, 0, N) cin >> A[i];

//   int n = 100010;
//   VI X(n);
//   for (auto &a : A)
//     X[a]++;

//   int res = 0;
//   forn(i, 1, n - 1) chmax(res, X[i - 1] + X[i] + X[i + 1]);
//   cout << res << endl;

//   return 0;
// }

// O(nlogn)
int main() {
  int N;
  cin >> N;
  VI A(N);
  forn(i, 0, N) cin >> A[i];
  sort(all(A));

  int res = 0;
  for (int i = 0, j = 0; j < N; j++) {
    while (i < j && A[j] - A[i] > 2)
      i++;
    chmax(res, j - i + 1);
  }
  cout << res << endl;

  return 0;
}