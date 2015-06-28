
#include <bits/stdc++.h>

using namespace std;

int n, cnt[1010], a;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		cnt[a]++;
		if (cnt[a] > (n + 1) / 2)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}	