
#include <bits/stdc++.h>

using namespace std;

int k, l, h;

int main()
{
	scanf("%d%d", &k, &l);
	while (l % k == 0 && l != 1)
	{
		l /= k;
		h++;
	}
	if (l == 1)
		printf("YES\n%d", h - 1);
	else
		printf("NO");
}