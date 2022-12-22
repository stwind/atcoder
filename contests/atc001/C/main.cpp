#include <bits/stdc++.h>
#include <math.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
#define MOD 1000000007
#define DEBUG(x) cout << #x << ": " << x << endl;
#define DEBUGV(a) for(auto it = a.begin() ; it != a.end(); it++) { cout << *it << " "; } cout << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> void add(T& a, T b) { a += b; if (a >= MOD) a -= MOD; }
template<typename T> void sub(T& a, T b) { a -= b; if (a < 0) a -= MOD; }
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using PLL = pair<LL, LL>;

// https://www.creativ.xyz/fast-fourier-transform/
vector<complex<double>> fft(vector<complex<double>> a, bool inverse = false)
{
    int n = a.size(), h = 0;
    for (int i = 0; 1 << i < n; i++)
        h++;

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        for (int k = 0; k < h; k++)
            j |= (i >> k & 1) << (h - 1 - k);
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int b = 1; b < n; b *= 2)
    {
        for (int j = 0; j < b; j++)
        {
            complex<double> w = polar(1.0, (2 * M_PI) / (2 * b) * j * (inverse ? 1 : -1));
            for (int k = 0; k < n; k += b * 2)
            {
                complex<double> s = a[j + k], t = a[j + k + b] * w;
                a[j + k] = s + t;
                a[j + k + b] = s - t;
            }
        }
    }
    if (inverse)
        for (int i = 0; i < n; i++)
            a[i] /= n;
    return a;
}

vector<complex<double>> fft(vector<double> a, bool inverse = false)
{
    int n = a.size();
    vector<complex<double>> a_complex(n);
    for (int i = 0; i < n; i++)
        a_complex[i] = complex<double>(a[i], 0);
    return fft(a_complex, inverse);
}

vector<double> convolve(vector<double> a, vector<double> b)
{
    int s = a.size() + b.size() - 1, t = 1;
    while (t < s)
        t *= 2;

    a.resize(t);
    b.resize(t);
    vector<complex<double>> A = fft(a), B = fft(b);
    for (int i = 0; i < t; i++)
        A[i] *= B[i];
    A = fft(A, true);
    a.resize(s);
    for (int i = 0; i < s; i++)
        a[i] = A[i].real();
    return a;
}

int main()
{
    IOS;
    int N;
    cin >> N;
    vector<double> A(N + 1, 0), B(N + 1, 0);
    forn(i, 0, N) cin >> A[i + 1] >> B[i + 1];

    vector<double> ans = convolve(A, B);
    forn(i, 1, (int)ans.size())
    {
        cout << (int)(ans[i] + 0.5) << endl;
    }
    return 0;
}