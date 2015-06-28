
#include <bits/stdc++.h>

using namespace std;

int n, m;
int d[3030];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", d + i);
		if (d[i] == 1 || d[i] == n)
		{
			puts("NO");
			return 0;
		}
	}
	sort(d + 1, d + 1 + m);
	int now = 0;
	for (int i = 2; i <= m; i++)
		if (d[i] - d[i - 1] == 1)
		{
			now++;
		}
		else
		{
			if (now >= 2)
			{
				puts("NO");
				return 0;
			}
			now = 0;
		}
	puts(now >= 2 ? "NO" : "YES");

}