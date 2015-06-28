
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define fn "a"
#define ch(x, y) (1 <= x && x <= m && 1 <= y && y <= n)

char a[55][55];
int n, m;
int xs, ys, cyc;
int us[55][55];

void dfs(int x, int y, int deep, pii pr)
{
	us[y][x] = 1;
	int i = -1, j = 0;
	for (i = -1; i <= 1; i++)
	{
		if (!ch(x + i, y + j))
			continue;
		if (x + i == xs && y + j == ys && deep > 2 && pr.f != x + i && pr.s != y + j)
		{
			cyc = 1;
			return;
		}
		if (us[y + j][x + i] || a[y + j][x + i] != a[ys][xs])
			continue;
		dfs(x + i, y + j, deep + 1, mp(x, y));
	}
	i = 0, j = -1;
	for (j = -1; j <= 1; j++)
	{
		if (!ch(x + i, y + j))
			continue;
		if (x + i == xs && y + j == ys && deep > 2 && pr.f != x + i && pr.s != y + j)
		{
			cyc = 1;
			return;
		}
		if (us[y + j][x + i] || a[y + j][x + i] != a[ys][xs])
			continue;
		dfs(x + i, y + j, deep + 1, mp(x, y));
	}
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			for (int it = 1; it <= n; it++)
				for (int jt = 1; jt <= m; jt++)
					us[it][jt] = 0;
			cyc = 0;
			xs = j, ys = i;
			dfs(j, i, 1, mp(j, i));
			if (cyc)
			{
				puts("Yes");
				return 0;
			}
		}
	puts("No");
}
