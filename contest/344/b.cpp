
#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main()
{
	scanf("%d%d%d", &a, &b, &c);
	///a = x + z	x = a - z = b - y
	///b = x + y	y = b - x = c - z
	///c = y + z	z = a - x = c - y
	for (int x = 0; x <= a + b + c; x++)
	{
		int y = b - x;
		int z = a - x;
		if (y < 0 || z < 0)
			continue;
		if (a - z != b - y || b - x != c - z || a - x != c - y)
			continue;
		printf("%d %d %d", x, y, z);
		return 0;
	}
	puts("Impossible");
}