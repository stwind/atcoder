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
using PLL = pair<LL, LL>;

int main()
{
    IOS;
    int N, X;
    cin >> N >> X;
    VI W(N);
    forn(i, 0, N) cin >> W[i];

    int h = N / 2;

    VI A;
    forn(bit, 0, 1 << h)
    {
        int w = 0;
        forn(i, 0, h) if (bit & (1 << i)) w += W[i];
        if (w <= X)
            A.push_back(w);
    }

    unordered_map<int, int> cnt;
    forn(bit, 0, 1 << (N - h))
    {
        int w = 0;
        forn(i, 0, N - h) if (bit & (1 << i)) w += W[h + i];
        cnt[w]++;
    }

    int res = 0;
    for (auto a : A)
        res += cnt[X - a];
    cout << res << endl;

    return 0;
}