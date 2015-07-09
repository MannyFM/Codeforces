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

int n, w;
int a[maxn * 2];
double l, r;

inline double f(double x)
{
	return 3.0 * x * n;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &w);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", a + i);
	sort(a, a + n + n);
	l = .0, r = min(a[0] + .0, a[n ] / 2.0);
	for (int step = 0; step <= 200; step++)
	{
		double m = (l + r) / 2.0;
		if (f(m) <= w + .0)
			l = m;
		else
			r = m;
	}
	printf("%.9f", f(r) <= w + .0 ? f(r) : f(l));
}
