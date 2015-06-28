
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(2e3 + 12)

int n, k;
int a[maxn];
long long ans;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
	int i = n;
	while (i > 0)
	{
		ans += 2 * a[i] - 2;
		i = max(0, i - k);
	}
	cout << ans;
}
