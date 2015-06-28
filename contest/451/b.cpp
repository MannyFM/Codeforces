
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 243)

int n, a[maxn], b[maxn];
map <int, int> m;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		m[b[i]] = i;
	for (int i = 0; i < n; i++)
		a[i] = m[a[i]];
	int l = -1, r = -1;
	for (int i = 0; i < n; i++)
		if (a[i] != i)
		{
			l = i;
			break;
		}
	for (int i = n - 1; i >= 0; i--)
		if (a[i] != i)
		{
			r = i;
			break;
		}
	if (l == -1 || r == -1)
	{
		printf("yes\n1 1");
		return 0;
	}
	reverse (a + l, a + r + 1);
	int fl = 1;
	for (int i = 0; i < n; i++)
		if (a[i] != i)
		{
			fl = 0;
			break;
		}
	if (fl)
	{
		printf("yes\n%d %d", l + 1, r + 1);
	}
	else
		printf("no");
		
}