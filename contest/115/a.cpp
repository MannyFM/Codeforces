
#include <bits/stdc++.h>

using namespace std;

int n, p[2020];
int ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", p + i);
	}
	for (int i = 1; i <= n; i++)
	{
		int buf = 1, v = i;
		while (p[v] != -1)
		{
			buf++;
			v = p[v];
		}
		ans = max(ans, buf);
	}
	printf("%d", ans);
}