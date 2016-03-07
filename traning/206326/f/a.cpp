
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

ll n, k;

ll f(ll x)
{
//	printf("f(" I64 ")=" I64 "\n", x, (x + k) * (k - x + 1) / 2);
	return (x + k) * (k - x + 1) / 2;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64 I64, &n, &k);
	n--, k--;
	if (k * (k + 1) / 2 < n)
	{
		puts("-1");
		return 0;
	}
	ll l = 0, r = k + 1;
	while (r - l > 1)
	{
//		printf("[%lld %lld]\n", l, r);
		ll m = l + (r - l) / 2;
		if (f(m) > n)
			l = m;
		else
			r = m;
	}
//	printf(I64 " " I64 "\n", l, r);
//	printf(I64 " " I64 "\n", f(l), f(r));
	ll ans = k - r + 1;
	if (f(r) != n)
		ans++;
	printf(I64, ans);
}

