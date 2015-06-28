
#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	scanf("%d", &n);
	printf("%d\n", (n * n + 1) / 2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf(((i + j) % 2 == 0)?"C":".");
		puts("");
	}
}