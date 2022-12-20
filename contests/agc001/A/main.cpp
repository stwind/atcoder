#include <bits/stdc++.h>
using namespace std;

void solve(long long N, std::vector<long long> L)
{
    sort(L.begin(), L.end());
    int res = 0;
    for (int i = 0; i < 2 * N; i += 2)
    {
        res += min(L[i], L[i + 1]);
    }
    cout << res << endl;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> L(2 * N);
    for (int i = 0; i < 2 * N; i++)
    {
        scanf("%lld", &L[i]);
    }
    solve(N, std::move(L));
    return 0;
}