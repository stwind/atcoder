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
    int N;
    cin >> N;
    VI A(N + 1);
    forn(i, 0, N) cin >> A[i + 1];

    unordered_set<int> seen;
    int i = 1, res = 0;
    while (!seen.count(i))
    {
        seen.insert(i);
        i = A[i];
        res++;
        if (i == 2)
        {
            cout << res << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}