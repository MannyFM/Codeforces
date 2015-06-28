
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n;
pair <int, int> a[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].first, &a[i].second);
	sort (a, a + n);
	for (int i = 1; i < n; i++)
		if (a[i].second < a[i - 1].second)
		{
			puts("Happy Alex");
			return 0;
		}
	puts("Poor Alex");
}