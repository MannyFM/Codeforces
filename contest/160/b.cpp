
#include <bits/stdc++.h>

using namespace std;

int n, a[200], b[200];

int main()
{
	char cc;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cc, a[i] = (int)(cc - '0');
	for (int i = 0; i < n; i++)
		cin >> cc, b[i] = (int)(cc - '0');
	sort(a, a + n);
	sort(b, b + n);
	bool x = 1, y = 1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < b[i])
			y = 0;
		if (a[i] == b[i])
		{
			puts("NO");
			return 0;
		}
		if (a[i] > b[i])
			x = 0;
	}
	puts(x | y ? "YES" : "NO");
}