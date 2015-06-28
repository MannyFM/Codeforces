
#include <bits/stdc++.h>

using namespace std;

#define c(x) (0 <= x && x < n)
int n;
int a[4][4];
int b[4][4];

int main()
{
	n = 3;
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &b[i][0], &b[i][1], &b[i][2]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (b[i][j] % 2 == 0)
				continue;
			if (c(i + 1))
				a[i + 1][j] ^= 1;
			if (c(i - 1))
				a[i - 1][j] ^= 1;
			if (c(j + 1))
				a[i][j + 1] ^= 1;
			if (c(j - 1))
				a[i][j - 1] ^= 1;
			a[i][j] ^= 1;
		}
	for (int i = 0; i < n; i++)
		printf("%d%d%d\n", !a[i][0], !a[i][1], !a[i][2]);
}