
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define dinf 1e9
#define eps 1e-6
#define linf ll(1e18 + 12)
#define mp make_pair
#define pb push_back
#define fn "cubroot"
#define LOCAL

int a, b, c, d;

double f(double x)
{
	return x * x * x * a + x * x * b + x * c + d;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d%d", &a, &b, &c, &d);
	double l = -dinf, r = dinf, mid;
	while (r - l > eps)
	{
		mid = (l + r) / 2;
		/*
		printf("%0.09f %0.09f %0.09f\n", l, mid, r);
		printf("%0.09f %0.09f %0.09f\n", f(l), f(mid), f(r));
		*/
		if (f(mid) < eps)
			l = mid;
		else
			r = mid;
	}
	//printf("%d %d %d\n", l, mid, r);
	printf("%0.09f", l);
}