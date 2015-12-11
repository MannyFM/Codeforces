
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
//#define fn ""

int n, pr[maxn], root;
vector <pii> q[maxn];
vector <int> g[maxn];
int ans[maxn], lvl[maxn], dp[maxn];

void dfs(int v)
{
	lvl[v] = lvl[pr[v]] + 1;
	for (pii x : q[v])
		if (x.S + lvl[v] < maxn)
		{
			ans[x.F] = dp[x.S + lvl[v]];
			//printf("v:%d i:%d k:%d = %d\n", v, x.F, x.S, ans[x.F]);
		}
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int & to = g[v][i];
		dfs(to);
	}
	for (pii x : q[v])
		if (x.S + lvl[v] < maxn)
		{
			ans[x.F] = dp[x.S + lvl[v]] - ans[x.F];
			//printf("v:%d i:%d k:%d = %d\n", v, x.F, x.S, ans[x.F]);
		}
	dp[lvl[v]]++;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", pr + i);
		if (pr[i] == -1)
			root = i;
		else
			g[pr[i]].pb(i);
	}
	pr[root] = 0;
	int m, v, k;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &v, &k);
		q[v].pb(mp(i, k));
	}
	dfs(root);
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
}
