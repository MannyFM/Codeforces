
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(3e4 + 12)

int n, a[maxn], t, j;

int main()
{
	scanf("%d%d", &n, &t);
	j = 1;
	for (int i = 1; i < n; i++)
		scanf("%d", &a[i]);
	while (j < t)
	{
		j += a[j];
	}
	puts(j == t ? "YES" : "NO");
}
