
#include <bits/stdc++.h>

using namespace std;

int n, a[200];

int main()
{
	scanf("%d", &n);
	if (n <= 2)
	{
		puts("-1");
		return 0;
	}
	for (int i = n; i > 0; i--)
		printf("%d ", i);
}