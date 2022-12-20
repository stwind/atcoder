#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
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

template <class T> struct BinaryIndexTree {
  int _n;
  vector<T> data;
  T sum(int r) {
    T s = 0;
    for (; r > 0; r -= r & -r)
      s += data[r - 1];
    return s;
  }

public:
  BinaryIndexTree(int n) : _n(n), data(n, 0) {}
  void add(int p, T x) {
    assert(0 <= p && p < _n);
    for (p++; p <= _n; p += p & -p)
      data[p - 1] += x;
  }
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= _n);
    return sum(r) - sum(l);
  }
};

int main() {
  IOS;
  int N;
  cin >> N;
  VI B(N);
  forn(i, 0, N) cin >> B[i];

  BinaryIndexTree<int> bit(N);
  LL tot = 0;
  for (auto &x : B) {
    bit.add(x - 1, 1);
    int l = bit.sum(x, N);
    int r = N - l - x;
    tot += min(l, r);
  }
  cout << tot << endl;

  return 0;
}