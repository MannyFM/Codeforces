
#include <bits/stdc++.h>

using namespace std;

int n, last = -1, ans;
char a[3030];

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '.')
			continue;
		if (a[i] == 'L')
			if (a[last] == 'R')
			{
				ans += (i - last - 1) & 1;
			}
		if (a[i] == 'R')
		{
			if (last == -1)
			{
				ans += i;
			}
			else
				ans += i - last - 1;
		}
		last = i;
	}
	if (last == -1)
		ans = n;
	else
	if (a[last] == 'L')
		ans += n - 1 - last;
	printf("%d", ans);
}