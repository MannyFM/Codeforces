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

ll dp[maxn][(1 << maxn) + 2], ans;
int n, m, k;
int c[maxn][maxn], a[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		dp[i][1 << i] = a[i];
	}
	for (int i = 0; i < k; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		c[x][y] = z;
	}
	for (int mask = 0; mask < (1 << n); mask++)
		for (int y = 0; y < n; y++)
		{
			if (mask & (1 << y))
				continue;
			for (int x = 0; x < n; x++)
				if (mask & (1 << x))
					dp[y][mask | (1 << y)] = max(dp[y][mask | (1 << y)], dp[x][mask] + a[y] + c[x][y]);
		}
	for (int mask = 0; mask < (1 << n); mask++)
		if (__builtin_popcount(mask) == m)
			for (int last = 0; last < n; last++)
				ans = max(ans, dp[last][mask]);
	printf(I64, ans);
}
