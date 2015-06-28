
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)

int n, m, a[2000], ans = inf;

int main()
{
	freopen("stupid_rmq.in", "r", stdin);
	freopen("stupid_rmq.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	int l, r;
	while (m--)
	{
		scanf("%d%d", &l, &r);
		ans = inf;
		l--, r--;
		for (int i = l; i <= r; i++)
			ans = min(ans, a[i]);
		printf("%d\n", ans);
	}
}