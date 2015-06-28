
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, cnt[maxn], a[maxn];
long long f[maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), cnt[a[i]]++;
	f[0] = 0;
	f[1] = cnt[1];
	for (int i = 2; i < maxn; i++)
		f[i] = max(f[i - 1], f[i - 2] + i * 1ll * cnt[i]);
	printf("%I64d", f[maxn - 1]);
}