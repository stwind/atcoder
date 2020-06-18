#include <bits/stdc++.h>
using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int x0 = 0, y0 = 0, t0 = 0;
  int x1, y1, t1;
  for (int i = 0; i < N; i++)
  {
    cin >> t1 >> x1 >> y1;

    int d = abs(x1 - x0) + abs(y1 - y0);
    int dt = t1 - t0;
    if (dt < d || d % 2 != dt % 2)
    {
      cout << "No" << endl;
      return 0;
    }
    x0 = x1;
    y0 = y1;
    t0 = t1;
  }
  cout << "Yes" << endl;

  return 0;
}