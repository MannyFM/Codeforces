
#include <bits/stdc++.h>

using namespace std;

int xa, ya, xb, yb;

int main()
{
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	if (xa != xb && ya != yb && abs(xb - xa) != abs(ya - yb))
	{
		cout << -1;
		return 0;
	}
	if (xa == xb)
	{
		int a = abs(ya - yb);
		printf("%d %d %d %d", xa + a, ya, xb + a, yb);
	}
	else
	if (ya == yb)
	{
		int a = abs(xa - xb);
		printf("%d %d %d %d", xa, ya + a, xb, yb + a);
	}
	else
	{
		printf("%d %d %d %d", xa, yb, xb, ya);
	}
}	
