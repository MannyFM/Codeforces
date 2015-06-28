
#include <bits/stdc++.h>

using namespace std;

int n, a[5010], ans;
bool us[5010];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (!us[a[i]] && 1 <= a[i] && a[i] <= n)
		{
			us[a[i]] = 1;
			continue;
		}
		ans++;
	}
	printf("%d", ans);
}