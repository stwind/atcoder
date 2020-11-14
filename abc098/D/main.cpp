#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    IOS;
    int N;
    cin >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    VI D(20, 0);

    LL res = 0;
    for (int i = 0, j = 0; i < N; i++)
    {
        for (int k = 0; k < 20; k++)
            D[k] += (A[i] >> k) & 1;

        while (any_of(all(D), [](int x) { return x >= 2; }) && j < i)
        {
            for (int k = 0; k < 20; k++)
                D[k] -= (A[j] >> k) & 1;
            j++;
        }
        res += i - j + 1;
    }
    cout << res << endl;

    return 0;
}