
#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int const maxn = int(1e5) + 12;

int n, d;
int a[maxn], b[maxn];
long long pre[maxn];
pair <int, int> p[maxn];

int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", a + i, b + i), p[i] = make_pair(a[i], b[i]);
	sort(p + 1, p + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		a[i] = p[i].first;
		b[i] = p[i].second;
		pre[i] = pre[i - 1] + b[i];
	}
	long long ans = 0ll;
	/*
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", a[i], b[i]);
	puts("");
	*/
	for (int i = 1; i <= n; i++)
	{
		int pos = upper_bound(a + 1, a + 1 + n, a[i] + d - 1) - a - 1;
		ans = max(ans, pre[pos] - pre[i - 1]);
		//printf("%d %d %d\n", i, a[i], a[pos]);
	}
	printf("%I64d", ans);
}