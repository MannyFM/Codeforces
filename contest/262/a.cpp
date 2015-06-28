
#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[200];

int f(int n)
{
	int ans = 0;
	while (n > 0)
	{
		if (n % 10 == 4 || n % 10 == 7)
			ans++;
		n /= 10;
	}
	return ans;
}

int main()
{
	int ans = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		ans += (f(a[i]) <= k);
	}
	printf("%d", ans);
}