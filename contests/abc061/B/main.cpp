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
    int N, M;
    cin >> N >> M;

    map<int, int> cnt;
    int a, b;
    forn(i, 0, M)
    {
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    forn(i, 0, N) cout << cnt[i + 1] << endl;

    return 0;
}