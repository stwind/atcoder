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
  LL N, K;
  cin >> N >> K;
  VI A(N);
  REP(i, 0, N) cin >> A[i];

  LL res = 0;
  VLL S(N + 1);
  unordered_map<LL, LL> cnt = {{0, 1}};
  REP(i, 0, N) {
    S[i + 1] = S[i] + A[i];
    if (i + 1 >= K)
      cnt[(S[i + 1 - K] - (i + 1 - K)) % K]--;
    res += cnt[(S[i + 1] - (i + 1)) % K]++;

    // S[i + 1] = (S[i] + A[i] - 1) % K;
    // if (i + 1 >= K)
    //   cnt[S[i + 1 - K]]--;
    // res += cnt[S[i + 1]]++;
  }

  cout << res << endl;

  return 0;
}