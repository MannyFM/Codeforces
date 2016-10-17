
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ld, ld> pt;

int const maxn = int(1e5 + 12);
int const maxlen = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
ld const eps = 1e-7;
ld const pi = 3.1415926535897932384626433832795l;

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define x1 MyLittleX1
#define y1 MyLittleY1
#define x2 MyLittleX2
#define y2 MyLittleY2
#define rt(x) {puts(x); exit(0);}
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

pt operator * (const pt & a, const ld & b) {
	return {a.x * b, a.y * b};
}

pt operator + (const pt & a, const pt & b) {
	return {a.x + b.x, a.y + b.y};
}

pt operator - (const pt & a, const pt & b) {
	return a + (b * -1.0);
}

ld dist(const pt & a, const pt & b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

pt P, v;

ld f(double k) {
	return dist(P, v * k);
}

pt get() {
	int x, y;
	scanf("%d%d", &x, &y);
	return {x, y};
}
int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	pt x[2], V[2];
	x[0] = get();
	x[1] = get();
	V[0] = get();
	V[1] = get();
	P = x[0] - x[1];
	v = V[1] - V[0];
	ld  l = 0, r = linf;
	for (int step = 0; step <= 200; step++) {
		ld m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) > f(m2))
			l = m1;
		else
			r = m2;
	}
//	printf("%lf\n", f(l));
	ld ans = min(f(r), f(l));
	l = 0, r = linf;
	for (int step = 0; step <= 200; step++) {
		ld m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		if (f(m1) < f(m2))
			l = m1;
		else
			r = m2;
	}
	umin(ans, f(l));
	umin(ans, f(r));
	printf("%.6lf", (double)ans);
}

