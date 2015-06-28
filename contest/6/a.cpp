
#include <bits/stdc++.h>

int a, b, c;
int x[4];

int check(int i = 0)
{
	if (!i)
		return a < b + c && b < a + c && c < a + b;
	return a <= b + c && b <= a + c && c <= a + b;
}

int main()
{
	scanf("%d%d%d%d", x, x + 1, x + 2, x + 3);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i != j)
			for (int k = 0; k < 4; k++)
				if (k != i && k != j)
				{
					a = x[i];
					b = x[j];
					c = x[k];
					if (check())
					{
						puts("TRIANGLE");
						return 0;
					}
				}
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i != j)
			for (int k = 0; k < 4; k++)
				if (k != i && k != j)
				{
					a = x[i];
					b = x[j];
					c = x[k];
					if (check(1))
					{
						puts("SEGMENT");
						return 0;
					}
				}
	puts("IMPOSSIBLE");
}