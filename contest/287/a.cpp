
#include <bits/stdc++.h>

using namespace std;

int a[5][5];
char _char;

int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> _char, a[i][j] = (_char == '.');
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		int c = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
		if (c != 2)
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}
