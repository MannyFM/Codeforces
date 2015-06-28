
#include <bits/stdc++.h>

using namespace std;

int n, sum, ans, a;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a), sum += a;
	for (int add = 1; add <= 5; add++)
	{
		ans += ((sum + add) % (n + 1) != 1);
	}
	printf("%d", ans);
}