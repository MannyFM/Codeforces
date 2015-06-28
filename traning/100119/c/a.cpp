
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-8
#define sqr(x) ((x) * (x))
#define mp make_pair
#define pb push_back
#define fn "forest"
#define LOCAL

int v1, v2;
double a;

double d(double xa, double ya, double xb, double yb)
{
	double ans = sqr(xa - xb) + sqr(ya - yb);
	ans = sqrt(ans);
	return ans;
}

double f(double x)
{
	double s1 = d(0.0, 1.0, x, a);
	double s2 = d(x, a, 1.0, 0.0);
	return (s1 * v2 + s2 * v1) / (v1 * v2);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%lf", &v1, &v2, &a);
	double l = 0.0, r = 1.0;
	while (r - l > eps)
	{
		//cout << l << " " << r << '\n';
		double m1 = l + (r - l) / 3;
		double m2 = r - (r - l) / 3;
		if (f(m1) > f(m2))
			l = m1;
		else
			r = m2;
	}
	/*
	if (f(r) < f(l))
		swap(l, r);
	*/
	printf("%.08f %.08f\n", l, r);
	printf("%.09f", l);
}