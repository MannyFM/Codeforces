
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
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
#define fn "bridge"
#define NO {puts("-1"); exit(0);}

struct pt
{
	ll x, y;
	ld len()
	{
		return ld(sqrt(ld(x) * x + ld(y) * y));
	}
};

pt operator + (pt a, pt b)
{
	return {a.x + b.x, a.y + b.y};
}

pt operator - (pt a, pt b)
{
	return {a.x - b.x, a.y - b.y};
}

ll operator * (pt a, pt b)
{
	return a.x * b.y - a.y * a.x;
}

ll operator % (pt a, pt b)
{
	return a.x * b.x + a.y * b.y;
}

ll triangle(pt & a, pt & b, pt & c)
{
	return (b - a) * (c - b);
}

bool clockwise(pt & a, pt & b, pt & c)
{
	return triangle(a, b, c) < 0;
}

struct line
{
	ll a, b, c;
	line(int x1, int y1, int x2, int y2)
	{
		a = y2 - y1;
		b = x1 - x2;
		c = x2 * y1 - x1 * y2;
	}
	line (pt a, pt b)
	{
		(*this) = line(a.x, a.y, b.x, b.y);
	}
};

ld dist(pt A, line a)
{
	ld res = (ld)abs(a.a * A.x + a.b * A.y + a.c);
	return res / (ld)sqrt(a.a * a.a + a.b * a.b);
}

ld dist(pt A, pt a, pt b)
{
	ld alpha = ;
	return dist(A, line(a, b));
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
}
