#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define PARENS ()
#define EXPAND(...) EXPAND4(EXPAND4(EXPAND4(EXPAND4(__VA_ARGS__))))
#define EXPAND4(...) EXPAND3(EXPAND3(EXPAND3(EXPAND3(__VA_ARGS__))))
#define EXPAND3(...) EXPAND2(EXPAND2(EXPAND2(EXPAND2(__VA_ARGS__))))
#define EXPAND2(...) EXPAND1(EXPAND1(EXPAND1(EXPAND1(__VA_ARGS__))))
#define EXPAND1(...) __VA_ARGS__
#define FOR_EACH(macro, ...) __VA_OPT__(EXPAND(FOR_EACH_HELPER(macro, __VA_ARGS__)))
#define FOR_EACH_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(FOR_EACH_AGAIN PARENS (macro, __VA_ARGS__))
#define FOR_EACH_AGAIN() FOR_EACH_HELPER
#define REP(i, x, y) for(int i = x; i < y; i++)
#define REPR(i, x, y) for(int i = x; i >= y; i--)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define DBG(x) cout << #x << ": " << x << " ";
#define DEBUG(...) FOR_EACH(DBG, __VA_ARGS__) cout << endl;
#define DEBUGV(a) cout << #a << ": "; for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) ((a) + (b) - 1) / (b)
#define IN(x, a, b) (a <= x && x < b)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
template <typename T> T mul(T a, T b) { return 1ULL * a * b % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

struct Point {
  double x, y;
  explicit Point() {}
  explicit Point(double x, double y) :x(x), y(y) {}

  Point operator+(const Point& p) { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }

  friend ostream& operator<<(ostream& os, const Point& p) { return os << "(" << p.x << "," << p.y << ")"; }
  friend istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
};

int main() {
  IOS;

  Point A, B; cin >> A >> B;
  int N; cin >> N;
  vector<Point> P(N);
  REP(i, 0, N) cin >> P[i];

  auto cross = [](Point& a, Point& b, Point& c) -> double {
    Point p = b - a, q = c - a;
    return p.x * q.y - p.y * q.x;
  };

  auto intersect = [&](Point& a, Point& b, Point& c, Point& d) -> bool {
    double o1 = cross(a, b, c), o2 = cross(a, b, d);
    double o3 = cross(c, d, a), o4 = cross(c, d, b);
    return o1 * o2 < 0 && o3 * o4 < 0;
  };

  int x = 0;
  REP(i, 0, N) if (intersect(A, B, P[i], P[(i + 1) % N]))
    x++;

  cout << x / 2 + 1 << endl;

  return 0;
}