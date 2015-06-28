
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)
#define f first
#define s second

int n, p[maxn];
pair <string, string> a[maxn];

bool f(int i, int j)
{
	if (a[i].f < a[j].f)
		return 1;
	if (a[i].f < a[j].s)
	{
		swap(a[j].s, a[j].f);
		return 1;
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].f >> a[i].s;
		if (a[i].f > a[i].s)
			swap(a[i].f, a[i].s);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	
	for (int i = 1; i < n; i++)
	{
		if (!f(p[i], p[i + 1]))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}