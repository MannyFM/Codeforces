
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(5e3 + 12);
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
#define fn "tree"

ll dp[maxn][maxn];

int n, a[maxn], sz[maxn];
vector <int> G[maxn], g[maxn];

void dfs(int v, int pr = -1)
{
	for (int i = 0; i < int(G[v].size()); i++)
	{
		int & to = G[v][i];
		if (to == pr)
			continue;
		g[v].pb(to);
		//printf("%d->%d\n", v, to);
		dfs(to, v);
		sz[v] += sz[to];
	}
	if (g[v].size() == 2 && sz[g[v][0]] > sz[g[v][1]])
		swap(g[v][0], g[v][1]);
	sz[v]++;
}

ll rec(int v, int sum)
{
	//printf(" %d %d %d\n", v, sum, int(g[v].size()));
	if (sum > sz[v])
		return linf;
	if (g[v].empty())
		return abs(sum - a[v]);
	ll & ans = dp[v][sum];
	if (ans != -1)
		return ans;
	ans = inf;
	int l = g[v][0];
	if (g[v].size() == 1)
		return ans = rec(l, sum) + abs(sum - a[v]);
	int r = g[v][1];
	for (int s = 0; s <= min(sum, sz[l]); s++)
		ans = min(ans, rec(l, s) + rec(r, sum - s) + abs(sum - a[v]));
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].pb(y);
		G[y].pb(x);
	}
	dfs(1);
	ll ans = linf;
	for (int sum = 0; sum <= n; sum++)
	{
		ll x = rec(1, sum);
		ans = min(ans, x);
		//printf("%d " I64 "\n", sum, x);
	}
	printf(I64, ans);
}
