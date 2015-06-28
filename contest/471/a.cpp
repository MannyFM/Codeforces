
#include <bits/stdc++.h>

using namespace std;

int l[10], x;

int main()
{
	for (int i = 0; i < 6; i++)
		scanf("%d", &x), l[x]++;
	int fl = 0;
	for (int i = 0; i < 10; i++)
		if (l[i] >= 4)
		{
			fl = 1;
			l[i] -= 4;
			break;
		}
	if (!fl)
	{
		puts("Alien");
		return 0;
	}
	for (int i = 0; i < 10; i++)
		if (l[i] >= 2)
		{
			puts("Elephant");
			return 0;
		}
	puts("Bear");
}
