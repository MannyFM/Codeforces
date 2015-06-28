
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int F(int r, int g, int b)
{
	int R, G, B, mix;
	mix = min(r, min(g, b));
	r -= mix;
	g -= mix;
	b -= mix;
	R = r / 3;
	G = g / 3;
	B = b / 3;
	return mix + R + G + B;
}

int S(int r, int g, int b)
{
	int R, G, B, mix;
	R = r / 3;
	G = g / 3;
	B = b / 3;
	mix = min(r % 3, min(g % 3, b % 3));
	return mix + R + G + B;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	printf("%d ", max(F(r, g, b), S(r, g, b)));
}
