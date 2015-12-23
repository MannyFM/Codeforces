
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
#define next MyLittleNext
#define rank MyLittleRank
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn "tree"

template <typename T>
bool umax(T & a, const T & b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}

struct edge
{
	int a, b, c, id;
	bool in;
	edge() { a = b = id = c = 0; in = 0;};
	edge(int a, int b, int c, int id) : a(a), b(b), c(c), id(id), in(0) {};
	bool operator < (const edge & p)
	{
		return c < p.c;
	}
};

const int max_k = 22;
int boss[maxn], rank[maxn];

int who(int v)
{
	if (boss[v] == v)
		return v;
	return boss[v] = who(boss[v]);
}

bool merge(int u, int v)
{
	u = who(u);
	v = who(v);
	if (u == v)
		return 0;
	if (rank[u] < rank[v])
		swap(u, v);
	boss[v] = u;
	if (rank[u] == rank[v])
		rank[u]++;
	return 1;
}

int n, m;
ll ans[maxn];
vector <pii> g[maxn];
vector <edge> e;

int pr[22][maxn], mx[22][maxn];
int lvl[maxn];

void dfs(int v, int p = 0, int val = -inf)
{
	pr[0][v] = p;
	mx[0][v] = val;
	lvl[v] = lvl[p] + 1;
	for (int k = 1; k < max_k; k++)
	{
		pr[k][v] = pr[k - 1][pr[k - 1][v]];
		mx[k][v] = max(mx[k - 1][v], mx[k - 1][pr[k - 1][v]]);
	}
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int & to = g[v][i].F, & cost = g[v][i].S;
		if (to != p)
			dfs(to, v, cost);
	}
}

int f(int u, int v)
{
	if (lvl[u] > lvl[v])
		swap(u, v);
	int a = u, b = v;
	int ans = -inf;
	for (int k = max_k - 1; k >= 0; k--)
		if (pr[k][v] > 0 && lvl[pr[k][v]] >= lvl[u])
		{
			//printf("%d=>%d(%d)\n", v, pr[k][v], mx[k][v]);
			umax(ans, mx[k][v]);
			v = pr[k][v];
		}
	for (int k = max_k - 1; k >= 0; k--)
		if (pr[k][v] > 0 && pr[k][u] > 0 && pr[k][v] != pr[k][u])
		{
			//printf("%d=>%d(%d)\n", v, pr[k][v], mx[k][v]);
			//printf("%d=>%d(%d)\n", v, pr[k][u], mx[k][u]);
			umax(ans, mx[k][v]);
			umax(ans, mx[k][u]);
			v = pr[k][v];
			u = pr[k][u];
		}
	if (u != v)
	{
		umax(ans, mx[0][v]);
		umax(ans, mx[0][u]);
	}
	//printf("a:%d b:%d u:%d v:%d l1:%d l2:%d a: %d\n", a, b, u, v, pr[0][v], pr[0][u], ans);
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		e.pb(edge(a, b, c, i));
	}
	for (int i = 1; i <= n; i++)
		boss[i] = i;
	sort(e.begin(), e.end());
	ll cur = 0ll;
	for (auto & i : e)
		if (merge(i.a, i.b))
		{
			cur += i.c;
			g[i.a].pb(mp(i.b, i.c));
			g[i.b].pb(mp(i.a, i.c));
			//printf("%d -> %d\n", i.a, i.b);
			i.in = 1;
		}
	dfs(1);
	for (auto i : e)
	{
		//printf("%d -> %d (c:%d i:%d %c)\n", i.a, i.b, i.c, i.id, i.in ? '+' : '-');
		if (i.in)
			ans[i.id] = cur;
		else
			ans[i.id] = cur + i.c - f(i.a, i.b);
	}
	for (int i = 1; i <= m; i++)
		printf(I64 "\n", ans[i]);
	
}

