
#include <bits/stdc++.h>

using namespace std;

int l, r, n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = (n + 1) / 2; i <= n; i++)
		if (i % m == 0)
		{
			printf("%d", i);
			return 0;
		}
	puts("-1");
}