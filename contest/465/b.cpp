
#include <bits/stdc++.h>

using namespace std;

int n, a[2000];
int ans, last;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		if (a[i])
		{
			ans++;
		}
		else
		{
			if (i > 0 && a[i - 1])
				ans++;
		}
	}
	if (ans > 0 && !a[n - 1])
		ans--;
	printf("%d", ans);
}
