// https://pekempey.hatenablog.com/entry/2016/05/29/132404
// https://hackmd.io/@tXULjr4DSBKJ41FFYzU_hg/ryz2UNuhf?type=view

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

// BIT
int main() {
  IOS;
  int N;
  cin >> N;
  vector<PII> S;
  int w, h;
  forn(i, 0, N) {
    cin >> w >> h;
    S.emplace_back(w, h);
  }

  sort(all(S), [](PII a, PII b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first < b.first;
  });

  int n = 100001;
  VI D(n);
  auto update = [&](int p, int x) {
    for (; p < n; p += p & -p)
      chmax(D[p], x);
  };
  auto get = [&](int r) {
    int s = 0;
    for (; r > 0; r -= r & -r)
      chmax(s, D[r]);
    return s;
  };

  int res = 0;
  for (auto &s : S) {
    int l = get(s.second - 1) + 1;
    update(s.second, l);
    chmax(res, l);
  }
  cout << res << endl;

  return 0;
}

// binary search
// int main() {
//   IOS;
//   int N;
//   cin >> N;
//   vector<PII> S;
//   int w, h;
//   forn(i, 0, N) {
//     cin >> w >> h;
//     S.emplace_back(w, h);
//   }

//   sort(all(S), [](PII a, PII b) {
//     if (a.first == b.first)
//       return a.second > b.second;
//     return a.first < b.first;
//   });

//   int res = 0;
//   VI dp(N + 1, 1 << 30);
//   for (auto &s : S) {
//     int l = 0, r = N, m;
//     while (r - l > 1) {
//       m = (l + r) / 2;
//       if (dp[m] < s.second)
//         l = m;
//       else
//         r = m;
//     }
//     dp[r] = s.second;
//     chmax(res, r);
//   }
//   cout << res << endl;

//   return 0;
// }