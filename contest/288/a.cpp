
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == k && n == 1)
	{	puts("a");
		return 0;
	}
	if (n < k || k == 1) 
	{
		puts("-1");
		return 0;
	}
	if (k == 1)
	{
		for (int i = 0; i < n; i++)
			printf("a");
		return 0;
	}
	int fl = 0;
	for (int i = 0; i < n - k + 2; i++, fl ^= 1)
		printf("%c", fl ? 'b' : 'a');
	char c = 'c';
	for (int i = 0; i < k - 2; i++)
		printf("%c", c++);
}