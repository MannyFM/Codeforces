
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
int const mx = 17;
int fact[70];
int dp[110][(1 << mx) + 3];
int p[110][(1 << mx) + 3];
vector <int> pr;
int n, a[maxn], k;
int b[maxn];

bool isPrime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

void out(int mask)
{
	for (int i = 0; i < k; i++)
		if (in(mask, i))
			printf("%d ", pr[i]);
	puts("");
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	for (int i = 2; i <= 60; i++)
		if (isPrime(i))
			pr.pb(i);
	k = (int)pr.size();
	for (int i = 2; i <= 60; i++)
	{
		for (int j = 0; j < int(pr.size()) && pr[j] <= i; j++)
			if (i % pr[j] == 0)
				fact[i] |= (1 << j);
//		printf("%d %d %d\n", i, fact[i], (~fact[i]) & ((1 << (k + 0)) - 1));
//		out(fact[i]);
//		out((~fact[i]) & ((1 << (k + 0)) - 1));
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
		for (int mask = 0; mask < (1 << k); mask++)
			dp[i][mask] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	 	for (int x = 1; x < 60; x++)
		{
			int mask = (~fact[x]) & ((1 << (k + 0)) - 1);
			for (int s = mask; ; s = (s - 1) & mask)
			{
				if (umin(dp[i][s | fact[x]], dp[i - 1][s] + abs(a[i] - x)))
					p[i][s | fact[x]] = x;
				if (!s)
					break;
			}
		}
	int ans = inf, msk = 0;
	for (int mask = 0; mask < (1 << k); mask++)
		if (umin(ans, dp[n][mask]))
			msk = mask;
	for (int i = n; i > 0; i--)
	{
		b[i] = p[i][msk];
		msk ^= fact[b[i]];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);
}

