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

// vector<int> z_algo(string s) {
//   int n = s.size();
//   vector<int> Z(n);
//   Z[0] = n;
//   for (int i = 1, j = 0; i < n; i++) {
//     while (i + j < n && s[j] == s[i + j])
//       j++;
//     Z[i] = j;
//     if (j > 0) {
//       int k = 1;
//       for (; k < j && k + Z[k] < j; k++)
//         Z[i + k] = Z[k];
//       i += k - 1;
//       j -= k;
//     }
//   }
//   return Z;
// }

// int main() {
//   IOS;
//   int N;
//   cin >> N;
//   string S;
//   cin >> S;

//   int res = 0;
//   forn(i, 0, N) {
//     VI Z = z_algo(S.substr(i));
//     forn(j, 0, (int)Z.size()) chmax(res, min(Z[j], j));
//   }
//   cout << res << endl;

//   return 0;
// }

// int main() {
//   IOS;
//   int N;
//   cin >> N;
//   string S;
//   cin >> S;

//   VVI dp(N, VI(N));
//   for (int j = N - 1; j >= 0; j--) {
//     if (S[j] == S[N - 1])
//       dp[N - 1][j] = 1;
//   }
//   for (int i = N - 2; i >= 0; i--) {
//     for (int j = i; j >= 0; j--) {
//       dp[i][j] = S[i] == S[j] ? dp[i + 1][j + 1] + 1 : 0;
//     }
//   }
//   int res = 0;
//   forn(i, 0, N) forn(j, 0, i) {
//     if (dp[i][j] < i - j + 1)
//       chmax(res, dp[i][j]);
//   }
//   cout << res << endl;

//   return 0;
// }

struct RollingHash {
  vector<int64_t> hash, pow;
  int64_t base, mod;
  RollingHash(string s, int64_t base = 1009, int64_t mod = 1000000007)
      : base(base), mod(mod) {
    int n = s.size();
    hash.resize(n + 1);
    pow.resize(n + 1);
    hash[0] = 1;
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
      hash[i] = (hash[i - 1] * base + s[i - 1]) % mod;
      pow[i] = pow[i - 1] * base % mod;
    }
  }

  int64_t get(int l, int r) {
    return (mod + hash[r] - hash[l] * pow[r - l] % mod) % mod;
  }
};

int main() {
  IOS;
  int N;
  cin >> N;
  string S;
  cin >> S;

  RollingHash rh1(S, 1007), rh2(S, 2009);
  auto check = [&](int m) -> bool {
    set<pair<int64_t, int64_t>> s;
    vector<pair<int64_t, int64_t>> v(N);
    for (int i = 0; i + m <= N; i++) {
      if (i >= m)
        s.insert(v[i - m]);
      v[i] = {rh1.get(i, i + m), rh2.get(i, i + m)};
      if (s.count(v[i]))
        return true;
    }
    return false;
  };

  int lo = 0, hi = N / 2 + 1, mid;
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