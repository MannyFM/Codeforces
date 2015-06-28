
#include <bits/stdc++.h>

using namespace std;

int n, k, a[200];

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (k > n)
	{
		puts("-1");
		return 0;
	}
	if (k == n)
	{
		puts("0 0");
		return 0;
	}
	sort (a, a + n);
	cout << a[n - k] << " 0";
}
