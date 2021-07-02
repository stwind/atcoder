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

template <typename T> T powm(T x, T k) {
  T res = 1;
  while (k) {
    if (k & 1)
      res = res * x % MOD;
    x = x * x % MOD;
    k >>= 1;
  }
  return res;
}

int main() {
  IOS;
  int N;
  cin >> N;
  VI A(N);
  forn(i, 0, N) cin >> A[i];

  unordered_map<int, int> C;
  for (auto &a : A) {
    int x = a;
    for (int i = 2; i <= sqrt(x); i++) {
      int k = 0;
      while (x % i == 0) {
        k++;
        x /= i;
      }
      C[i] = max(C[i], k);
    }
    if (x > 1)
      C[x] = max(C[x], 1);
  }

  LL l = 1;
  for (auto &c : C)
    l = l * powm(c.first, c.second) % MOD;

  LL res = 0;
  for (auto &a : A) {
    LL x = l * powm((LL)a, (LL)(MOD - 2)) % MOD;
    add(res, x);
  }

  cout << res << endl;

  return 0;
}