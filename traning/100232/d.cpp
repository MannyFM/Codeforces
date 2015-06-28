
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 100 * 1000 + 12
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fname "cycle"
#define LOCAL
#define F first
#define S second

int n, m, st = -1, fn = -1;
vector <int> g[maxn], pr;
vector <char> us;

void dfs(int v)
{
	us[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (us[to] == 1 && st == -1)
		{
			st = to;
			fn = v;
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
		freopen(fname".in", "r", stdin);
		freopen(fname".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	us.assign(n + 1, 0);
	pr.assign(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
	}
	for (int i = 1; i <= n; i++)
		if (!us[i])
			dfs(i);
	if (fn == -1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int v = fn;
	vector <int> path;
	while (v != st)
	{
		path.pb(v);
		v = pr[v];
	}
	path.pb(st);
	reverse(path.begin(), path.end());
	for (auto i : path)
		printf("%d ", i);
}