
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define mp make_pair
#define pb push_back
#define fn "cows"
#define LOCAL

int n, a[maxn], k;

bool f(int x)
{
	int last = -inf;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - last >= x)
		{
			cnt++;
			last = a[i];
		}
	}
	return (cnt >= k);
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	int l = 0, r = inf;
	int mid;
	while (r - l > 1)
	{
		mid = (l + r) >> 1;
		if (f(mid))
			l = mid;
		else
			r = mid;
	}
	//printf("%d %d %d\n", l, mid, r);
	printf("%d", l);
}