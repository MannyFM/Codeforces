
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, x, a[maxn];
long long ans;

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort (a, a + n);
	for (int i = 0; i < n; i++)
	{
		ans += (x + 0ll) * a[i];
		x = max(1, x - 1);
	}
	printf("%I64d", ans);
}