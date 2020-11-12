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
    int N;
    cin >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    auto sign = [](int a, int b) {
        int diff = b - a;
        return diff > 0 ? 1 : diff < 0 ? -1 : 0;
    };

    int res = 1;
    if (N > 2)
    {
        int prev = sign(A[0], A[1]);
        for (int i = 2; i < N; i++)
        {
            int cur = sign(A[i - 1], A[i]);
            if (prev == 0)
            {
                prev = cur;
            }
            else if ((cur == 1 && prev == -1) || (cur == -1 && prev == 1))
            {
                prev = 0;
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}