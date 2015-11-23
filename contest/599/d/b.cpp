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
//#define fn ""

ll a, b, x;

ll f(ll a, ll b)
{
	ll x = 0;
	if (a > b)
		swap(a, b);
	for (ll i = 1; i <= a; i++)
	{
		x += (a - i + 1) * (b - i + 1);
		//printf("%d ", (a - i + 1) * (b - i + 1));
	}
	printf(" " I64 ":", (3ll * b - a + 1) * a * (a + 1) / 6);
	return x;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf(I64 I64, &a, &b);
	printf(I64, f(a, b));
}
