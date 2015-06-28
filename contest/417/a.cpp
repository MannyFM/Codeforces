
#include <bits/stdc++.h>

using namespace std;

int n, m, c, d, k;
int gen, ex;

int main()
{
	scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
	int p = n * m - k;
	if (p <= 0)
	{
		puts("0");
		return 0;
	}
	int ans = 10000;
	for (int i = 0; i <= p; i++)
	{
		ex = i;
		gen = (p - ex + n - 1) / n;
		if (gen * c + ex * d < ans)
		{
			//printf("%d %d\n", gen, ex);
			ans = gen * c  + ex * d;
		}
		//ans = min(ans, i * d + need * c);
	}
	printf("%d", ans);
}