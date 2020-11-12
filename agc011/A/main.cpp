#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define printVector(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define all(s) s.begin(), s.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    int N, C, K;
    cin >> N >> C >> K;
    VI T(N);
    forn(i, 0, N) cin >> T[i];
    sort(all(T));

    int res = 1;
    for (int i = 0, j = 0; i < N; i++)
    {
        if (T[i] - T[j] > K || i - j == C)
        {
            res++;
            j = i;
        }
    }
    cout << res << endl;

    return 0;
}