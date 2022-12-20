#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

bool check(string S)
{
    if (S.size() == 1)
        return S == "8";
    if (S.size() == 2)
    {
        if (stoi(S) % 8 == 0)
            return true;
        swap(S[0], S[1]);
        return stoi(S) % 8 == 0;
    }

    vector<int> cnt(10);
    for (char x : S)
        cnt[x - '0']++;

    for (int x = 112; x < 1000; x += 8)
    {
        string s = to_string(x);
        cnt[s[0] - '0']--;
        cnt[s[1] - '0']--;
        cnt[s[2] - '0']--;
        if (cnt[s[0] - '0'] >= 0 && cnt[s[1] - '0'] >= 0 && cnt[s[2] - '0'] >= 0)
            return true;
        cnt[s[0] - '0']++;
        cnt[s[1] - '0']++;
        cnt[s[2] - '0']++;
    }

    return false;
}

int main()
{
    IOS;

    string S;
    cin >> S;

    cout << (check(S) ? "Yes" : "No") << endl;

    return 0;
}
