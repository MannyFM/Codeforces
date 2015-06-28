
#include <bits/stdc++.h>

using namespace std;

bool check(int n, int s)
{
	return s >= 0 && s <= n * 9;
}

int mn[200], mx[200];

int main()
{
	int n, s;
	scanf("%d%d", &n, &s);
	if (n == 1)
	{
		if (s < 10)
			printf("%d %d", s, s);
		else
			printf("-1 -1");
		return 0;
	}
	int buf = s;
	for (int i = 0; i < n; i++)
	{
		int ok = 0;
		for (int j = !i; j < 10; j++)
		{
			if (check(n - i - 1, s - j))
			{
				mn[i] = j;
				s -= j;
				ok = 1;
				break;
			}
		}
		if (!ok)
		{
			puts("-1 -1");
			return 0;
		}
	}
	s = buf;
	for (int i = 0; i < n; i++)
	{
		int ok = 0;
		for (int j = 9; j >= !i; j--)
		{
			if (check(n - i - 1, s - j))
			{
				mx[i] = j;
				s -= j;
				ok = 1;
				break;
			}
		}
		if (!ok)
		{
			puts("-1 -1");
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d", mn[i]);
	printf(" ");
	for (int i = 0; i < n; i++)
		printf("%d", mx[i]);
}