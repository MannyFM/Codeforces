
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	if (n < 4)
	{
		puts("NO");
		return 0;
	}
	if (n & 1)
	{
		puts("YES");
		puts("5 - 3 = 2");
		puts("1 + 2 = 3");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		for (int i = 6; i < n; i += 2)
			printf("%d - %d = 1\n1 * 24 = 24\n", i + 1, i);
		return 0;
	}
	else
	{
		puts("YES");
		puts("1 * 2 = 2");
		puts("2 * 3 = 6");
		puts("6 * 4 = 24");
		for (int i = 5; i < n; i += 2)
			printf("%d - %d = 1\n1 * 24 = 24\n", i + 1, i);
		return 0;
	}
	
}