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

int r1, r2;
int c1, c2;
int d1, d2;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &r1, &r2);
	scanf("%d%d", &c1, &c2);
	scanf("%d%d", &d1, &d2);
	for (int a = 1; a < 10; a++)
	{
		for (int b = 1; b < 10; b++)
		{
			if (a == b)
				continue;
			for (int c = 1; c < 10; c++)
			{
				if (c == a || c == b)
					continue;
				for (int d = 1; d < 10; d++)
				{
					if (d == a || d == b || d == c)
						continue;
					if (a + b == r1 && c + d == r2 &&
						a + c == c1 && b + d == c2 &&
						a + d == d1 && b + c == d2)
					{
						printf("%d %d\n%d %d", a, b, c ,d);
						return 0;
					}
				}
			}
		}
	}
	puts("-1");
}
