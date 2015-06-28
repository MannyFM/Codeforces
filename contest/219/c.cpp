
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5 + 12)

int n, k, a[maxn], cnt[maxn];
int now;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), cnt[a[i]]++;
	for (int i = 0; i < maxn; i++)
		now += cnt[i] > 0;
	if (now < k)
	{
		puts("-1 -1");
		return 0;
	}
	int l = 1, r = n;
	int ok = 1;
	while (l <= r && ok)
	{
		ok = 0;
		cnt[a[r]]--;
		if (cnt[a[r]] == 0)
			now --;
		r--;
		ok = 1;
		if (now < k)
		{
			r++;
			cnt[a[r]]++;
			now++;
			ok--;
		}
		if (ok)
			continue;
		cnt[a[l]]--;
		if (cnt[a[l]] == 0)
			now --;
		l++;
		ok = 1;
		if (now < k)
		{
			l--;
			cnt[a[l]]++;
			now++;
			ok--;
		}
	}
	printf("%d %d", l, r);
}