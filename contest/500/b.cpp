
#include <bits/stdc++.h>

using namespace std;

int n, g[330][330];
int us[330], s, a[330];

void dfs(int i)
{
	us[i] = 1;
	g[i][s] = g[s][i] = 1;
	for (int j = 1; j <= n; j++)
		if (!us[j] && g[i][j])
			dfs(j);
}

int main()
{
	scanf("%d", &n);
	char _char;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> _char;
			g[i][j] = (_char == '1');
		}
	for (s = 1; s <= n; s++)
	{
		for (int j = 1; j <= n; j++)
			us[j] = 0;
		dfs(s);
	}
	for (int i = 1; i <= n; i++)
	{
		int k = i;
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[k] && g[i][j])
			{
				k = j;
			}
		}
		swap(a[i], a[k]);
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}