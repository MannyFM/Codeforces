
#include <bits/stdc++.h>

using namespace std;

int n, m, us[110];
vector <int> g[110][110];

void dfs(int v, int color)
{
	us[v] = 1;
	for (int i = 0; i < (int)g[v][color].size(); i++)
	{
		int t = g[v][color][i];
		if (!us[t])
			dfs(t, color);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		g[u][c].push_back(v);
		g[v][c].push_back(u);
	}
	int t;
	scanf("%d", &t);
	for (int j = 0; j < t; j++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int ans = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int k = 1; k <= n; k++)
				us[k] = 0;
			dfs(a, i);
			ans += us[b];
		}
		printf("%d\n", ans);
	}

}