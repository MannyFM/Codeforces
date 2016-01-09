
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

int n, m, k;
int sz[maxn];
vector <int> g[maxn];
ll ans = 1;

ll bp(ll x, ll y)
{
	ll ans = 1;
	while (y)
	{
		if (y & 1)
			ans = (ans * x) % k;
		x = (x * x) % k;
		y >>= 1;
	}
	return ans;
}

int dfs(int v)
{
	sz[v] = 1;
	for (int & to : g[v])
		if (!sz[to])
			sz[v] += dfs(to);
	return sz[v];
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (sz[i])
			continue;
		cnt++;
		ans = (ans * dfs(i)) % k;
	}
	if (cnt == 1)
	{
		printf("%d", cnt % k);
		return 0;
	}
	ans = (ans * bp(n, cnt - 2)) % k;
	printf(I64, ans);
}

