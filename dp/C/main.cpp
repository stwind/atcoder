#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define FOR(i, x, y) for(int i = x; i < y; i++)
// clang-format on

int main()
{
  IOS;

  int N;
  cin >> N;
  int a, b, c;
  cin >> a >> b >> c;

  int A = a, B = b, C = c;
  int x, y, z;
  FOR(i, 1, N)
  {
    cin >> a >> b >> c;
    x = A, y = B, z = C;

    A = a + max(y, z);
    B = b + max(x, z);
    C = c + max(x, y);
  }

  cout << max(A, max(B, C)) << endl;

  return 0;
}
