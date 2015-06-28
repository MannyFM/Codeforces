
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(2e5)

long long sum, ans;
int n, k, a[maxn], j;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= k; i++)
		sum += a[i];
	ans = sum;
	j = 1;
	for (int i = k + 1; i <= n; i++)
	{
		sum -= a[i - k];
		sum += a[i];
		if (sum < ans)
		{
			ans = sum;
			j = i - k + 1;
		}
	}
	printf("%d", j);
}