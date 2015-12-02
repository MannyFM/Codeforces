
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int const maxn = int(1e5) + 4, max_k = 25;

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()

vector <int> g[maxn], gr[maxn];
int us[maxn], n, m;
vector <int> order, cmp;

void dfs1(int v)
{
	us[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int & to = g[v][i];
		if (!us[to])
			dfs1(to);
	}
	order.pb(v);
}

void dfs2(int v)
{
	us[v] = 1;
	cmp.pb(v);
	for (int i = 0; i < int(gr[v].size()); i++)
	{
		int & to = gr[v][i];
		if (!us[to])
			dfs2(to);
	}
}

set <int> G[maxn];
int N, H[maxn], F;
int pr[30][maxn];

void dfs3(int v, int p = -1)
{
	for (int k = 1; k < max_k; k++)
		pr[k][v] = pr[k - 1][pr[k - 1][v]];
	for (int to : G[v])
	{
		if (to == p)
			continue;
		pr[0][to] = v;
		dfs3(to, v);
	}
}

int lca(int u, int v)
{
	if (H[u] > H[v])
		swap(u, v);
	for (int k = max_k - 1; k >= 0; k--)
		if (H[pr[k][v]] <= H[u])
			v = pr[k][v];
	for (int k = max_k - 1; k >= 0; k--)
		if (pr[k][v] != pr[k][u])
		{
			v = pr[k][v];
			u = pr[k][u];
		}
	if (u != v)
		return pr[0][u];
	return u;
}

vector <vector <int>> C;
vector <pii> E;
int pos[maxn];

int main()
{
	scanf("%d%d%d", &n, &m, &F);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].pb(y);
		gr[y].pb(x);
		
		g[y].pb(x);
		gr[x].pb(y);
		E.pb({x, y});
	}
	/*
	for (int i = 1; i <= n; i++)
		if (!us[i])
			dfs1(i);
	*/
	dfs1(F);
	memset(us, 0, sizeof(us));
	reverse(all(order));
	for (int v : order)
	{
		if (!us[v])
		{
			dfs2(v);
			C.pb(cmp);
			N++;
			for (int x : cmp)
				pos[x] = N;
			cmp.clear();
		}
	}
	for (pii e : E)
	{
		G[pos[e.F]].insert(pos[e.S]);
		G[pos[e.S]].insert(pos[e.F]);
	}
	for (int i = 1; i <= n; i++)
		printf("pos[%d]=%d\n", i, pos[i]);
	dfs3(F);
}