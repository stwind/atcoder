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
template <typename T> T mul(T a, T b) { return 1ULL * a * b % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

const double EPS = 1e-8;

struct Point {
  double x, y;

  double dist(Point r) const {
    double dx = x - r.x, dy = y - r.y;
    return sqrt(dx * dx + dy * dy);
  }

  Point dir_to(Point p) const {
    double dx = p.x - x, dy = p.y - y;
    double r = hypot(dx, dy);
    return Point{ dx / r, dy / r };
  }

  Point lerp(Point p, double t = .5) const {
    return Point{ x * (1 - t) + p.x * t, y * (1 - t) + p.y * t };
  }

  friend ostream& operator<<(ostream& os, const Point& p) { return os << p.x << ", " << p.y; }
  friend istream& operator>>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
};

int main() {
  IOS;

  int N; cin >> N;
  vector<Point> P(N);
  REP(i, 0, N) cin >> P[i];

  auto cross_points = [&](Point p1, Point p2, double R) -> vector<Point> {
    vector<Point> res;
    Point m = p1.lerp(p2);
    double h = p1.dist(m);
    if (h > R - EPS) return res;

    double d = sqrt(R * R - h * h);
    Point dir = p1.dir_to(p2);
    res.push_back(Point{ m.x - d * dir.y, m.y + d * dir.x });
    res.push_back(Point{ m.x + d * dir.y, m.y - d * dir.x });
    return res;
  };

  auto check = [&](double R) -> bool {
    REP(i, 0, N) REP(j, 0, N) if (i != j) {
      for (auto p : cross_points(P[i], P[j], R)) {
        bool good = true;
        REP(k, 0, N) if (p.dist(P[k]) > R + EPS) {
          good = false;
          break;
        }
        if (good) return true;
      }
    }
    return false;
  };

  double l = 0, r = 2000, m;
  while (abs(l - r) > EPS) {
    m = (l + r) / 2;
    if (check(m)) r = m;
    else l = m;
  }
  cout << fixed << setprecision(10) << (l + r) / 2 << endl;

  return 0;
}