
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e3 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(5e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "path"
#define F first
#define S second
#define LOCAL

struct edge
{
	int a, b;
	ll c;
	edge(int a, int b, ll c) : a(a), b(b), c(c) {};
};
int n, m, s, x;
vector <ll> d;
vector <int> g[maxn], pr;
vector <char> us;
vector <edge> e;

void dfs(int v)
{
	us[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (!us[to])
			dfs(to);
	}
}

void solve()
{
	d.assign(n + 1, linf);
	pr.assign(n + 1, 0);
	for (int i = 1; i <= n; i++)
		pr[i] = i;
	d[s] = 0ll;
	for (int i = 0; i < n; i++)
	{
		x = -1;
		for (int j = 0; j < m; j++)
			if (d[e[j].a] < linf)
				if (d[e[j].b] > d[e[j].a] + e[j].c)
				{
					d[e[j].b] = max(d[e[j].a] + e[j].c, -linf);
					pr[e[j].b] = e[j].a;
					x = e[j].b;
				}
	}
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%I64d", &a, &b, &c);
		edge it = edge(a, b, c);
		g[a].pb(b);
		e.pb(it);
	}
	solve();
	us.assign(n + 1, 0);
	//printf("%d\n", x);
	if (x != -1)
	{
		for (int i = 0; i < n; i++)
			x = pr[x];
		dfs(x);
	}
	for (int i = 1; i <= n; i++)
		if (us[i])
		{
			puts(d[i] == linf ? "*" : "-");
		}
		else
		{
			if (d[i] == linf)
				puts("*");
			else
				printf("%I64d\n", d[i]);
		}
}