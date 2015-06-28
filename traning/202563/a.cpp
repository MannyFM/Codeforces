
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define LOCAL

int n, m;
char a[100][100], us[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, char color, int px, int py)
{
	us[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (!(1 <= xx && xx <= m && 1 <= yy && yy <= n) || a[yy][xx] != color || (yy == py && xx == px))
			continue;
		if (us[yy][xx] > 1)
			return 1;
		if (dfs(xx, yy, color, x, y))
			return 1;
	}
	return 0;
}

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("\n%c", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (dfs(j, i, a[i][j], -1, -1))
			{
				puts("Yes");
				return 0;
			}
		}
	puts("No");
}