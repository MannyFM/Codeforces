
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
int const mod = int(1e9 + 7);
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

ll bp(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	return res;
}

int n, a[maxn], k, b[maxn];
ll l, F[maxn], pre, Fr[maxn], N;
vector <ll> dp[maxn], sum;
map <int, ll> mx[maxn];

ll C(ll k)
{
	if (k < 0 || N < 0 || N < k)
		return 0;
	if (k == 0)
		return 1;
	return (Fr[k - 1] * bp(F[k], mod - 2)) % mod;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d" I64 "%d", &n, &l, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		b[i] = a[i];
	}
	F[0] = 1;
	for (int i = 1; i < maxn; i++)
		F[i] = (F[i - 1] * i) % mod;
	N = (l / n) % mod;
	Fr[0] = N;
	sort(a, a + n);
	for (int i = 1; i < maxn; i++)
		Fr[i] = (Fr[i - 1] * (N - i)) % mod;
	/*
	for (int x = 0; x <= k; x++)
		printf(I64 " ", Fr[x]);
	puts("");
	*/
	for (int i = 0; i < n; i++)
		dp[i].assign(k + 1, 0);
	sum.assign(n, 0);
	sum[0] = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i][1] = 1;
		mx[1][a[i]] = 1;
		mx[0][a[i]] = 1;
	}
	for (int x = 2; x <= k; x++)
	{
		pre = 0;
		for (int pos = 0; pos < n; pos++)
		{
			pre += dp[pos][x - 1];
			dp[pos][x] += pre;
			mx[x][a[pos]] = max(mx[x][a[pos]], dp[pos][x]);
		}
	}
	/*
	for (int x = 1; x <= k; x++)
	{
		for (int i = 0; i < n; i++)
			printf(I64 " ", dp[i][x]);
		puts("");
	}
	puts("");
	for (int x = 1; x <= k; x++)
	{
		for (int i = 0; i < n; i++)
			printf(I64 " ", mx[x][a[i]]);
		puts("");
	}
	puts("");
	
	cerr << "!";
	*/
	ll ans = 0;
	for (int x = 1; x <= k; x++)
	{
		for (int pos = 0; pos < n; pos++)
		{
			ans = (ans + (C(x) * mx[x][a[pos]]) % mod) % mod;
			//printf("%d %d " I64 " " I64 "\n", pos, x, C(x), mx[x][a[pos]]);
		}
	}
	//puts("");
	int cnt = l % n;
	//printf(I64 " %d\n", ans, cnt);
	if (cnt)
	{
		for (int x = 1; x <= k; x++)
			for (int pos = 0; pos < cnt; pos++)
			{
				ans = (ans + (C(x - 1) * mx[x][b[pos]]) % mod) % mod;
				//printf("%d %d " I64 " " I64 "\n", pos, x, C(x - 1), mx[x][b[pos]]);
			}
	}
	printf(I64 "\n", ans);
}           	
