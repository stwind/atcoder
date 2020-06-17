#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll f(ll a, ll b)
{
  if (a > b)
    return f(b, a);

  ll d = b / a;
  if (b % a == 0)
    return (2 * d - 1) * a;
  else
    return 2 * d * a + f(b % a, a);
}

int main()
{
  ll n, x;
  cin >> n >> x;
  ll a = x, b = n - x;
  cout << a + b + f(a, b) << endl;
  return 0;
}
