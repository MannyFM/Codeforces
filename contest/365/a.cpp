
#include <bits/stdc++.h>

using namespace std;

int n, k, a[200];

bool check(int x)
{
	vector <char> us(10, 0);
	while (x > 0)
		us[x % 10] = 1, x /= 10;
	for (int i = 0; i <= k; i++)
		if (!us[i])
			return 0;
	return 1;
}

int main()
{
	int ans = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		ans += check(a[i]);
	}
	printf("%d", ans);
}