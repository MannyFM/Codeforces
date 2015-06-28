
#include <bits/stdc++.h>

using namespace std;

int n, h[100 * 1000 + 12];
long long ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", h + i);
	ans = h[1] + 1;
	for (int i = 2; i <= n; i++)
		ans += abs(h[i - 1] - h[i]) + 2;
	printf("%I64d", ans);
}