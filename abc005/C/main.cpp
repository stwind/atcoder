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
using PII = pair<int, int>;

int main()
{
    IOS;
    int T, N, M;
    cin >> T >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];
    cin >> M;
    VI B(M);
    forn(i, 0, M) cin >> B[i];

    for (int i = 0, j = 0; i < M; i++)
    {
        while (j < N && A[j] + T < B[i])
            j++;
        if (j < N && A[j] <= B[i])
            j++;
        else
        {
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;

    return 0;
}