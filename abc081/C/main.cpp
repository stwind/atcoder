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
using VLL = vector<LL>;

int main()
{
    int N, K;
    cin >> N >> K;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    map<int, int> cnt;
    forn(i, 0, N) cnt[A[i]]++;

    VI vals;
    for (auto c : cnt)
        vals.push_back(c.second);
    sort(all(vals));

    int res = 0, n = cnt.size();
    forn(i, 0, n - K) res += vals[i];

    cout << res << endl;

    return 0;
}