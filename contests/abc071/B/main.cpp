#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
#define all(s) s.begin(), s.end()
// clang-format on

using LL = long long;
using VI = vector<int>;
using VLL = vector<LL>;

int main()
{
    string S;
    cin >> S;

    unordered_set<int> C;
    for (auto c : S)
        C.insert(c - 'a');

    if (C.size() == 26)
    {
        cout << "None" << endl;
    }
    else
    {
        forn(i, 0, 26)
        {
            if (!C.count(i))
            {
                cout << (char)(i + 'a') << endl;
                break;
            }
        }
    }

    return 0;
}