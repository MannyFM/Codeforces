
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
int const maxlen = int(2e5 + 12);
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

ll const mod2 = inf * 1ll * inf, md2 = (inf - 1) * 1ll * (inf - 1);

ll bp(ll a, ll b)
{
	ll ans = 1ll;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % inf;
		a = (a * a) % inf;
		b >>= 1;
	}
	return ans;
}

int n, a[maxlen];
ll l[maxlen], r[maxlen];
int cnt[maxlen];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		cnt[a[i]]++;
	}
	l[0] = 1;
	for (int i = 1; i < maxn; i++)
		l[i] = (l[i - 1] * (1 + cnt[i]) + (inf - 1ll) * (inf - 1ll)) % (inf - 1);
	r[maxn - 1] = 1;
	for (int i = maxn - 2; i > 0; i--)
		r[i] = (r[i + 1] * (1 + cnt[i]) + (inf - 1ll) * (inf - 1ll)) % (inf - 1);
	ll ans = 1ll;
	for (int i = 1; i < maxn; i++)
	{
		if (!cnt[i])
			continue;
		ll cur = (l[i - 1] * r[i + 1] + md2) % (inf - 1);
		for (int j = 1; j <= cnt[i]; j++)
		{
			ans = (ans * bp(bp(i, j), cur) + mod2) % inf;
			//printf(I64 "**" I64 "\n", bp(i, j), cur);
		}
	}
	printf(I64, ans);
}

