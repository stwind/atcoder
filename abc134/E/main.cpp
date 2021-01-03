// ref: https://hiramekun.hatenablog.com/entry/2019/07/21/082628

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define CEIL(a, b) (a + b - 1) / b
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T &a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T &a, T b) { a -= b; if (a < 0) a += MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N;
    cin >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    // deque
    deque<int> S;
    for (auto x : A)
    {
        int it = lower_bound(all(S), x) - S.begin();
        if (it == 0)
            S.push_front(x);
        else
            S[--it] = x;
    }
    cout << S.size() << endl;

    // multiset
    // multiset<int> S;
    // for (auto x : A)
    // {
    //     auto it = S.lower_bound(x);
    //     if (it != S.begin())
    //     {
    //         it--;
    //         S.erase(it);
    //     }
    //     S.insert(x);
    // }
    // cout << S.size() << endl;

    return 0;
}