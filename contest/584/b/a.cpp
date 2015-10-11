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

ll bp(ll x, int n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * x) % inf;
		x = (x * x) % inf;
		n >>= 1;
	}
	return res;
}

int n;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	ll all = bp(3ll, n * 3);
	all = (all - bp(7ll, n) + inf) % inf;
	printf(I64, all);
}
