
#include <bits/stdc++.h>

using namespace std;

int n, cnt[2], ans[2], a;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		cnt[a % 2]++;
		ans[a % 2] = i;
	}
	printf("%d", ans[cnt[1] == 1]);
}