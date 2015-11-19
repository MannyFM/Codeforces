
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int us[1500][1500];
int cnt[1500][1500];
char s[1500][1500];

int dfs(int x, int y)
{
	if (us[y][x])
		return 0;
	if (s[y][x] == '*')
		return 1;
	us[y][x] = 1;
	int ans = 0;
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
			if ((abs(dx) + abs(dy) == 1) && 1 <= dx + x && dx + x <= m && 1 <= dy + y && dy + y <= n)
				ans += dfs(dx + x, dy + y);
	return ans;
}

void fill(int x, int y, int f)
{
	if (us[y][x] || s[y][x] == '*')
		return;
	us[y][x] = 1;
	cnt[y][x] = f;
	for (int dx = -1; dx <= 1; dx++)
		for (int dy = -1; dy <= 1; dy++)
			if (abs(dx) + abs(dy) == 1 && 1 <= dx + x && dx + x <= m && 1 <= dy + y && dy + y <= n)
				fill(x + dx, y + dy, f);
	
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '.' && !us[i][j])
			{
				cnt[i][j] = dfs(j, i);
				//printf("%d %d %d\n", j, i, cnt[i][j]);
			}
	memset(us, 0, sizeof(us));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!us[i][j])
				fill(j, i, cnt[i][j]);
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", cnt[i][j]);
		puts("");
	}
	*/
	for (int i = 1;  i <= k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", cnt[x][y]);
	}
}