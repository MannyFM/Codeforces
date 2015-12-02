
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 350;
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
#define fn "dfs"
#define NO {puts("-1"); exit(0);}

int n, l;
int a[3 * maxn], pos, pr[maxn];
bool g[maxn][maxn];

void dfs(int v)
{
	//cerr << v << " " << pr[v] << " " << a[pos] << " " << pos << '\n';
	if (pos == l + 1)
	{
		g[pr[v]][v] = 0;
		pr[v] = 0;
		return;
	}
	while (pos <= l && a[pos] != pr[v])
	{
		g[v][a[pos]] = 1;
		pr[a[pos]] = v;
		dfs(a[pos++]);
	}
	if (a[pos] == pr[v])
	{
		pos++;
		return;
	}
	g[pr[v]][v] = 0;
	pr[v] = 0;
}

vector <int> cur, G[maxn];

void up(int v)
{
	int u = v;
	//printf("%d:", v);
	while (pr[u] > 0)
	{
		//printf("%d ", u);
		if (u < v)
			g[pr[u]][v] = 1;
		u = pr[u];
	}
	//puts("");
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= l; i++)
		scanf("%d", a + i);
	pos = 2;
	dfs(a[1]);
	/*
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j])
				printf("%d -> %d\n", i, j);
	*/
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (g[i][j])
				G[i].pb(j);
	for (int i = 1; i <= n; i++)
		up(i);
	set <pii> v;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (g[i][j] || g[j][i])
				v.insert(mp(i, j));
	printf("%d\n", v.size());
	for (pii x : v)
		printf("%d %d\n", x.F, x.S);
}
