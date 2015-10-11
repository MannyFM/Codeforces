
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

map <int, bool> help;

bool prime(int x)
{
	if (help.count(x))
		return help[x];
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return help[x] = false;
	return help[x] = true;
}

void calc(int n, int & a, int & b)
{
	a = b = -1;
	for (a = 2; a <= n; a++)
		if (prime(a) && prime(n - a))
		{
			b = n - a;
			return;
		}
}

int n;

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
	int a, b;
	if (n & 1)
	{
		calc(n - 3, a, b);
		printf("3\n3 %d %d", a, b);
	}
	else
	{
		calc(n, a, b);
		printf("2\n%d %d", a, b);
	}
}
