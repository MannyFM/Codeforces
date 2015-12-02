

#include <bits/stdc++.h>

using namespace std;

int const maxn = 500 * 1000 + 12, max_k = 20;

int h[maxn], pr[25][maxn];

void add(int v, int p)
{
	h[v] = h[p] + 1;
	pr[0][v] = p;
	for (int k = 1; k < max_k; k++)
	{
		pr[k][v] = pr[k - 1][pr[k - 1][v]];
		//printf("pr[%d][%d] = %d pr[%d][pr[%d][%d](%d)] = %d\n", k, v, pr[k][v], k - 1, k - 1, v, pr[k - 1][v], pr[k - 1][pr[k - 1][v]]);
	}
}

int lca(int u, int v)
{
	if (h[u] > h[v])
		swap(u, v);
	for (int k = max_k - 1; k >= 0; k--)
		if (h[pr[k][v]] >= h[u])
			v = pr[k][v];
	for (int k=  max_k - 1; k >= 0; k--)
	{
		if (pr[k][v] != pr[k][u])
		{
			v = pr[k][v];
			u = pr[k][u];
		}
	}
	if (v != u)
		return pr[0][v];
	return v;
}

int q;
char s[15];
int x, y;

int main()
{
	freopen("lca.in", "r", stdin);
	freopen("lca.out", "w", stdout);
	for (int k = 0; k < max_k; k++)
		for (int i = 0; i < maxn; i++)
			pr[k][i] = 1;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%s %d %d", s, &x, &y);
		if (s[0] == 'A')
		{
			add(y, x);
		}
		else
		{
			printf("%d\n", lca(x, y));
		}
	}
}