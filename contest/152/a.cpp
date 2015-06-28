
#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
char a[150][150], mx[150];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			mx[j] = max(mx[j], a[i][j]);
		}
	for (int i = 0; i < n; i++)
	{
		bool fl = 0;
		for (int j = 0; j < m; j++)
			if (a[i][j] == mx[j])
			{
				fl = 1;
				break;
			}
		ans += fl;
	}
	printf("%d", ans);
}