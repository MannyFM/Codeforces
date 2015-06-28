
#include <bits/stdc++.h>

using namespace std;

int n, m;
int i;

int main()
{
	scanf("%d%d", &n, &m);
	i = 1;
	while (1)
	{
		//printf("%d %d\n", m, i);
		if (m < i)
			break;
		m -= i;
		i++;
		if (i > n)
			i -= n;
	}
	printf("%d", m);
}