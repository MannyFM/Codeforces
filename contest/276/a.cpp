
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e4 + 12)

int n, k, f, t, ans = -(1e9 + 7);

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &f, &t);
		if (t > k)
			ans = max(ans, f - (t - k));
		else
			ans = max(ans, f);
	}
	printf("%d", ans);
}