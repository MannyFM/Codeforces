
#include <bits/stdc++.h>

using namespace std;

#define maxm (int)(1e3 + 12)

int n, k, m;
int a[maxm], ans;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
	{
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			int b1 = (a[i] & (1 << j) ) > 0;
			int b2 = (a[m] & (1 << j) ) > 0;
			cnt += (b1 != b2);
		}
		if (cnt <= k)
			ans++;
	}
	printf("%d", ans);
}