
#include <bits/stdc++.h>

using namespace std;

int a, b;
int x, y, z;

int main()
{
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= 6; i++)
	{
		if (abs(i - a) < abs(i - b))
			x++;
		if (abs(i - a) == abs(i - b))
			y++;
		if (abs(i - a) > abs(i - b))
			z++;
	}
	printf("%d %d %d", x, y, z);
}