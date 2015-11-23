
#include <bits/stdc++.h>

using namespace std;

int const maxn = int(1e5) + 12, inf = int(1e9) + 7;
int n, a[maxn];
int pre[maxn], suf[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    pre[0] = inf;
    suf[n + 1] = -inf;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += pre[i] <= suf[i + 1];
    printf("%d", ans);
}