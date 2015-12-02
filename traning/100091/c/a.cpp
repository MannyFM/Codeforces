
#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
int const maxn = int(1e5) + 4;
int n, q, pos[maxn], old[4 * maxn];
vector <int> g[maxn];
vector <int> a;

void dfs(int v)
{
	pos[v] = a.size();
	old[pos[v]] = v;
	a.pb(pos[v]);
	for (int i = 0; i < int(g[v].size()); i++)
	{
		int to = g[v][i];
		dfs(to);
		a.pb(pos[v]);
	}
}

int s[30][4 * maxn];
int lg[4 * maxn];

void pre()
{
	int n = int(a.size());
	assert(n < 4 * maxn); 
	for (int i = 2; i <= n; i++)
		lg[i] = lg[i / 2] + 1;
	assert(lg[n] < 30);
	for (int i = 0; i < n; i++)
		s[0][i] = a[i];
	for (int k = 1; k <= lg[n]; k++)
		for (int i = 0; i < n; i++)
			s[k][i] = min(s[k - 1][i], s[k - 1][i + (1 << (k - 1))]);
}

int lca(int u, int v)
{
	int l = pos[u], r = pos[v];
	if (l > r)
		swap(l, r);
	int k = lg[r - l + 1];
	return old[min(s[k][l], s[k][r - (1 << k) + 1])];
}

int main()
{
	freopen("lca_rmq.in", "r", stdin);
	freopen("lca_rmq.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		g[x].pb(i);
	}
	dfs(0);
	pre();
	int a[4], x, y, z, last = 0;
	ll ans = 0;
	scanf("%d%d%d%d%d", a, a + 1, &x, &y, &z);
	for (int i = 1; i <= q; i++)
	{
		last = lca((a[0] + last) % n, a[1]);
		ans += last;
		last %= n;
		a[2] = (x * 1ll * a[0] + y * 1ll * a[1] + z) % n;
		a[3] = (x * 1ll * a[1] + y * 1ll * a[2] + z) % n;
		a[0] = a[2], a[1] = a[3];
	}
	printf("%lld", ans);
}
