
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, a[maxn];
int ans = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), a[i]++;
	for (int i = 1; i <= n; i++)
		ans += (a[i] == i);
	int now = ans;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != i)
		{
			if (a[a[i]] == i)
			{
				printf("%d", ans + 2);
				return 0;
			}
			now = ans + 1;
		}
	}
	printf("%d", now);
}
