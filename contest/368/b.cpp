
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 213)

int n, m, a[maxn], us[maxn], l[maxn], ans[maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = n; i > 0; i--)
	{
		ans[i] += ans[i + 1] + !us[a[i]];
		us[a[i]] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", l + i);
		printf("%d\n", ans[l[i]]);
	}
}