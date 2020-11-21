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
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    map<char, int> cnt;
    forn(i, 0, N) cnt[S[i]]++;

    string res;
    int diff = 0;
    forn(i, 0, N)
    {
        for (auto c : cnt)
        {
            if (!c.second)
                continue;

            int tmp = c.first != S[i];

            map<char, int> cnt2(cnt);
            cnt2[c.first]--;
            forn(j, i + 1, N)
            {
                if (cnt2[S[j]])
                    cnt2[S[j]]--;
                else
                    tmp++;
            }

            if (diff + tmp <= K)
            {
                res += c.first;
                cnt[c.first]--;
                if (c.first != S[i])
                    diff++;
                break;
            }
        }
    }
    cout << res << endl;

    return 0;
}