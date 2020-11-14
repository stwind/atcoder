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
    int N;
    cin >> N;
    string S;
    cin >> S;

    unordered_map<char, int> left, right;
    forn(i, 0, N) right[S[i]]++;

    int res = 0;
    forn(i, 0, N)
    {
        right[S[i]]--;
        left[S[i]]++;

        int r = 0;
        for (auto c : left)
        {
            if (c.second > 0 && right[c.first] > 0)
                r++;
        }

        res = max(res, r);
    }

    cout << res << endl;

    return 0;
}