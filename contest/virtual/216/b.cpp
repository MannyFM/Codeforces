
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
#define fn "a"
#define f first
#define s second

int n, m, ok;
int us[maxn], now;
vector <int> g[maxn];

void dfs(int v, int color)
{
	us[v] = color;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (us[to] == color)
		{
			us[v] = 3;
			ok = 0;
		}
		if (!us[to])
			dfs(to, color == 1 ? 2 : 1);
	}
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	ok = 0;
	while (!ok)
	{
		ok = 1;
		for (int i = 1; i <= n; i++)
			us[i] = us[i] == 3 ? 3 : 0;
		for (int i = 1; i <= n; i++)
			if (!us[i])
				dfs(i, 1);
		/*
		for (int i = 1; i <= n; i++)
			printf("%d ", us[i]);
		puts("");
		*/
	}
	for (int i = 1; i <= n; i++)
		now += us[i] == 3;
	printf("%d", now);
}