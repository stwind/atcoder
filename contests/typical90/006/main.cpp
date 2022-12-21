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

int main() {
  IOS;

  int N, K;
  string S;
  cin >> N >> K >> S;

  int C[26][N + 1];
  REP(c, 0, 26) {
    C[c][N] = N;
    REPR(i, N - 1, -1) {
      if (S[i] - 'a' == c) C[c][i] = i;
      else C[c][i] = C[c][i + 1];
    }
  }

  string res = "";
  int i = 0, k = 0, c = 0;
  while (k < K) {
    int p = C[c][i];
    if (N - p >= K - k) {
      res += c + 'a';
      k++;
      i = p + 1;
      c = 0;
    }
    else {
      c++;
    }
  }
  cout << res << endl;

  return 0;
}