
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e3 + 10)
#define mp make_pair
#define f first
#define s second

int n, a[maxn], l;
double ans;

int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
	ans = a[1];
	a[n + 1] = l;
	for (int i = 1; i <= n + 1; i++)
	{
		if (2 * ans < a[i] - a[i - 1])
			ans = (a[i] - a[i - 1]) / 2;
	}
	printf("%.9f", ans);

}