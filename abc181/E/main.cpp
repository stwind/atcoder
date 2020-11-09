#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(v) v.begin(), v.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    IOS;

    int N, M;
    cin >> N >> M;
    vector<int> H(N), W(M);
    forn(i, 0, N) cin >> H[i];
    forn(i, 0, M) cin >> W[i];

    sort(all(H));

    vector<int> left(N, 0), right(N, 0);
    forn(i, 2, N)
    {
        left[i] = left[i - 1];
        if (i % 2 == 0)
            left[i] += abs(H[i - 2] - H[i - 1]);
    }
    for (int i = N - 3; i >= 0; i--)
    {
        right[i] = right[i + 1];
        if (i % 2 == 0)
            right[i] += abs(H[i + 2] - H[i + 1]);
    }
    vector<int> suf(N, 0);
    forn(i, 0, N)
    {
        suf[i] = left[i] + right[i];
        if (i % 2 == 1)
            suf[i] += abs(H[i - 1] - H[i + 1]);
    }

    int res = INT_MAX;
    forn(i, 0, M)
    {
        int l = -1, r = N, m;
        while (r - l > 1)
        {
            m = (l + r) / 2;
            if (H[m] < W[i])
                l = m;
            else
                r = m;
        }

        if (r < N)
            res = min(res, abs(W[i] - H[r]) + suf[r]);
        if (r > 0)
            res = min(res, abs(W[i] - H[r - 1]) + suf[r - 1]);
    }

    cout << res << endl;

    return 0;
}
