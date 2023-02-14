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
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int num_digits(int x) {
  int k = 1;
  while (x >= 10) x /= 10, k++;
  return k;
};

int op2(int x) {
  int k = num_digits(x);
  return (x % 10) * pow(10, k - 1) + x / 10;
};

int main() {
  IOS;

  int a, N;
  cin >> a >> N;

  int k = num_digits(N);
  int m = pow(10, k);

  map<int, int> D = { {1,0} };
  queue<int> q({ 1 });
  while (!q.empty()) {
    auto x = q.front();
    q.pop();
    if (x == N) {
      cout << D[x] << endl;
      return 0;
    }

    int x1 = x * a;
    if (D.count(x1) == 0 && x1 < m) D[x1] = D[x] + 1, q.push(x1);

    if (x >= 10 && x % 10 != 0) {
      int x2 = op2(x);
      if (D.count(x2) == 0 && x2 < m) D[x2] = D[x] + 1, q.push(x2);
    }
  }
  cout << -1 << endl;

  return 0;
}