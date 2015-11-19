#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 5400;
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

struct edge
{
	int a, b, c, f;
	edge(): a(0), b(0), c(0), f(0){};
	edge(int a, int b, int c) : a(a), b(b), c(c), f(0) {};
	edge(int a, int b) : a(a), b(b), c(0), f(0) {};
};

vector <int> g[maxn];
vector <edge> e;

void add_edge(int a, int b, int c)
{
	g[a].pb(e.size());
	e.pb(edge(a, b, c));
	g[b].pb(e.size());
	e.pb(edge(b, a));
}

int d[maxn], q[maxn], qh, qt;
int S, T;
int ptr[maxn];

bool bfs()
{
	qh = qt = 0;
	q[qt++] = S;
	memset(d, -1, sizeof(d));
	d[S] = 0;
	while (qh < qt)
	{
		int v = q[qh++];
		for (int i = 0; i < int(g[v].size()); i++)
		{
			int id = g[v][i], to = e[id].b;
			if (d[to] == -1 && e[id].f < e[id].c)
			{
				d[to] = d[v] + 1;
				q[qt++] = to;
			}
		}
	}
	return d[T] != -1;
}

int dfs(int v, int flow)
{
	if (!flow)
		return 0;
	if (v == T)
		return flow;
	for (; ptr[v] < int(g[v].size()); ptr[v]++)
	{
		int & id = g[v][ptr[v]], & to = e[id].b;
		if (d[to] != d[v] + 1)
			continue;
		int pushed = dfs(to, min(flow, e[id].c - e[id].f));
		if (pushed)
		{
			e[id].f += pushed;
			e[id ^ 1].f -= pushed;
			return pushed;
		}
	}
	return 0;
}

int dinic()
{
	int flow = 0;
	while (1)
	{
		if (!bfs())
			break;
		//cerr << flow << " ";
		memset(ptr, 0, sizeof(ptr));
		while (int pushed = dfs(S, inf))
			flow += pushed;
	}
	return flow;
}

int n, m;
int a[maxn], b[maxn], A, B;
int f[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	S = 0, T = 1010;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", b + i);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add_edge(a, b + 150, inf);
		add_edge(b, a + 150, inf);
	}
	for (int i = 1; i <= n; i++)
	{
		add_edge(i, i + 150, inf);
		add_edge(S, i, a[i]);
		add_edge(i, i + 150, inf);
		add_edge(i + 150, T, b[i]);
		A += a[i];
		B += b[i];
	}
	if (A != B || A != dinic())
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < int(g[i].size()); j++)
		{
			int & id = g[i][j];
			if (e[id].f <= 0)
				continue;
			//printf("%d -> %d (%d)\n", e[id].a, e[id].b - 150, e[id].f);
			f[e[id].a][e[id].b - 150] = e[id].f;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", f[i][j]);
		puts("");
	}
}
