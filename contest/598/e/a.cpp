
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[32][32][55];

ll rec(int n, int m, int k)
{
	//printf("%d %d %d\n", n, m, k);
	if (!k)
		return 0;
	if (n > m)
		return rec(m, n, k);
	if (n == 1)
		return m != k;
	if (n * m == k)
		return 0;
	ll & ans = dp[n][m][k];
	if (ans != -1)
		return ans;
	ans = int(1e9);
	for (int i = 1; i <= n; i++)
	{
		for (int x = 1; x <= min(i * m, k); x++)
		{
			ll cost = rec(i, m, x) + rec(n - i, m, k - x) + m * m;
			ans = min(ans, cost);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int x = 1; x <= min(i * n, k); x++)
		{
			ll cost = rec(n, i, x) + rec(n, m - i, k - x) + n * n;
			ans = min(ans, cost);
		}
	}
	return ans;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		printf("%I64d\n", rec(n, m, k));
	}	
}