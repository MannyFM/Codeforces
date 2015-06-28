
#include <bits/stdc++.h>

using namespace std;

int d, k;

int main()
{
	scanf("%d%d", &k, &d);
	if (d == 0)
	{
		puts(k == 1 ? "0" : "No solution");
		return 0;
	}
	printf("%d", d);
	for (int i = 1; i < k; i++)
		printf("0");
}