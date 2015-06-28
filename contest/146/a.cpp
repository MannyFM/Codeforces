
#include <bits/stdc++.h>

using namespace std;

int n, a[60], s[2];
char c;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> c, a[i] = (int)(c - '0');
	for (int i = 0; i < n; i++)
		if (a[i] != 4 && a[i] != 7)
		{
			puts("NO");
			return 0;
		}
		else
			s[i >= n / 2] += a[i];
	if (s[0] == s[1])
		puts("YES");
	else
		puts("NO");
	
}