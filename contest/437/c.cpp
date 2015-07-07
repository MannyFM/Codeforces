
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 1010;
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef WIN32
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
int v[maxn], cost[maxn];
pii a[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", v + i);
		a[i] = mp(v[i], i);
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
		cost[a] += v[b];
		cost[b] += v[a];
	}
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int u = a[i].S;
		ans += cost[u];
		for (int i = 0; i < int(g[u].size()); i++)
			cost[g[u][i]] -= v[u];
	}
	printf(I64, ans);
}
