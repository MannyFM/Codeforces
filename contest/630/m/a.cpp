
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

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

ll x;
ll y = inf;
int ans;

int f(int x)
{
	int y = x;
	if (x > 0)
		y -= 360;
	else
		y += 360;
	if (abs(y) < abs(x))
		return y;
	return x;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf(I64, &x);
	x *= -1;
	x %= 360;
	if (x < 0)
		x += 360;
	y = min(360 - x, x), ans = 0;
//	printf(I64 "\n", x);
	for (int i = 1; i < 4; i++)
	{
		x += 90;
		if (x >= 360)
			x -= 360;
//		printf(I64 " " I64 "\n", x, 360ll - x);
		if (umin(y, min(360ll - x, x)))
			ans = i;
	}
	printf("%d", ans);
}

