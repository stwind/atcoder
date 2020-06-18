#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> D(10);
  int d;
  for (int i = 0; i < K; i++)
  {
    cin >> d;
    D[d] = 1;
  }

  for (;; N++)
  {
    int c = N;
    while (c && !D[c % 10])
      c /= 10;

    if (c == 0)
      break;
  }
  cout << N << endl;

  return 0;
}
