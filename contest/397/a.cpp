
#include <bits/stdc++.h>

using namespace std;

int n, l[200], r[200];
int us[200];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", l + i, r + i);
	for (int i = l[1]; i < r[1]; i++)
		us[i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = l[i]; j < r[i]; j++)
			us[j] = 2;
	int ans = 0;
	for (int i = l[1]; i < r[1]; i++)
		ans += us[i] == 1;
	printf("%d", ans);
}