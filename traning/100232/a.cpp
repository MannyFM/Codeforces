
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
#define linf ll(2e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "path_easy"
#define LOCAL

struct edge
{
	int a, b;
	ll c;
	edge() {};
	edge(int a, int b, ll c) : a(a), b(b), c(c) {};
};

vector <int> g[maxn];
vector <edge> e;
int n, m, s, x;
vector <char> us;
vector <ll> d;

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

void ford()
{
	d.assign(n + 1, linf);
	d[s] = 0ll;
	for (int i = 0; i < n; i++)
	{
		x = -1;
		for (int j = 0; j < m; j++)
			if (d[e[j].a] < linf)
				if (d[e[j].b] > d[e[j].a] + e[j].c)
				{
					d[e[j].b] = d[e[j].a] + e[j].c;
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
	for (int i = 0; i < m; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%I64d", &a, &b, &c);
		edge it = edge(a, b, c);
		e.pb(it);
		g[a].pb(b);
	}
	ford();
	us.assign(n + 1, 0);
	if (x != -1)
		dfs(x);
	for (int i = 1; i <= n; i++)
	{
		if (!us[i])
		{
			if (d[i] == linf)
				puts("*");
			else
				printf("%I64d\n", d[i]);
		}
		else
			puts(d[i] == linf ? "*" : "-");
	}
}