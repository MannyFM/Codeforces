
#include <bits/stdc++.h>

using namespace std;

int n, a[1012], us[1012], ans, maxi;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), us[a[i]]++;
	for (int i = 0; i <= 1012; i++)
	{
		maxi = max(maxi, us[i]);
		ans += us[i] > 0;
	}
	printf("%d %d", maxi, ans);
}