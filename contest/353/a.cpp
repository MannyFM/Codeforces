
#include <bits/stdc++.h>

using namespace std;

int n, a[200], b[200], s1, s2;
bool x;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		s1 += a[i];
		s2 += b[i];
	}
	for (int i = 0; i < n; i++)
	{
		if ((a[i] & 1) ^ (b[i] & 1))
			x = 1;
	}
	if ((s1 % 2 == 0) && (s2 % 2 == 0))
	{
		puts("0");
		return 0;
	}
	if ((s1 % 2 == 0) ^ (s2 % 2 == 0))
	{
		puts("-1");
		return 0;
	}
	puts(x ? "1" : "-1");
}