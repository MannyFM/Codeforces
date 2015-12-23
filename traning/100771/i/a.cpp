
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxk = 22;
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

int n, m;
vector <int> g[maxn];
int tin[maxn], tout[maxn], timer;

void dfs(int v, int p = 0)
{
	tin[v] = timer++;
	for (int & to : g[v])
		if (to != p)
			dfs(to, v);
	tout[v] = timer++;
}

bool par(int v, int u)
{
	return tin[v] < tin[u] && tout[u] < tout[v];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	int q, u, v;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &u, &v);
		puts(par(u, v) ? "YES" : "NO");
	}
}

