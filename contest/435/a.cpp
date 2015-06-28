
#include <bits/stdc++.h>

using namespace std;

int n, m, a[200], ans, os;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	os = m;
	ans = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] <= os)
			os -= a[i];
		else
			ans++, os = m - a[i];
	}
	printf("%d", ans);
}