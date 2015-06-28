
#include <bits/stdc++.h>

using namespace std;

int n;
char a[200][200];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cnt = 0;
			cnt += (0 < i && a[i - 1][j] == 'o');
			cnt += (i + 1 < n && a[i + 1][j] == 'o');
			cnt += (0 < j && a[i][j - 1] == 'o');
			cnt += (j + 1 < n && a[i][j + 1] == 'o');
			if (cnt & 1)
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
}