
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
//#define fn "a"

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

typedef vector <ll> vi;

ll bp(ll a, ll b, ll mod)
{
	ll ans = 1ll;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int n, x, k;
ll b;
vi cnt;

vi mult(const vi & a, const vi & b, ll step)
{
	step = bp(10, step, x);
	vi c(x);
	for (int i = 0; i < x; i++)
	{
		int I = (i * step) % x;
		for (int j = 0; j < x; j++)
		{
			c[(I + j) % x] += a[i] * 1ll * b[j];
			c[(I + j) % x] %= inf;
		}
	}
//	printf(I64 ":\n", step);
//	for (int i = 0; i < x; i++)
//		printf("%2d ", a[i]);
//	puts("\n*");
//	for (int i = 0; i < x; i++)
//		printf("%2d ", b[i]);
//	puts("\n=");
//	for (int i = 0; i < x; i++)
//		printf("%2lld ", c[i]);
//	puts("\n");
	return c;
}

vi rec(ll b)
{
	if (b == 1)
		return cnt;
	if (!b)
		return vi(x, 0);
	if (b & 1)
	{
		vi l = rec(b - 1);
		vi r = cnt;
		return mult(l, r, b - 1);
	}
	vi l = rec(b / 2);
	vi r = l;
	return mult(l, r, b / 2);
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d" I64 "%d%d", &n, &b, &k, &x);
	cnt.resize(x);
	for (int i = 1; i <= n; i++)
	{
		int y;
		scanf("%d", &y);
		cnt[y % x]++;
	}
	vi ans = rec(b);
//	for (int i = 0; i < x; i++)
//		printf("%2d ", i);
//	puts("");
//	for (int i = 0; i < x; i++)
//		printf("%2d ", ans[i]);
//	puts("");
	printf(I64, ans[k]);
}

