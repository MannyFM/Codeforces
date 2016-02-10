
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
ld const eps = 1e-7;
ld const pi = 3.14;
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
#define _USE_MATH_DEFINES
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

struct pt
{
	ld x, y;
	pt () {x = y = .0;}
	pt (int)
	{
		double a, b;
		scanf("%lf%lf", &a, &b);
		x = ld(a);
		y = ld(b);
	}
	pt (ld x, ld y) : x(x), y(y) {}
	pt operator + (const pt & p) const
	{
		return pt(x + p.x, y + p.y);
	}
	pt operator - (const pt & p) const
	{
		return pt(x - p.x, y - p.y);
	}
	pt operator * (ld k) const
	{
		return pt(x * k, y * k);
	}
	pt operator *= (ld k)
	{
		x *= k, y *= k;
		return *this;
	}
};

ld dist2(const pt & a, const pt & b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ld dist(const pt & a, const pt & b)
{
	return sqrt(dist2(a, b));
}

ld dist(const pt & p, const pt & a, const pt & b)
{
	ld l = 0.0, r = 1.0;
	int step = 100;
	while (step--)
	{
		ld m1 = l + (r - l) / 3,
		   m2 = r - (r - l) / 3;
		pt t1 = a + (b - a) * m1,
		   t2 = a + (b - a) * m2;
		if (dist2(p, t1) > dist2(p, t2))
			l = m1;
		else
			r = m2;
	}
	return dist(p, a + (b - a) * l);
}

inline ld dist(const pt & p, ld a, ld b, ld c)
{
	return fabs(a * p.x + b * p.y + c) / sqrt(p.x * p.x + p.y * p.y);
}

int n;
pt p, a[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	p = pt(1);
	for (int i = 1; i <= n; i++)
		a[i] = pt(i);
	a[0] = a[n];
	ld R = .0, r = inf;
	for (int i = 1; i <= n; i++)
	{
		ld d = dist(p, a[i - 1], a[i]);
		umax(R, dist(p, a[i]));
		umin(r, d);
	}
	//printf("%.12f %.12f\n", double(r), double(R));
	printf("%.12f", double(M_PI * (R * R - r * r)));
}

