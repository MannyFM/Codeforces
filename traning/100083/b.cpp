
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "cycle2"
#define F first
#define S second
#define LOCAL

int n, m;
int pr[maxn], us[maxn];
vector <int> g[maxn];
int st = -1, fi = -1;

void dfs(int v)
{
	us[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (us[to] == 2)
			continue;
		if (us[to] == 1)
		{
			st = to;
			fi = v;
			return;
		}
		if (!us[to])
		{
			pr[to] = v;
			dfs(to);
		}
	}
	us[v] = 2;
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
	}
	for (int i = 1; i <= n; i++)
		if (!us[i])
			pr[i] = i, dfs(i);
	if (st == -1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int y = fi;
	vector <int> path;
	while (y != st && y != pr[y])
	{
		path.pb(y);
		y = pr[y];
	}
	path.pb(y);
	reverse(path.begin(), path.end());
	for (auto i : path)
		printf("%d ", i);
}