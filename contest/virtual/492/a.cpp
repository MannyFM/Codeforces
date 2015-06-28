
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e9 + 7)
#define mp make_pair
#define f first
#define s second

int n, h, i = 1;

int main()
{
	scanf("%d", &n);
	int now = 0;
	while (n > 0)
	{
		n -= i;
		i++;
		if (n < 0)
		{
			i--;
			break;
		}
	}
	printf("%d", i);
}