
#include <bits/stdc++.h>

using namespace std;

int n, a[3], x;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == 25)
			a[0]++;
		if (x == 50)
		{
			if (a[0] > 0)
				a[0]--, a[1]++;
			else
			{
				puts("NO");
				return 0;
			}
		}
		if (x == 100)
		{
			if (a[1] > 0 && a[0] > 0)
			{
				a[1]--, a[2]++, a[0]--;
			}
			else
			{
				if (a[0] > 2)
				{
					a[0] -= 3;
					a[2]++;
				}
				else
				{
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
}