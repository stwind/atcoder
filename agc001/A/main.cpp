#include <bits/stdc++.h>
using namespace std;

void solve(long long N, std::vector<long long> L)
{
}

// Generated by 1.1.7.1 https://github.com/kyuridenamida/atcoder-tools  (tips: You use the default template now. You can remove this line by using your custom template)
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