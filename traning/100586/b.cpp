
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "prizes"
#define LOCAL
#define F first
#define S second

int n, a[maxn], k;
int l, r;
ll sum, now, pre[maxn];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), pre[i] = pre[i - 1] + a[i];
	sum = 0;
	for (int i = k; i <= n; i++)
	{
		now = pre[i] - pre[i - k];
		if (now > sum)
		{
			sum = now;
			l = i - k + 1;
			r = i;
		}
		//printf("%d %d %I64d\n", i - k + 1, i, now);
	}
	sum = 0ll;
	for (int i = k; i < l; i++)
	{
		now = pre[i] - pre[i - k];
		if (now > sum)
			sum = now;
	}
	for (int i = r + k + 1; i <= n; i++)
	{
		now = pre[i] - pre[i - k];
		if (now > sum)
			sum = now;
	}
	printf("%I64d", sum);
}