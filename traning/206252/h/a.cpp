
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

ll x;
set <pll> se;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64, &x);
	x *= 6;
	for (ll n = 1; n * n * n <= x; n++)
	{
		if (x % n || x % (n + 1))
			continue;
		ll m = (x / (n + 1)) / n + n - 1;
		if (m <= 0 || m % 3)
			continue;
		m /= 3;
		if (m < n)
			break;
		se.insert(mp(n, m));
		se.insert(mp(m, n));
	}
	printf("%d\n", (int)se.size());
	for (pll x : se)
		printf(I64 " " I64 "\n", x.F, x.S);
}

