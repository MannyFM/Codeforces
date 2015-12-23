
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

int r;

inline bool out(int x, int y)
{
	return x * x + y * y > r * r;
}

inline bool gran(int x, int y)
{
	return x * x + y * y == r * r;
}

inline bool axis(int x, int y)
{
	return !x || !y;
}

int pts(int x, int y)
{
	if (!x && !y)
		return -240;
	if (out(x, y))
		return 0;
	bool g = gran(x, y), a = axis(x, y);
	if (g && a)
		return -300;
	if (g)
		return -100;
	if (a)
		return -200;
	if (x > 0 && y > 0)
		return 50;
	if (x > 0 && y < 0)
		return 400;
	if (x < 0 && y > 0)
		return 100;
	if (x < 0 && y < 0)
		return 10;
	return 0;
}

int n;
int x[maxn], y[maxn];
int p[2];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	n *= 2;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", x + i, y + i);
	scanf("%d", &r);
	for (int i = 1; i <= n; i++)
	{
		p[2 - (i & 1)] += pts(x[i], y[i]);
		//printf("%d ", pts(x[i], y[i]));
	}
	if (p[1] > p[2])
		printf("Gavaya %d\n", p[1]);
	if (p[1] < p[2])
		printf("Margarita %d\n", p[2]);
	if (p[1] == p[2])
		printf("Despair %d\n", p[1]);
}

