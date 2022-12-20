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
    int Q;
    cin >> Q;
    VI L(Q), R(Q);
    int M = 0;
    forn(i, 0, Q)
    {
        cin >> L[i] >> R[i];
        M = max(M, R[i]);
    }

    VI P(M + 1, 1);
    P[0] = P[1] = 0;
    forn(i, 2, sqrt(M) + 1)
    {
        if (!P[i])
            continue;
        for (int j = i * i; j <= M; j += i)
            P[j] = 0;
    }

    VI C(M + 2, 0);
    forn(i, 0, M + 1)
    {
        C[i + 1] = C[i];
        if (P[i] && P[(i + 1) / 2])
        {
            C[i + 1] += 1;
        }
    }

    forn(i, 0, Q)
    {
        cout << C[R[i] + 1] - C[L[i]] << endl;
    }

    return 0;
}