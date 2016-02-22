
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 19;
int const maxb = 1 << maxn;
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

#define in(mask, i) ((mask & (1 << i)) > 0)
ll dp[maxn][maxb];
int n, m, a[maxn];
int g[maxn][maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int k;
	scanf("%d%d%d", &n, &m, &k);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= k; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		g[x][y] = z;
	}
	for (int i = 1; i <= n; i++)
		dp[i][1 << (i - 1)] = a[i];
	for (int mask = 0; mask < (1 << n); mask++)
	{
		for (int last = 1; last <= n; last++)
		{
			if (!in(mask, (last - 1)))
				continue;
			for (int cur = 1; cur <= n; cur++)
				if (!in(mask, (cur - 1)))
					umax(dp[cur][mask | (1 << (cur - 1))], dp[last][mask] + a[cur] + g[last][cur]);
		}
	}
	ll ans = 0ll;
	for (int mask = 0; mask < (1 << n); mask++)
		for (int last = 1; last <= n; last++)
			if (in(mask, (last - 1)) && __builtin_popcount(mask) == m)
				umax(ans, dp[last][mask]);
	printf(I64, ans);
}

