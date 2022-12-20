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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    VI L(Q), R(Q);
    forn(i, 0, Q) cin >> L[i] >> R[i];

    VI C(N + 1, 0);
    forn(i, 0, N)
    {
        C[i + 1] = C[i];
        if (i > 0 && S[i] == 'C' && S[i - 1] == 'A')
            C[i + 1] += 1;
    }

    forn(i, 0, Q)
    {
        int res = C[R[i]] - C[L[i]];
        cout << res << endl;
    }

    return 0;
}