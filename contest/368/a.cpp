
#include <bits/stdc++.h>

using namespace std;

int n, d, m, a[200];

int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	scanf("%d", &m);
	sort(a, a + n);
	long long ans = 0;
	for(int i = 0; i < min(n,m); i++)
		ans += a[i];
	if (m > n)
		ans -= (m - n) * d;
	printf("%I64d", ans);
}