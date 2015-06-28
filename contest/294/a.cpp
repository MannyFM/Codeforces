
#include <bits/stdc++.h>

using namespace std;

int n, a[200];
int m, x, y;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		int l = y - 1;
		int r = a[x] - y;
		a[x] = 0;
		if (x > 1)
			a[x - 1] += l;
		if (x + 1 <= n)
			a[x + 1] += r;
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", a[i]);
}
