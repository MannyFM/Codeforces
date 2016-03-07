
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 18;
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
#define in(mask, x) ((mask & (1 << x)) > 0)
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

int n, m, k, a[maxn];
ll dp[maxn + 2][(1 << maxn) + 3];
ll C[maxn + 2][maxn + 2];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		dp[i][1 << i] = a[i];
	}
	for (int i = 1; i <= k; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		C[a][b] = c;
	}
	for (int mask = 0; mask < (1 << n); mask++)
		for (int x = 0; x < n; x++)
		{
			if (!in(mask, x))
				continue;
			for (int y = 0; y < n; y++)
			{
				if (in(mask, y))
					continue;
				umax(dp[y][mask | (1 << y)], dp[x][mask] + C[x][y] + a[y]);
			}
		}
	ll ans = 0ll;
	for (int mask = 0; mask < (1 << n); mask++)
		for (int x = 0; x < n; x++)
			if (in(mask, x) && __builtin_popcount(mask) == m)
				umax(ans, dp[x][mask]);
	printf(I64, ans);
}

