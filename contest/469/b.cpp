
#include <bits/stdc++.h>

using namespace std;

int p, q, l, r;
int a[100], b[100];
int c[100], d[100];

bool in(int l1, int r1, int l2, int r2)
{
	int l = max(l1, l2);
	int r = min(r1, r2);
	return l <= r;
}

bool check(int t)
{
	for (int i = 0; i < p; i++)
		for (int j = 0; j < q; j++)
			if (in(a[i], b[i], c[j] + t, d[j] + t))
				return 1;
	return 0;
}

int main()
{
	scanf("%d%d%d%d", &p, &q, &l, &r);
	for (int i = 0; i < p; i++)
		scanf("%d%d", a + i, b + i);
	for (int j = 0; j < q; j++)
		scanf("%d%d", c + j, d + j);
	int ans = 0;
	for (int t = l; t <= r; t++)
		ans += check(t);
	printf("%d", ans);
}