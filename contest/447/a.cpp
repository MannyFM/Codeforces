
#include <bits/stdc++.h>

using namespace std;

int n, p;
int h[400], x, ans = -1;

int main()
{
	scanf("%d%d", &p, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		int j = x % p;
		if (h[j] && ans == -1)
		{
			ans = i + 1;
		}
		h[j] = 1;
	}
	printf("%d", ans);
}