
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int g[1010][1010];

bool check(int x, int y)
{
	if (!(x + 1 <= m && y + 1 <= n))
		return 0;
	int ans = 0;
	for (int i = 0; i <= 1; i++)
	for (int j = 0; j <= 1; j++)
		ans += g[i + y][x + j];
	//printf("%d", ans);
	return (ans == 4);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int t = 1; t <= k; t++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		swap(x, y);
		g[y][x] = 1;
		for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
		{
			if (1 <= y + j && y + j <= n && 1 <= x + i && x + i <= m)
			{
				//printf("%d %d ", y + j, x + i);
				if (check(x + i, y + j))
				{
					printf("%d", t);
					return 0;
				}
				//puts("");
			}
		}
		/*
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
				printf("%d", g[i][j]);
			puts("");
		}
		puts("");
		*/
	}
	puts("0");
}
