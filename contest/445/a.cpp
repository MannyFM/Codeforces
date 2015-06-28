
#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[200][200];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '-')
			{
				printf("-");
				continue;
			}
			printf("%c", (i + j) & 1 ? 'W' : 'B');
		}
		puts("");
	}
}