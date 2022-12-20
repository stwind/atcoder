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

VI enumpr(int x) {
  VI res;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      res.push_back(i);
      while (x % i == 0)
        x /= i;
    }
  }
  if (x > 1)
    res.push_back(x);
  return res;
}

int main() {
  IOS;
  int N, M;
  cin >> N >> M;
  VI A(N);
  forn(i, 0, N) cin >> A[i];

  unordered_map<int, int> C;
  for (auto &a : A) {
    VI primes = enumpr(a);
    int n = primes.size();
    for (int bit = 1; bit < (1 << n); bit++) {
      int mul = 1;
      for (int i = 0; i < n; i++)
        if (bit >> i & 1)
          mul *= primes[i];

      C[mul]++;
    }
  }

  forn(x, 1, M + 1) {
    VI primes = enumpr(x);
    int n = primes.size(), tot = 0;
    for (int bit = 1; bit < (1 << n); bit++) {
      int mul = 1;
      for (int i = 0; i < n; i++)
        if (bit >> i & 1)
          mul *= primes[i];

      if (__builtin_popcount(bit) % 2 == 1)
        tot += C[mul];
      else
        tot -= C[mul];
    }
    cout << N - tot << endl;
  }

  return 0;
}