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

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    unordered_set<int> seen;
    int a = 1;
    while (!seen.count((A * a - C) % B))
    {
        int x = (A * a - C) % B;
        if (x == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
        seen.insert(x);
        a++;
    }
    cout << "NO" << endl;

    return 0;
}