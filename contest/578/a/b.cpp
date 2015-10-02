
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

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	ll a, b, k;
	scanf(I64, &b);
	for (a = 3 * b; a <= 300 * b; a++)
	{
		printf(I64 " " I64 ":\n", a, b);
		if (a == b)
		{
			printf("%.11f\n", a + .0);
			continue;
		}
		if (a < b)
		{
			puts("-1");
			continue;
		}
		k = (a - b) / (2 * b);
		printf(I64 "\n", k);
		long double x = (long double)(a - b) / (2 * k);
		long double y = (long double)(a + b) / (2 * k + 2);
		printf("%.11f %.11f\n", (double)x, double(y));
		//printf("%.11f\n", (double)min(x, y));
		if (min(x, y) != y)
		{
			puts("Succes");
			printf(I64 " " I64 "\n", a, b);
			break;
		}
	}
}
