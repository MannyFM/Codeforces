
#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a[1010][1010], row[1010], col[1010];
int x, y;
char s;

inline void swap(int & a, int & b)
{
	a ^= b ^= a ^= b;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		row[i] = i;
	for (int j = 1; j <= m; j++)
		col[j] = j;
	while (k--)
	{
		scanf("\n%c%d%d", &s, &x, &y);
		if (s == int('c'))
		{
			swap(col[x], col[y]);
		}
		if (s == int('r'))
		{
			swap(row[x], row[y]);
		}
		if (s == int('g'))
		{
			printf("%d\n", a[row[x]][col[y]]);
		}

	}
}