
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
#define fn "vikings"

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	double r, d;
	scanf("%lf%lf", &r, &d);
	if (r * 2 < d)
	{
		printf("%.9f %.9f\n", -r, .0);
		printf("%.9f %.9f\n", r, .0);
		return 0;
	}
	double x = d * d / (2 * r) - r;
	double y = sqrt(r * r - x * x);
	printf("%.9f %.9f\n", -r, .0);
	printf("%.9f %.9f\n", x, y);
}
