
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, a[maxn];
long long s[maxn];

int main()
{
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	int m, l, r;
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d%d", &l, &r);
		long long ans = s[r] - s[l - 1];
		printf("%I64d\n", ans);
	}
}
