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
#define CEIL(a, b) ((a) + (b) - 1) / (b)
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

double dist(int x1, int y1, int x2, int y2) { return hypot(x2 - x1, y2 - y1); }

int main() {
  IOS;
  cout << fixed << setprecision(15);
  int N, M;
  cin >> N >> M;
  VI Xn(N), Yn(N), Rn(N);
  forn(i, 0, N) cin >> Xn[i] >> Yn[i] >> Rn[i];
  VI Xm(M), Ym(M);
  forn(i, 0, M) cin >> Xm[i] >> Ym[i];

  double res = 1e9;
  forn(i, 0, N) chmin(res, (double)Rn[i]);

  forn(i, 0, M) {
    double mr = 1e9;
    forn(j, 0, M) {
      if (i == j)
        continue;
      double d = dist(Xm[i], Ym[i], Xm[j], Ym[j]) / 2;
      chmin(mr, d);
    }
    forn(j, 0, N) {
      double d = dist(Xm[i], Ym[i], Xn[j], Yn[j]);
      chmin(mr, d - Rn[j]);
    }
    chmin(res, mr);
  }
  cout << res << endl;

  return 0;
}