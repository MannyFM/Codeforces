
#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)(1e5 + 12);
int n, a[maxn];
int pos = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i] < a[pos])
			pos = i;
	}
	for (int i = 1; i <= n; i++)
		if (a[i] == a[pos] && i != pos)
		{
			puts("Still Rozdil");
			return 0;
		}
	printf("%d", pos);
}