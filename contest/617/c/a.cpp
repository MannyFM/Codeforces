
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
#define x1 X1
#define y1 Y1
#define x2 X2
#define y2 Y2
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

int n, x1, y1, x2, y2;
int x[maxn], y[maxn];

inline ll dist(ll x, ll y, ll x0, ll y0)
{
	return (x - x0) * (x - x0) + (y - y0) * (y - y0);
}

ll calc(ll r1)
{
	ll r2 = 0;
	for (int i = 1; i <= n; i++)
		if (dist(x[i], y[i], x1, y1) > r1)
			umax(r2, dist(x[i], y[i], x2, y2));
	return r1 + r2;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", x + i, y + i);
	ll ans = calc(0);
	for (int i = 1; i <= n; i++)
		umin(ans, calc(dist(x[i], y[i], x1, y1)));
	printf(I64, ans);
}

