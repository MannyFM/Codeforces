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

int n;

map <int, bool> ch;

bool prime(int x)
{
	if (x < 2)
		return false;
	if (ch.count(x))
		return ch[x];
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return ch[x] = false;
	return ch[x] = true;
}

bool two(int x, int & a, int & b)
{
	for (int i = 2; i <= x; i++)
	{
		if (prime(i) && prime(x - i))
		{
			a = i, b = x - i;
			return true;
		}
	}
	return false;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	if (prime(n))
	{
		printf("1\n%d", n);
		return 0;
	}
	if (n % 2 == 0 && prime(n / 2))
	{
		printf("2\n%d %d", n / 2, n / 2);
		return 0;
	}
	if (n % 3 == 0 && prime(n / 3))
	{
		printf("3\n%d %d %d", n / 3, n / 3, n / 3);
		return 0;
	}
	for (int a = 1; a * a <= n; a++)
	{
		bool x = prime(a), y = prime(n - a), z = prime(n - a - 2);
		if (x && y)
		{
			printf("2\n%d %d", a, n - a);
			return 0;
		}
		if (x && z)
		{
			printf("3\n%d %d 2", a, n - a - 2);
			return 0;
		}
	}
}
