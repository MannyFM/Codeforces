
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(100003)

int n, m, a[maxn];
long long sum[maxn];

int main()
{
	freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	scanf("%d", &m);
	int l, r;
	while (m--)
	{
		scanf("%d%d", &l, &r);
		printf("%I64d\n", sum[r] - sum[l - 1]);
	}
}