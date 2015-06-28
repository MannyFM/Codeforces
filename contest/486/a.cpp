
#include <bits/stdc++.h>

using namespace std;

int a[200][200], b[200][200], c[200][200];
int row[200], col[200], n, m;
int xrow[200], xcol[200];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &b[i][j]);
			a[i][j] = 1;
		}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		if (!b[i][j])
			row[i] = 0, col[j] = 0;
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		if (!row[i] || !col[j])
			a[i][j] = 0;
		else
			a[i][j] = 1;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			xrow[i] |= a[i][j];
			xcol[j] |= a[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			c[i][j] = xcol[j] | xrow[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", c[i][j]);
		puts("");
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (b[i][j] != c[i][j])
			{
				puts("NO");
				return 0;
			}
		}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", a[i][j]);
		puts("");
	}
}
