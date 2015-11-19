
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, T;
ll sum;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        sum = (n + 1ll) * n / 2;
        ll cur = 0;
        for (int i = 0; (1ll << i) <= n; i++)
            cur += (1ll << i);
        sum -= cur * 2;
        printf("%lld\n", sum);
    }
}