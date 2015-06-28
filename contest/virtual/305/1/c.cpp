
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5 + 12)

int n, l[maxn], r[maxn];
int L, R;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", l + i, r + i);
	L = l[1], R = r[1];
	for (int i = 2; i <= n; i++)
		L = min(L, l[i]), R = max(R, r[i]);
	for (int i = 1; i <= n; i++)
		if (l[i] == L && r[i] == R)
		{
			printf("%d", i);
			return 0;
		}
	puts("-1");
}              \