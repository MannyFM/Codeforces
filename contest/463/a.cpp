
#include <bits/stdc++.h>

using namespace std;

int n, s, x, y;
int ans = -1;

int main()
{
	scanf("%d%d", &n, &s);
	s *= 100;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		//printf("%d %d %d %d\n", x, y, x * 100 + y, s);
		if (x * 100 + y > s)
			continue;
		ans = max(ans, (100 - y) % 100);
	}
	printf("%d", ans);
}