
#include <bits/stdc++.h>

using namespace std;

int a[4][4];

int main()
{
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &a[i][j]);
	for (int x = 1; x <= (int)(1e5); x++)
	{
		int y = x - a[3][2] + a[1][3];
		int z = x - a[3][2] + a[2][1];
		if (y > 0 && z > 0 && y + z == a[1][2] + a[1][3])
		{
			a[1][1] = x;
			a[2][2] = y;
			a[3][3] = z;
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 3; j++)
					printf("%d ", a[i][j]);
				puts("");
			}
			return 0;
		}
	}
}