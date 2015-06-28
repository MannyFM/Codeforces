
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 2)

int n, a[2][maxn];
int cnt[2][maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[0][i], &a[1][i]);
		cnt[0][a[0][i]]++;
		cnt[1][a[1][i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		int f, s;
		f = n - 1 + cnt[0][a[1][i]];
		s = 2 * (n - 1) - f;
		printf("%d %d\n", f, s);
	}
}