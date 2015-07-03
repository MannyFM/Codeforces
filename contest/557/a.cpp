
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

int n, mx[3], mn[3];
int a[3];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
		scanf("%d %d", mn + i, mx + i);
	for (int i = 0; i < 3; i++)
	{
		a[i] = min(n, mn[i]);
		n -= a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		int x = min(mx[i] - a[i], n);
		a[i] += x;
		n -= x;
	}
	printf("%d %d %d", a[0], a[1], a[2]);
}

