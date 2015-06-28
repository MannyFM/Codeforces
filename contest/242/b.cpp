
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 1)
#define inf (int)(1e9 + 7)

int n, L = inf, R = -inf;
int l[maxn], r[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", l + i, r + i);
		L = min(L, l[i]);
		R = max(R, r[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (l[i]  <= L && R <= r[i])
		{
			printf("%d", i);
			return 0;
		}
	}
	puts("-1");
}