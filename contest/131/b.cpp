
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, a[maxn];
int cnt[30];
const int shift = 12;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i), cnt[a[i] + shift]++;
	long long ans = (cnt[shift] * 1ll * (cnt[shift] - 1)) / 2;
	for (int i = 1; i <= 10; i++)
	{
		ans += cnt[shift + i] * 1ll * cnt[shift - i];
	}
	printf("%I64d", ans);
}