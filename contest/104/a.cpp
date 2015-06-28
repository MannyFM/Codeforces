
#include <bits/stdc++.h>

using namespace std;

int n;
///1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11

int main()
{
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= 11; i++)
	{
		if (i + 10 == n)
		{
			ans += 4;
		}
	}
	if (n == 20)
	{
		ans += 11;
	}
	printf("%d", ans);
}