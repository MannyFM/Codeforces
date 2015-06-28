
#include <bits/stdc++.h>

using namespace std;

int cnt[2], n, b[240];
char a[230];

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++)
		b[i] = (a[i] == 'X'), cnt[b[i]]++;
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (cnt[b[i]] > n / 2)
		{
			cnt[b[i]]--;
			cnt[!b[i]]++;
			b[i] ^= 1;
			ans++;
		}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%c", b[i] ? 'X' : 'x');
}