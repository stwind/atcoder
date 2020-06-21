#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, N) for (int i = 0; i < N; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

int main()
{
  IOS;

  int N;
  cin >> N;
  vector<int> A(N), B(N), C(N);
  forn(i, N) cin >> A[i] >> B[i] >> C[i];

  long long dA = A[0], dB = B[0], dC = C[0];

  for (int i = 1; i < N; i++)
  {
    long long a = dA, b = dB, c = dC;
    dA = A[i] + max(b, c);
    dB = B[i] + max(a, c);
    dC = C[i] + max(a, b);
  }

  cout << max(dA, max(dB, dC)) << endl;

  return 0;
}
