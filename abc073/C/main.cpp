#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    int N;
    cin >> N;

    unordered_map<int, int> cnt;
    int a;
    forn(i, 0, N)
    {
        cin >> a;
        cnt[a]++;
    }

    int res = 0;
    for (auto c : cnt)
        res += c.second % 2;

    cout << res << endl;

    return 0;
}