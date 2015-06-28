
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define maxn (int)(1e5+123)

long long n, m, kn, kx;

long long s(long long c)
{
    long long ans = c * (c - 1);
    return ans / 2;
}

long long sum(long long c)
{
    long long ans = c * (c - 1);
    return ans / 2;
}

int main()
{
    cin >> n >> m;
    cout << sum(n - m + 1) << " " << s(n - m + 1) << " " << (n - m + 1) * (n - m) / 2;
}
