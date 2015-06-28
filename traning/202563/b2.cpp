
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn (1500 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define LOCAL

char a[maxn][maxn], us[maxn][maxn];
int n, m;
pii vis[maxn][maxn];
queue <pii> q;

pii get(int x, int y)
{
	if (x >= 0)
		x /= n;
	else
		x = (x + 1) / n - 1;
	if (y >= 0)
		y /= m;
	else
		y = (y + 1) / m - 1;
	return mp(x, y);
}

int main()
{
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		scanf("\n%c", &a[i][j]);
		if (a[i][j] == 'S')
		{
			us[i][j] = 1;
			vis[i][j] = get(i, j);
			q.push(mp(i, j));
		}
	}
	while (!q.empty())
	{
		pii t = q.front();
		q.pop();
		int x = t.F, y = t.S;
		for (int dx = -1; dx < 2; dx++)
		for (int dy = -1; dy < 2; dy++)
		if (abs(dx) + abs(dy) == 1)
		{
			int xx = x + dx;
			int yy = y + dy;
			int wx = (xx % n + n) % n;
			int wy = (yy % m + m) % m;
			if (a[wx][wy] == '#')
				continue;
			if (us[wx][wy] && vis[wx][wy] != get(xx, yy))
			{
				puts("Yes");
				exit(0);
			}
			if (us[wx][wy])
				continue;
			us[wx][wy] = 1;
			vis[wx][wy] = get(xx, yy);
			q.push(mp(xx, yy));
		}
	}
	puts("No");
	
			
}