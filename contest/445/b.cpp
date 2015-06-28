
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "a"
#define f first
#define s second

int n, m, sz, us[maxn];
vector <int> g[maxn];

void dfs(int v)
{
	us[v] = 1;
	for (int i = 0; i < int(g[v].size()); i++)
		if (!us[g[v][i]])
			dfs(g[v][i]);	
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	for (int i = 1; i <= n; i++)
		if (!us[i])
			sz++, dfs(i);
	printf("%I64d", (1ll << (n - sz)));
}