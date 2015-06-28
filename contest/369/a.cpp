
#include <bits/stdc++.h>

using namespace std;

int n, m, k, a;
int ans;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			if (m > 0)
				m--;
			else
				ans++;
		}
		else
		{
			if (k > 0)
				k--;
			else
			if (m > 0)
				m--;
			else
				ans++;
		}
	}
	printf("%d", ans);
}
