
#include <bits/stdc++.h>

using namespace std;

int n, x, a, b;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		if (x == 100)
			a++;
		else
			b++;
	}
	int all = a * 100 + b * 200;
	if (all % 200)
	{
		puts("NO");
		return 0;
	}
	int half = all / 2, ok = 0;
	for (int i = 0; i <= b; i++)
		if (i * 200 <= half && half <= a * 100 + i * 200)
			ok = 1;
	puts(ok ? "YES" : "NO");
}
