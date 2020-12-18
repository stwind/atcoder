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
    int N, MA, MB;
    cin >> N >> MA >> MB;
    VI A(N), B(N), C(N);
    forn(i, 0, N) cin >> A[i] >> B[i] >> C[i];

    int h = N / 2;

    unordered_map<int, int> G1;
    forn(bit, 1, 1 << h)
    {
        int a = 0, b = 0, c = 0;
        forn(i, 0, h) if (bit & (1 << i))
        {
            a += A[i];
            b += B[i];
            c += C[i];
        }
        int k = a * MB - b * MA;
        if (G1.count(k))
            chmin(G1[k], c);
        else
            G1[k] = c;
    }

    unordered_map<int, int> G2;
    forn(bit, 1, 1 << (N - h))
    {
        int a = 0, b = 0, c = 0;
        forn(i, 0, N - h) if (bit & (1 << i))
        {
            a += A[h + i];
            b += B[h + i];
            c += C[h + i];
        }
        int k = b * MA - a * MB;
        if (G2.count(k))
            chmin(G2[k], c);
        else
            G2[k] = c;
    }

    const int INF = 1e9;
    int res = INF;
    if (G1.count(0))
        chmin(res, G1[0]);
    if (G2.count(0))
        chmin(res, G2[0]);
    for (auto [k, c] : G1)
    {
        if (G2.count(k))
            chmin(res, c + G2[k]);
    }
    cout << (res < INF ? res : -1) << endl;

    return 0;
}