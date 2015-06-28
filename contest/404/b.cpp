
#include <bits/stdc++.h>

using namespace std;

double a, d;
int n;

void printf(double s)
{
	if (.0 <= s && s <= a)
		printf("%.06f %.06f\n", s, .0);
	if (a < s && s <= 2 * a)
		printf("%.06f %.06f\n", a, s - a);
	if (2 * a < s && s <= 3 * a)
		printf("%.06f %.06f\n", a - (s - 2 * a), a);
	if (3 * a < s)
		printf("%.06f %.06f\n", .0, a - (s - 3 * a));
}

int main()
{
	scanf("%lf%lf%d", &a, &d, &n);
	while (d >= 4 * a)
		d -= 4 * a;
	double l = .0;
	while (n--)
	{
		l += d;
		while (l >= 4 * a)
			l -= 4 * a;
		printf(l);
	}
}