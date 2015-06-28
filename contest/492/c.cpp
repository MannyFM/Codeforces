
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)
#define mp make_pair
#define f first
#define s second

int n;
long long a[maxn], b[maxn];
long long avg, r;
long long ans, sz;
pair <long long, long long> c[maxn];

int main()
{
	scanf("%d%I64d%I64d", &n, &r, &avg);
	for (int i = 0; i < n; i++)
		scanf("%I64d%I64d", &a[i], &b[i]), ans += a[i];
	double p = ans / n;
	if (ans >= avg * n)
	{
		puts("0");
		return 0;
	}
	for (int i = 0; i < n; i++)
		if (a[i] != r)
			c[sz++] = mp(b[i], r - a[i]);
	sort (c, c + sz);
	int i = 0;
	long long cnt = 0;
	
	while (ans < avg * n && i < sz)
	{
		long long t = avg * n - ans;
		if (t <= 0)
			break;
		long long pl = t;
		if (c[i].s < t)
			pl = c[i].s;
		cnt += pl * c[i].f;
		ans += pl;
		c[i].s -= pl;
		i++;
			
	}
	cout << cnt;
}