
#include <bits/stdc++.h>

using namespace std;

int n, m, x;
int ans, maxi = -(int)(1e9 + 8);

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (((x + m - 1) / m) >= maxi)
		{
			ans = i + 1;
			maxi = ((x + m - 1) / m);
		}
	}
	printf("%d", ans);
}