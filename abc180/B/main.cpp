#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    IOS;
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    VI X(N);
    forn(i, 0, N) cin >> X[i];

    LL man = 0.0;
    forn(i, 0, N) man += abs(X[i]);
    cout << man << endl;

    double ecu = 0.0;
    forn(i, 0, N) ecu += X[i] * (long)X[i];
    cout << sqrt(ecu) << endl;

    int che = 0.0;
    forn(i, 0, N) che = max(che, abs(X[i]));
    cout << che << endl;

    return 0;
}
