#include <bits/stdc++.h>
using namespace std;

void solve(long long N, long long K, std::vector<long long> A, std::vector<long long> B)
{
}

int main()
{
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> A(N - 1);
    std::vector<long long> B(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }
    solve(N, K, std::move(A), std::move(B));
    return 0;
}
