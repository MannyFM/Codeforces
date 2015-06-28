
#include <bits/stdc++.h>

using namespace std;

int a[5], b[5];

int main()
{
	int i = 1;
	scanf("%d%d", a + i, b + i), i++;
	scanf("%d%d", a + i, b + i), i++;
	scanf("%d%d", a + i, b + i), i++;
	scanf("%d%d", a + i, b + i), i++;
	
	if (a[1] > b[3] && b[2] > a[4])
		if ((a[1] > b[4] && b[2] > a[4]) && (a[2] > b[4] && b[1] > a[4]))
		{
			puts("Team 1");
			return 0;
		}
	if (a[2] > b[3] && b[1] > a[4])
		if ((a[1] > b[4] && b[2] > a[4]) && (a[2] > b[4] && b[1] > a[4]))
		{
			puts("Team 1");
			return 0;
		}
	
	if (a[3] > b[1] && b[4] > a[2])
		if ((a[3] > b[2] && b[4] > a[1]) && (a[4] > b[2] && b[3] > a[1]))
		{
			puts("Team 2");
			return 0;
		}
	if (a[4] > b[1] && b[3] > a[2])
		if ((a[3] > b[2] && b[4] > a[1]) && (a[4] > b[2] && b[3] > a[1]))
		{
			puts("Team 2");
			return 0;
		}
	puts("Draw");
}