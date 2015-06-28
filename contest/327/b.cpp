
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e7 + 12)

int n, npr[maxn];

int main()
{
	npr[0] = npr[1] = 1;
	for (int j = 2; j * j <= maxn; j++)
	{
		if (npr[j])
			continue;
		for (int i = j * j; i <= maxn; i += j)
			npr[i] = 1;
	}
	scanf("%d", &n);
	int j = 0;
	for (int i = 2; j < n; i++)
	{
		if (!npr[i])
			printf("%d ", i), j++;
	}
	
}