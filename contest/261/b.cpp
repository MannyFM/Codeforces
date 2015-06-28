
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(2e5 + 12)

int n, a[maxn];
int f, l, c1, c2;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort (a, a + n);
	f = a[0], l = a[n - 1];
	if (f == l)
	{
		long long ans = n * (n - 1ll) / 2;
		cout << 0 << " " << ans;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == f)
			c1++;
		if (a[i] == l)
			c2++;
	}
	cout << l - f << " " << (c1 + 0ll) * (c2 + 0ll);
}	