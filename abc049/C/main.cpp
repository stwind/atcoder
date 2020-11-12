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
using VVI = vector<VI>;
using VLL = vector<LL>;

int main()
{
    string S;
    cin >> S;

    int i = S.size();
    while (i > 0)
    {
        if (i >= 6 && S.compare(i - 6, 6, "eraser") == 0)
            i -= 6;
        else if (i >= 7 && S.compare(i - 7, 7, "dreamer") == 0)
            i -= 7;
        else if (i >= 5 && (S.compare(i - 5, 5, "erase") == 0 || S.compare(i - 5, 5, "dream") == 0))
            i -= 5;
        else
            break;
    }

    cout << (i == 0 ? "YES" : "NO") << endl;

    return 0;
}