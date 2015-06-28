
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(3e5 + 12)

int n, a[maxn];
long long ans, sum;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), sum += a[i] + 0ll;
	sort(a, a + n);
	ans += sum;
	for (int i = 0; i < n; i++)
		ans += a[i] * (i + 1ll);
	ans -= a[n - 1];
	printf("%I64d", ans);
}

