
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

int n, x[1010];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 1; i < n; i++)
	for (int j = 1; j < n; j++)
		{
			int l = min(x[i], x[i - 1]), r = max(x[i], x[i - 1]);
			int L = min(x[j], x[j - 1]), R = max(x[j], x[j - 1]);
			if (l < L && L < r && r < R)
			{
				puts("yes");
				return 0;
			}
			if (L < l && l < R && R < r)
			{
				puts("yes");
				return 0;
			}
		}
	puts("no");
}