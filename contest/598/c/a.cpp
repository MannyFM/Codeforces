
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int maxn = int(1e5) + 5;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286, eps = 1e-20;

struct pt
{
	int x, y, id;
	ld alpha;
	pt() {};
	pt(int id) : id(id)
	{
		scanf("%d%d", &x, &y);
		alpha = ld(atan2(ld(y), ld(x)));
		if (alpha < eps)
			alpha += pi * 2.0;
		if (alpha > pi * 2.0)
			alpha -= pi * 2.0;
	}
};

bool cmp(pt a, pt b)
{
	return b.alpha - a.alpha > eps;
}

ld f(pt a, pt b)
{
	return fabs(b.alpha - a.alpha);
}

int n;
pt a[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i] = pt(i);
	sort(a + 1, a + 1 + n, cmp);
	a[0] = a[n];
	a[0].alpha -= 2.0 * pi;
	/*
	for (int i = 1; i <= n; i++)
		printf("(%d: %d %d %f %f) ", a[i].id, a[i].x, a[i].y, float(a[i].alpha), float(f(a[i - 1], a[i])));
	puts("");
	*/
	ld cur = 1e18;
	int pos = -1;
	for (int i = 1; i <= n; i++)
		if (cur - f(a[i - 1], a[i]) > eps)
		{
			cur = f(a[i - 1], a[i]);
			pos = i;
		}
	//printf("%d\n", pos);
	printf("%d %d\n", a[pos - 1].id, a[pos].id);
}
