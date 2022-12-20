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
  int N;
  cin >> N;

  unordered_map<LL, int> C;
  for (int n = 1; n <= N; n++) {
    int x = n;
    for (int i = 2; i <= sqrt(x); i++) {
      while (x % i == 0) {
        C[i]++;
        x /= i;
      }
    }
    if (x > 1)
      C[x]++;
  }

  auto count = [&](int n) {
    int res = 0;
    for (auto &c : C)
      if (c.second >= n)
        res++;
    return res;
  };

  int res = 0;
  res += count(74);
  res += count(14) * (count(4) - 1);
  res += count(24) * (count(2) - 1);
  res += count(4) * (count(4) - 1) * (count(2) - 2) / 2;

  cout << res << endl;

  return 0;
}