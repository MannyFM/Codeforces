
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
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int a, b, n;
int x = -1;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &a, &b, &n);

	for (int i = 0; i < 10; i++)
	{
		if ((a * 10 + i) % b == 0)
		{
			x = i;
			break;
		}
	}
	if (x == -1)
	{
		puts("-1");
		return 0;
	}
	printf("%d%d", a, x);
	for (int i = 1; i < n; i++)
		putchar('0');
}

