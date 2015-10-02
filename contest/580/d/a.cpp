#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 19;
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

ll c[maxn][maxn];
int a[maxn];
//ll dp[maxn][maxn][(1 << maxn) + 12];
map <pii>, ll> dp;
int n, k, m;

void rec(int v, int mask)
{
	if (dp.find(mp(v, mask)) != dp.end())
		return dp[mp(v, mask)];
	ll & ans = dp[mp(v, mask)];
	//printf("%d %d %d " I64 "\n", v, cnt, mask, ans);
	if (__builtin_popcount(mask) == m)
		return;
	ans = 0ll;
	for (int to = 0; to < n; to++)
	{
		if (mask & (1 << to))
			continue;
		ans = max(ans, rec(to, cnt - 1, mask | (1 << to)) + c[v][to]);
	}
	ans += a[v];
	return ans;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	//memset(dp, -1, sizeof (dp));
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < k; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		c[x][y] = z;
	}
	ll ans = 0ll;
	for (int i = 0; i < n; i++)
	{
		//printf("%d:\n", i);
		ans = max(ans, rec(i, m, (1 << i)));
	}
	printf(I64, ans);
}
