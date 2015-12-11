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
//#define fn "sideslip"

int v, x, y, a, b;

double kv(double a, double b, double c)
{
	double d = b * b - 4 * a * c;
	if (d < .0 || a == .0)
		return -1.0;
	d = sqrt(d);
	double x1 = (-b + d) / 2 * a;
	double x2 = (-b - d) / 2 * a;
	if (x1 < .0 && x2 < .0)
		return -1.0;
	if (x1 < 0 || x2 < .0)
		return x1 < 0 ? x2 : x1;
	return min(x1, x2);
}

double t1, t2, t3, t4;

double f1()
{
	double t1 = (x + .0) / v - (v + .0) / (2 * b);
	double t2 = kv(b / 2.0, -v, -v * t1 + x);
	if (t1 < .0 || t2 < .0)
		return inf;
	t2 = sqrt(t2);
	return t1 + t2;
}

double f2()
{
	double V = min(sqrt(2.0 * x * b), v + .0);
	return 2.0 * x / V;
}

double g1()
{
	double t4 = (y + .0) / v - (v + .0) / (2 * a);
	double t3 = (y - v * t4 + .0) * 2 / a;
	if (t3 < .0 || t4 < .0)
		return inf;
	return t3 + t4;
	
}

double g2()
{
	double V = min(sqrt(2.0 * y * a), v + .0);
	return 2.0 * y / V;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d%d%d", &v, &x, &y, &a, &b);
	double t1 = f1();
	double t2 = f2();
	double t3 = g1();
	double t4 = g2();
	printf("%f %f\n", t3, t4);
	printf("%.9f\n", min(t1, t2) + min(t3, t4));
}