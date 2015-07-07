
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
#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int a, b;
int s[maxb];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &a, &b);
	if (!(a - 1 <= b && b <= 2 * (a + 1)))
	{
		puts("-1");
		return 0;
	}
	if (a - 1 == b)
	{
		while (a > 0 && b > 0)
		{
			printf("01");
			a--, b--;
		}
		printf("0");
		return 0;
	}
	if (a == b)
	{
		while (a > 0 && b > 0)
		{
			printf("01");
			a--, b--;
		}
		return 0;
	}
	int delta = (b - a - 1);
	while (a > 0 && b > 0)
	{
		if (delta)
			printf("1"), delta--, b--;
		printf("10"), a--, b--;
	}
	if (a)
		printf("0");
	if (b)
	{
		printf("1");
		if (delta)
			printf("1");
	}
}
