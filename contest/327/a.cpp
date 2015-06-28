
#include <bits/stdc++.h>

using namespace std;

int n, a[200], sum;
int ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum = sum + a[i];
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++)
		{
			int cnt[2] = {0, 0};
			for (int i = l; i <= r; i++)
				cnt[a[i]]++;
			int new_sum = sum + cnt[0] - cnt[1];
			ans = max(new_sum, ans);
		}
	printf("%d", ans);
}