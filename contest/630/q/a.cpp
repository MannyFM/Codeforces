
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

typedef long double ld;

ld V(ld S, ld h)
{
	return S * h / 3;
}

ld v(int a, int b)
{
	ld d = sqrt(2) * a;
	ld h = sqrt(b * b - d * d / 4);
	return V(a * a, h);
}

ld const pi = 3.141592653589793238462643383279;
int a, b, c;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d%d", &a, &b, &c);
	ld v1 = sqrt(2) * a * a * a / 12;
	ld v2 = V(b * b, b * cos(pi / 4));

	ld R = c * sqrt(2.0 / (5 - sqrt(5)));
	ld H = sqrt(c * c - R * R);
	ld S = 5.0 / 4 * c * c * (1.0 / tan(pi / 5));
	ld v3 = V(S, H);
	//printf("%.12f %.12f %.12f\n", double(v1), double(v2), double(v3));
	printf("%.12f", double(v1 + v2 + v3));
}

