#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define ALL(s) s.begin(), s.end()
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
#define MOD 1000000007
template <typename T> T sub(T a, T b) { return (a + MOD - b) % MOD; }
template <typename T> T add(T a, T b) { return (a + b) % MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;

vector<string> A(10);
VVI I(10, VI(10, 0));

void mark(int i, int j, int t)
{
    if (i < 0 || i >= 10 || j < 0 || j >= 10 || A[i][j] == 'x' || I[i][j] > 0)
        return;

    I[i][j] = t;
    mark(i - 1, j, t);
    mark(i + 1, j, t);
    mark(i, j - 1, t);
    mark(i, j + 1, t);
}

int main()
{
    IOS;
    forn(i, 0, 10) cin >> A[i];

    int t = 0;
    forn(i, 0, 10) forn(j, 0, 10)
    {
        if (A[i][j] == 'o' && I[i][j] == 0)
            mark(i, j, ++t);
    }
    forn(i, 0, 10) forn(j, 0, 10)
    {
        if (A[i][j] == 'o')
            continue;
        unordered_set<int> island;
        if (i > 0 && A[i - 1][j] == 'o')
            island.insert(I[i - 1][j]);
        if (i < 9 && A[i + 1][j] == 'o')
            island.insert(I[i + 1][j]);
        if (j > 0 && A[i][j - 1] == 'o')
            island.insert(I[i][j - 1]);
        if (j < 9 && A[i][j + 1] == 'o')
            island.insert(I[i][j + 1]);
        if ((int)island.size() == t)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}