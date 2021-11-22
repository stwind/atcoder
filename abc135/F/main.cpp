// https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2019/0727_abc135#f_-_strings_of_eternity

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
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

VI rolling_hash(string s, LL n, LL base = 26, LL mod = 1000000007) {
  int m = s.size();
  VI H(m);
  LL pow = 1;
  REP(i, 0, n - 1) pow = pow * base % mod;

  LL h = 0;
  REP(i, 0, m) {
    if (i >= n)
      h = h + mod - (s[i - n] - 'a') * pow % mod;

    h = (h * base + (s[i] - 'a')) % mod;
    H[i] = h;
  }
  return H;
}

int main() {
  string S, T;
  cin >> S >> T;

  int n = T.size();
  string s = S;
  while ((int)s.size() < n * 3)
    s += S;
  s += s;

  int h = rolling_hash(T, n)[n - 1];
  VI H = rolling_hash(s, n);

  int m = H.size() / 2;
  VI H2(H.begin() + m, H.end());

  VI D(m, -1);
  function<int(int, int)> dfs = [&](int u, int st) {
    if (u == st)
      return -1;

    if (D[u] < 0) {
      D[u] = 0;
      if (H2[u] == h) {
        int x = dfs((u + n) % m, st);
        if (x == -1)
          return -1;
        D[u] = x + 1;
      }
    }

    return D[u];
  };
  REP(i, 0, m) {
    if (D[i] < 0) {
      D[i] = 0;
      if (H2[i] == h) {
        int res = dfs((i + n) % m, i);
        if (res == -1) {
          cout << -1 << endl;
          return 0;
        }
        D[i] = res + 1;
      }
    }
  }

  cout << *max_element(all(D)) << endl;

  return 0;
}