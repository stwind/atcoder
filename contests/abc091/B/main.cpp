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
    int N, M;
    cin >> N;
    vector<string> S(N);
    forn(i, 0, N) cin >> S[i];
    cin >> M;
    vector<string> T(M);
    forn(i, 0, M) cin >> T[i];

    unordered_map<string, int> cnt;
    forn(i, 0, N) cnt[S[i]]++;
    forn(i, 0, M) cnt[T[i]]--;

    int res = 0;
    for (auto c : cnt)
        res = max(res, c.second);

    cout << res << endl;

    return 0;
}