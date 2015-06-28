
#include <bits/stdc++.h>

using namespace std;

const int maxn = 100 * 1000 + 12;

int n, a[maxn];
int ans;

int f(int l)
{
	int r = min(l + 2, n);
	while (r <= n && a[r] == a[r - 1] + a[r - 2])
		r++;
	r--;
	ans = max(ans, r - l + 1);
	return r;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	ans = min(n, 2);
	for (int i = 1; i <= n; i++)
		i = max(f(i) - 2, i);
	printf("%d", ans);
}