
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
#define x1 MyLittleX1
#define x2 MyLittleX2
#define y1 MyLittleY1
#define y2 MyLittleY2
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

int x1, x2, y1, y2;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	ll a = ((x2 - x1 + 1) / 2ll) * ((y2 - y1 + 1) / 2);
	ll b = ((x2 - x1 + 2) / 2ll) * ((y2 - y1 + 2) / 2);
//	printf("%d %d\n%d %d\n", (x2 - x1 + 1) / 2, (y2 - y1 + 1) / 2, (x2 - x1 + 2) / 2, (y2 - y1 + 1) / 2);
//	printf(I64 " " I64 "\n", a, b);
	printf(I64, a + b);
}

