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
  explicit Point(double x = 0, double y = 0) :x(x), y(y) {}

  Point operator+(const Point& p) { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) { return Point(x - p.x, y - p.y); }

  Point& operator+=(const Point& p) { x += p.x, y += p.y; return *this; }
  Point& operator-=(const Point& p) { x -= p.x, y -= p.y; return *this; }

  double dist(Point r) const {
    double dx = x - r.x, dy = y - r.y;
    return sqrt(dx * dx + dy * dy);
  }

  friend ostream& operator<<(ostream& os, const Point& p) { return os << "(" << p.x << "," << p.y << ")"; }
  friend istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
};

int main() {
  IOS;

  int N; cin >> N;
  vector<Point> A(N), B(N);
  REP(i, 0, N) cin >> A[i];
  REP(i, 0, N) cin >> B[i];

  Point c1, c2;
  REP(i, 0, N) c1 += A[i], c2 += B[i];
  c1.x /= N, c1.y /= N;
  c2.x /= N, c2.y /= N;

  double d1 = 0, d2 = 0;
  REP(i, 0, N) {
    chmax(d1, c1.dist(A[i]));
    chmax(d2, c2.dist(B[i]));
  }
  cout << fixed << setprecision(12) << d2 / d1 << endl;

  return 0;
}