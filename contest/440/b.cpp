
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 50000 + 12
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "b"
#define F first
#define S second

int n;
ll sum, a[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", a + i), sum += a[i];
	sum /= n;
	ll ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == sum)
			continue;
		ans += abs(a[i] - sum);
		a[i + 1] += a[i] - sum;
	}
	printf("%I64d", ans);
}