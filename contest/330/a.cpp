
#include <bits/stdc++.h>

using namespace std;

char a[20][20];
int ver[20], hor[20], n, m, ans;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'S')
				ver[j] = 1, hor[i] = 1;
		}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((ver[j] && hor[i]))
				ans++;
		}
	}
	ans = n * m - ans;
	printf("%d", ans);
}