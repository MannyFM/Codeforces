
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5 + 12)

int n, x, k;
int now[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &x, &k);
		if (x < now[k])
			continue;
		if (x == now[k])
		{
			now[k]++;
			continue;
		}
		puts("NO");
		return 0;
	}
	puts("YES");
}