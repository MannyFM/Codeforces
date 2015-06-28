
#include <bits/stdc++.h>

using namespace std;

#define YES {puts("2"); return 0;}

int n, m, a[60][60];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		if (a[i][m] || a[i][1])
			YES;
	for (int i = 1; i <= m; i++)
		if (a[1][i] || a[n][i])
			YES;
	puts("4");

}