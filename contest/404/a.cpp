
#include <bits/stdc++.h>

using namespace std;

#define ex {puts("NO"); return 0;}
int n;
char a[350][350], o, x;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	o = a[2][1];
	x = a[1][1];
	if (x == o)
	{
		puts("NO");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				if (a[i][j] != x)
					ex;
			}
			else
				
			if (i == n - j + 1)
			{
				if (a[i][j] != x)
					ex;
			}
			else
			
			if (a[i][j] != o)
				ex;
		}
	}
	puts("YES");
}