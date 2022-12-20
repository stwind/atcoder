// ref: https://blog.hamayanhamayan.com/entry/2018/11/24/223908

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

int main() {
  IOS;
  int N, Q;
  cin >> N;
  string S;
  cin >> S >> Q;
  VI K(Q);
  forn(i, 0, Q) cin >> K[i];

  for (auto &k : K) {
    int M = 0, C = 0;
    LL res = 0, tot = 0;
    for (int a = 0, c = 0; a < N; a++) {
      if (S[a] == 'D') {
        while (c - a < k && c < N) {
          if (S[c] == 'M')
            M++;
          else if (S[c] == 'C') {
            C++;
            tot += M;
          }
          c++;
        }
        res += tot;
      } else if (S[a] == 'M') {
        M--;
        tot -= C;
      } else if (S[a] == 'C') {
        C--;
      }
    }
    cout << res << endl;
  }

  return 0;
}