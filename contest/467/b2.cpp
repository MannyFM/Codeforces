
#include <bits/stdc++.h>

using namespace std;

#define maxm (int)(1e3 + 12)

int n, k, m;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int bit1 = (k & (1 << i)) > 0;
		printf("%d", bit1);
	}
}