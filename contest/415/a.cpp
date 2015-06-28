
#include <bits/stdc++.h>

using namespace std;

int n, m, a[200];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if (a[j] <= i)
			{
				printf("%d ", a[j]);
				break;
			}
	}
}
