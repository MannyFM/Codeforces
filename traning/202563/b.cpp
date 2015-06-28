
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 1500 + 1
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define LOCAL

char a[maxn][maxn];
char us[maxn][maxn];

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
pii s;

void dfs(pii v, int tx, int ty, pii pr)
{
	//cout << v.F << " " << v.S << '\n';
	us[v.S][v.F] = 1;
	for (int i = 0; i < 4; i++)
	{
		int x = dx[i] + v.F;
		int y = dy[i] + v.S, fl = 0;
		if (x < 0)
			fl = 1, x += m;
		if (x > m)
			fl = 2, x -= m;
		if (y <	0)
			fl = 3, y += n;
		if (y > n)
			fl = 4, y -= n;
		if (a[y][x] == '#')
			continue;
		if (us[y][x] == 1 && mp(x, y) != pr && (tx || ty))
		{
			puts("Yes");
			exit(0);
		}
		if (!us[y][x])
		{
			if (fl == 0)
				dfs(mp(x, y), tx, ty, v);
			if (fl == 1)
				dfs(mp(x, y), tx - 1, ty, v);
			if (fl == 2)
				dfs(mp(x, y), tx + 1, ty, v);
			if (fl == 3)
				dfs(mp(x, y), tx, ty - 1, v);
			if (fl == 4)
				dfs(mp(x, y), tx, ty + 1, v);
		}
	}
	us[v.S][v.F] = 2;
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
		{
			scanf("\n%c", &a[i][j]);
			if (a[i][j] == 'S')
				s = mp(j, i);
		}
	dfs(s, 0, 0, s);
	puts("No");
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			printf("%d ", us[i][j]);
		puts("");
	}
	*/
}