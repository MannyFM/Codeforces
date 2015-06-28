
#include <bits/stdc++.h>

using namespace std;

int n, t[200], d, sum;
int ans;

int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t[i]);
		sum += t[i];
	}
	if (sum + (n - 1) * 10 > d)
	{
		printf("-1");
		return 0;
	}
	printf("%d", (d - sum) / 5);
}