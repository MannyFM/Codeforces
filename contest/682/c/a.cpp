
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int n;
vector <pii> g[maxn];
int sz[maxn], a[maxn];
ll dist[maxn];
int ans;

int dfs(int v) {
	sz[v] = 1;
	for (auto & x : g[v]) {
		int & to = x.F, & cost = x.S;
		dist[to] = dist[v] + cost;
		sz[v] += dfs(to);
	}
	return sz[v];
}

void solve(int v, ll mn) {
	ll MX = dist[v] - mn;
	if (MX > a[v]) {
		printf("%d--\n", v);
		ans += sz[v];
		return;
	}
	umin(mn, dist[v]);
	for (auto x : g[v])
		solve(x.F, mn);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 2; i <= n; i++) {
		int cost, pr;
		scanf("%d%d", &pr, &cost);
		g[pr].pb({i, cost});
	}
	dfs(1);
	solve(1, 0ll);
	printf("%d", ans);
}

