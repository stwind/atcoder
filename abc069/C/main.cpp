// ref: https://qiita.com/nomikura/items/fecd8002fd236af9b0e9

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define MOD 1000000007
#define INF (1 << 30)
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

int main()
{
    IOS;
    int N;
    cin >> N;
    VI A(N);
    forn(i, 0, N) cin >> A[i];

    VI C(3);
    for (auto &a : A)
    {
        int k = 0;
        while (a % 2 == 0)
        {
            k++;
            a /= 2;
        }
        C[min(2, k)]++;
    }

    if (C[1] > 0)
        C[0]++;

    if (C[0] <= C[2] + 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}