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
//#define fn ""

int n, m;
vector <int> g[maxn];
int cat[maxn], us[maxn], ans;

void dfs(int v, int cnt)
{
	cnt = cat[v] ? cnt + 1 : 0;
	//printf("%d %d\n", v, cnt);
	if (cnt > m)
		return;
	us[v] = true;
	if (g[v].size() == 1 && v != 1)
	{
		ans++;
		return;
	}
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		if (!us[to])
			dfs(to, cnt);
	}
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", cat + i);
	int u, v;
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	printf("%d", ans);
}
