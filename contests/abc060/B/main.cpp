#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  if (C % gcd(A, B) == 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}