
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

pii x;

bool check(pii t)
{
	return (t.F / 10 == t.S % 10) && (t.F % 10 == t.S / 10);
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d:%d", &x.F, &x.S);
	do
	{
		x.S++;
		if (x.S >= 60)
			x.F = (x.F + 1) % 24, x.S -= 60;
		//printf("%d:%d\n", x.F, x.S);
	}
	while (!check(x));
	printf("%02d:%02d", x.F, x.S);
}
