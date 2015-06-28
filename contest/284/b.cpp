
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(2e5 + 12)

int n, cnt[300];
char a[maxn];

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++)
		cnt[(int)a[i]]++;
	int ans = 0;
	//printf("%d %d %d\n", cnt['A'], cnt['I'], cnt['F']);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 'I')
		{
			ans += (cnt[(int)'I'] == 1);
		}
		if (a[i] == 'A')
		{
			ans += (cnt[(int)'I'] == 0);
		}
	}
	printf("%d", ans);
}