#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 998244353
#define INF (1 << 30)
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return (a * b) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;\
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main() {
  IOS;

  int H, W, r, c, N, Q;
  cin >> H >> W >> r >> c >> N;
  r--, c--;
  VI R(N), C(N);
  REP(i, 0, N) {
    cin >> R[i] >> C[i];
    R[i]--, C[i]--;
  }
  cin >> Q;
  vector<string> D(Q);
  VI L(Q);
  REP(i, 0, Q) cin >> D[i] >> L[i];

  map<int, VI> KR, KC;
  REP(i, 0, N) {
    KR[R[i]].push_back(C[i]);
    KC[C[i]].push_back(R[i]);
  }
  for (auto& k : KR) k.second.push_back(-1), k.second.push_back(W), sort(all(k.second));
  for (auto& k : KC) k.second.push_back(-1), k.second.push_back(H), sort(all(k.second));

  REP(i, 0, Q) {
    if ((D[i] == "L" || D[i] == "R")) {
      if (KR.count(r)) {
        if (D[i] == "L") {
          auto it = lower_bound(all(KR[r]), c) - 1;
          c = max(*it + 1, c - L[i]);
        }
        else if (D[i] == "R") {
          auto it = upper_bound(all(KR[r]), c);
          c = min(*it - 1, c + L[i]);
        }
      }
      else if (D[i] == "L") {
        c = max(0, c - L[i]);
      }
      else if (D[i] == "R") {
        c = min(W - 1, c + L[i]);
      }
    }
    else {
      if (KC.count(c)) {
        if (D[i] == "U") {
          auto it = lower_bound(all(KC[c]), r) - 1;
          r = max(*it + 1, r - L[i]);
        }
        else {
          auto it = upper_bound(all(KC[c]), r);
          r = min(*it - 1, r + L[i]);
        }
      }
      else if (D[i] == "U") {
        r = max(0, r - L[i]);
      }
      else if (D[i] == "D") {
        r = min(H - 1, r + L[i]);
      }
    }

    cout << r + 1 << " " << c + 1 << endl;
  }


  return 0;
}