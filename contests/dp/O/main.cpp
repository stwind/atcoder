#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define printVector(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte) \
  (byte & 0x200 ? '1' : '0'), \
  (byte & 0x100 ? '1' : '0'), \
  (byte & 0x80  ? '1' : '0'), \
  (byte & 0x40  ? '1' : '0'), \
  (byte & 0x20  ? '1' : '0'), \
  (byte & 0x10  ? '1' : '0'), \
  (byte & 0x08  ? '1' : '0'), \
  (byte & 0x04  ? '1' : '0'), \
  (byte & 0x02  ? '1' : '0'), \
  (byte & 0x01  ? '1' : '0')
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

const long long MOD = 1000000007;

void add(LL &a, LL b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
}

LL rec(VI &A, int F, int i)
{
  if (i == int(A.size()))
    return 1;

  int n = A.size();
  LL res = 0;
  for (int j = 0; j < n; j++)
    if (A[i] & F & (1 << j))
      add(res, rec(A, F - (1 << j), i + 1));

  return res;
}

int main()
{
  IOS;

  int N;
  cin >> N;
  VI A(N);
  int k;
  forn(i, 0, N) forn(j, 0, N)
  {
    cin >> k;
    A[i] |= k << j;
  }

  // cout << rec(A, pow(2, N) - 1, 0) << endl;

  VLL dp(1 << N);
  dp[0] = 1;
  for (int mask = 1; mask < (1 << N); mask++)
  {
    int m = __builtin_popcount(mask) - 1;
    for (int w = 0; w < N; w++)
    {
      if (mask & A[m] & (1 << w))
        add(dp[mask], dp[mask ^ (1 << w)]);
    }
  }
  cout << dp[(1 << N) - 1] << endl;

  return 0;
}

// Referencces
// https: //kuroneko1259.hatenablog.com/entry/2019/08/01/203505