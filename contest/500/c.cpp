
#include <bits/stdc++.h>

using namespace std;

int n, m;
int w[550], b[1010];
bool us[550];
int a[550], sz;
int q[550];

void shift(int j)
{
	q[1] = a[j];
	for (int i = 1; i < j; i++)
		q[i + 1] = a[i];
	for (int i = j + 1; i <= n; i++)
		q[i] = a[i];
	for (int i = 1; i <= n; i++)
		a[i] = q[i];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", w + i);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", b + i);
		if (!us[b[i]])
		{
			us[b[i]] = 1;
			a[++sz] = b[i];
		}
	}
	for (int i = 1; i <= n; i++)
		if (!us[i])
			a[++sz] = i;
	long long ans = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n && a[j] != b[i]; j++)
		{
			ans += w[a[j]];
		}
		int pos = 0;
		for (int j = 1; j <= n; j++)
			if (a[j] == b[i])
			{
				pos = j;
				break;
			}
		shift(pos);
	}
	printf("%I64d", ans);
}
