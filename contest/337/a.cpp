
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)

int n, m, a[60], ans = inf;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &a[i]);
	sort (a, a + m);
	for (int i = 0; i + n  - 1 < m; i++)
		ans = min(ans, a[i + n - 1] - a[i]);
	printf("%d", ans);
}