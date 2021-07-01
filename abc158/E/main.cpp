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
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  if (P == 2 || P == 5) {
    unordered_map<int, int> C;
    LL res = 0;
    for (int i = N - 1; i >= 0; i--) {
      int a = S[i] - '0';
      C[a % P]++;
      res += C[0];
    }
    cout << res << endl;
    return 0;
  }

  unordered_map<int, int> C;
  C[0] = 1;
  LL res = 0;
  int x = 0, t = 1;
  for (int i = N - 1; i >= 0; i--) {
    int a = S[i] - '0';

    x = (t * (a % P) % P + x) % P;
    t = ((10 % P) * t) % P;

    res += C[x];
    C[x]++;
  }

  cout << res << endl;

  return 0;
}