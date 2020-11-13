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
    string S;
    cin >> S;

    VI W(N + 1, 0), E(N + 1, 0);
    forn(i, 0, N)
    {
        W[i + 1] = W[i];
        E[i + 1] = E[i];
        if (S[i] == 'W')
            W[i + 1] += 1;
        else
            E[i + 1] += 1;
    }

    int res = N;
    forn(i, 0, N)
    {
        int c = W[i] - W[0] + E[N] - E[i + 1];
        res = min(res, c);
    }
    cout << res << endl;

    return 0;
}