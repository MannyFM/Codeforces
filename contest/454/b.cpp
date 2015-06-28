
#include <bits/stdc++.h>

using namespace std;

int n, a[(int)(1e5 + 12)], cnt, fl;

int main()
{
	scanf("%d%d", &n, a + 1);
	for (int i = 2; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i - 1] > a[i])
			fl++, cnt = 0;
		cnt++;
	}
	if (!fl)
		puts("0");
	else
		printf("%d", fl == 1 && a[1] >= a[n] ? cnt : -1);
}