
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int n, m;
int a[maxn], b[maxn];
mii x, y;

mii f(int x)
{
	mii ans;
	for (int i = 2; i * i <= x; i++)
	{
		while (x % i == 0)
			ans[i]++, x /= i;
	}
	if (x > 1)
		ans[x]++;
	return ans;
}

ll bp(ll a, ll n)
{
	ll ans = 1ll;
	while (n)
	{
		if (n & 1)
			ans *= a;
		a *= a;
		n >>= 1;
	}
	return ans;
}

int A[maxn], B[maxn];
int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	for (int i = 1; i <= n; i++)
	{
		mii cur = f(a[i]);
		for (pii j : cur)
			x[j.F] += j.S;
	}

	for (int i = 1; i <= m; i++)
	{
		mii cur = f(b[i]);
		for (pii j : cur)
			y[j.F] += j.S;
	}
	mii x1 = x, y1 = y;
	for (int i = 1; i <= n; i++)
	{
		mii cur = f(a[i]);
		ll now = 1ll;
		int val = a[i];
		for (int j = 2; j * j <= val; j++)
		{
			int cnt = 0;
			while (val % j == 0)
				val /= j, cnt++;
			if (!cnt)
				continue;
			int need = min(x[j], y[j]);
			umin(need, cnt);
			x[j] -= need, y[j] -= need;
			now *= bp(j, cnt - need);
		}
		if (val > 1)
		{
			int need = min(x[val], y[val]);
			umin(need, 1);
			x[val] -= need, y[val] -= need;
			now *= bp(val, 1 - need);
		}
		A[i] = now;
	}
	for (int i = 1; i <= m; i++)
	{
		mii cur = f(b[i]);
		ll now = 1ll;
		int val = b[i];
		for (int j = 2; j * j <= val; j++)
		{
			int cnt = 0;
			while (val % j == 0)
				val /= j, cnt++;
			if (!cnt)
				continue;
			int need = min(x1[j], y1[j]);
			umin(need, cnt);
			x1[j] -= need, y1[j] -= need;
			now *= bp(j, cnt - need);
		}
		if (val > 1)
		{
			int need = min(x1[val], y1[val]);
			umin(need, 1);
			x1[val] -= need, y1[val] -= need;
			now *= bp(val, 1 - need);
		}
		B[i] = now;
	}
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
		printf("%d ", A[i]);
	puts("");
	for (int i = 1; i <= m; i++)
		printf("%d ", B[i]);
}

