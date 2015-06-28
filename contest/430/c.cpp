
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5 + 12)

int n;
int init[maxn];
int goal[maxn];
int us[maxn];
vector <int> g[maxn], ans;

void dfs(int v, int level, int tak, int zhyp)
{
	us[v] = 1;
	int now = (init[v] + ((level & 1) ? tak : zhyp)) % 2;
	if (now != goal[v])
	{
		ans.push_back(v);
		if (level & 1)
			tak++;
		else
			zhyp++;
	}
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (!us[to])
			dfs(to, level + 1, tak, zhyp);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", init + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", goal + i);
	dfs(1, 1, 0, 0);
	printf("%d\n", int(ans.size()));
	for (auto i : ans)
		printf("%d\n", i);
}