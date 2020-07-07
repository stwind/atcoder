#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

template <typename T>
class RMQ
{
  const T INF = numeric_limits<T>::min();
  int n = 1;
  vector<T> data;

public:
  RMQ(int s)
  {
    while (n < s)
      n *= 2;
    data.resize(2 * n - 1);
  }

  void update(int i, T x)
  {
    i += n - 1;
    data[i] = x;
    while (i > 0)
    {
      i = (i - 1) / 2;
      data[i] = max(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  T query(int a, int b) { return query1(a, b, 0, 0, n); }
  T query1(int a, int b, int i, int l, int r)
  {
    if (b <= l || r <= a)
      return INF;
    if (a <= l && r <= b)
      return data[i];
    int m = (l + r) / 2;
    T x = query1(a, b, i * 2 + 1, l, m);
    T y = query1(a, b, i * 2 + 2, m, r);
    return max(x, y);
  }
};

int main()
{
  IOS;
  int N;
  cin >> N;
  VLL H(N), A(N);
  LL MAX_H = 0;
  forn(i, 0, N)
  {
    cin >> H[i];
    MAX_H = max(MAX_H, H[i]);
  }
  forn(i, 0, N) cin >> A[i];

  RMQ<LL> rmq(MAX_H + 1);
  VLL dp(MAX_H + 1);
  LL res = 0;
  for (int i = 0; i < N; i++)
  {
    LL a = rmq.query(0, H[i] + 1);
    chmax(dp[H[i]], A[i] + a);
    rmq.update(H[i], dp[H[i]]);
    res = max(res, dp[H[i]]);
  }
  cout << res << endl;

  return 0;
}
