
#include <bits/stdc++.h>

using namespace std;

int n, x;
int l[60], r[60];
int now, ans;

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d%d", l + i, r + i);
	now = 1;
	ans = 0;
	for (int i = 0; i < n; i++)
	{
		int delta = l[i] - now;
		int jump_cnt = delta / x;
		now += jump_cnt * x;
		ans += r[i] - now + 1;
		now += r[i] - now;
		now++;
	}
	printf("%d", ans);
}