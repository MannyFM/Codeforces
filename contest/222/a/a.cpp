
#include <bits/stdc++.h>

#define maxn (int)(1e5 + 12)

int n, k, a[maxn];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = k + 1; i <= n; i++)
		if (a[i] != a[k])
		{
			puts("-1");
			return 0;
		}
	int i = k;
	while (a[i] == a[k])
		i--;
	printf("%d", i);
}