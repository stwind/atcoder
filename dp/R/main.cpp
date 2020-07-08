#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

const long long MOD = 1000000007;

template <typename T>
void add(T &a, T b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
}

VVLL matMul(VVLL a, VVLL b)
{
  int n = a.size();
  VVLL ret(n, VLL(n));
  forn(i, 0, n) forn(j, 0, n) forn(k, 0, n)
      add<LL>(ret[i][j], a[i][k] * b[k][j] % MOD);
  return ret;
}

int main()
{
  IOS;

  LL N, K;
  cin >> N >> K;
  VVLL G(N, VLL(N));
  forn(i, 0, N) forn(j, 0, N) cin >> G[i][j];

  VVLL R(N, VLL(N));
  forn(i, 0, N) R[i][i] = 1;

  for (; K > 0; K >>= 1)
  {
    if (K & 1)
      R = matMul(R, G);

    G = matMul(G, G);
  }

  LL res = 0;
  forn(i, 0, N) forn(j, 0, N) add(res, R[i][j]);
  cout << res << endl;

  return 0;
}
