
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int a[maxn];
string s;

int main()
{
	cin >> s;
	int n = (int)(s.size());
	for (int i = 0; i < n; i++)
		a[i] = int(s[i] - '0');
	int pos = -1, other = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{
			pos = i;
			if (other == -1 && a[i] < a[n - 1])
				other = i;
		}
	}
	if (pos == -1 && other == -1)
	{
		puts("-1");
		return 0;
	}
	swap(a[n - 1], a[other != -1 ? other : pos]);
	for (int i = 0; i < n; i++)
		printf("%d", a[i]);
}