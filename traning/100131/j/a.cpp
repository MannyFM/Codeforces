
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
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
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn

struct edge
{
	int a, b, c;
	edge(int a, int b, int c) : a(a), b(b), c(c) {};
};

int n, m;
vector <edge> e;
vector <int> g[maxn];
int us[maxn];

void dfs(int v)
{
	if (us[v])
		return;
	us[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
		dfs(g[v][i]);
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
		e.pb(edge(a, b, -c));
		g[a].pb(b);
	}
	vector <int> d(n + 1, inf);
	d[1] = 0;
	int x = -1;
	for (int i = 1; i <= n; i++)
	{
		x = -1;
		for (int j = 0; j < m; j++)
			if (d[e[j].a] < inf && d[e[j].b] > d[e[j].a] + e[j].c)
			{
				x = e[j].b;
				d[e[j].b] = d[e[j].a] + e[j].c;
			}
	}
	if (x != -1)
	{
		dfs(x);
		if (us[n])
		{
			puts(":)");
			return 0;
		}
	}
	if (d[n] < inf)
		printf("%d", -d[n]);
	else
		printf(":(");
}
