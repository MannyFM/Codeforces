
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 125)

int n, a[maxn];
int res, energy;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		energy += (a[i - 1] - a[i]);
		if (energy < 0)
		{
			res -= energy;
			energy = 0;
		}
	}
	printf("%d", res);

}