
#include <bits/stdc++.h>

using namespace std;

int n, a[200];

int main()
{
	scanf("%d", &n);
	if (n % 2)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i += 2)
		a[i] = i + 1, a[i + 1] = i;
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
}