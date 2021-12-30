// ref: https://blogger.jinyanakamura.com/2021/04/90-005-restricted-digits7.html
// ref: https://drken1215.hatenablog.com/entry/2021/10/08/231200

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
constexpr int LOG = 62;

int main() {
  IOS;
  LL N;
  int B, K;
  cin >> N >> B >> K;
  VI C(K);
  REP(i, 0, K) cin >> C[i];

  auto mul = [&](const VLL &dpi, const VLL &dpj, LL tj) {
    VLL res(B);
    REP(p, 0, B) REP(q, 0, B) {
      int nex = (p * tj + q) % B;
      res[nex] += dpi[p] * dpj[q];
      res[nex] %= MOD;
    }
    return res;
  };

  VLL ten(LOG);
  ten[0] = 10;
  REP(i, 1, LOG) ten[i] = (ten[i - 1] * ten[i - 1]) % B;

  VVLL D(LOG, VLL(B));
  REP(k, 0, K) D[0][C[k] % B]++;
  REP(i, 1, LOG) D[i] = mul(D[i - 1], D[i - 1], ten[i - 1]);

  VLL res(B);
  res[0] = 1;
  REP(i, 0, LOG) if (N & (1LL << i)) { res = mul(res, D[i], ten[i]); }

  cout << res[0] << endl;

  return 0;
}