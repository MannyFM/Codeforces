
#include <bits/stdc++.h>

using namespace std;

int n, a[7], now, j;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 7; i++)
		scanf("%d", &a[i]);
	j = 0, now = 0;
	while (n > 0)
	{
		n -= a[j];
		j = (j + 1) % 7;
	}
	printf("%d", j ? j : 7);
}