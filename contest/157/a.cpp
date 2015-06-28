
#include <bits/stdc++.h>

using namespace std;

int n, a[32][32];
int hor[32], ver[32];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			ver[i] += a[i][j];
			hor[j] += a[i][j];
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			ans += (ver[i] < hor[j]);
		}
	printf("%d", ans);
}