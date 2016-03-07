
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

#define in(mask, i) ((mask & (1 << i)) > 0)
bool isPrime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

int mn(int p, int x)
{
//	printf("%d %d: ", p, x);
	if (p < 2)
		return 1;
	int v = p, ans = abs(p - x), y = v;
	for (int i = 2; ; i++)
	{
		v *= p;
//		printf("%d ", v);
		if (umin(ans, abs(v - x)))
			y = v;
		if (abs(v - x) < abs(v * p - x))
			break;
	}
//	puts("");
	return y;
}

vector <int> v;
int mx = 65;
int n, a[110], k;
int dp[110][(1 << 18) + 3];
int pr[110][(1 << 18) + 3];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 2; i <= mx; i++)
		if (isPrime(i))
			v.pb(i);
//	printf("%d:", (int)v.size());
//	for (int x : v)
//		printf("%d ", x);
//	puts("");
//	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	k = (int)v.size();
	for (int i = 0; i <= n; i++)
		for (int mask = 0; mask < (1 << k); mask++)
			dp[i][mask] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int x = mn(v[j], a[i]);
			int diff = abs(a[i] - x);
			for (int mask = 0; mask < (1 << k); mask++)
			{
				if (in(mask, j))
					continue;
				int & ans = dp[i][mask | (1 << j)];
				if (umin(ans, dp[i - 1][mask] + diff))
					pr[i][mask | (1 << j)] = j;
			}
		}
		for (int mask = 0; mask < (1 << k); mask++)
			if (umin(dp[i][mask], dp[i - 1][mask] + abs(a[i] - 1)))
				pr[i][mask] = -1;
//		for (int mask = 0; mask < (1 << k); mask++)
//			if (dp[i][mask] < inf)
//				printf("dp[%d][%d]=%d\n", i, mask, dp[i][mask]);
	}
	int ans = inf;
	int msk = 0;
	for (int mask = 0; mask < (1 << k); mask++)
		if (umin(ans, dp[n][mask]))
			msk = mask;
//	printf("%d %d\n", ans, msk);
	vector <int> res;
	for (int i = n; i > 0; i--)
	{
		int j = pr[i][msk];
//		printf("[%d %d] ", j, msk);
		if (j == -1)
		{
			res.pb(1);
			continue;
		}
		int x = mn(v[j], a[i]);
//		printf("[%d] ", x);
		res.pb(x);
		msk ^= (1 << j);
	}
//	puts("");
	reverse(all(res));
	for (int x : res)
		printf("%d ", x);
}
