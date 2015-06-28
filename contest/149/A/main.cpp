
#include <bits/stdc++.h>

using namespace std;

int n = 12, a[13];
int k, sum;

int main()
{
	scanf("%d", &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
   	if (k == 0)
   	{
   		printf("0");
   		return 0;
	}
	sort(a + 1, a + n + 1);
	int i = n + 1;
	for (i = n; i > 0; i--)
	{
		sum += a[i];
		if (sum >= k)
			break;
	}
	if (sum < k)
		cout << -1;
	else
		cout << n - i + 1;
}