
#include <bits/stdc++.h>

using namespace std;

int pr[1010];
int us[1010];
int q, x, y;

int lca(int u, int v)
{
	memset(us, 0, sizeof(us));
	while (u > 1)
	{
		us[u] = 1;
		u = pr[u];
	}
	while (v > 1)
	{
		if (us[v])
			return v;
		v = pr[v];
	}
	return 1;
}

char s[10];

int main()
{
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%s %d%d", s, &x, &y);
		if (s[0] == 'A')
			pr[y] = x;
		else
		{
			printf("%d\n", lca(x, y));
		}
	}
}